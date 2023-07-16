import sys, array, hashlib, struct, argparse, os
import util
from util import cache

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

@cache
def calc_level_len(ea):
  ea_org = ea
  ea += 5
  while True:
    b0 = util.get_byte(ea); ea += 1
    if b0 == 0xff:
      break
    b1 = util.get_byte(ea); ea += 1
    b2 = util.get_byte(ea); ea += 1

    blocks_object_number = (b1 >> 4) | ((b0 & 0x60) >> 1)
    blocks_size_or_type = b2

    if blocks_object_number == 0 and blocks_size_or_type == 0:
      ea += 1
  return ea - ea_org


def print_all(args):
  r = []
  lo, hi, bank = util.get_bytes(0xB992, 50), util.get_bytes(0xB9c4, 50), util.get_bytes(0xB9f6, 50)
  for i in range(50):
    p = bank[i] << 16 | hi[i] << 8 | lo[i]
    data, comp_len = util.decomp(p, util.get_byte, return_length = True)
    #print('%d: %d: %d' % (i, comp_len, len(data)))
    r.append(data)
  add_asset_packed('kGraphicsPtrs', r)

  data, comp_len = util.decomp(0x88000, util.get_byte, return_length = True)
  #print('%d: %d: %d' % (0x32, comp_len, len(data)))
  add_asset_uint8('kGfx32', data)

  data, comp_len = util.decomp(0x8bfc0, util.get_byte, return_length = True)
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

  add_asset_uint8('kOverworldLayer2EventTilemap_Tiles', util.get_bytes(0xc8000, 3328))

  add_asset_uint8('kSpcCreditsMusicBank', util.get_bytes(0x3e400, 6624))
  add_asset_uint8('kSpcLevelMusicBank', util.get_bytes(0xEAED6, 16899))
  add_asset_uint8('kSpcEngine', util.get_bytes(0xe8000, 6321) + b'\x00\x00')
  add_asset_uint8('kSpcSamples', util.get_bytes(0xf8000, 28538))
  add_asset_uint8('kSpcOverworldMusicBank', util.get_bytes(0xe98b1, 5667))

  add_asset_uint16('kMap16Data_OverworldLayer1', util.get_words(0x05d000, 772))

  add_asset_uint8('kkOverworldLayer2EventTilemap_Prop', util.get_bytes(0xc8d00, 1664))

  add_asset_uint16('kMap16Data', util.get_words(0xd8000, (0xA100 - 0x8000) // 2))
  add_asset_uint16('kMap16Data_Castle', util.get_words(0xdbc00, 712))
  add_asset_uint16('kMap16Data_Rope', util.get_words(0xdc800, 712))
  add_asset_uint16('kMap16Data_Underground', util.get_words(0xdd400, 712))
  add_asset_uint16('kMap16Data_GhostHouse', util.get_words(0xde300, 712))

  add_asset_uint8('kGameMode1B_EndingCinema_Tilemaps', util.get_bytes(0xC95C7, 1873))
  add_asset_uint16('kGameMode1B_EndingCinema_RowPointers', util.get_words(0xC9D18, 202))

  add_asset_uint8('kLevelInfo_05F000', util.get_bytes(0x5f000, 0x200))  
  add_asset_uint8('kLevelInfo_05F200', util.get_bytes(0x5f200, 0x200))  
  add_asset_uint8('kLevelInfo_05F400', util.get_bytes(0x5f400, 0x200))
  add_asset_uint8('kLevelInfo_05F600', util.get_bytes(0x5f600, 0x200))
  add_asset_uint8('kLevelInfo_05F800', util.get_bytes(0x5f800, 0x200))
  add_asset_uint8('kLevelInfo_05FA00', util.get_bytes(0x5fa00, 0x200))
  add_asset_uint8('kLevelInfo_05FC00', util.get_bytes(0x5fc00, 0x200))
  add_asset_uint8('kLevelInfo_05FE00', util.get_bytes(0x5fe00, 0x200))

  add_asset_uint8('kLoadLevel_DATA_05D608', util.get_bytes(0x5D608, 0x100))

  add_asset_uint8('kDisplayMessage_DATA_05A5D9', util.get_bytes(0x5A5D9, 2854))

  add_asset_uint8('kOverworldLightningAndRandomCloudSpawning', util.get_bytes(0x4F708, 128))

  add_asset_uint16('kLevelNames', util.get_words(0x4A0FC, 256))

  add_asset_uint8('kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap', util.get_bytes(0x4A533, 6904))
  add_asset_uint8('kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap_Prop', util.get_bytes(0x4C02B , 5709))
  add_asset_uint8('kLoadOverworldLayer1AndEvents_DATA_0CF7DF', util.get_bytes(0xCF7DF, 0x800))

  add_asset_uint8('kLineGuideSpeedTableData', util.get_bytes(0x7F9DB, 536))

  def add_packed_levels(name, addr, num, bank = None):
    r = []
    for i in range(num):
      if bank == None:
        ea = util.get_24(addr + i * 3)
      else:
        ea = util.get_word(addr + i * 2) | bank << 16
      ln = calc_level_len(ea)
      r.append(util.get_bytes(ea, ln))
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

      fl = 0
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


  def add_sprites():
    r = []

    def touch(ea):
      lx = get_sprite_data_len(ea)
      r.append(util.get_bytes(ea, lx))

    for i in range(0x200):
      touch(util.get_word(0x5ec00 + i * 2) | 0x70000)

    touch(0x7c3ee)
    for i in range(9):
      touch(util.get_word(0x5DB1A + i * 2) | 0x70000)

    add_asset_packed('kLoadLevelSpriteList', r)

  add_sprites()

  add_asset_uint16('kLoadLevel_SpriteDataPtrs', util.get_words(0x5EC00, 0x200))
  add_asset_uint8('kFileSelectText_EraseFile', util.get_bytes(0x5B6FE, 203 + 204))
  add_asset_uint8('kInitializeMode7TilemapsAndPalettes_TilemapData', util.get_bytes(0x3D9DE, 912))

  add_asset_uint16('kLayer2EventData_TileEntries', util.get_words(0x4DD8D, 742))
  add_asset_uint8('kUpdateLevelName_LevelNameStrings', util.get_bytes(0x49ac5, 460))  
  
  add_asset_uint8('kGameMode25_ShowEnemyRollcallScreen_TileData', util.get_bytes(0xCAF11, 1681))

  add_asset_uint8('kRom', util.ROM.ROM if args.include_rom else b'')

  #add_asset_uint16('', util.get_words(0x, ))
  #add_asset_uint8('', util.get_bytes(0x, ))  



def write_assets_to_file(print_header = False):
  key_sig = b''
  all_data = []
  if print_header:
    print('''#pragma once
#include "types.h"

enum {
  kNumberOfAssets = %d
};
extern const uint8 *g_asset_ptrs[kNumberOfAssets];
extern uint32 g_asset_sizes[kNumberOfAssets];
extern MemBlk FindInAssetArray(int asset, int idx);
''' % len(assets))

  for i, (k, (tp, data)) in enumerate(assets.items()):
    if print_header:
      if tp == 'packed':
        print('#define %s(idx) FindInAssetArray(%d, idx)' % (k, i))
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


