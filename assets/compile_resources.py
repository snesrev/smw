import sys, array, hashlib, struct, argparse, os
import util
from util import cache, get_byte, get_word, get_24, get_bytes, get_words

def flatten(xss):
    return [x for xs in xss for x in xs]
  
def invert_dict(xs):
  return {s:i for i,s in xs.items()}

assets = {}

def add_asset_uint8(name, data):
  assert name not in assets
  assets[name] = ('uint8', bytes(array.array('B', data)))

def add_asset_uint16(name, data):
  assert name not in assets
  assets[name] = ('uint16', bytes(array.array('H', data)))

def add_asset_int8(name, data):
  assert name not in assets
  assets[name] = ('int8', bytes(array.array('b', data)))

def add_asset_int16(name, data):
  assert name not in assets
  assets[name] = ('int16', bytes(array.array('h', data)))

def add_asset_packed(name, data):
  assert name not in assets
  assets[name] = ('packed', pack_arrays(data))

def add_asset_blob(name, data):
  assert name not in assets
  assets[name] = ('blob', pack_blob(data))

def pack_24(v):
  assert v >= 0 and v < (1 << 24)
  return struct.pack('I', v)[:3]

# Pack arrays and determine automatically the index size
def pack_arrays(arr):
  if len(arr) == 0:
    return b''
  backmap, fstmap = {}, []
  all_offs, offs = [], 0
  saved = 0
  for i, v in enumerate(arr):
    v = bytes(v)
    k = backmap.get(v)
    if k == None:
      k = len(all_offs)
      backmap[v] = k
      offs += len(v)
      all_offs.append(offs)
    else:
      saved += len(v)
    fstmap.append(k)
  assert len(arr) <= 4096
  del all_offs[-1]
  flags = len(arr) - 1
  if len(all_offs) == 0 or all_offs[-1] < 65536:
    r = [struct.pack('H', i) for i in all_offs] + list(backmap.keys())
    flags |= 0x8000
  else:
    r = [struct.pack('I', i) for i in all_offs] + list(backmap.keys())
  if len(backmap) != len(arr):
    if len(all_offs) <= 255:
      r.append(array.array('B', fstmap).tobytes())  
    else:
      r.append(array.array('H', fstmap).tobytes())  
    r.append(struct.pack('H', len(all_offs)))
    flags |= 0x4000
  r.append(struct.pack('H', flags))
  return b''.join(r)

def pack_blob(ranges):
  out = []
  for a, b in sorted(ranges):
    if len(out) and a <= out[-1][1]:
      # continue existing range
      if b > out[-1][1]:
        out[-1] = (out[-1][0], b)
    else:
      out.append((a, b))
  off = 2 + len(out) * 6
  a_arr, b_arr, r_arr = [], [], []
  for a, b in out:
    a_arr.append(pack_24(a))
    b_arr.append(pack_24(off))
    r_arr.append(util.get_bytes(a, b - a))
    off += b - a
  return struct.pack('H', len(out)) + b''.join(a_arr) + b''.join(b_arr) + b''.join(r_arr)

def get_stripe_len(ea):
  ea_org = ea
  while True:
    b = util.get_byte(ea)
    if b & 0x80: 
      return ea + 1 - ea_org
    p1 = util.get_byte(ea + 1)
    p2 = util.get_byte(ea + 2)
    p3 = util.get_byte(ea + 3)
    ea += 4
    if p2 & 0x40:
      ea += 2
    else:
      ll = ((p2 << 8 | p3) & 0x3fff) + 1
      ea += ll

def get_rats_size(p):
  if p == 0: return 0
  p -= 8
  if (p & 0x8000) == 0:
    p -= 0x8000
  assert util.get_bytes(p, 4) == b'STAR', hex(p)
  return get_word(p + 4) + 1

def get_rats_bytes(p):
  return get_bytes(p, get_rats_size(p))

@cache
def unpack_rle(ea):
  ea_org = ea
  r = bytearray()
  while util.get_word(ea) != 0xffff:
    x = util.get_byte(ea); ea += 1 
    if x & 0x80:
      y = util.get_byte(ea); ea += 1 
      for i in range((x & 0x7f) + 1):
        r.append(y)
    else:
      for i in range((x & 0x7f) + 1):
        y = util.get_byte(ea); ea += 1 
        r.append(y)
  return bytes(r), ea + 2 - ea_org

def unpack_rle_of_size(ea, size):
  ea_org = ea
  r = bytearray()
  while len(r) < size:
    x = util.get_byte(ea); ea += 1 
    if x & 0x80:
      y = util.get_byte(ea); ea += 1 
      for i in range((x & 0x7f) + 1):
        r.append(y)
    else:
      for i in range((x & 0x7f) + 1):
        y = util.get_byte(ea); ea += 1 
        r.append(y)
  return bytes(r), ea - ea_org


@cache
def calc_level_len(ea, dbg = False):
  if dbg: print('Now decoding level at 0x%x' % ea)
  ea_org = ea
  ea += 5

  kObjNames = {
    60 : 'StoneBlock',
    13 : 'CementBlock',
    0x22: 'LmMap16',
  }

  while True:
    b0 = util.get_byte(ea); ea += 1
    if b0 == 0xff:
      break
    b1 = util.get_byte(ea); ea += 1
    b2 = util.get_byte(ea); ea += 1

    obj_id = (b1 >> 4) | ((b0 & 0x60) >> 1)
    blocks_size_or_type = b2

    if dbg:
      print(' %.2X %.2X %.2X: 0x%x, 0x%x, %d: %s' % (b0, b1, b2, ea-3, obj_id, blocks_size_or_type, kObjNames.get(obj_id)))

    if obj_id == 0 and blocks_size_or_type == 0:
      ea += 1
    elif obj_id in (0x22, 0x23): # lunar magic
      ea += 1 
    elif obj_id in (0x24, 0x25): # lunar deprecated
      ea += 0
    elif obj_id in (0x27, ):
      ea += 2
  return ea - ea_org

LUNAR_MAGIC = get_bytes(0xFF0A0, 5) == b'Lunar'

def extra_lunar_magic_text():
  return '\n\nDo the following steps:\n1) Use Lunar Magic 3.33.\n' + \
         '2) Open up a level, modify something, save it.\n' + \
         '3) Open up the 16x16 tile map editor, edit something, save it.\n' + \
         '4) Open up the Exanim editor for some level. Edit something, save.\n'


if LUNAR_MAGIC:
  s = get_bytes(0xFF0A0, 24).decode('utf8')
  print('Detected %s' % s, file = sys.stderr)
  if s != 'Lunar Magic Version 3.33':
    raise Exception('Invalid Lunar Magic version. Expected 3.33, found "%s"\n' % s + extra_lunar_magic_text())

  if get_byte(0x6F540) != 0xc9:
    raise Exception('The map16 file format is incorrect. ' + extra_lunar_magic_text())


def get_comp_data(ea):
  data, comp_len = util.decomp(ea, util.get_byte, return_length = True)  
  return util.get_bytes(ea, comp_len)

def decomp_data(ea):
  data, comp_len = util.decomp(ea, util.get_byte, return_length = True)  
  return data


kLmFeature_LmEnabled = 1 << 0
kLmFeature_Exanim = 1 << 1
kLmFeature_SkipOverworldDecompress = 1 << 2
kLmFeature_OverworldTiles4bpp = 1 << 3
kLmFeature_Copy512colors = 1 << 4
kLmFeature_WeirdPalette = 1 << 5
kLmFeature_SkipLoadPaletteHook = 1 << 6
kLmFeature_GfxUpload = 1 << 7
kLmFeature_LoadLevel = 1 << 8
kLmFeature_4bppgfx = 1 << 9
kLmFeature_CustomTitleScreenDemo = 1 << 10
kLmFeature_CustomDisplayMessage = 1 << 11
kLmFeature_DontSetYposForIntroMarch = 1 << 12
kLmFeature_OwPalette = 1 << 13
kLmFeature_LevelNamesPatch = 1 << 14
kLmFeature_DestroyTileAnims = 1 << 15
kLmFeature_EventStuff = 1 << 16
kLmFeature_MusicRegTweak = 1 << 17
kLmFeature_TideWaterTweak = 1 << 18
kLmFeature_EnemyCollTweak = 1 << 19
kLmFeature_Ow4bppGfx = 1 << 20
kLmFeature_DontResetOwPlayersMap = 1 << 21
kLmFeature_NonStdGfxAA8D = 1 << 22 
kLmFeature_TimerTweaks = 1 << 23
kLmFeature_NoDefaultSavePrompts = 1 << 24

kHack_Walljump = 1 << 0

class LmFeatures:
  flags = 0
  kLmLvlInfo_addr = 0
  kLmLvlInfo_addr_other = 0
  hacks = 0

  def serialize(self):
    return struct.pack('IIII', self.flags, self.kLmLvlInfo_addr, self.kLmLvlInfo_addr_other, self.hacks)

def print_all(args):
  lm_feat = LmFeatures()
  r = []
  lo, hi, bank = util.get_bytes(0xB992, 50), util.get_bytes(0xB9c4, 50), util.get_bytes(0xB9f6, 50)
  for i in range(50):
    p = bank[i] << 16 | hi[i] << 8 | lo[i]
    r.append(get_comp_data(p))
  add_asset_packed('kGraphicsPtrs', r)

  data, comp_len = util.decomp(0x80000 | util.get_word(0xB8D8), util.get_byte, return_length = True)
  #print('%d: %d: %d' % (0x32, comp_len, len(data)))
  add_asset_uint8('kGfx32', data)

  data, comp_len = util.decomp(0x80000 | util.get_word(0xB88B), util.get_byte, return_length = True)
  #print('%d: %d: %d' % (0x33, comp_len, len(data)))
  add_asset_uint8('kGfx33', data)

  r = [b'']
  for i in range(1, 86):
    p = util.get_24(0x84D0 + i * 3)
    pl = get_stripe_len(p)
    #if i == 1:
      #print(util.get_bytes(p, 16))
    r.append(util.get_bytes(p, pl))
  add_asset_packed('kLoadStripeImagePtrs', r)

  r = []
  for i in range(45):
    p = util.get_24(0x59000 + i * 3)
    pl = get_stripe_len(p)
    r.append(util.get_bytes(p, pl))
  add_asset_packed('kLayer3ImagePtrs', r)

  add_asset_uint8('kSpcCreditsMusicBank', util.get_bytes(0x3e400, 6624))
  add_asset_uint8('kSpcLevelMusicBank', util.get_bytes(0xEAED6, 16899))
  add_asset_uint8('kSpcEngine', util.get_bytes(0xe8000, 6321) + b'\x00\x00')
  add_asset_uint8('kSpcSamples', util.get_bytes(0xf8000, 28538))
  add_asset_uint8('kSpcOverworldMusicBank', util.get_bytes(0xe98b1, 5667))

  add_asset_uint16('kMap16Data_OverworldLayer1', util.get_words(0x05d000, 772))

  add_asset_uint16('kMap16Data', util.get_words(0xd8000, (0xA100 - 0x8000) // 2))
  add_asset_uint16('kMap16Data_Castle', util.get_words(0xdbc00, 712))
  add_asset_uint16('kMap16Data_Rope', util.get_words(0xdc800, 712))
  add_asset_uint16('kMap16Data_Underground', util.get_words(0xdd400, 712))
  add_asset_uint16('kMap16Data_GhostHouse', util.get_words(0xde300, 712))

  add_asset_uint16('kGlobalPalettes_Sky', util.get_words(0x00B0A0, 16))
  add_asset_uint16('kGlobalPalettes_Background', util.get_words(0x00B0B0, 96))
  add_asset_uint16('kGlobalPalettes_Layer3', util.get_words(0xB170, 16))
  add_asset_uint16('kGlobalPalettes_Foreground', util.get_words(0x00B190, 96))
  add_asset_uint16('kGlobalPalettes_Objects', util.get_words(0x00B250, 60))
  add_asset_uint16('kPlayerPalettes', util.get_words(0x00B2C8, 40))
  add_asset_uint16('kGlobalPalettes_Sprites', util.get_words(0x00B318, 84))
  add_asset_uint16('kGlobalPalettes_YoshiBerry', util.get_words(0x00B674, 21))
  add_asset_uint16('kGlobalPalettes_Flashing', util.get_words(0x00B60C, 16))

  add_asset_uint16('kGlobalPalettes_OW_Objects', util.get_words(0xB528, 42))
  add_asset_uint16('kGlobalPalettes_OW_Sprites', util.get_words(0xB57C, 56))
  add_asset_uint16('kGlobalPalettes_B5EC', util.get_words(0xB5EC, 16))
  add_asset_uint16('kGlobalPalettes_OW_Areas', util.get_words(0xB3D8, 168))
  add_asset_uint16('kGlobalPalettes_OW_AreasPassed', util.get_words(0xB732, 168))
  add_asset_uint16('kGlobalPalettes_Bowser', util.get_words(0xB69E, 56))
  add_asset_uint16('kGlobalPalettes_Layer3Smasher', util.get_words(0xB66C, 4))
  #add_asset_uint16('', util.get_words(0x, ))

 
  add_asset_uint8('kGameMode1B_EndingCinema_Tilemaps', util.get_bytes(0xC95C7, 1873))
  add_asset_uint16('kGameMode1B_EndingCinema_RowPointers', util.get_words(0xC9D18, 202))

  add_asset_uint8('kLevelInfo_05F000', util.get_bytes(0x5f000, 0x200))  
  add_asset_uint8('kLevelInfo_05F200', util.get_bytes(0x5f200, 0x200))  
  add_asset_uint8('kLevelInfo_05F400', util.get_bytes(0x5f400, 0x200))
  add_asset_uint8('kLevelInfo_05F600', util.get_bytes(0x5f600, 0x200))

  add_asset_uint8('kLoadLevel_DATA_05D608', util.get_bytes(0x5D608, 0x100))

  add_asset_uint8('kDisplayMessage_DATA_05A5D9', util.get_bytes(0x5A5D9, 2854))

  add_asset_uint8('kOverworldLightningAndRandomCloudSpawning', util.get_bytes(0x4F708, 128))

  add_asset_uint16('kLevelNames', util.get_words(0x4A0FC, 256))

  add_asset_uint8('kLineGuideSpeedTableData', util.get_bytes(0x7F9DB, 536))

  def add_packed_levels(name, addr, num, bank = None):
    r = []
    for i in range(num):
      try:
        if bank == None:
          ea = util.get_24(addr + i * 3)
        else:
          ea = util.get_word(addr + i * 2) | bank << 16
        ln = calc_level_len(ea)
        r.append(util.get_bytes(ea, ln))
      except:
        print('\n*** Crashed while decoding level 0x%x at 0x%x ***' % (i, ea), file = sys.stderr)
        print('*** Try opening it in LM and then saving it ***', file = sys.stderr)

    add_asset_packed(name, r)

  add_packed_levels('kLevelData_Layer1', 0x5E000, 0x200)
  add_packed_levels('kEntranceData_Layer1', 0x5d766, 6)
  add_packed_levels('kChoclateIsland2_Layer1', 0x5DB08, 9, bank = 6)
  add_packed_levels('kRollCallData_Layer1', 0xCAD58, 13, bank = 0xc)


  def add_packed_level_bg(name, addr, num, mode = None):
    r = []
    fls = []
    for i in range(num):
      if mode == None:
        ea = util.get_24(addr + i * 3)
      elif mode == 'choc':
        ea = util.get_word(addr + i * 2) | 0xff0000
      elif mode == 'end':
        ea = util.get_word(addr + i * 2) | (0xff0000 if i != 12 else 0xc0000)
      else:
        assert 0

      fl = util.get_byte(0xEF310 + i) if num == 0x200 and LUNAR_MAGIC else 0
      if (ea & 0xff0000) == 0xff0000:
        ea = (ea & 0xffff) | 0xc0000
        fl = ((ea & 0xffff) >= 0xE8FE) << 4 | 2
      fls.append(fl)

      if fl & 2:
        packed, ln = unpack_rle(ea)
      else:
        ln = calc_level_len(ea)

      r.append(util.get_bytes(ea, ln))
    add_asset_packed(name, r)
    add_asset_uint8(name + '_IsBg', fls)

  add_packed_level_bg('kLevelData_Layer2', 0x5E600, 0x200)
  add_packed_level_bg('kEntranceData_Layer2', 0x5d778, 6)
  add_packed_level_bg('kChoclateIsland2_Layer2', 0x5DB2C, 9, mode = 'choc')
  add_packed_level_bg('kRollCallData_Layer2', 0xCAD72, 13, mode = 'end')
  add_packed_level_bg('kBufferCreditsBackgrounds_Layer2', 0xc93c1, 7, mode = 'choc')

  def get_sprite_data_len(ea):
    ea_org = ea
    ea += 1
    while util.get_byte(ea) != 0xff:
      ea += 3
    return ea + 1 - ea_org

  def remove_trail_zero(s):
    lx = len(s)
    while lx and s[lx - 1] == 0:
      lx -= 1
    return s[:lx]

  def remove_trail_empty(s):
    lx = len(s)
    while lx and len(s[lx - 1]) == 0:
      lx -= 1
    return s[:lx]

  def add_sprites():
    spr_ranges = []
    def touch(ea):
      lx = get_sprite_data_len(ea)
      spr_ranges.append((ea, ea + lx))

    banks = util.get_bytes(0xef100, 512) if get_byte(0x05D8F5) == 0x22 else [7] * 512
    for i in range(0x200):
      touch(util.get_word(0x5ec00 + i * 2) | (banks[i] << 16))
  
    touch(0x7c3ee)
    for i in range(9):
      touch(util.get_word(0x5DB1A + i * 2) | 0x70000)

    add_asset_blob('kLvlSprBlob', spr_ranges)
    add_asset_uint8('kLmSpritePtrBankByte', banks)

  add_sprites()

  add_asset_uint16('kLoadLevel_SpriteDataPtrs', util.get_words(0x5EC00, 0x200))
  add_asset_uint8('kFileSelectText_EraseFile', util.get_bytes(0x5B6FE, 203 + 204))
  add_asset_uint8('kInitializeMode7TilemapsAndPalettes_TilemapData', util.get_bytes(0x3D9DE, 912))

  def do_u16(name, addr, org_addr, org_size, bank_addr = None):
    p = get_24(addr) if bank_addr == None else util.get_word(addr) | get_byte(bank_addr) << 16
    sz = get_rats_size(p) // 2 if p != org_addr else org_size
    add_asset_uint16(name, util.get_words(p, sz))
    assert p == org_addr or LUNAR_MAGIC
    return p != org_addr

  def do_u8(name, addr, org_addr, org_size, bank_addr = None):
    p = get_24(addr) if bank_addr == None else util.get_word(addr) | get_byte(bank_addr) << 16
    sz = get_rats_size(p) if p != org_addr else org_size
    add_asset_uint8(name, util.get_bytes(p, sz))
    assert p == org_addr or LUNAR_MAGIC
    return p != org_addr

  def add_event_tile_entries():
    do_u16('kLayer2EventData_TileEntries', 0x4E49F, 0x4DD8D, 742)
    do_u16('kChangingLayer1OverworldTiles_Layer1TileLocation', 0x4EC8C, 0x4D85D, 112)
    do_u16('kOwEventProcess01_DestroyTileAnimation_DATA_04E587', 0x4EEC9, 0x4E587, 16)
    if do_u16('kCheckIfDestroyTileEventIsActive_DATA_04E5B6', 0x4E69C, 0x4E5B6, 16):
      lm_feat.flags |= kLmFeature_DestroyTileAnims
    do_u16('kOwEventProcess01_DestroyTileAnimation_DATA_04D93D', 0x4EDB8, 0x4D93D, 112)

    do_u8('kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles', 0x4E9F4, 0x4E8E4, 44)  
    do_u8('kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileLayer', 0x4EA27, 0x4E910, 44)  

    do_u16('kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileNum', 0x4EA31+1, 0x4E994, 44)
    do_u16('kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TilemapLocation', 0x4EA37+1, 0x4E93C, 44)

    add_asset_uint8('kOwDestruction_TileToIdx_04E5A7', get_bytes(0x4e5a7, 5))
    add_asset_uint8('kOwDestruction_TopTile_04E5AC', get_bytes(0x4e5ac, 5))
    add_asset_uint8('kOwDestruction_BottomTile_04E5B1', get_bytes(0x4e5b1, 5))
    do_u8('kOwDestruction_TriggerEvent_04E5D6', 0x4E67C, 0x4e5d6, 16)

  add_event_tile_entries()

  def add_eventstuff():
    def get_words_rats(p):
      return get_words(p, get_rats_size(p) // 2)

    def get_u8_rats(p):
      return get_bytes(p, get_rats_size(p))

    r1, r2, r3, r4 = [], [], [], [], 
    if get_byte(0x4E9F7) == 0x22:
      lm_feat.flags |= kLmFeature_EventStuff
      p = get_24(0x4E9F8)
      r1 = get_words_rats(get_24(p - 0x8008 + 0x8014 + 1))
      r2 = get_words_rats(get_24(p - 0x8008 + 0x8029 + 1))
      r3 = get_words_rats(get_24(p - 0x8008 + 0x802F + 1))
      r4 = get_u8_rats(get_24(p - 0x8008 + 0x803B + 1))
    add_asset_uint16('kLmEventStuff1', r1)
    add_asset_uint16('kLmEventStuff2', r2)
    add_asset_uint16('kLmEventStuff3', r3)
    add_asset_uint8('kLmEventStuff4', r4)


  add_eventstuff()

  do_u8('kOverworldLayer2EventTilemap_Tiles', 0x4EAF5, 0xc8000, 3328)

  p = get_word(0x4DC72) | get_byte(0x4DC79) << 16
  _, sz = unpack_rle_of_size(p, 0x2000)
  add_asset_uint8('kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap', get_bytes(p, sz))

  p = get_word(0x4DC8d) | get_byte(0x4DC79) << 16
  _, sz = unpack_rle_of_size(p, 0x2000)
  add_asset_uint8('kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap_Prop', get_bytes(p, sz))

  do_u8('kOverworldLayer2EventTilemap_Prop', 
      addr = 0x4DD45, org_addr = 0xC8D00, org_size = 1642, bank_addr = 0x4DD4a)

  add_asset_uint8('kLoadOverworldLayer1AndEvents_DATA_0CF7DF', util.get_bytes(0xCF7DF, 0x800))
  
  add_asset_uint8('kRom', util.ROM.ROM if args.include_rom else b'')

  add_asset_uint8('kUpdateLevelName_LevelNameStrings', util.get_bytes(0x49ac5, 460))  
  add_asset_uint8('kGameMode25_ShowEnemyRollcallScreen_TileData', util.get_bytes(0xCAF11, 1681))

  lm_pals = []
  if LUNAR_MAGIC and get_24(0xef577) == 0xf58320:
    for i in range(0x200):
      pp = util.get_24(0xEF600 + i * 3)
      lm_pals.append(util.get_bytes(pp, 0x202) if pp else b'')
  add_asset_packed('kLmPalettes', lm_pals)

  add_asset_uint8('kPlayerGFXRt_HeadTilePointerIndex', util.get_bytes(0xE00C, 192))  
  add_asset_uint8('kPlayerGFXRt_BodyTilePointerIndex', util.get_bytes(0xE0CC, 192))  

  add_asset_uint8('kLvlInitialFlags', util.get_bytes(0x5DDA0, 96))  
  add_asset_uint8('kLoadOverworldSprites_SpriteSlotData', util.get_bytes(0x4F625, 65))  
  add_asset_uint8('kChangingLayer1OverworldTiles_TilesThatChange', util.get_bytes(0x4DA1D, 22))  
  add_asset_uint8('kChangingLayer1OverworldTiles_TilesToBecome', util.get_bytes(0x4DA33, 22))

  add_asset_uint8('kOverworldEventProcess01_DestroyTileAnimation_DATA_04EE7A', util.get_bytes(0x4EE7A, 48))

  add_asset_uint16('kLevelTileAnimations_FrameData', util.get_words(0x5B999, 208))

  add_asset_uint8('kSetPlayerPose_WalkingPoseCount', util.get_bytes(0xDC78, 4))  

  add_asset_uint8('kDrawLoadingLetters_TileData', util.get_bytes(0x90d1, 52))
  add_asset_uint8('kDrawLoadingLetters_TileData_BottomTiles', util.get_bytes(0x9105, 52))
  add_asset_uint8('kDrawLoadingLetters_TileData_TopProp', util.get_bytes(0x9139, 52))
  add_asset_uint8('kDrawLoadingLetters_TileData_BottomProp', util.get_bytes(0x916A, 52))

  add_asset_uint16('kOwTileAnimations_WaterTileNumbers', util.get_words(0x48000, 3))
  add_asset_uint16('kOwTileAnimations_TileNumbers', util.get_words(0x48006, 64))
    
  def add_star_pipe_warp():
    if get_byte(0x48509) == 0x22:
      p = get_24(0x4850a)
      n = get_word(p + 0xe00f - 0xdfff) // 2
      add_asset_uint16('kOwStarPipeWarp_SrcX_048431', get_words(get_24(p + 0xe016 - 0xdfff), n))
      add_asset_uint16('kOwStarPipeWarp_SrcY_048467', get_words(get_24(p + 0xe026 - 0xdfff), n))
      assert get_byte(0x48566) == 0x22
      p = get_24(0x48567)
      add_asset_uint16('kOwStarPipeWarp_DstX_04849D', get_words(get_24(p + 0xe04b - 0xe03f), n))
      add_asset_uint16('kOwStarPipeWarp_DstY_0484D3', get_words(get_24(p + 0xe05d - 0xe03f), n))
    else:
      add_asset_uint16('kOwStarPipeWarp_SrcX_048431', get_words(0x48431, 27))
      add_asset_uint16('kOwStarPipeWarp_SrcY_048467', get_words(0x48467, 27))
      add_asset_uint16('kOwStarPipeWarp_DstX_04849D', get_words(0x4849d, 27))
      add_asset_uint16('kOwStarPipeWarp_DstY_0484D3', get_words(0x484d3, 27))

  add_star_pipe_warp()

  add_asset_uint16('kOwLevelsForcedMusicChange_048D74', get_words(0x48d74, 11))
  add_asset_uint8('kOwSubmapMusic_048D8A', get_bytes(0x48d8a, 7))
  add_asset_uint16('kOw_KoopaKidTeleportXYPos_048E49', get_words(0x48e49, 6))
  add_asset_uint8('kOwTriggerSaveTiles_048F7F', get_bytes(0x48f7f, 8))
  add_asset_uint16('kOwNoAutoMoveLevels_04906C', get_words(0x4906c, 6))
  add_asset_uint8('kOwHardcodedPathLevel_049078', get_bytes(0x49078, 10))
  add_asset_uint16('kOwHardcodedPathChocolateIsland2_049082', get_words(0x49082, 2))
  add_asset_uint8('kOwHardcodedPathTiles_049086', get_bytes(0x49086, 68))
  add_asset_uint8('kOwHardcodedPathDirs_0490CA', get_bytes(0x490ca, 68))
  add_asset_uint8('kOwHardcodedPathStartIndex_04910E', get_bytes(0x4910e, 10))
  add_asset_uint8('kOwExitLevelTiles_049426', get_bytes(0x49426, 10))
  add_asset_uint16('kUpdateLevelName_DATA_049C91', get_words(0x49c91, 31))
  add_asset_uint16('kUpdateLevelName_DATA_049CCF', get_words(0x49ccf, 15))
  add_asset_uint16('kUpdateLevelName_DATA_049CED', get_words(0x49ced, 13))
  add_asset_uint8('kOwExitSource_049964', get_bytes(0x49964, 70))
  add_asset_uint8('kOwExitDest_0499AA', get_bytes(0x499aa, 70))
  add_asset_uint8('kOwExitExtra_0499F0', get_bytes(0x499f0, 28))
  add_asset_uint16('kOwExitLayerPosition_049A0C', get_words(0x49a0c, 12))
  add_asset_uint8('kOwUnknownTableA_From_04A03C', get_bytes(0x4a03c, 24))
  add_asset_uint16('kOwUnknownTableA_Alpha_04A054', get_words(0x4a054, 24))
  add_asset_uint16('kOwUnknownTableA_XY_04A084', get_words(0x4a084, 48))
  add_asset_uint8('kOwUnknownTableA_Direction_04A0E4', get_bytes(0x4a0e4, 24))
  add_asset_uint8('kOwDirectionAfterBeatingLevel_04D678', get_bytes(0x4d678, 113))
  add_asset_uint8('kOwSubmapTileset_04DC02', get_bytes(0x4dc02, 7))
  add_asset_uint16('kLayer2EventData_Ptrs_04E359', get_words(0x4e359, 121))

  add_asset_uint8('kLmInitSaveData', get_bytes(0x05DDA0, 96) if get_byte(0x5dd80) != 0xff else b'')
  add_asset_uint8('kInitializeSaveData_InitialOWPlayerPos', get_bytes(0x9EF0, 22))

  add_asset_uint16('kOWSpr07_Smoke_DATA_04FC1E', get_words(0x4FC1E, 4))

  add_asset_uint16('kLoadOverworldSprites_SubmapBooXPosOffset', get_words(0x4F666, 3))
  add_asset_uint16('kLoadOverworldSprites_SubmapBooYPosOffset', get_words(0x4F66C, 3))

  add_asset_uint8('kLoadLevelHeader_LevelMusicTable', get_bytes(0x584DB, 8))

  # hack
  add_asset_uint8('kLevelsThatTriggerCutscenes', get_bytes(0xC9A7, 8) + bytearray([get_byte(0xCA0C), get_byte(0xCA13)]))

  #add_asset_uint16('', util.get_words(0x, ))
  #add_asset_uint8('', util.get_bytes(0x, ))  

  def add_exgfx(name, addr, size):
    r = []
    if LUNAR_MAGIC and addr != 0xffffff:
      for i in range(size):
        p = util.get_24(addr + i * 3)
        r.append(get_comp_data(p) if p not in (0, 0xffffff) else b'')
      while len(r) and r[-1] == b'':
        r.pop()
    add_asset_packed(name, r)

  add_exgfx('kLmExgfx', 0xFF600, 128)
  add_exgfx('kLmSuperExgfx', get_24(0xFF937), 0x1000 - 0x100)
  add_asset_uint8('kLmGraphicsRemapped', remove_trail_zero(util.get_bytes(0xFF200, 1024)) if LUNAR_MAGIC else b'')

  def add_load_level_stuff():
    lm_load_level = get_byte(0x5D9A1) == 0x22

    p = get_24(0x6F624)
    add_asset_uint16('kLmModifyMap16Ids', util.get_words(p, 4096) if lm_load_level and p != 0xffffff else b'')
    add_asset_uint8('kLm5DE00', util.get_bytes(0x5DE00, 512) if lm_load_level else b'')    
    add_asset_uint8('kLm6FC00', util.get_bytes(0x6FC00, 512) if lm_load_level else b'')    
    add_asset_uint8('kLm6FE00', util.get_bytes(0x6FE00, 512) if lm_load_level else b'')    

    p = util.get_24(util.get_24(0x5D9A2) + 0x10BBDF - 0x10BB83) if lm_load_level else 0
    add_asset_uint8('kLm10B8BC', util.get_bytes(p, 512) if p != 0 else b'')    
    add_asset_uint8('kLmLevelData3FE00', util.get_bytes(0x3FE00, 512) if lm_load_level else b'')    

    add_asset_uint8('kLmLevelData5DC85', util.get_bytes(get_24(0x5DC86), 512) if lm_load_level else b'')    
    add_asset_uint8('kLmLevelData5DC8A', util.get_bytes(get_24(0x5DC8B), 512) if lm_load_level else b'')    
    add_asset_uint8('kLm5FE00', util.get_bytes(get_24(0x5DC81), 512) if lm_load_level else util.get_bytes(0x5fe00, 0x200))

    add_asset_uint8('kLevelInfo_05F800', util.get_bytes(get_24(0xde191), 0x200) if lm_load_level else util.get_bytes(0x5f800, 0x200))
    add_asset_uint8('kLevelInfo_05FA00', util.get_bytes(get_24(0xde198), 0x200) if lm_load_level else util.get_bytes(0x5fa00, 0x200))
    add_asset_uint8('kLevelInfo_05FC00', util.get_bytes(get_24(0xde19f), 0x200) if lm_load_level else util.get_bytes(0x5fc00, 0x200))
    lm_feat.flags |= kLmFeature_LoadLevel if lm_load_level else 0

  add_load_level_stuff()

  def add_lm_map16():
    if LUNAR_MAGIC:
      B = 0x06F500
      half = (get_byte(0x6F54B) != 0xB0)
      B -= 2 if half else 0
      arr = [
        get_byte(B + 0x57)<<16|(get_word(B + 0x53)+0x1000&0xFFFF),
        get_byte(B + 0x60)<<16|(get_word(B + 0x5C)^0x8000),
        get_byte(B + 0x6B)<<16|(get_word(B + 0x67)+1 & 0xFFFF),
        get_byte(B + 0x74)<<16|(get_word(B + 0x70)+0x8001&0xFFFF),
      ]
      if not half:
        arr += [
          get_byte(B + 0x98)<<16|get_word(B + 0x94),
          get_byte(B + 0xA1)<<16|(get_word(B + 0x9D)+0x8000&0xFFFF),
          get_byte(B + 0xAC)<<16|(get_word(B + 0xA8)+1 & 0xFFFF),
          get_byte(B + 0xB5)<<16|(get_word(B + 0xB1)+0x8001&0xFFFF),
        ]
      else:
        print('Warning: Half map16', file=sys.stderr)
        arr += [0, 0, 0, 0]
      arr.append(get_byte(B + 0x8A)<<16|(get_word(B + 0x86)+0x1000&0xFFFF)), # TS
    else:
      arr = [0 for i in range(9)]

    for i, p in enumerate(arr):
      sz = get_rats_size(p)
      add_asset_uint16('kMap16_%s' % ('TS' if i == 8 else i), get_words(p, sz // 2))

  add_lm_map16()

  #add_asset_uint16('kMap16Bank11', util.get_words(0x118000, 16384) if LUNAR_MAGIC else b'')
  #add_asset_uint16('kMap16Bank12', util.get_words(0x128000, 12288) if LUNAR_MAGIC else b'')

  def calc_one_exanim_end(p):
    p_org = p
    tp = util.get_byte(p)
    trigger = util.get_byte(p + 1)
    if tp >= 1 and tp <= 0x13:
      limit = util.get_byte(p + 2)
      p += 5 # type, trigger, limit, dest(w)
      p += (limit + 1) * 2 * (1 if trigger==0 else 2)
      return p
    raise Exception('exanim type %x not supported' % tp)

  def calc_exanim_size(p):
    p_org = p
    num = util.get_word(p)
    trig = util.get_word(p + 6)
    p += 8
    for i in range(16):
      if trig & (1 << i):
        p += 2 # manual triggers
    max_p = p
    for i in range(num):
      pd = util.get_word(p + i * 2)
      max_p = max(max_p, calc_one_exanim_end(p + pd))
    return max_p - p_org

  # parse all level exanimation 
  lm_lvl_exanim = []
  lm_exanim_ranges = []
  if LUNAR_MAGIC and get_byte(0x0583AD) == 0x22:  # call LmHook_InitExanimForLevel
    LmHook_InitExanimForLevel = get_24(0x583AE)
    if get_bytes(LmHook_InitExanimForLevel, 4) != b'\xe2\x30\x8b\xa2':
      raise Exception('The Exanim file format is incorrect. ' + extra_lunar_magic_text())

    exanim_ptr = get_24((0x10C24E  - 0x10C164) + LmHook_InitExanimForLevel) # 0x10CD9C

    for i in range(512):
      p = util.get_24(exanim_ptr + i * 3)
      lm_lvl_exanim.append(0 if (p & 0x8000) == 0 else p)
      if (p & 0x8000) != 0:
        sz = calc_exanim_size(p)
        lm_exanim_ranges.append((p, p + sz))
    lm_feat.flags |= kLmFeature_Exanim

  add_asset_uint8('kLmLvlExAnim', b''.join(pack_24(a) for a in remove_trail_zero(lm_lvl_exanim)))
  add_asset_blob('kLmExanimBlob', lm_exanim_ranges)

  kSkipOwDecompressMap = {
    b'\xea\xea\xea\xea' : kLmFeature_SkipOverworldDecompress,
    b'\x22\x00\xFC\x0E' : 0, # lm
    b'\x22\x28\xBA\x00' : 0, # orig
  }

  lm_feat.flags |= kLmFeature_LmEnabled if LUNAR_MAGIC else 0
  lm_feat.flags |= kSkipOwDecompressMap[bytes(get_bytes(0xA149, 4))]
  lm_feat.flags |= kLmFeature_OverworldTiles4bpp if get_byte(0x480D0) == 0x60 else 0
  lm_feat.flags |= kLmFeature_Copy512colors if get_byte(0xA5E1) == 0xea else 0
  lm_feat.flags |= kLmFeature_WeirdPalette if get_byte(0xAF71) == 0x22 else 0
  lm_feat.flags |= kLmFeature_SkipLoadPaletteHook if get_byte(0xEF570) != 0xc2 else 0
  lm_feat.flags |= kLmFeature_GfxUpload if get_bytes(0xAA6B, 4) != b'\x22\x28\xBA\x00' else 0
  lm_feat.flags |= kLmFeature_4bppgfx if get_byte(0xAACE) == 0x10 else 0
  lm_feat.flags |= kLmFeature_DontSetYposForIntroMarch if get_byte(0x05B15D) == 0xea else 0
  lm_feat.flags |= kLmFeature_MusicRegTweak if get_byte(0x5855C) == 0x8d else 0
  lm_feat.flags |= kLmFeature_TideWaterTweak if get_byte(0xa045) == 0x22 else 0
  lm_feat.flags |= kLmFeature_EnemyCollTweak if get_byte(0x194B6) == 0x5c else 0
  lm_feat.flags |= kLmFeature_Ow4bppGfx if get_bytes(0xA149, 4) != b'\x22\x28\xBA\x00' else 0
  lm_feat.flags |= kLmFeature_DontResetOwPlayersMap if get_byte(0xa0a0) == 0xea else 0
  lm_feat.flags |= kLmFeature_NonStdGfxAA8D if get_byte(0xAA8D) != 0x08 else 0
  lm_feat.flags |= kLmFeature_TimerTweaks if get_byte(0x58E24) == 0x8f else 0
  lm_feat.flags |= kLmFeature_NoDefaultSavePrompts if get_byte(0x3BA26) == 0 else 0


  #  Allows Mario to perform a wall kick by sliding along a wall and pressing the
  # B button.
  lm_feat.hacks |= kHack_Walljump if get_24(0xA2A1) != 0x86F122 else 0
  
  def add_custom_ow_palette():
    r = b''
    if get_byte(0xAD32) == 0x22:
      lm_feat.flags |= kLmFeature_OwPalette
      p = get_24(0xAD33) - 0x10813F
      r = get_rats_bytes(get_byte(p + 0x10815D) << 16 | get_word(p + 0x108151))
    add_asset_uint8('kLmOverworldPal', r)
  add_custom_ow_palette()

  def add_custom_display_message():
    flag = get_byte(0x5B1A3) == 0x22
    lm_feat.flags |= kLmFeature_CustomDisplayMessage if flag else 0
    add_asset_uint8('kLmDisplayMessage_Tab0', get_rats_bytes(get_24(0x3BC0B)) if flag else b'')
    add_asset_uint16('kLmDisplayMessage_3BC7F', get_words(0x3BC7F, 8) if flag else b'')
    add_asset_uint16('kLmDisplayMessage_3BE80', get_words(0x3BE80, 192) if flag else b'')
    r = []
    if flag:
      for a in [0x3BB9A, 0x3BBA1, 0x3BBA6, 0x3BBAB, 0x3BBB0]:
        assert get_byte(a) == 0xe0
        r.append(get_byte(a+1))
    add_asset_uint8('kLmDisplayMessage_Tab1', r)

  add_custom_display_message()

  def add_custom_title_screen():
    lm_feat.flags |= kLmFeature_CustomTitleScreenDemo if get_byte(0x9c6f) == 0x22 else 0
    r = b''
    if lm_feat.flags & kLmFeature_CustomTitleScreenDemo:
      p = get_24(get_24(0x9c70) + 0x10F6B0 - 0x10F68D) - 2
      r = get_bytes(p, get_rats_size(p))
    add_asset_uint8('kLmTitleScreenMoves', r)

  add_custom_title_screen()

  def add_level_names_patch():
    lm_feat.flags |= kLmFeature_LevelNamesPatch if get_byte(0x48E81) == 0x22 else 0
    r = b''
    if lm_feat.flags & kLmFeature_LevelNamesPatch:
      p = get_24(0x3BB57)
      r = get_bytes(p, get_rats_size(p))
    add_asset_uint8('kLmLevelNamesPatch', r)
 
  add_level_names_patch()

  # compressed layer1 and events
  def add_overworld():
    d = []
    if get_byte(0x4d813) == 0x5c:
      d = get_comp_data(get_byte(0x4d808) << 16 | get_word(0x4d803))
    add_asset_uint8('kOwLayer1AndEvents', d)

    d = []
    if get_byte(0x4d832) == 0x5c:
      d = get_comp_data(get_byte(0x4d827) << 16 | get_word(0x4d822))
    add_asset_uint8('kOwLayer1AndEvents2', d)

  add_overworld()

  r = b''
  if LUNAR_MAGIC and get_byte(0xA140) == 0x22:
    lm_feat.kLmLvlInfo_addr_other = get_byte(0xFFAC2) << 16 | get_word(0xFFAB9)
    lm_feat.kLmLvlInfo_addr = get_24(0xFF7FF)
    r = util.get_words(lm_feat.kLmLvlInfo_addr, (512+8) * 16)
  add_asset_uint16('kLmLvlInfo', r)
  #add_lm_lvlinfo()



  def add_custom_map16_bg():
    r = []
    if LUNAR_MAGIC:
      for i in range(16):
        p = util.get_24(0xEFD50 + i * 3)
        if p:
          r.append(util.get_bytes(p, 0x8000 - (p & 0x7fff)))
        else:
          r.append(b'')
    add_asset_packed('kLmCustomMap16Bg', remove_trail_empty(r))
  add_custom_map16_bg()

  def add_sprite_extra_size():
    r = b''
    if LUNAR_MAGIC:
      p = util.get_24(0xef30c)
      if p != 0xffffff:
        r = util.get_bytes(p, 1024)
    add_asset_uint8('kLmSprExtraSize', r)
  add_sprite_extra_size()

  add_asset_uint8('kLmFeatures', lm_feat.serialize())


def write_assets_to_file(print_header = False):
  key_sig = b''
  all_data = []
  if print_header:
    print('''#pragma once
#include "../src/types.h"

enum {
  kNumberOfAssets = %d
};
extern const uint8 *g_asset_ptrs[kNumberOfAssets];
extern uint32 g_asset_sizes[kNumberOfAssets];
extern MemBlk FindInAssetArray(int asset, int idx);
extern const uint8 *FindPtrInAsset(int asset, uint32 addr);
''' % len(assets))

  for i, (k, (tp, data)) in enumerate(assets.items()):
    if print_header:
      if tp == 'packed':
        print('#define %s(idx) FindInAssetArray(%d, idx)' % (k, i))
      elif tp == 'blob':
        print('#define %s(addr) FindPtrInAsset(%d, addr)' % (k, i))
      else:
        if tp == 'uint8':
          print('#define %s g_asset_ptrs[%d]' % (k, i))
        else:
          print('#define %s ((%s*)g_asset_ptrs[%d])' % (k, tp, i))
        print('#define %s_SIZE (g_asset_sizes[%d])' % (k, i))
    key_sig += k.encode('utf8') + b'\0'
    all_data.append(data)

  assets_sig = b'Smw_v0        \n\0' + hashlib.sha256(key_sig).digest()

  if print_header:
    print('#define kAssets_Sig %s' % ", ".join((str(a) for a in assets_sig)))

  hdr = assets_sig + b'\x00' * 32 + struct.pack('II', len(all_data), len(key_sig))

  encoded_sizes = array.array('I', [len(i) for i in all_data])

  file_data = hdr + encoded_sizes + key_sig

  for v in all_data:
    while len(file_data) & 3:
      file_data += b'\0'
    file_data += v

  open('smw_assets.dat', 'wb').write(file_data)

def main(args):
  print_all(args)
  write_assets_to_file(args.print_assets_header)

if __name__ == "__main__":
  ROM = util.load_rom(sys.argv[1] if len(sys.argv) >= 2 else None)
  class DefaultArgs:
    print_assets_header = True
    include_rom = True
  main(DefaultArgs())
else:
  ROM = util.ROM


