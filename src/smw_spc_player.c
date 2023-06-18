#include "smw_spc_player.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include "types.h"
#include "snes/spc.h"
#include "snes/dsp_regs.h"
#include "tracing.h"

#pragma warning (disable: 4267)

typedef struct Channel {
  uint16 pattern_cur_ptr;
  uint8 index;
  uint8 note_ticks_left;
  uint8 volume_fade_ticks;
  uint8 pan_num_ticks;
  uint8 pitch_slide_length;
  uint8 pitch_slide_delay_left;
  uint8 vibrato_hold_count;
  uint8 vib_depth;
  uint8 tremolo_hold_count;
  uint8 tremolo_depth;
  uint8 subroutine_num_loops;
  uint8 instrument_id;
  uint8 note_keyoff_ticks_left;
  uint8 vibrato_change_count;
  uint8 note_length;
  uint8 note_gate_off_fixedpt;
  uint8 instrument_pitch_base;
  uint8 channel_volume_master;
  uint16 channel_volume;
  uint16 volume_fade_addpertick;
  uint8 volume_fade_target;
  uint16 pan_value;
  uint16 pan_add_per_tick;
  uint8 pan_target_value;
  uint8 pan_flag_with_phase_invert;
  uint16 pitch;
  uint16 pitch_add_per_tick;
  uint8 pitch_target;
  uint8 fine_tune;
  uint8 pitch_envelope_num_ticks;
  uint8 pitch_envelope_delay;
  uint8 pitch_envelope_direction;
  uint8 pitch_envelope_slide_value;
  uint8 vibrato_count;
  uint8 vibrato_rate;
  uint8 vibrato_delay_ticks;
  uint8 vibrato_fade_num_ticks;
  uint8 vibrato_fade_add_per_tick;
  uint8 vib_depth_orig;
  uint8 tremolo_count;
  uint8 tremolo_delay_ticks;
  uint8 final_volume;
  uint16 saved_pattern_ptr;
  uint16 pattern_start_ptr;
} Channel;

typedef struct SmwSpcPlayer {
  SpcPlayer base;
  DspRegWriteHistory *reg_write_history;
  uint8 new_value_from_snes[4];
  
  uint8 last_value_from_snes[4];
  uint8 timer_cycles;
  uint8 counter_sf0c;
  uint8 sfx3_timer;
  uint16 temp_accum;
  uint8 ttt;
  uint8 did_affect_volumepitch_flag;
  uint16 addr0;
  uint16 addr1;
  uint16 sfx0_sound_ptr_cur;
  uint16 sfx3_sound_ptr_cur;
  uint8 chan7_countdown_2;
  uint8 is_chan_on;
  uint8 sfx3_unused;
  uint8 chan_bit_flags;
  uint16 music_ptr_toplevel;
  uint8 block_count;
  uint8 global_transposition;
  uint8 sfx_timer_accum;
  uint8 sfx_tick_counter;
  uint8 chn;
  uint8 key_ON;
  uint8 cur_chan_bit;
  uint8 main_tempo_accum;
  uint16 tempo;
  uint8 tempo_fade_num_ticks;
  uint8 tempo_fade_final;
  uint16 tempo_fade_add;
  uint16 master_volume;
  uint8 master_volume_fade_ticks;
  uint8 master_volume_fade_target;
  uint16 master_volume_fade_add_per_tick;
  uint8 vol_dirty;
  uint8 echo_volume_fade_ticks;
  uint16 echo_volume_left;
  uint16 echo_volume_right;
  uint16 echo_volume_fade_add_left;
  uint16 echo_volume_fade_add_right;
  uint8 echo_volume_fade_target_left;
  uint8 echo_volume_fade_target_right;
  uint8 byte_2FF;
  uint8 sfx0_note_length_left;
  uint8 sfx0_note_length;
  uint8 sfx0_countdown;
  uint8 sfx1_countdown;
  uint8 sfx3_countdown;
  uint8 sfx3_length;
  uint8 smw_player_on_yoshi;
  uint8 smw_tempo_increase;
  uint8 smw_pause_music;
  uint8 echo_channels;
  uint16 pattern_start_ptr;
  Channel channel[8];
  uint8 ram[65536]; // rest of ram
} SmwSpcPlayer;
typedef struct MemMap {
  uint16 off, org_off;
} MemMap;
typedef struct MemMapSized {
  uint16 off, org_off, size;
} MemMapSized;
static const MemMap kChannel_Maps[] = {
{offsetof(Channel, pattern_cur_ptr), 0x8030},
{offsetof(Channel, note_ticks_left), 0x70},
{offsetof(Channel, volume_fade_ticks), 0x80},
{offsetof(Channel, pan_num_ticks), 0x81},
{offsetof(Channel, pitch_slide_length), 0x90},
{offsetof(Channel, pitch_slide_delay_left), 0x91},
{offsetof(Channel, vibrato_hold_count), 0xa0},
{offsetof(Channel, vib_depth), 0xa1},
{offsetof(Channel, tremolo_hold_count), 0xb0},
{offsetof(Channel, tremolo_depth), 0xb1},
{offsetof(Channel, subroutine_num_loops), 0xc0},
{offsetof(Channel, instrument_id), 0xc1},
{offsetof(Channel, note_keyoff_ticks_left), 0x100},
{offsetof(Channel, vibrato_change_count), 0x110},
{offsetof(Channel, note_length), 0x200},
{offsetof(Channel, note_gate_off_fixedpt), 0x201},
{offsetof(Channel, instrument_pitch_base), 0x210},
{offsetof(Channel, channel_volume_master), 0x211},
{offsetof(Channel, channel_volume), 0x8240},
{offsetof(Channel, volume_fade_addpertick), 0x8250},
{offsetof(Channel, volume_fade_target), 0x260},
{offsetof(Channel, pan_value), 0x8280},
{offsetof(Channel, pan_add_per_tick), 0x8290},
{offsetof(Channel, pan_target_value), 0x2a0},
{offsetof(Channel, pan_flag_with_phase_invert), 0x2a1},
{offsetof(Channel, pitch), 0x82b0},
{offsetof(Channel, pitch_add_per_tick), 0x82c0},
{offsetof(Channel, pitch_target), 0x2d0},
{offsetof(Channel, fine_tune), 0x2d1},
{offsetof(Channel, pitch_envelope_num_ticks), 0x300},
{offsetof(Channel, pitch_envelope_delay), 0x301},
{offsetof(Channel, pitch_envelope_direction), 0x320},
{offsetof(Channel, pitch_envelope_slide_value), 0x321},
{offsetof(Channel, vibrato_count), 0x330},
{offsetof(Channel, vibrato_rate), 0x331},
{offsetof(Channel, vibrato_delay_ticks), 0x340},
{offsetof(Channel, vibrato_fade_num_ticks), 0x341},
{offsetof(Channel, vibrato_fade_add_per_tick), 0x350},
{offsetof(Channel, vib_depth_orig), 0x351},
{offsetof(Channel, tremolo_count), 0x360},
{offsetof(Channel, tremolo_delay_ticks), 0x370},
{offsetof(Channel, final_volume), 0x371},
{offsetof(Channel, saved_pattern_ptr), 0x83e0},
{offsetof(Channel, pattern_start_ptr), 0x83f0},
};
static const MemMapSized kSpcPlayer_Maps[] = {
{offsetof(SmwSpcPlayer, new_value_from_snes), 0x0, 4},
{offsetof(SmwSpcPlayer, base.port_to_snes), 0x4, 4},
{offsetof(SmwSpcPlayer, last_value_from_snes), 0x8, 4},
{offsetof(SmwSpcPlayer, counter_sf0c), 0xc, 1},
{offsetof(SmwSpcPlayer, sfx3_timer), 0xd, 1},
{offsetof(SmwSpcPlayer, temp_accum), 0x10, 2},
{offsetof(SmwSpcPlayer, ttt), 0x12, 1},
{offsetof(SmwSpcPlayer, did_affect_volumepitch_flag), 0x13, 1},
{offsetof(SmwSpcPlayer, addr0), 0x14, 2},
{offsetof(SmwSpcPlayer, addr1), 0x16, 2},
{offsetof(SmwSpcPlayer, sfx0_sound_ptr_cur), 0x18, 2},
{offsetof(SmwSpcPlayer, sfx3_sound_ptr_cur), 0x1a, 2},
{offsetof(SmwSpcPlayer, chan7_countdown_2), 0x1c, 1},
{offsetof(SmwSpcPlayer, is_chan_on), 0x1d, 1},
{offsetof(SmwSpcPlayer, sfx3_unused), 0x2e, 1},
{offsetof(SmwSpcPlayer, chan_bit_flags), 0x2f, 1},
{offsetof(SmwSpcPlayer, music_ptr_toplevel), 0x40, 2},
{offsetof(SmwSpcPlayer, block_count), 0x42, 1},
{offsetof(SmwSpcPlayer, global_transposition), 0x43, 1},
{offsetof(SmwSpcPlayer, sfx_timer_accum), 0x44, 1},
{offsetof(SmwSpcPlayer, sfx_tick_counter), 0x45, 1},
{offsetof(SmwSpcPlayer, chn), 0x46, 1},
{offsetof(SmwSpcPlayer, key_ON), 0x47, 1},
{offsetof(SmwSpcPlayer, cur_chan_bit), 0x48, 1},
{offsetof(SmwSpcPlayer, main_tempo_accum), 0x49, 1},
{offsetof(SmwSpcPlayer, timer_cycles), 0x4a, 1},
{offsetof(SmwSpcPlayer, tempo), 0x50, 2},
{offsetof(SmwSpcPlayer, tempo_fade_num_ticks), 0x52, 1},
{offsetof(SmwSpcPlayer, tempo_fade_final), 0x53, 1},
{offsetof(SmwSpcPlayer, tempo_fade_add), 0x54, 2},
{offsetof(SmwSpcPlayer, master_volume), 0x56, 2},
{offsetof(SmwSpcPlayer, master_volume_fade_ticks), 0x58, 1},
{offsetof(SmwSpcPlayer, master_volume_fade_target), 0x59, 1},
{offsetof(SmwSpcPlayer, master_volume_fade_add_per_tick), 0x5a, 2},
{offsetof(SmwSpcPlayer, vol_dirty), 0x5c, 1},
{offsetof(SmwSpcPlayer, echo_volume_fade_ticks), 0x60, 1},
{offsetof(SmwSpcPlayer, echo_volume_left), 0x61, 2},
{offsetof(SmwSpcPlayer, echo_volume_right), 0x63, 2},
{offsetof(SmwSpcPlayer, echo_volume_fade_add_left), 0x65, 2},
{offsetof(SmwSpcPlayer, echo_volume_fade_add_right), 0x67, 2},
{offsetof(SmwSpcPlayer, echo_volume_fade_target_left), 0x69, 1},
{offsetof(SmwSpcPlayer, echo_volume_fade_target_right), 0x6a, 1},
{offsetof(SmwSpcPlayer, byte_2FF), 0x2ff, 1},
{offsetof(SmwSpcPlayer, sfx0_note_length_left), 0x380, 1},
{offsetof(SmwSpcPlayer, sfx0_note_length), 0x381, 1},
{offsetof(SmwSpcPlayer, sfx0_countdown), 0x382, 1},
{offsetof(SmwSpcPlayer, sfx1_countdown), 0x383, 1},
{offsetof(SmwSpcPlayer, sfx3_countdown), 0x384, 1},
{offsetof(SmwSpcPlayer, sfx3_length), 0x385, 1},
{offsetof(SmwSpcPlayer, smw_player_on_yoshi), 0x386, 1},
{offsetof(SmwSpcPlayer, smw_tempo_increase), 0x387, 1},
{offsetof(SmwSpcPlayer, smw_pause_music), 0x388, 1},
{offsetof(SmwSpcPlayer, echo_channels), 0x389, 1},
{offsetof(SmwSpcPlayer, pattern_start_ptr), 0x3f0, 2},
};

static void Sfx0_Process(SmwSpcPlayer *p);
static void Sfx1_Process(SmwSpcPlayer *p);
static void Sfx3_Process(SmwSpcPlayer *p);
static void ReadPortFromSnes(SmwSpcPlayer *p, int port);
static void Sfx_WritePitchSweep(SmwSpcPlayer *p, Channel *c);
static void Music_Process(SmwSpcPlayer *p);
static void WritePitch(SmwSpcPlayer *p, Channel *c, uint16 pitch);
static void Write_KeyOn(SmwSpcPlayer *p, uint8 a);
static void Channel_SetInstrument(SmwSpcPlayer *p, Channel *c, uint8 instrument);
static bool Channel_SetInstrumentEx(SmwSpcPlayer *p, Channel *c, uint16 addr);
static void HandleEffect(SmwSpcPlayer *p, Channel *c, uint8 effect);
static void ComputePitchAdd(Channel *c, uint8 pitch);
static void Chan_HandleTick(SmwSpcPlayer *p, Channel *c);
static void WriteVolumeToDsp(SmwSpcPlayer *p, Channel *c, uint16 volume);
static void HandleNoteTick(SmwSpcPlayer *p, Channel *c);
static void CalcVibratoAddPitch(SmwSpcPlayer *p, Channel *c, uint16 pitch, uint8 value);
static void HandleTremolo(SmwSpcPlayer *p, Channel *c);
static void CalcTremolo(SmwSpcPlayer *p, Channel *c);
static void HandlePanAndSweep(SmwSpcPlayer *p, Channel *c);
static void CalcFinalVolume(SmwSpcPlayer *p, Channel *c, uint8 vol);

static void Dsp_Write(SmwSpcPlayer *p, uint8_t reg, uint8 value) {
  DspRegWriteHistory *hist = p->reg_write_history;
  if (hist) {
    if (hist->count < 256) {
      hist->addr[hist->count] = reg;
      hist->val[hist->count] = value;
      hist->count++;
    }
  }
  if (p->base.dsp)
    dsp_write(p->base.dsp, reg, value);
}

static void Not_Implemented(void) {
  assert(0);
  printf("Not Implemented\n");
}

static uint16 SpcDivHelper(int a, uint8 b) {
  int org_a = a;
  if (a & 0x100)
    a = -a;
  int q = b ? (a & 0xff) / b : 0xff;
  int r = b ? (a & 0xff) % b : (a & 0xff);
  int t = (q << 8) + (b ? ((r << 8) / b & 0xff) : 0xff);
  return (org_a & 0x100) ? -t : t;
}

static void SmwSpcPlayer_CopyVariablesToRam(SmwSpcPlayer *p) {
  Channel *c = p->channel;
  for (int i = 0; i < 8; i++, c++) {
    for (const MemMap *m = &kChannel_Maps[0]; m != &kChannel_Maps[countof(kChannel_Maps)]; m++)
      memcpy(&p->ram[(m->org_off & 0x7fff) + i * 2], (uint8 *)c + m->off, m->org_off & 0x8000 ? 2 : 1);
  }
  for (const MemMapSized *m = &kSpcPlayer_Maps[0]; m != &kSpcPlayer_Maps[countof(kSpcPlayer_Maps)]; m++)
    memcpy(&p->ram[m->org_off], (uint8 *)p + m->off, m->size);
}

static void SmwSpcPlayer_CopyVariablesFromRam(SmwSpcPlayer *p) {
  Channel *c = p->channel;
  for (int i = 0; i < 8; i++, c++) {
    for (const MemMap *m = &kChannel_Maps[0]; m != &kChannel_Maps[countof(kChannel_Maps)]; m++)
      memcpy((uint8 *)c + m->off, &p->ram[(m->org_off & 0x7fff) + i * 2], m->org_off & 0x8000 ? 2 : 1);
  }
  for (const MemMapSized *m = &kSpcPlayer_Maps[0]; m != &kSpcPlayer_Maps[countof(kSpcPlayer_Maps)]; m++)
    memcpy((uint8 *)p + m->off, &p->ram[m->org_off], m->size);

  for (int i = 0; i < 8; i++)
    p->channel[i].index = i;
}

static void SmwSpcPlayer_CopyVariables(SpcPlayer *p_in, bool copy_to_ram) {
  SmwSpcPlayer *p = (SmwSpcPlayer *)p_in;
  if (copy_to_ram)
    SmwSpcPlayer_CopyVariablesToRam(p);
  else
    SmwSpcPlayer_CopyVariablesFromRam(p);
}

static const uint8 kDefDspRegs[12] = { MVOLL,MVOLR,EVOLL,EVOLR,FLG,EFB,PMON,NON,EON,DIR,ESA,EDL };
static const uint8 kDefDspValues[12] = { 0x7F, 0x7F,  0,  0, 0x2F, 0x60,  0,  0,  0, 0x80, 0x60, 2 };

static void Spc_Reset(SmwSpcPlayer *p) {
  memset(p->ram, 0, 0x500);

  SmwSpcPlayer_CopyVariablesFromRam(p);

  memset(p->base.input_ports, 0, sizeof(p->base.input_ports));

  for (int i = 11; i >= 0; i--)
    Dsp_Write(p, kDefDspRegs[i], kDefDspValues[i]);
  HIBYTE(p->tempo) = 0x36;
}

static void Spc_Loop_Part2(SmwSpcPlayer *p, uint8 ticks) {
  int t = p->sfx_timer_accum + (uint8)(ticks * 0x38);
  p->sfx_timer_accum = t;
  if (t >= 256) {
    p->sfx_tick_counter++;

    Sfx0_Process(p);
    ReadPortFromSnes(p, 0);

    Sfx1_Process(p);
    ReadPortFromSnes(p, 1);

    Sfx3_Process(p);
    ReadPortFromSnes(p, 3);
  }
  t = p->main_tempo_accum + (uint8)(ticks * HIBYTE(p->tempo));
  p->main_tempo_accum = t;
  if (t >= 256) {
    if (!p->smw_pause_music)
      Music_Process(p);
    ReadPortFromSnes(p, 2);
  } else if (p->base.port_to_snes[2]) {
    Channel *c = p->channel + 7;
    for (p->cur_chan_bit = 0x80; p->cur_chan_bit != 0; p->cur_chan_bit >>= 1, c--) {
      if (HIBYTE(c->pattern_cur_ptr))
        HandlePanAndSweep(p, c);
    }
  }
}

static void ReadPortFromSnes(SmwSpcPlayer *p, int port) {
  uint8 old = p->last_value_from_snes[port];
  p->last_value_from_snes[port] = p->base.input_ports[port];

  if (p->base.input_ports[port] != old) {
    p->new_value_from_snes[port] = p->base.input_ports[port];
  } else
    p->new_value_from_snes[port] = 0;
}

static void PlayNote(SmwSpcPlayer *p, Channel *c, uint8 note) {
  if (note >= 0xd0) {
    c->instrument_id = note;
    uint16 addr = (note - 0xd0) * 6 + 0x5fa5;
    if (Channel_SetInstrumentEx(p, c, addr))
      return;
    note = p->ram[addr + 5];
  } else if (note >= 0xc6) {
    return;
  }
  c->pitch = ((note & 0x7f) + p->global_transposition) << 8 | c->fine_tune;
  c->vibrato_count = 0;
  c->tremolo_count = 0;
  c->vibrato_hold_count = 0;
  c->vibrato_change_count = 0;
  c->tremolo_hold_count = 0;
  p->vol_dirty |= p->cur_chan_bit;
  p->key_ON |= p->cur_chan_bit;
  c->pitch_slide_length = c->pitch_envelope_num_ticks;
  if (c->pitch_slide_length) {
    c->pitch_slide_delay_left = c->pitch_envelope_delay;
    if (!c->pitch_envelope_direction)
      c->pitch -= c->pitch_envelope_slide_value << 8;
    ComputePitchAdd(c, (c->pitch >> 8) + c->pitch_envelope_slide_value);
  }
  WritePitch(p, c, c->pitch);
}

static uint16 ComputePeriod(uint8 v) {
  static const uint16 kBaseNoteFreqs[] = { 4286, 4541, 4811, 5097, 5400, 5721, 6061, 6422, 6804, 7208, 7637, 8091 };
  uint8 pp = v & 0x7f;
  uint8 q = pp / 12, r = pp % 12;
  uint16 t = kBaseNoteFreqs[r];
  while (q != 6)
    t >>= 1, q++;
  return t;
}

static void WritePitch(SmwSpcPlayer *p, Channel *c, uint16 pitch) {
  if ((pitch >> 8) >= 0x34) {
    pitch += (pitch >> 8) - 0x34;
  } else if ((pitch >> 8) < 0x13) {
    pitch += (uint8)(((pitch >> 8) - 0x13) * 2) - 256;
  }

  uint16 t = ComputePeriod(pitch >> 8);
  uint16 t1 = ComputePeriod((pitch >> 8) + 1);

  uint16 td = t1 - t;
  t += (td >> 8) * (uint8)pitch;
  t += ((uint8)td * (uint8)pitch) >> 8;
  t *= c->instrument_pitch_base;
  if (!(p->cur_chan_bit & p->is_chan_on)) {
    uint8 reg = c->index * 16;
    Dsp_Write(p, reg + V0PITCHL, t & 0xff);
    Dsp_Write(p, reg + V0PITCHH, t >> 8);
  }
}

static void Sfx0_TurnOffChannel(SmwSpcPlayer *p) {
  if (p->base.port_to_snes[0] == 0x11) {
    p->smw_pause_music = 0x60;
    Dsp_Write(p, FLG, 0x60);
  }
  p->base.port_to_snes[0] = 0;
  p->is_chan_on &= ~0x10;
  if (p->channel[4].instrument_id)
    Channel_SetInstrument(p, &p->channel[4], p->channel[4].instrument_id);
}

static void SetEchoVolume(SmwSpcPlayer *p) {
  Dsp_Write(p, EVOLL, p->echo_volume_left >> 8);
  Dsp_Write(p, EVOLR, p->echo_volume_right >> 8);
}

static void SetEchoOff(SmwSpcPlayer *p) {
  p->echo_volume_left = p->echo_volume_right = 0;
  SetEchoVolume(p);
  p->sfx3_unused = 0;
  Dsp_Write(p, FLG, 0x20);
}

static void Sfx0_Process(SmwSpcPlayer *p) {
  uint8 cmd;

  if (p->new_value_from_snes[0] == 0x12 || p->new_value_from_snes[0] == 0x11 ||
      p->base.port_to_snes[0] != 0x11 && p->base.port_to_snes[0] != 0x1d) {

    if (p->new_value_from_snes[0] & 0x80) {
      p->smw_tempo_increase = 10;
      p->tempo = (p->tempo + (p->smw_tempo_increase << 8)) & ~0xff;
      p->new_value_from_snes[3] = 0x1d;
      p->base.port_to_snes[0] = 0x1d;
      goto play_it;
    } else if (p->new_value_from_snes[0] != 0) {
      p->base.port_to_snes[0] = p->new_value_from_snes[0];
      goto play_it;
    }
  }

  if (p->sfx0_countdown) {
    if (--p->sfx0_countdown)
      return;
    goto restart_sfx;
  } else if (p->base.port_to_snes[0]) {
    goto keep_playing;
  } else {
    return;
  }
    
play_it:
  if (p->smw_pause_music) {
    p->smw_pause_music = 0;
    if (!p->echo_channels) {
      Dsp_Write(p, FLG, 0x20);
    } else {
      HIBYTE(p->echo_volume_left) = 22;
      HIBYTE(p->echo_volume_right) = 22;
      SetEchoVolume(p);
      Dsp_Write(p, FLG, 0);
    }
  }

  p->sfx0_countdown = 2;
  if (p->base.port_to_snes[0] == 0x11 && p->echo_channels) {
    SetEchoOff(p);
  }

  Dsp_Write(p, KOF, 0x10);
  p->is_chan_on |= 0x10;
  p->channel[4].pitch_envelope_num_ticks = 0;
  return;

keep_playing:
  if (--p->sfx0_note_length_left)
    goto note_continue;

  for (;;) {
    p->sfx0_sound_ptr_cur++;
start_sfx:
    cmd = p->ram[p->sfx0_sound_ptr_cur];
    if (cmd == 0) {
      Sfx0_TurnOffChannel(p);
      return;
    }

    if (!(cmd & 0x80)) {
      p->sfx0_note_length = cmd;
      cmd = p->ram[++p->sfx0_sound_ptr_cur];
      if (!(cmd & 0x80)) {
        uint8 volume = cmd;
        Dsp_Write(p, V4VOLL, cmd);
        cmd = p->ram[++p->sfx0_sound_ptr_cur];
        if (cmd & 0x80) {
          Dsp_Write(p, V4VOLR, volume);
        } else {
          Dsp_Write(p, V4VOLR, cmd);
          cmd = p->ram[++p->sfx0_sound_ptr_cur];
        }
      }
    }

    if (cmd == 0xda) {
      cmd = p->ram[++p->sfx0_sound_ptr_cur];
      const uint8 *ip = p->ram + 0x5570 + cmd * 9;
      for (int i = 0; i != 8; i++)
        Dsp_Write(p, V4VOLL + i, ip[i]);
      p->channel[4].instrument_pitch_base = ip[8];
      continue;
    } else if (cmd == 0xdd) {
      PlayNote(p, &p->channel[4], p->ram[++p->sfx0_sound_ptr_cur]);
      Write_KeyOn(p, 0x10);
      goto note_pitch_envelope_to;
    } else if (cmd == 0xeb) {
note_pitch_envelope_to:
      p->channel[4].pitch_slide_delay_left = p->ram[++p->sfx0_sound_ptr_cur];
      p->channel[4].pitch_slide_length = p->ram[++p->sfx0_sound_ptr_cur];
      ComputePitchAdd(&p->channel[4], p->ram[++p->sfx0_sound_ptr_cur]);
      p->sfx0_note_length_left = p->sfx0_note_length;
      goto note_continue;
    } else if (cmd == 0xff) {
restart_sfx:
      p->sfx0_sound_ptr_cur = WORD(p->ram[0x5681 + (uint8)(p->base.port_to_snes[0] * 2)]);
      goto start_sfx;
    } else {
      PlayNote(p, &p->channel[4], cmd);
      Write_KeyOn(p, 0x10);
      p->sfx0_note_length_left = p->sfx0_note_length;
note_continue:
      p->did_affect_volumepitch_flag = 0;
      if (p->channel[4].pitch_slide_length) {
        Sfx_WritePitchSweep(p, &p->channel[4]);
      } else if (p->sfx0_note_length_left == 2) {
        Dsp_Write(p, KOF, 0x10);
      }
      return;
    }
  }
}

static void Sfx3_TurnOffChannel(SmwSpcPlayer *p) {
  p->base.port_to_snes[3] = 0;
  p->is_chan_on &= ~0x40;
  p->chan_bit_flags = 0;
  Dsp_Write(p, NON, 0);
  if (p->channel[6].instrument_id)
    Channel_SetInstrument(p, &p->channel[6], p->channel[6].instrument_id);
}

static void Sfx3_Process(SmwSpcPlayer *p) {
  uint8 cmd;

  if (p->base.port_to_snes[3] != 0x24 && (p->new_value_from_snes[3] == 0x24 || p->base.port_to_snes[3] != 0x1d && p->base.port_to_snes[3] != 5)) {
    if (p->new_value_from_snes[3] != 0) {
      p->base.port_to_snes[3] = p->new_value_from_snes[3];
      p->sfx3_timer = 2;
      Dsp_Write(p, KOF, 0x40);
      p->is_chan_on |= 0x40;
      p->channel[6].pitch_envelope_num_ticks = 0;
      return;
    }
  }

  if (p->sfx3_timer) {
    if (--p->sfx3_timer)
      return;
    p->sfx3_sound_ptr_cur = WORD(p->ram[0x5619 + (uint8)(p->base.port_to_snes[3] * 2)]);
    goto start_sfx;
  } else if (!p->base.port_to_snes[3]) {
    return;
  }

  if (--p->sfx3_countdown)
    goto note_continue;

  for (;;) {
    p->sfx3_sound_ptr_cur++;
start_sfx:
    cmd = p->ram[p->sfx3_sound_ptr_cur];
    if (cmd == 0) {
      Sfx3_TurnOffChannel(p);
      return;
    }

    if (!(cmd & 0x80)) {
      p->sfx3_length = cmd;
      cmd = p->ram[++p->sfx3_sound_ptr_cur];
      if (!(cmd & 0x80)) {
        uint8 volume = cmd;
        Dsp_Write(p, V6VOLL, cmd);
        cmd = p->ram[++p->sfx3_sound_ptr_cur];
        if (cmd & 0x80) {
          Dsp_Write(p, V6VOLR, volume);
        } else {
          Dsp_Write(p, V6VOLR, cmd);
          cmd = p->ram[++p->sfx3_sound_ptr_cur];
        }
      }
    }

    if (cmd == 0xda) {
      p->chan_bit_flags = 0;
      Dsp_Write(p, NON, 0);
      for (;;) {
        cmd = p->ram[++p->sfx3_sound_ptr_cur];
        if (!(cmd & 0x80))
          break;
        p->sfx3_unused = 0x1f;
        Dsp_Write(p, FLG, 0x1f);
        p->chan_bit_flags = 0x40;
        Dsp_Write(p, NON, 0x40);
      }
      const uint8 *ip = p->ram + 0x5570 + cmd * 9;
      for (int i = 0; i != 8; i++)
        Dsp_Write(p, V6VOLL + i, ip[i]);
      p->channel[6].instrument_pitch_base = ip[8];
      continue;
    } else if (cmd == 0xdd) {
      PlayNote(p, &p->channel[6], p->ram[++p->sfx3_sound_ptr_cur]);
      Write_KeyOn(p, 0x40);
      goto note_pitch_envelope_to;
    } else if (cmd == 0xeb) {
note_pitch_envelope_to:
      p->channel[6].pitch_slide_delay_left = p->ram[++p->sfx3_sound_ptr_cur];
      p->channel[6].pitch_slide_length = p->ram[++p->sfx3_sound_ptr_cur];
      ComputePitchAdd(&p->channel[6], p->ram[++p->sfx3_sound_ptr_cur]);
      p->sfx3_countdown = p->sfx3_length;
      goto note_continue;
    } else if (cmd == 0xff) {
      p->sfx3_sound_ptr_cur--;
      goto start_sfx;
    } else {
      PlayNote(p, &p->channel[6], cmd);
      Write_KeyOn(p, 0x40);
      p->sfx3_countdown = p->sfx3_length;
note_continue:
      p->did_affect_volumepitch_flag = 0;
      if (p->channel[6].pitch_slide_length) {
        Sfx_WritePitchSweep(p, &p->channel[6]);
      } else if (p->sfx3_countdown == 2) {
        Dsp_Write(p, KOF, 0x40);
      }
      return;
    }
  }
}

static void Port1_WriteInstrument(SmwSpcPlayer *p, uint8 cmd) {
  const uint8 *ip = p->ram + 0x5570 + cmd * 9;
  for (int i = 0; i != 8; i++)
    Dsp_Write(p, V5VOLL + i, ip[i]);
  p->channel[5].instrument_pitch_base = ip[8];
}

static inline void Chan_DoAnyFade(uint16 *p, uint16 add, uint8 target, uint8 cont) {
  if (!cont)
    *p = target << 8;
  else
    *p += add;
}

static void Sfx_WritePitchSweep(SmwSpcPlayer *p, Channel *c) {
  Chan_DoAnyFade(&c->pitch, c->pitch_add_per_tick, c->pitch_target, --c->pitch_slide_length);
  p->cur_chan_bit = 0;  // force change through
  WritePitch(p, c, c->pitch);
}

static void Chan7_WriteInstrumentData(SmwSpcPlayer *p, uint8 cmd) {
  const uint8 *ip = p->ram + 0x5570 + cmd * 9;
  for (int i = 0; i != 8; i++)
    Dsp_Write(p, V7VOLL + i, ip[i]);
  p->channel[7].instrument_pitch_base = ip[8];
}

static void Sfx1_Process(SmwSpcPlayer *p) {
  if (p->new_value_from_snes[1] == 0xff) {
    assert(0);
    return;
  }

  if (p->new_value_from_snes[1] == 2) {
    // enable yoshi drums
    if ((p->base.port_to_snes[2] == 6 || !(p->base.port_to_snes[2] & ~3)) && !p->smw_player_on_yoshi) {
      Port1_WriteInstrument(p, 9);
      p->smw_player_on_yoshi = 1;
    }
  } else if (p->new_value_from_snes[1] == 3) {
    // disable yoshi drums
    p->smw_player_on_yoshi = 0;
  } else if (p->new_value_from_snes[1] == 1 ||
             p->base.port_to_snes[1] != 1 && p->new_value_from_snes[1] == 4) {
    // jump & two note sfx
    p->base.port_to_snes[1] = p->new_value_from_snes[1];
    p->sfx1_countdown = 4;
    Dsp_Write(p, KOF, 0x80);
    p->is_chan_on |= 0x80;
    for (int i = 0; i < 8; i++) {
      p->channel[i].pitch_envelope_num_ticks = 0;
      p->channel[i].pitch_envelope_delay = 0;
    }
    return;
  } 
  
  if (p->base.port_to_snes[1] == 1) {
    if (p->sfx1_countdown) {
      if (--p->sfx1_countdown)
        return;
      p->chan7_countdown_2 = 0x30;
      Chan7_WriteInstrumentData(p, 8);
      PlayNote(p, &p->channel[7], 0xb2);
      p->channel[7].pitch_slide_delay_left = 0;
      p->channel[7].pitch_slide_length = 5;
      ComputePitchAdd(&p->channel[7], 0xb5);
      Dsp_Write(p, V7VOLL, 0x38);
      Dsp_Write(p, V7VOLR, 0x38);
      Write_KeyOn(p, 0x80);
    } else if (--p->chan7_countdown_2 == 0) {
      p->base.port_to_snes[1] = 0;
      p->is_chan_on &= ~0x80;
      if (p->channel[7].instrument_id)
        Channel_SetInstrument(p, &p->channel[7], p->channel[7].instrument_id);
      return;
    } else if (p->chan7_countdown_2 == 0x2a) {
      p->channel[7].pitch_slide_delay_left = 0;
      p->channel[7].pitch_slide_length = 0x12;
      ComputePitchAdd(&p->channel[7], 0xb9);
    }
    if (p->chan7_countdown_2 == 2)
      Dsp_Write(p, KOF, 0x80);
    p->did_affect_volumepitch_flag = 0;
    if (p->channel[7].pitch_slide_length)
      Sfx_WritePitchSweep(p, &p->channel[7]);
  } else if (p->base.port_to_snes[1] == 4) {
    if (p->sfx1_countdown) {
      if (--p->sfx1_countdown)
        return;
      p->chan7_countdown_2 = 0x18;
      goto write_it;
    } else if (--p->chan7_countdown_2 == 0) {
      p->base.port_to_snes[1] = 0;
      p->is_chan_on &= ~0x80;
      if (p->channel[7].instrument_id)
        Channel_SetInstrument(p, &p->channel[7], p->channel[7].instrument_id);
      return;
    } else if (p->chan7_countdown_2 == 0xc) {
write_it:
      Chan7_WriteInstrumentData(p, 7);
      PlayNote(p, &p->channel[7], 0xa4);
      Dsp_Write(p, V7VOLL, 0x28);
      Dsp_Write(p, V7VOLR, 0x28);
      Write_KeyOn(p, 0x80);
    }
    if (p->chan7_countdown_2 == 2)
      Dsp_Write(p, KOF, 0x80);
  }
}

static void Music_Process(SmwSpcPlayer *p) {
  uint8 cmd;
  int t;

  if (p->base.port_to_snes[2] != 0) {
    if ((p->base.port_to_snes[2] == 6 || !(p->base.port_to_snes[2] & ~3)) && !p->smw_player_on_yoshi) {
      Dsp_Write(p, KOF, 0x20);
      p->is_chan_on |= 0x20;
    } else {
      p->is_chan_on &= ~0x20;
    }
  }
  cmd = p->new_value_from_snes[2];
  if ((int8)cmd <= 0) {
    if ((int8)cmd < 0) {
      p->master_volume_fade_ticks = 0xf0;
      p->master_volume_fade_target = 0;
      p->master_volume_fade_add_per_tick = SpcDivHelper(-HIBYTE(p->master_volume), 0xf0);
    }
    if (p->counter_sf0c)
      goto music_keep_running;
    if (p->base.port_to_snes[2])
      goto label_a;
    return;
  }

  if (cmd == 0x16 || cmd == 0x10 || cmd == 0xf || cmd >= 9 && cmd < 13)
    p->smw_tempo_increase = 0;

  p->base.port_to_snes[2] = cmd;
  p->counter_sf0c = 2;
  p->music_ptr_toplevel = WORD(p->ram[0x1360 + (cmd - 1) * 2]);

  Channel *c = p->channel + 7;
  for (int i = 7; i >= 0; i--, c--) {
    HIBYTE(c->pan_value) = 10;
    HIBYTE(c->channel_volume) = 0xff;
    c->fine_tune = 0;
    c->pan_num_ticks = 0;
    c->volume_fade_ticks = 0;
    c->vib_depth = 0;
    c->tremolo_depth = 0;
    c->subroutine_num_loops = 0;
    c->instrument_id = 0;
  }
  p->master_volume_fade_ticks = 0;
  p->echo_volume_fade_ticks = 0;
  p->tempo_fade_num_ticks = 0;
  p->global_transposition = 0;
  HIBYTE(p->master_volume) = 0xc0;
  HIBYTE(p->tempo) = 0x36;
  for (int i = 0; i < 8; i++)
    p->channel[i].pitch_envelope_num_ticks = p->channel[i].pitch_envelope_delay = 0;
  
  Dsp_Write(p, KOF, ~p->is_chan_on);
  return;

music_keep_running:
  if (--p->counter_sf0c)
    return;
Music_loop_1:
  for(;;) {
    t = WORD(p->ram[p->music_ptr_toplevel]);
    p->music_ptr_toplevel += 2;
    if ((t >> 8) != 0)
      break;
    if (t == 0) {
      p->base.port_to_snes[2] = 0;
      Dsp_Write(p, KOF, ~p->is_chan_on);
      return;
    }
    if (--p->block_count == 0) {
      p->music_ptr_toplevel += 2;
    } else {
      if (p->block_count & 0x80)
        p->block_count = t;
      p->music_ptr_toplevel = WORD(p->ram[p->music_ptr_toplevel]);
    }
  }
  uint16 *src = (uint16*)(p->ram + t);
  for (int i = 7; i >= 0; i--)
    p->channel[i].pattern_cur_ptr = WORD(src[i]);
  
  p->cur_chan_bit = 0x80;
  for (int i = 7; i >= 0; i--, p->cur_chan_bit >>= 1) {
    if (HIBYTE(p->channel[i].pattern_cur_ptr)) {
      p->channel[i].note_ticks_left = 1;
      if (p->channel[i].instrument_id == 0)
        Channel_SetInstrument(p, &p->channel[i], 1);
    }
  }
label_a:

  p->key_ON = 0;
  p->cur_chan_bit = 1;
  c = p->channel;
  do {
    if (!HIBYTE(c->pattern_cur_ptr))
      continue;
    if (--c->note_ticks_left) {
      HandleNoteTick(p, c);
      continue;
    }
    for(;;) {
      cmd = p->ram[c->pattern_cur_ptr++];
      if (cmd == 0) {
        if (!c->subroutine_num_loops)
          goto Music_loop_1;
        c->pattern_cur_ptr = (--c->subroutine_num_loops == 0) ? c->saved_pattern_ptr : c->pattern_start_ptr;
        continue;
      }
      if (!(cmd & 0x80)) {
        c->note_length = cmd;
        cmd = p->ram[c->pattern_cur_ptr++];
        if (!(cmd & 0x80)) {
          static const uint8 kNoteVol[16] = { 8, 18, 27, 36, 44, 53, 62, 71, 81, 90, 98,107,125,143,161,179 };
          static const uint8 kNoteGateOffPct[8] = { 51,102,128,153,179,204,230,255 };
          c->note_gate_off_fixedpt = kNoteGateOffPct[cmd >> 4 & 7];
          c->channel_volume_master = kNoteVol[cmd & 0xf];
          p->vol_dirty |= p->cur_chan_bit;
          cmd = p->ram[c->pattern_cur_ptr++];
        }
      }
      if (cmd >= 0xda) {
        HandleEffect(p, c, cmd);
        continue;
      }
      if (!(p->is_chan_on & p->cur_chan_bit))
        PlayNote(p, c, cmd);
      c->note_ticks_left = c->note_length;
      t = c->note_ticks_left * c->note_gate_off_fixedpt >> 8;
      c->note_keyoff_ticks_left = (t != 0) ? t : 1;
      break;
    }
  } while (c++, p->cur_chan_bit <<= 1);

  if (p->tempo_fade_num_ticks)
    p->tempo = (--p->tempo_fade_num_ticks == 0) ? p->tempo_fade_final << 8 : p->tempo + p->tempo_fade_add;

  if (p->echo_volume_fade_ticks) {
    if (--p->echo_volume_fade_ticks == 0) {
      p->echo_volume_left &= ~0xff;
      p->echo_volume_right &= ~0xff;
    } else {
      p->echo_volume_left += p->echo_volume_fade_add_left;
      p->echo_volume_right += p->echo_volume_fade_add_right;
    }
    SetEchoVolume(p);
  }

  if (p->master_volume_fade_ticks) {
    p->master_volume = (--p->master_volume_fade_ticks == 0) ? p->master_volume_fade_target << 8 : p->master_volume + p->master_volume_fade_add_per_tick;
    p->vol_dirty = 0xff;
  }
  c = p->channel + 7;
  p->cur_chan_bit = 0x80;
  do {
    if (HIBYTE(c->pattern_cur_ptr))
      Chan_HandleTick(p, c);
  } while (c--, p->cur_chan_bit >>= 1);

  p->vol_dirty = 0;
  Write_KeyOn(p, p->key_ON & ~p->is_chan_on);
}

static void Write_KeyOn(SmwSpcPlayer *p, uint8 a) {
  Dsp_Write(p, KOF, 0);
  Dsp_Write(p, KON, a);
}

static void Channel_SetInstrument(SmwSpcPlayer *p, Channel *c, uint8 instrument) {
  c->instrument_id = instrument;
  Channel_SetInstrumentEx(p, c, 0x5F46 + (instrument - 1) * 5);
}

static bool Channel_SetInstrumentEx(SmwSpcPlayer *p, Channel *c, uint16 addr) {
  if (p->is_chan_on & p->cur_chan_bit)
    return true;
  p->chan_bit_flags &= ~p->cur_chan_bit;
  Dsp_Write(p, NON, p->chan_bit_flags);
  uint8 reg = c->index * 16;
  const uint8 *ip = p->ram + addr;
  Dsp_Write(p, reg + V0SRCN, ip[0]);
  Dsp_Write(p, reg + V0ADSR1, ip[1]);
  Dsp_Write(p, reg + V0ADSR2, ip[2]);
  Dsp_Write(p, reg + V0GAIN, ip[3]);
  c->instrument_pitch_base = ip[4];
  return false;
}


static void HandleEffect(SmwSpcPlayer *p, Channel *c, uint8 effect) {
  
  switch (effect) {
  case 0xda:
    Channel_SetInstrument(p, c, p->ram[c->pattern_cur_ptr++] + 1);
    break;
  case 0xdb: {
    uint8 arg = p->ram[c->pattern_cur_ptr++];
    c->pan_value = (arg & 0x1f) << 8;
    c->pan_flag_with_phase_invert = arg & 0xc0;
    p->vol_dirty |= p->cur_chan_bit;
    break;
  }
  case 0xdc:
    c->pan_num_ticks = p->ram[c->pattern_cur_ptr++];
    c->pan_target_value = p->ram[c->pattern_cur_ptr++];
    c->pan_add_per_tick = SpcDivHelper(c->pan_target_value - (c->pan_value >> 8), c->pan_num_ticks);
    break;
  case 0xde: // vibrato on
    c->vibrato_delay_ticks = p->ram[c->pattern_cur_ptr++];
    c->vibrato_fade_num_ticks = 0;
    c->vibrato_rate = p->ram[c->pattern_cur_ptr++];
    c->vib_depth = p->ram[c->pattern_cur_ptr++];
    break;
  case 0xdf: // vibrato off
    c->vib_depth = 0;
    break;
  case 0xe0:  // master volume
    p->master_volume = p->ram[c->pattern_cur_ptr++] << 8;
    p->vol_dirty = 0xff;
    break;
  case 0xe1:  // master volume fade
    p->master_volume_fade_ticks = p->ram[c->pattern_cur_ptr++];
    p->master_volume_fade_target = p->ram[c->pattern_cur_ptr++];
    p->master_volume_fade_add_per_tick = SpcDivHelper(p->master_volume_fade_target - (p->master_volume >> 8), p->master_volume_fade_ticks);
    break;
  case 0xe2:  // tempo
    p->tempo = (p->ram[c->pattern_cur_ptr++] + p->smw_tempo_increase + 1) << 8;
    break;
  case 0xe3:  // tempo fade
    p->tempo_fade_num_ticks = p->ram[c->pattern_cur_ptr++];
    p->tempo_fade_final = p->ram[c->pattern_cur_ptr++] + p->smw_tempo_increase + 1;
    p->tempo_fade_add = SpcDivHelper(p->tempo_fade_final - (p->tempo >> 8), p->tempo_fade_num_ticks);
    break;
  case 0xe4:
    p->global_transposition = p->ram[c->pattern_cur_ptr++];
    break;
  case 0xe5:  // tremolo on
    c->tremolo_delay_ticks = p->ram[c->pattern_cur_ptr++];
    printf("Writing to bad tremolo ram addr!\n");
    //c->tremolo_rate = p->ram[c->pattern_cur_ptr++];
    c->tremolo_depth = p->ram[c->pattern_cur_ptr++];
    break;
  case 0xe6:  // tremolo off
    c->tremolo_depth = 0;
    break;
  case 0xe7:  // volume
    c->channel_volume = p->ram[c->pattern_cur_ptr++] << 8;
    p->vol_dirty |= p->cur_chan_bit;
    break;
  case 0xe8:  // volume fade
    c->volume_fade_ticks = p->ram[c->pattern_cur_ptr++];
    c->volume_fade_target = p->ram[c->pattern_cur_ptr++];
    c->volume_fade_addpertick = SpcDivHelper(c->volume_fade_target - (c->channel_volume >> 8), c->volume_fade_ticks);
    break;
  case 0xe9: { // subroutine
    uint16 t = p->ram[c->pattern_cur_ptr++];
    t |= p->ram[c->pattern_cur_ptr++] << 8;
    c->subroutine_num_loops = p->ram[c->pattern_cur_ptr++];
    c->saved_pattern_ptr = c->pattern_cur_ptr;
    c->pattern_cur_ptr = c->pattern_start_ptr = t;
    break;
  }
  case 0xea:  // vibrato fade
    c->vibrato_fade_num_ticks = p->ram[c->pattern_cur_ptr++];
    c->vib_depth_orig = c->vib_depth;
    c->vibrato_fade_add_per_tick = c->vibrato_fade_num_ticks ? c->vib_depth / c->vibrato_fade_num_ticks : 0xff;
    break;
  case 0xeb:  // pitch envelope release
    c->pitch_envelope_direction = 1;
    goto pitch_env;
  case 0xec:  // pitch envelope attack
    c->pitch_envelope_direction = 0;
pitch_env:
    c->pitch_envelope_delay = p->ram[c->pattern_cur_ptr++];
    c->pitch_envelope_num_ticks = p->ram[c->pattern_cur_ptr++];
    c->pitch_envelope_slide_value = p->ram[c->pattern_cur_ptr++];
    break;
  case 0xee:  // fine tune
    c->fine_tune = p->ram[c->pattern_cur_ptr++];
    break;
  case 0xef:  // echo enable bits and volume
    p->echo_channels = p->ram[c->pattern_cur_ptr++];
    Dsp_Write(p, EON, p->echo_channels);
    p->echo_volume_left = p->ram[c->pattern_cur_ptr++] << 8;
    p->echo_volume_right = p->ram[c->pattern_cur_ptr++] << 8;
    p->sfx3_unused = 0;
    Dsp_Write(p, FLG, 0);
    SetEchoVolume(p);
    break;
  case 0xf0:  // echo off
    p->echo_channels = 0;
    SetEchoOff(p);
    break;
  case 0xf1: { // set echo properties
    static const int8_t kEchoFirParameters[] = {
       -1,   8,  23,  36,  36,  23,   8,  -1,
      127,   0,   0,   0,   0,   0,   0,   0,
    };
    Dsp_Write(p, EDL, p->ram[c->pattern_cur_ptr++]);
    Dsp_Write(p, EFB, p->ram[c->pattern_cur_ptr++]);
    const int8_t *ep = kEchoFirParameters + p->ram[c->pattern_cur_ptr++] * 8;
    for (int i = 0; i < 8; i++)
      Dsp_Write(p, FIR0 + i * 16, *ep++);
    break;
  }
  case 0xf2:
    p->echo_volume_fade_ticks = p->ram[c->pattern_cur_ptr++];
    p->echo_volume_fade_target_left = p->ram[c->pattern_cur_ptr++];
    p->echo_volume_fade_target_right = p->ram[c->pattern_cur_ptr++];
    p->echo_volume_fade_add_left = SpcDivHelper(p->echo_volume_fade_target_left - (p->echo_volume_left >> 8), p->echo_volume_fade_ticks);
    p->echo_volume_fade_add_right = SpcDivHelper(p->echo_volume_fade_target_right - (p->echo_volume_right >> 8), p->echo_volume_fade_ticks);
    break;
  default:
    Not_Implemented();
  }
}

static void ComputePitchAdd(Channel *c, uint8 pitch) {
  c->pitch_target = pitch & 0x7f;
  c->pitch_add_per_tick = SpcDivHelper(c->pitch_target - (c->pitch >> 8), c->pitch_slide_length);
}

static void Chan_HandleTick(SmwSpcPlayer *p, Channel *c) {
  if (c->volume_fade_ticks) {
    p->vol_dirty |= p->cur_chan_bit;
    Chan_DoAnyFade(&c->channel_volume, c->volume_fade_addpertick, c->volume_fade_target, --c->volume_fade_ticks);
  }
  if (c->tremolo_depth) {
    if (c->tremolo_delay_ticks == c->tremolo_hold_count) {
      p->vol_dirty |= p->cur_chan_bit;
      if (c->tremolo_count & 0x80 && c->tremolo_depth == 0xff) {
        c->tremolo_count = 0x80;
      } else {
        printf("Reading bad tremolo ram addr!\n");
        //c->tremolo_count += c->tremolo_rate;
      }
      CalcTremolo(p, c);
    } else {
      c->tremolo_hold_count++;
      CalcFinalVolume(p, c, c->channel_volume_master);
    }
  } else {
    CalcFinalVolume(p, c, c->channel_volume_master);
  }

  if (c->pan_num_ticks) {
    Chan_DoAnyFade(&c->pan_value, c->pan_add_per_tick, c->pan_target_value, --c->pan_num_ticks);
  } else if (!(p->vol_dirty & p->cur_chan_bit)) {
    return;
  }
  WriteVolumeToDsp(p, c, c->pan_value);
}

static void WriteVolumeToDsp(SmwSpcPlayer *p, Channel *c, uint16 volume) {
  static const uint8 kVolumeTable[22] = { 0, 1, 3, 7, 13, 21, 30, 41, 52, 66, 81, 94, 103, 110, 115, 119, 122, 124, 125, 126, 127, 127 };
  if (p->is_chan_on & p->cur_chan_bit)
    return;
  for (int i = 0; i < 2; i++) {
    int j = volume >> 8;
    assert(j < 21);
    uint8 t = kVolumeTable[j] + ((kVolumeTable[j + 1] - kVolumeTable[j]) * (uint8)volume >> 8);
    t = t * c->final_volume >> 8;
    if ((c->pan_flag_with_phase_invert << i) & 0x80)
      t = -t;
    Dsp_Write(p, V0VOLL + i + c->index * 16, t);
    volume = 0x1400 - volume;
  }
}


static const  uint8 kEffectByteLength[] = {
  2,  2,  3,  4,  4,  1,  2,  3,  2,  3,  2,  4,  1,  2,  3,  4,
  2,  4,  4,  1,  2,  4,  1,  4,  4
};

static bool WantWriteKof(SmwSpcPlayer *p, Channel *c) {
  int ptr = c->pattern_cur_ptr;
  for (;;) {
    uint8 cmd = p->ram[ptr++];
    if (cmd == 0)
      return true;

    while (!(cmd & 0x80))
      cmd = p->ram[ptr++];

    if (cmd == 0xc6)
      return false;
    if (cmd < 0xda)
      return true;
    ptr += kEffectByteLength[cmd - 0xda] - 1;
  }
}

static void HandleNoteTick(SmwSpcPlayer *p, Channel *c) {
  if (--c->note_keyoff_ticks_left == 0 || c->note_ticks_left == 2) {
    if (WantWriteKof(p, c) && !(p->cur_chan_bit & p->is_chan_on))
      Dsp_Write(p, KOF, p->cur_chan_bit);
  }

  p->did_affect_volumepitch_flag = 0;
  if (c->pitch_slide_length == 0 || (p->is_chan_on & p->cur_chan_bit)) {
    if (p->ram[c->pattern_cur_ptr] != 0xdd)
      goto after_pitch_thing;
    if (p->cur_chan_bit & p->is_chan_on) {
      c->pattern_cur_ptr += 4;
    } else {
      c->pattern_cur_ptr++;
      c->pitch_slide_delay_left = p->ram[c->pattern_cur_ptr++];
      c->pitch_slide_length = p->ram[c->pattern_cur_ptr++];
      ComputePitchAdd(c, p->ram[c->pattern_cur_ptr++] + p->global_transposition);
    }
  }

  if (c->pitch_slide_delay_left) {
    c->pitch_slide_delay_left--;
  } else if (!(p->is_chan_on & p->cur_chan_bit)) {
    p->did_affect_volumepitch_flag = 0x80;
    Chan_DoAnyFade(&c->pitch, c->pitch_add_per_tick, c->pitch_target, --c->pitch_slide_length);
  }
after_pitch_thing:;
  uint16 pitch = c->pitch;
  if (c->vib_depth) {
    if (c->vibrato_delay_ticks == c->vibrato_hold_count) {
      if (c->vibrato_fade_num_ticks) {
        if (c->vibrato_change_count == c->vibrato_fade_num_ticks) {
          c->vib_depth = c->vib_depth_orig;
        } else {
          c->vib_depth = (c->vibrato_change_count++ == 0 ? 0 : c->vib_depth) + c->vibrato_fade_add_per_tick;
        }
      }
      c->vibrato_count += c->vibrato_rate;
      CalcVibratoAddPitch(p, c, pitch, c->vibrato_count);
      return;
    }
    c->vibrato_hold_count++;
  }
  if (p->did_affect_volumepitch_flag)
    WritePitch(p, c, pitch);
}

static void CalcVibratoAddPitch(SmwSpcPlayer *p, Channel *c, uint16 pitch, uint8 value) {
  int t = value << 2;
  t ^= (t & 0x100) ? 0xff : 0;
  int r = (c->vib_depth >= 0xf1) ?
    (uint8)t * (c->vib_depth & 0xf) :
    (uint8)t * c->vib_depth >> 8;
  WritePitch(p, c, pitch + (value & 0x80 ? -r : r));
}

static void HandleTremolo(SmwSpcPlayer *p, Channel *c) {
  Not_Implemented();
}

static void CalcTremolo(SmwSpcPlayer *p, Channel *c) {
  Not_Implemented();
}

static void HandlePanAndSweep(SmwSpcPlayer *p, Channel *c) {
  p->did_affect_volumepitch_flag = 0;
  if (c->tremolo_depth && c->tremolo_hold_count == c->tremolo_delay_ticks)
    HandleTremolo(p, c);

  uint16 volume = c->pan_value;
  if (c->pan_num_ticks != 0) {
    p->did_affect_volumepitch_flag = 0x80;
    volume += p->main_tempo_accum * (int16_t)c->pan_add_per_tick / 256;
  }

  if (p->did_affect_volumepitch_flag)
    WriteVolumeToDsp(p, c, volume);
  p->did_affect_volumepitch_flag = 0;

  uint16 pitch = c->pitch;
  if (c->pitch_slide_length && !c->pitch_slide_delay_left) {
    p->did_affect_volumepitch_flag = 0x80;
    pitch += p->main_tempo_accum * (int16_t)c->pitch_add_per_tick / 256;
  }
  if (c->vib_depth && c->vibrato_delay_ticks == c->vibrato_hold_count) {
    CalcVibratoAddPitch(p, c, pitch, (p->main_tempo_accum * c->vibrato_rate >> 8) + c->vibrato_count);
    return;
  }
  if (p->did_affect_volumepitch_flag)
    WritePitch(p, c, pitch);
}

static void CalcFinalVolume(SmwSpcPlayer *p, Channel *c, uint8 vol) {
  int t = vol * (c->channel_volume >> 8) >> 8;
  t = (p->master_volume >> 8) * t >> 8;
  c->final_volume = t * t >> 8;
}

static void SmwSpcPlayer_Initialize(SpcPlayer *p_in) {
  SmwSpcPlayer *p = (SmwSpcPlayer *)p_in;
  dsp_reset(p->base.dsp);
  Spc_Reset(p);
}

static void SmwSpcPlayer_GenerateSamples(SpcPlayer *p_in) {
  SmwSpcPlayer *p = (SmwSpcPlayer *)p_in;
  assert(p->timer_cycles <= 64);
  assert(p->base.dsp->sampleOffset <= 534);

  for (;;) {
    if (p->timer_cycles >= 64) {
      Spc_Loop_Part2(p, p->timer_cycles >> 6);
      p->timer_cycles &= 63;
    }

    // sample rate 32000
    int n = 534 - p->base.dsp->sampleOffset;
    if (n > (64 - p->timer_cycles))
      n = (64 - p->timer_cycles);

    p->timer_cycles += n;

    for (int i = 0; i < n; i++)
      dsp_cycle(p->base.dsp);

    if (p->base.dsp->sampleOffset == 534)
      break;
  }
}

static void SmwSpcPlayer_Upload(SpcPlayer *p_in, const uint8_t *data) {
  SmwSpcPlayer *p = (SmwSpcPlayer *)p_in;
  Dsp_Write(p, FLG, 0x60);
  Dsp_Write(p, KOF, 0xff);
  for (;;) {
    int numbytes = *(uint16 *)(data);
    if (numbytes == 0)
      break;
    int target = *(uint16 *)(data + 2);
    data += 4;
    do {
      p->ram[target++ & 0xffff] = *data++;
    } while (--numbytes);
  }
  p->base.port_to_snes[0] = p->base.port_to_snes[1] = p->base.port_to_snes[2] = p->base.port_to_snes[3] = 0;
  p->is_chan_on = 0;
  p->smw_tempo_increase = 0;
  p->smw_pause_music = 0;
  p->smw_player_on_yoshi = 0;
  p->echo_channels = 0;
  memset(p->base.input_ports, 0, sizeof(p->base.input_ports));
  memset(p->last_value_from_snes, 0, sizeof(p->last_value_from_snes));
  memset(p->new_value_from_snes, 0, sizeof(p->new_value_from_snes));
  Dsp_Write(p, FLG, 0x20);  
}

SpcPlayer *SmwSpcPlayer_Create(void) {
  SmwSpcPlayer *p = (SmwSpcPlayer *)malloc(sizeof(SmwSpcPlayer));
  memset(p, 0, sizeof(SmwSpcPlayer));
  p->base.dsp = dsp_init(p->ram);
  p->base.ram = p->ram;
  p->base.initialize = &SmwSpcPlayer_Initialize;
  p->base.gen_samples = &SmwSpcPlayer_GenerateSamples;
  p->base.upload = &SmwSpcPlayer_Upload;
  p->base.copy_vars = &SmwSpcPlayer_CopyVariables;
  p->reg_write_history = 0;
  return &p->base;
}


// =======================================
#define WITH_SPC_PLAYER_DEBUGGING 0

#if WITH_SPC_PLAYER_DEBUGGING

#include <SDL.h>

static DspRegWriteHistory my_write_hist;
static SmwSpcPlayer my_spc_snapshot;
static int loop_ctr;

bool CompareSpcImpls(SmwSpcPlayer *p, SmwSpcPlayer *p_org, Apu *apu) {
  SmwSpcPlayer_CopyVariablesToRam(p);
  memcpy(p->ram + 0x120, apu->ram + 0x120, 256-32);  // stack
  memcpy(p->ram + 0xf1, apu->ram + 0xf1, 15);  // dsp regs
  memcpy(p->ram + 0x10, apu->ram + 0x10, 8);  // temp regs
  p->ram[0x46] = apu->ram[0x46]; // chn
  int errs = 0;
  static const uint16 ranges[][2] = {
    {0x0, 0x500},
    {0x1500, 0x6000},
    {0x7000, 0xffff},
  };

  for (int j = 0; j < 2; j++) {
    for (int i = ranges[j][0], i_end = ranges[j][1]; i != i_end; i++) {  // skip compare echo etc
      if (p->ram[i] != apu->ram[i]) {
        if (errs < 16) {
          if (errs == 0)
            printf("@%d\n", loop_ctr);
          printf("%.4X: %.2X != %.2X (mine, theirs) orig %.2X\n", i, p->ram[i], apu->ram[i], p_org->ram[i]);
          errs++;
        }
      }
    }
  }

  int n = my_write_hist.count < apu->hist.count ? apu->hist.count : my_write_hist.count;
  for (size_t i = 0; i != n; i++) {
    if (i >= my_write_hist.count || i >= apu->hist.count || my_write_hist.addr[i] != apu->hist.addr[i] || my_write_hist.val[i] != apu->hist.val[i]) {
      if (errs == 0)
        printf("@%d\n", loop_ctr);
      printf("%d: ", (int)i);
      if (i >= my_write_hist.count) printf("[??: ??]"); else printf("[%.2x: %.2x]", my_write_hist.addr[i], my_write_hist.val[i]);
      printf(" != ");
      if (i >= apu->hist.count) printf("[??: ??]"); else printf("[%.2x: %.2x]", apu->hist.addr[i], apu->hist.val[i]);
      printf("\n");
      errs++;
    }
  }

  if (errs) {
    printf("Total %d errors\n", errs);
    return false;
  }

  apu->hist.count = 0;
  my_write_hist.count = 0;
  loop_ctr++;
  return true;
}

extern bool g_debug_apu_cycles;

void RunAudioPlayer(void) {
  if(SDL_Init(SDL_INIT_AUDIO) != 0) {
    printf("Failed to init SDL: %s\n", SDL_GetError());
    return;
  }
  
  SDL_AudioSpec want, have;
  SDL_AudioDeviceID device;
  SDL_memset(&want, 0, sizeof(want));
  want.freq = 44100;
  want.format = AUDIO_S16;
  want.channels = 2;
  want.samples = 2048;
  want.callback = NULL; // use queue
  device = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
  if(device == 0) {
    printf("Failed to open audio device: %s\n", SDL_GetError());
    return;
  }
  int16_t* audioBuffer = (int16_t*)malloc(735 * 4); // *2 for stereo, *2 for sizeof(int16)
  SDL_PauseAudioDevice(device, 0);

  SmwSpcPlayer *p = (SmwSpcPlayer *)SmwSpcPlayer_Create();

  FILE *f = fopen("d:/code/smw/dis/bank2.spc", "rb");
  fread(p->ram, 1, 65536, f);
  fclose(f);

  p->reg_write_history = &my_write_hist;

  bool run_both = 1;

  if (!run_both) {
    SmwSpcPlayer_Initialize(&p->base);

    p->base.input_ports[0] = 4;

    for (;;) {
      SmwSpcPlayer_GenerateSamples(&p->base);

      int16_t audioBuffer[736 * 2];
      dsp_getSamples(p->base.dsp, audioBuffer, 736);
      SDL_QueueAudio(device, audioBuffer, 736 * 2 * have.channels);
      while (SDL_GetQueuedAudioSize(device) >= 736 * 4 * 3/* 44100 * 4 * 300*/)
        SDL_Delay(1);
    }

  } else {
    Apu *apu = apu_init();
    apu_reset(apu);
    apu->spc->pc = 0x500;

    memcpy(apu->ram, p->ram, 65536);

    CompareSpcImpls(p, &my_spc_snapshot, apu);

 //   g_debug_apu_cycles = true;

    uint64_t cycle_counter = 0;
    int tgt = 0x54E;
    uint8 ticks_next = 0;
    bool apu_debug = false;
    bool is_initialize = true;
    for (;;) {
      if (apu_debug && apu->cpuCyclesLeft == 0) {
        char line[80];
        getProcessorStateSpc(apu, line);
        puts(line);
      }

      apu_cycle(apu);

      if (((apu->cycles - 1) & 0x1f) == 0)
        dsp_cycle(p->base.dsp);

      if (apu->spc->pc == tgt) {
        tgt ^= 0x54E ^ 0x54F;
        if (tgt == 0x54E) {
          uint8 ticks = ticks_next;
          ticks_next = apu->spc->y;
          my_spc_snapshot = *p;
          for (;;) {
            my_write_hist.count = 0;
            if (is_initialize) {
              SmwSpcPlayer_Initialize(&p->base);
            } else {
              Spc_Loop_Part2(p, ticks);
            }
            if (CompareSpcImpls(p, &my_spc_snapshot, apu))
              break;
            *p = my_spc_snapshot;
          }
          is_initialize = false;

          if (cycle_counter == 0)
            apu->inPorts[2] = p->base.input_ports[2] = 21;
          //if (cycle_counter == 1000)
          //  apu->inPorts[0] = p->base.input_ports[0] = 1;
//          if (cycle_counter == 2000)
//            apu->inPorts[1] = p->base.input_ports[1] = 3;
//          if (cycle_counter == 3000)
//            apu->inPorts[1] = p->base.input_ports[1] = 1;

          cycle_counter++;
        }
      }

      if (p->base.dsp->sampleOffset == 534) {
        int16_t audioBuffer[736 * 2];
        dsp_getSamples(p->base.dsp, audioBuffer, 736);
        SDL_QueueAudio(device, audioBuffer, 736 * 2 * have.channels);
        while (SDL_GetQueuedAudioSize(device) >= 736 * 4 * 3/* 44100 * 4 * 300*/) {
          SDL_Delay(1);
        }
      }
    }
  }
}
#endif  // WITH_SPC_PLAYER_DEBUGGING
