#include "../src/smw_spc_player.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include "../src/types.h"
#include "../src/snes/spc.h"
#include "../src/snes/dsp_regs.h"
#include "../src/tracing.h"

typedef struct Channel {
  uint16 pattern_cur_ptr;
  uint8 index;
  uint8 note_ticks_left;
  uint8 note_keyoff_ticks_left;
  uint8 subroutine_num_loops;
  uint8 volume_fade_ticks;
  uint8 pan_num_ticks;
  uint8 pitch_slide_length;
  uint8 pitch_slide_delay_left;
  uint8 vibrato_hold_count;
  uint8 vib_depth;
  uint8 tremolo_hold_count;
  uint8 tremolo_depth;
  uint8 vibrato_change_count;
  uint8 note_length;
  uint8 note_gate_off_fixedpt;
  uint8 channel_volume_master;
  uint8 instrument_id;
  uint16 instrument_pitch_base;
  uint16 saved_pattern_ptr;
  uint16 pattern_start_ptr;
  uint8 byte_250;
  uint8 pitch_envelope_num_ticksa;
  uint8 pitch_envelope_delay;
  uint8 pitch_envelope_direction;
  uint8 pitch_envelope_slide_value;
  uint8 vibrato_count;
  uint8 vibrato_rate;
  uint8 vibrato_delay_ticks;
  uint8 vibrato_fade_num_ticks;
  uint8 vibrato_fade_add_per_tick;
  uint8 vibrato_depth_target;
  uint8 tremolo_count;
  uint8 tremolo_rate;
  uint8 tremolo_delay_ticks;
  uint8 channel_transpositionb;
  uint16 channel_volume;
  uint16 volume_fade_addpertick;
  uint8 volume_fade_target;
  uint8 final_volume;
  uint16 pan_value;
  uint16 pan_add_per_tick;
  uint8 pan_target_value;
  uint8 pan_flag_with_phase_invert;
  uint16 pitch;
  uint16 pitch_add_per_tick;
  uint8 pitch_target;
  uint8 fine_tunea;
  uint8 meh_unused;
  uint8 channel_transpositiona;
  uint8 fine_tuneb;
  uint8 pitch_envelope_num_ticksb;
} Channel;

typedef struct SmasSpcPlayer {
  SpcPlayer base;
  DspRegWriteHistory *reg_write_history;
  uint8 new_value_from_snes[4];
  uint8 last_value_from_snes[4];
  uint8 var_c;
  uint8 last_written_edl; // TODO:persist
  uint8 timer_cycles; // TODO:persist
  uint8 counter_sf0d;
  uint16 _always_zero;
  uint16 temp_accum;
  uint8 ttt;
  uint8 did_affect_volumepitch_flag;
  uint16 addr0;
  uint16 addr1;
  uint16 lfsr_value;
  uint8 is_chan_on;
  uint8 some_timer;
  uint8 chan7_note_index;
  uint8 port3_timeout;
  uint8 somerandomstuff_ctr;
  uint8 chan5_var25;
  uint8 enable_some_randomstuff;
  uint8 chan5_var27;
  uint16 sfx_sound_ptr_cur;
  uint8 port0_note_length_left;
  uint8 port0_note_length;
  uint16 music_ptr_toplevel;
  uint8 block_count;
  uint8 sfx_timer_accum;
  uint8 chn;
  uint8 key_ON;
  uint8 key_OFF;
  uint8 cur_chan_bit;
  uint8 reg_FLG;
  uint8 reg_NON;
  uint8 reg_EON;
  uint8 reg_PMON;
  uint8 echo_stored_time;
  uint8 echo_parameter_EDL;
  uint8 reg_EFB;
  uint8 global_transposition;
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
  uint8 percussion_base_id;
  uint16 echo_volume_left;
  uint16 echo_volume_right;
  uint16 echo_volume_fade_add_left;
  uint16 echo_volume_fade_add_right;
  uint8 echo_volume_fade_ticks;
  uint8 echo_volume_fade_target_left;
  uint8 echo_volume_fade_target_right;
  uint16 port3_cur_ptr;
  uint8 port_to_snes_b[4];
  uint8 echo_channels;
  uint8 chan7_timer;
  uint8 echo_fract_incr;
  uint8 extra_tempo;
  uint8 pause_music_ctr;
  uint8 port3_timer2;
  uint8 port3_note_length;
  uint8 some_volume_flag;
  uint8 var_3F8;
  Channel channel[8];
  uint8 input_ports[4];
  uint8 ram[65536]; // rest of ram
} SmasSpcPlayer;
typedef struct MemMap {
  uint16 off, org_off;
} MemMap;
typedef struct MemMapSized {
  uint16 off, org_off, size;
} MemMapSized;
static const MemMap kChannel_Maps[] = {
{offsetof(Channel, pattern_cur_ptr), 0x8030},
{offsetof(Channel, note_ticks_left), 0x70},
{offsetof(Channel, note_keyoff_ticks_left), 0x71},
{offsetof(Channel, subroutine_num_loops), 0x80},
{offsetof(Channel, volume_fade_ticks), 0x90},
{offsetof(Channel, pan_num_ticks), 0x91},
{offsetof(Channel, pitch_slide_length), 0xa0},
{offsetof(Channel, pitch_slide_delay_left), 0xa1},
{offsetof(Channel, vibrato_hold_count), 0xb0},
{offsetof(Channel, vib_depth), 0xb1},
{offsetof(Channel, tremolo_hold_count), 0xc0},
{offsetof(Channel, tremolo_depth), 0xc1},
{offsetof(Channel, vibrato_change_count), 0x100},
{offsetof(Channel, note_length), 0x200},
{offsetof(Channel, note_gate_off_fixedpt), 0x201},
{offsetof(Channel, channel_volume_master), 0x210},
{offsetof(Channel, instrument_id), 0x211},
{offsetof(Channel, instrument_pitch_base), 0x8220},
{offsetof(Channel, saved_pattern_ptr), 0x8230},
{offsetof(Channel, pattern_start_ptr), 0x8240},
{offsetof(Channel, byte_250), 0x250},
{offsetof(Channel, pitch_envelope_num_ticksa), 0x280},
{offsetof(Channel, pitch_envelope_delay), 0x281},
{offsetof(Channel, pitch_envelope_direction), 0x290},
{offsetof(Channel, pitch_envelope_slide_value), 0x291},
{offsetof(Channel, vibrato_count), 0x2a0},
{offsetof(Channel, vibrato_rate), 0x2a1},
{offsetof(Channel, vibrato_delay_ticks), 0x2b0},
{offsetof(Channel, vibrato_fade_num_ticks), 0x2b1},
{offsetof(Channel, vibrato_fade_add_per_tick), 0x2c0},
{offsetof(Channel, vibrato_depth_target), 0x2c1},
{offsetof(Channel, tremolo_count), 0x2d0},
{offsetof(Channel, tremolo_rate), 0x2d1},
{offsetof(Channel, tremolo_delay_ticks), 0x2e0},
{offsetof(Channel, channel_transpositionb), 0x2f0},
{offsetof(Channel, channel_volume), 0x8300},
{offsetof(Channel, volume_fade_addpertick), 0x8310},
{offsetof(Channel, volume_fade_target), 0x320},
{offsetof(Channel, final_volume), 0x321},
{offsetof(Channel, pan_value), 0x8330},
{offsetof(Channel, pan_add_per_tick), 0x8340},
{offsetof(Channel, pan_target_value), 0x350},
{offsetof(Channel, pan_flag_with_phase_invert), 0x351},
{offsetof(Channel, pitch), 0x8360},
{offsetof(Channel, pitch_add_per_tick), 0x8370},
{offsetof(Channel, pitch_target), 0x380},
{offsetof(Channel, fine_tunea), 0x381},
{offsetof(Channel, meh_unused), 0x3a0},
{offsetof(Channel, channel_transpositiona), 0x3a1},
{offsetof(Channel, fine_tuneb), 0x3e0},
{offsetof(Channel, pitch_envelope_num_ticksb), 0x3e1},
};
static const MemMapSized kSpcPlayer_Maps[] = {
{offsetof(SmasSpcPlayer, new_value_from_snes), 0x0, 4},
{offsetof(SmasSpcPlayer, base.port_to_snes), 0x4, 4},
{offsetof(SmasSpcPlayer, last_value_from_snes), 0x8, 4},
{offsetof(SmasSpcPlayer, var_c), 0xc, 1},
{offsetof(SmasSpcPlayer, counter_sf0d), 0xd, 1},
{offsetof(SmasSpcPlayer, _always_zero), 0xe, 2},
{offsetof(SmasSpcPlayer, temp_accum), 0x10, 2},
{offsetof(SmasSpcPlayer, ttt), 0x12, 1},
{offsetof(SmasSpcPlayer, did_affect_volumepitch_flag), 0x13, 1},
{offsetof(SmasSpcPlayer, addr0), 0x14, 2},
{offsetof(SmasSpcPlayer, addr1), 0x16, 2},
{offsetof(SmasSpcPlayer, lfsr_value), 0x18, 2},
{offsetof(SmasSpcPlayer, is_chan_on), 0x1a, 1},
{offsetof(SmasSpcPlayer, some_timer), 0x20, 1},
{offsetof(SmasSpcPlayer, chan7_note_index), 0x22, 1},
{offsetof(SmasSpcPlayer, port3_timeout), 0x23, 1},
{offsetof(SmasSpcPlayer, somerandomstuff_ctr), 0x24, 1},
{offsetof(SmasSpcPlayer, chan5_var25), 0x25, 1},
{offsetof(SmasSpcPlayer, enable_some_randomstuff), 0x26, 1},
{offsetof(SmasSpcPlayer, chan5_var27), 0x27, 1},
{offsetof(SmasSpcPlayer, timer_cycles), 0x28, 1},
{offsetof(SmasSpcPlayer, last_written_edl), 0x29, 1},
{offsetof(SmasSpcPlayer, sfx_sound_ptr_cur), 0x2c, 2},
{offsetof(SmasSpcPlayer, port0_note_length_left), 0x2e, 1},
{offsetof(SmasSpcPlayer, port0_note_length), 0x2f, 1},
{offsetof(SmasSpcPlayer, music_ptr_toplevel), 0x40, 2},
{offsetof(SmasSpcPlayer, block_count), 0x42, 1},
{offsetof(SmasSpcPlayer, sfx_timer_accum), 0x43, 1},
{offsetof(SmasSpcPlayer, chn), 0x44, 1},
{offsetof(SmasSpcPlayer, key_ON), 0x45, 1},
{offsetof(SmasSpcPlayer, key_OFF), 0x46, 1},
{offsetof(SmasSpcPlayer, cur_chan_bit), 0x47, 1},
{offsetof(SmasSpcPlayer, reg_FLG), 0x48, 1},
{offsetof(SmasSpcPlayer, reg_NON), 0x49, 1},
{offsetof(SmasSpcPlayer, reg_EON), 0x4a, 1},
{offsetof(SmasSpcPlayer, reg_PMON), 0x4b, 1},
{offsetof(SmasSpcPlayer, echo_stored_time), 0x4c, 1},
{offsetof(SmasSpcPlayer, echo_parameter_EDL), 0x4d, 1},
{offsetof(SmasSpcPlayer, reg_EFB), 0x4e, 1},
{offsetof(SmasSpcPlayer, global_transposition), 0x50, 1},
{offsetof(SmasSpcPlayer, main_tempo_accum), 0x51, 1},
{offsetof(SmasSpcPlayer, tempo), 0x52, 2},
{offsetof(SmasSpcPlayer, tempo_fade_num_ticks), 0x54, 1},
{offsetof(SmasSpcPlayer, tempo_fade_final), 0x55, 1},
{offsetof(SmasSpcPlayer, tempo_fade_add), 0x56, 2},
{offsetof(SmasSpcPlayer, master_volume), 0x58, 2},
{offsetof(SmasSpcPlayer, master_volume_fade_ticks), 0x5a, 1},
{offsetof(SmasSpcPlayer, master_volume_fade_target), 0x5b, 1},
{offsetof(SmasSpcPlayer, master_volume_fade_add_per_tick), 0x5c, 2},
{offsetof(SmasSpcPlayer, vol_dirty), 0x5e, 1},
{offsetof(SmasSpcPlayer, percussion_base_id), 0x5f, 1},
{offsetof(SmasSpcPlayer, echo_volume_left), 0x60, 2},
{offsetof(SmasSpcPlayer, echo_volume_right), 0x62, 2},
{offsetof(SmasSpcPlayer, echo_volume_fade_add_left), 0x64, 2},
{offsetof(SmasSpcPlayer, echo_volume_fade_add_right), 0x66, 2},
{offsetof(SmasSpcPlayer, echo_volume_fade_ticks), 0x68, 1},
{offsetof(SmasSpcPlayer, echo_volume_fade_target_left), 0x69, 1},
{offsetof(SmasSpcPlayer, echo_volume_fade_target_right), 0x6a, 1},
{offsetof(SmasSpcPlayer, port3_cur_ptr), 0xd0, 2},
{offsetof(SmasSpcPlayer, port_to_snes_b), 0xd2, 4},
{offsetof(SmasSpcPlayer, echo_channels), 0x3c3, 1},
{offsetof(SmasSpcPlayer, chan7_timer), 0x3c6, 1},
{offsetof(SmasSpcPlayer, echo_fract_incr), 0x3c7, 1},
{offsetof(SmasSpcPlayer, extra_tempo), 0x3c8, 1},
{offsetof(SmasSpcPlayer, pause_music_ctr), 0x3ca, 1},
{offsetof(SmasSpcPlayer, port3_timer2), 0x3d1, 1},
{offsetof(SmasSpcPlayer, port3_note_length), 0x3d3, 1},
{offsetof(SmasSpcPlayer, some_volume_flag), 0x3f1, 1},
{offsetof(SmasSpcPlayer, var_3F8), 0x3f8, 1},
};
static void ReadPortFromSnes(SmasSpcPlayer *p, int port);
static void Write_KeyOn(SmasSpcPlayer *p, uint8 bit);
static void PlayNote(SmasSpcPlayer *p, Channel *c, uint8 note);
static void WritePitch(SmasSpcPlayer *p, Channel *c, uint16 pitch);
static void SomeRandomStuff(SmasSpcPlayer *p);
static void HandleTremolo(SmasSpcPlayer *p, Channel *c);

static void SetupEchoParameter_EDL(SmasSpcPlayer *p, uint8 a);
static void SomeRandomStuff_Init(SmasSpcPlayer *p);
static void Music_ResetChan(SmasSpcPlayer *p);
static void Port2_HandleMusic(SmasSpcPlayer *p);
static void HandlePanAndSweep(SmasSpcPlayer *p, Channel *c);
static void CalcFinalVolume(SmasSpcPlayer *p, Channel *c, uint8 vol);
static void CalcVibratoAddPitch(SmasSpcPlayer *p, Channel *c, uint16 pitch, uint8 value);
static void HandleNoteTick(SmasSpcPlayer *p, Channel *c);
static void Chan_HandleTick(SmasSpcPlayer *p, Channel *c);
static void WriteVolumeToDsp(SmasSpcPlayer *p, Channel *c, uint16 volume);
static void Channel_SetInstrument(SmasSpcPlayer *p, Channel *c, uint8 instrument);
static void ComputePitchAdd(Channel *c, uint8 pitch);
static void PitchSlideToNote_Check(SmasSpcPlayer *p, Channel *c);
static void SetupEchoParameter_EDL(SmasSpcPlayer *p, uint8 a);
static void HandleEffect(SmasSpcPlayer *p, Channel *c, uint8 effect);
static void Port0_HandleCmd(SmasSpcPlayer *p);
static void Port3_HandleCmd(SmasSpcPlayer *p);
static void Chan5_SetInstrumentB(SmasSpcPlayer *p);
static void Randomstuff_Disable(SmasSpcPlayer *p);
static void Port1_FuncA(SmasSpcPlayer *p);
static void Chan7_WriteInstrumentData(SmasSpcPlayer *p, uint8 a);
static void Port1_HandleCmd(SmasSpcPlayer *p);
static void Chan7_Func1605(SmasSpcPlayer *p);

static const uint8 kEffectByteLength[27] = { 1, 1, 2, 3, 0, 1, 2, 1, 2, 1, 1, 3, 0, 1, 2, 3, 1, 3, 3, 0, 1, 3, 0, 3, 3, 3, 1 };


static void Dsp_Write(SmasSpcPlayer *p, uint8 reg, uint8 value) {
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

static void Not_Implemented() {
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

static void SmasSpcPlayer_CopyVariablesToRam(SmasSpcPlayer *p) {
  Channel *c = p->channel;
  for (int i = 0; i < 8; i++, c++) {
    for (const MemMap *m = &kChannel_Maps[0]; m != &kChannel_Maps[countof(kChannel_Maps)]; m++)
      memcpy(&p->ram[(m->org_off & 0x7fff) + i * 2], (uint8 *)c + m->off, m->org_off & 0x8000 ? 2 : 1);
  }
  for (const MemMapSized *m = &kSpcPlayer_Maps[0]; m != &kSpcPlayer_Maps[countof(kSpcPlayer_Maps)]; m++)
    memcpy(&p->ram[m->org_off], (uint8 *)p + m->off, m->size);
}

static void SmasSpcPlayer_CopyVariablesFromRam(SmasSpcPlayer *p) {
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

static void SmasSpcPlayer_CopyVariables(SpcPlayer *p_in, bool copy_to_ram) {
  SmasSpcPlayer *p = (SmasSpcPlayer *)p_in;
  if (copy_to_ram)
    SmasSpcPlayer_CopyVariablesToRam(p);
  else
    SmasSpcPlayer_CopyVariablesFromRam(p);
}

static inline void Chan_DoAnyFade(uint16 *p, uint16 add, uint8 target, uint8 cont) {
  if (!cont)
    *p = target << 8;
  else
    *p += add;
}

static void Spc_Reset(SmasSpcPlayer *p) {
  memset(p->ram, 0, 0x500);

  SmasSpcPlayer_CopyVariablesFromRam(p);

  SetupEchoParameter_EDL(p, 1);
  p->reg_FLG |= 0x20;
  SomeRandomStuff_Init(p);

  Dsp_Write(p, MVOLL, 0x60);
  Dsp_Write(p, MVOLR, 0x60);
  Dsp_Write(p, DIR, 0x3c);
  HIBYTE(p->tempo) = 16;
}

static void Spc_Loop_Part1(SmasSpcPlayer *p) {
  Dsp_Write(p, KOF, p->key_OFF);
  Dsp_Write(p, PMON, p->reg_PMON);
  Dsp_Write(p, NON, p->reg_NON);
  Dsp_Write(p, KOF, 0);
  Dsp_Write(p, KON, p->key_ON);
  if (!(p->echo_stored_time & 0x80)) {
    Dsp_Write(p, FLG, p->reg_FLG);
    if (p->echo_stored_time == p->echo_parameter_EDL) {
      Dsp_Write(p, EON, p->reg_EON);
      Dsp_Write(p, EFB, p->reg_EFB);
      Dsp_Write(p, EVOLR, p->echo_volume_right >> 8);
      Dsp_Write(p, EVOLL, p->echo_volume_left >> 8);
    }
  }
  p->key_OFF = p->key_ON = 0;
  uint8 bit = ((p->lfsr_value ^ (p->lfsr_value >> 8)) & 2 ? 0 : 0x80);
  p->lfsr_value = swap16((swap16(p->lfsr_value) >> 1)) | bit;
}

static void Spc_Loop_Part2(SmasSpcPlayer *p, uint8 ticks) {
  int t = p->sfx_timer_accum + (uint8)(ticks * 0x38);
  p->sfx_timer_accum = t;
  if (t >= 256) {
    Port0_HandleCmd(p);
    ReadPortFromSnes(p, 0);

    Port1_HandleCmd(p);
    Port1_FuncA(p);
    ReadPortFromSnes(p, 1);

    Port3_HandleCmd(p);
    ReadPortFromSnes(p, 3);

    if (p->echo_stored_time != p->echo_parameter_EDL && !(++p->echo_fract_incr & 1))
      p->echo_stored_time++;
  }

  t = p->main_tempo_accum + (uint8)(ticks * HIBYTE(p->tempo));
  p->main_tempo_accum = t;
  if (t >= 256) {
    Port2_HandleMusic(p);
    ReadPortFromSnes(p, 2);
    return;
  }
  if (p->base.port_to_snes[2]) {
    Channel *c = p->channel;
    for (p->cur_chan_bit = 1; p->cur_chan_bit != 0; p->cur_chan_bit <<= 1, c++) {
      if (HIBYTE(c->pattern_cur_ptr))
        HandlePanAndSweep(p, c);
    }
  }
  if (p->enable_some_randomstuff)
    SomeRandomStuff(p);
}

static void ReadPortFromSnes(SmasSpcPlayer *p, int port) {
  uint8 old = p->last_value_from_snes[port];
  p->last_value_from_snes[port] = p->base.input_ports[port];
  p->new_value_from_snes[port] = (p->base.input_ports[port] != old) ? p->base.input_ports[port] : 0;
}

static void Write_KeyOn(SmasSpcPlayer *p, uint8 bit) {
  Dsp_Write(p, KOF, 0);
  Dsp_Write(p, KON, bit);
}

static void PlayNote(SmasSpcPlayer *p, Channel *c, uint8 note) {
  if (note >= 0xca) {
    Channel_SetInstrument(p, c, note);
    note = 0xa4;
  }

  //  if (c->index == 0) {
  //    if (note == 0xc8) {
  //      printf("-+-\n");
  //    } else if (note == 0xc9) {
  //      printf("---\n");
  //    }
  //  }

  if (note >= 0xc8 || p->is_chan_on & p->cur_chan_bit)
    return;

  c->pitch = ((note & 0x7f) + p->global_transposition + c->channel_transpositionb) << 8 | c->fine_tunea;
  c->vibrato_count = c->vibrato_fade_num_ticks << 7;
  c->vibrato_hold_count = 0;
  c->vibrato_change_count = 0;
  c->tremolo_count = 0;
  c->tremolo_hold_count = 0;
  p->vol_dirty |= p->cur_chan_bit;
  p->key_ON |= p->cur_chan_bit;
  c->pitch_slide_length = c->pitch_envelope_num_ticksa;
  if (c->pitch_slide_length) {
    c->pitch_slide_delay_left = c->pitch_envelope_delay;
    if (!c->pitch_envelope_direction)
      c->pitch -= c->pitch_envelope_slide_value << 8;
    ComputePitchAdd(c, (c->pitch >> 8) + c->pitch_envelope_slide_value);
  }
  WritePitch(p, c, c->pitch);
}

static void WritePitch(SmasSpcPlayer *p, Channel *c, uint16 pitch) {
  static const uint16 kBaseNoteFreqs[13] = { 2143, 2270, 2405, 2548, 2700, 2860, 3030, 3211, 3402, 3604, 3818, 4045, 4286 };
  if ((pitch >> 8) >= 0x34) {
    pitch += (pitch >> 8) - 0x34;
  } else if ((pitch >> 8) < 0x13) {
    pitch += (uint8)(((pitch >> 8) - 0x13) * 2) - 256;
  }

  uint8 pp = (pitch >> 8) & 0x7f;
  uint8 q = pp / 12, r = pp % 12;
  uint16 t = kBaseNoteFreqs[r] + ((uint8)(kBaseNoteFreqs[r + 1] - kBaseNoteFreqs[r]) * (uint8)pitch >> 8);
  t *= 2;
  while (q != 6)
    t >>= 1, q++;

  t = c->instrument_pitch_base * t >> 8;
  if (!(p->cur_chan_bit & p->is_chan_on)) {
    uint8 reg = c->index * 16;
    Dsp_Write(p, reg + V0PITCHL, t & 0xff);
    Dsp_Write(p, reg + V0PITCHH, t >> 8);
  }
}

static void SomeRandomStuff(SmasSpcPlayer *p) {
  uint8 *rp = p->ram + 0xfe00 + (--p->somerandomstuff_ctr & 3) * 0x3f;
  for (int i = 0; i < 7; i++) {
    rp += 1;
    for (int j = 0; j < 4; j++) {
      int t = p->lfsr_value;
      t = p->lfsr_value * 2 + (((p->lfsr_value >> (8 + 5)) ^ (p->lfsr_value >> (8 + 6))) & 1);
      p->lfsr_value = t;
      rp[0] = (t >> 8) | 0x11;
      rp[1] = t | 0x11;
      rp += 2;
    }
  }
}

static void SomeRandomStuff_Init(SmasSpcPlayer *p) {
  for (int i = 0; i < 0x1b; i++)
    p->ram[0xfe00 + i * 9] = 0x96;
  p->ram[0xfe00 + 0x1b * 9] = 0x97;
  p->ram[0x3c80] = 0;
  p->ram[0x3c81] = 0xfe;
  p->ram[0x3c82] = 0;
  p->ram[0x3c83] = 0xfe;
  if (p->lfsr_value == 0)
    p->lfsr_value = 1;
}

static void Music_ResetChan(SmasSpcPlayer *p) {
  Channel *c = &p->channel[7];
  p->cur_chan_bit = 0x80;
  do {
    if ((p->cur_chan_bit & p->is_chan_on & 0x20) == 0) {
      HIBYTE(c->channel_volume) = 0xff;
      c->pan_flag_with_phase_invert = 10;
      c->pan_value = 10 << 8;
      c->instrument_id = 0;
      c->fine_tunea = 0;
      c->channel_transpositionb = 0;
      c->pitch_envelope_num_ticksa = 0;
      c->pitch_envelope_num_ticksb = 0;
      c->fine_tuneb = 0;
      c->channel_transpositiona = 0;
      c->vib_depth = 0;
      c->tremolo_depth = 0;
    }
  } while (c--, p->cur_chan_bit >>= 1);
  p->master_volume_fade_ticks = 0;
  p->echo_volume_fade_ticks = 0;
  p->tempo_fade_num_ticks = 0;
  p->global_transposition = 0;
  p->block_count = 0;
  p->percussion_base_id = 0;
  HIBYTE(p->master_volume) = 0xc0;
  HIBYTE(p->tempo) = 0x20;
}

static void Port2_HandleMusic(SmasSpcPlayer *p) {
  uint8 a = p->new_value_from_snes[2];
  Channel *c;
  int t; 

  if (a == 0) {
handle_cmd_00:
    if (p->var_3F8 != 0 || p->base.port_to_snes[2] == 0)
      return;
    if (p->pause_music_ctr != 0 && --p->pause_music_ctr == 0)
      goto HandleCmd_0xf0_PauseMusic;
    if (p->counter_sf0d == 0)
      goto label_a;
    if (--p->counter_sf0d != 0) {
      Music_ResetChan(p);
      return;
    }
next_phrase:
    for (;;) {
      t = WORD(p->ram[p->music_ptr_toplevel]);
      p->music_ptr_toplevel += 2;
      if ((t >> 8) != 0)
        break;
      if (t == 0)
        goto HandleCmd_0xf0_PauseMusic;
      if (sign8(--p->block_count))
        p->block_count = t;
      t = WORD(p->ram[p->music_ptr_toplevel]);
      p->music_ptr_toplevel += 2;
      if (p->block_count != 0)
        p->music_ptr_toplevel = t;
    }
    for (int i = 0; i < 8; i++)
      p->channel[i].pattern_cur_ptr = WORD(p->ram[t]), t += 2;
    c = p->channel, p->cur_chan_bit = 1;
    do {
      if (HIBYTE(c->pattern_cur_ptr) && c->instrument_id == 0)
        Channel_SetInstrument(p, c, 0);
      c->subroutine_num_loops = 0;
      if (!(p->cur_chan_bit & p->is_chan_on)) {
        c->pan_num_ticks = 0;
        c->volume_fade_ticks = 0;
      }
      c->note_ticks_left = 1;
    } while (c++, p->cur_chan_bit <<= 1);
label_a:
    p->vol_dirty = 0;
    c = p->channel, p->cur_chan_bit = 1;
    do {
      if (!HIBYTE(c->pattern_cur_ptr))
        continue;
      if (!--c->note_ticks_left) {
        for (;;) {
          uint8 cmd = p->ram[c->pattern_cur_ptr++];
          if (cmd == 0) {
            if (!c->subroutine_num_loops)
              goto next_phrase;
            c->pattern_cur_ptr = (--c->subroutine_num_loops == 0) ? c->saved_pattern_ptr : c->pattern_start_ptr;
            continue;
          }
          if (!(cmd & 0x80)) {
            static const uint8 kNoteVol[16] = { 25, 50, 76, 101, 114, 127, 140, 152, 165, 178, 191, 203, 216, 229, 242, 252 };
            static const uint8 kNoteGateOffPct[8] = { 50, 101, 127, 152, 178, 203, 229, 252 };
            c->note_length = cmd;
            cmd = p->ram[c->pattern_cur_ptr++];
            if (!(cmd & 0x80)) {
              c->note_gate_off_fixedpt = kNoteGateOffPct[cmd >> 4 & 7];
              c->channel_volume_master = kNoteVol[cmd & 0xf];
              cmd = p->ram[c->pattern_cur_ptr++];
            }
          }
          if (cmd >= 0xe0) {
            HandleEffect(p, c, cmd);
            continue;
          }
          if (!(p->is_chan_on & p->cur_chan_bit))
            PlayNote(p, c, cmd);
          c->note_ticks_left = c->note_length;
          t = c->note_ticks_left * c->note_gate_off_fixedpt >> 8;
          c->note_keyoff_ticks_left = (t != 0) ? t : 1;
          PitchSlideToNote_Check(p, c);
          break;
        }
      } else {
        HandleNoteTick(p, c);
        PitchSlideToNote_Check(p, c);
      }
    } while (c++, p->cur_chan_bit <<= 1);

    if (p->tempo_fade_num_ticks)
      p->tempo = (--p->tempo_fade_num_ticks == 0) ? p->tempo_fade_final << 8 : p->tempo + p->tempo_fade_add;
    if (p->echo_volume_fade_ticks) {
      p->echo_volume_left += p->echo_volume_fade_add_left;
      p->echo_volume_right += p->echo_volume_fade_add_right;
      if (--p->echo_volume_fade_ticks == 0) {
        p->echo_volume_left = p->echo_volume_fade_target_left << 8;
        p->echo_volume_right = p->echo_volume_fade_target_right << 8;
      }
    }
    if (p->master_volume_fade_ticks) {
      p->master_volume = (--p->master_volume_fade_ticks == 0) ? p->master_volume_fade_target << 8 : p->master_volume + p->master_volume_fade_add_per_tick;
      p->vol_dirty = 0xff;
    }
    c = p->channel, p->cur_chan_bit = 1;
    do {
      if (HIBYTE(c->pattern_cur_ptr))
        Chan_HandleTick(p, c);
    } while (c++, p->cur_chan_bit <<= 1);
    return;
  }
  p->var_3F8 = 0;
  p->port_to_snes_b[2] = a;

  if (a == 0xf1) {
    p->pause_music_ctr = 0;
    p->master_volume_fade_ticks = 0;
    if (p->some_volume_flag)
      return;
    p->some_volume_flag = HIBYTE(p->master_volume);
    HIBYTE(p->master_volume) = 0x70;
    goto handle_cmd_00;
  } else if (a == 0xf2) {
    if (p->some_volume_flag == 0)
      return;
    HIBYTE(p->master_volume) = p->some_volume_flag;
    p->some_volume_flag = 0;
    goto handle_cmd_00;
  } else if (a == 0xf0) HandleCmd_0xf0_PauseMusic: {
    p->key_OFF = p->is_chan_on ^ 0xff;
    p->base.port_to_snes[2] = 0;
    p->port_to_snes_b[2] = 0;
    p->cur_chan_bit = 0;
  } else if (a == 0xf3) {
    p->extra_tempo = 0;
less_0xf3:
    if (p->enable_some_randomstuff)
      Randomstuff_Disable(p);

    p->master_volume_fade_ticks = 0x90;
    p->pause_music_ctr = 0x90;
    p->master_volume_fade_target = 0;
    p->master_volume_fade_add_per_tick = SpcDivHelper(0 - (p->master_volume >> 8), 0x90);
    goto handle_cmd_00;
  } else if (sign8(a - 0xf3)) {
    goto less_0xf3;
  } else if (a < 0x19) {
    if (a != 18 && a != 13 && a != 17 && a != 20 && a >= 9 || a == 7) {
      p->extra_tempo = 0;
      if (p->enable_some_randomstuff)
        Randomstuff_Disable(p);
    }
    p->pause_music_ctr = 0;
    p->some_volume_flag = 0;
    p->base.port_to_snes[2] = a;
    t = WORD(p->ram[0xc000 + (a - 1) * 2]);
    if ((t >> 8) == 0) {
      p->base.port_to_snes[2] = 0;
      return;
    }
    p->music_ptr_toplevel = t;
    p->counter_sf0d = 2;
    p->key_OFF |= p->is_chan_on ^ 0xff;
  }
}


static void HandlePanAndSweep(SmasSpcPlayer *p, Channel *c) {
  p->did_affect_volumepitch_flag = 0;
  if (c->tremolo_depth) {
    c->tremolo_hold_count = c->tremolo_delay_ticks;
    HandleTremolo(p, c);
  }

  uint16 volume = c->pan_value;

  if (c->pan_num_ticks) {
    p->did_affect_volumepitch_flag = 0x80;
    volume += p->main_tempo_accum * (int16_t)c->pan_add_per_tick / 256;
  }

  if (p->did_affect_volumepitch_flag)
    WriteVolumeToDsp(p, c, volume);

  p->did_affect_volumepitch_flag = 0;
  uint16 pitch = c->pitch;
  if (c->pitch_slide_length && !c->pitch_slide_delay_left) {
    p->did_affect_volumepitch_flag |= 0x80;
    pitch += p->main_tempo_accum * (int16_t)c->pitch_add_per_tick / 256;
  }

  if (c->vib_depth && c->vibrato_delay_ticks == c->vibrato_hold_count) {
    CalcVibratoAddPitch(p, c, pitch, (p->main_tempo_accum * c->vibrato_rate >> 8) + c->vibrato_count);
    return;
  }

  if (p->did_affect_volumepitch_flag)
    WritePitch(p, c, pitch);
}

static void HandleTremolo(SmasSpcPlayer *p, Channel *c) {
  Not_Implemented();
}

static void CalcTremolo(SmasSpcPlayer *p, Channel *c) {
  Not_Implemented();
}

static void CalcFinalVolume(SmasSpcPlayer *p, Channel *c, uint8 vol) {
  int t = (p->master_volume >> 8) * vol >> 8;
  t = t * c->channel_volume_master >> 8;
  t = t * (c->channel_volume >> 8) >> 8;
  c->final_volume = t * t >> 8;
}

static void CalcVibratoAddPitch(SmasSpcPlayer *p, Channel *c, uint16 pitch, uint8 value) {
  int t = value << 2;
  t ^= (t & 0x100) ? 0xff : 0;
  int r = (c->vib_depth >= 0xf1) ?
    (uint8)t * (c->vib_depth & 0xf) :
    (uint8)t * c->vib_depth >> 8;
  WritePitch(p, c, pitch + (value & 0x80 ? -r : r));
}

static bool WantWriteKof(SmasSpcPlayer *p, Channel *c) {
  int loops = c->subroutine_num_loops;
  int ptr = c->pattern_cur_ptr;

  for (;;) {
    uint8 cmd = p->ram[ptr++];
    if (cmd == 0) {
      if (loops == 0)
        return true;
      ptr = (--loops == 0) ? c->saved_pattern_ptr : c->pattern_start_ptr;
    } else {
      while (!(cmd & 0x80))
        cmd = p->ram[ptr++];
      if (cmd == 0xc8)
        return false;
      if (cmd == 0xef) {
        ptr = p->ram[ptr + 0] | p->ram[ptr + 1] << 8;
      } else if (cmd >= 0xe0) {
        ptr += kEffectByteLength[cmd - 0xe0];
      } else {
        return true;
      }
    }
  }
}

static void HandleNoteTick(SmasSpcPlayer *p, Channel *c) {
  if (c->note_keyoff_ticks_left != 0 && (--c->note_keyoff_ticks_left == 0 || c->note_ticks_left == 2)) {
    if (WantWriteKof(p, c) && !(p->cur_chan_bit & p->is_chan_on))
      Dsp_Write(p, KOF, p->cur_chan_bit);
  }

  p->did_affect_volumepitch_flag = 0;
  if (c->pitch_slide_length) {
    if (c->pitch_slide_delay_left) {
      c->pitch_slide_delay_left--;
    } else if (!(p->is_chan_on & p->cur_chan_bit)) {
      p->did_affect_volumepitch_flag = 0x80;
      Chan_DoAnyFade(&c->pitch, c->pitch_add_per_tick, c->pitch_target, --c->pitch_slide_length);
    }
  }

  uint16 pitch = c->pitch;

  if (c->vib_depth) {
    if (c->vibrato_delay_ticks == c->vibrato_hold_count) {
      if (c->vibrato_change_count == c->vibrato_fade_num_ticks) {
        c->vib_depth = c->vibrato_depth_target;
      } else {
        c->vib_depth = (c->vibrato_change_count++ == 0 ? 0 : c->vib_depth) + c->vibrato_fade_add_per_tick;
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

static void Chan_HandleTick(SmasSpcPlayer *p, Channel *c) {
  if (c->volume_fade_ticks) {
    c->volume_fade_ticks--;
    p->vol_dirty |= p->cur_chan_bit;
    Chan_DoAnyFade(&c->channel_volume, c->volume_fade_addpertick, c->volume_fade_target, true);
  }
  if (c->tremolo_depth) {
    if (c->tremolo_delay_ticks == c->tremolo_hold_count) {
      p->vol_dirty |= p->cur_chan_bit;
      if (c->tremolo_count & 0x80 && c->tremolo_depth == 0xff) {
        c->tremolo_count = 0x80;
      } else {
        c->tremolo_count += c->tremolo_rate;
      }
      CalcTremolo(p, c);
    } else {
      c->tremolo_hold_count++;
      CalcFinalVolume(p, c, 0xff);
    }
  } else {
    CalcFinalVolume(p, c, 0xff);
  }

  if (c->pan_num_ticks) {
    c->pan_num_ticks--;
    p->vol_dirty |= p->cur_chan_bit;
    Chan_DoAnyFade(&c->pan_value, c->pan_add_per_tick, c->pan_target_value, true);
  }

  if (p->vol_dirty & p->cur_chan_bit)
    WriteVolumeToDsp(p, c, c->pan_value);
}

static void WriteVolumeToDsp(SmasSpcPlayer *p, Channel *c, uint16 volume) {
  static const uint8 kVolumeTable[22] = { 0, 1, 3, 7, 13, 21, 30, 41, 52, 66, 81, 94, 103, 110, 115, 119, 122, 124, 125, 126, 127, 127 };
  if (p->is_chan_on & p->cur_chan_bit)
    return;
  for (int i = 0; i < 2; i++) {
    int j = volume >> 8;
    uint8 t;
    t = kVolumeTable[j] + ((kVolumeTable[j + 1] - kVolumeTable[j]) * (uint8)volume >> 8);
    c->byte_250 = t;
    t = t * c->final_volume >> 8;
    if ((c->pan_flag_with_phase_invert << i) & 0x80)
      t = -t;
    Dsp_Write(p, V0VOLL + i + c->index * 16, t);
    volume = 0x1400 - volume;
  }
}

static void ComputePitchAdd(Channel *c, uint8 pitch) {
  c->pitch_target = pitch & 0x7f;
  c->pitch_add_per_tick = SpcDivHelper(c->pitch_target - (c->pitch >> 8), c->pitch_slide_length);
}


static void SmasSpcPlayer_Upload(SpcPlayer *p_in, const uint8_t *data) {
  SmasSpcPlayer *p = (SmasSpcPlayer *)p_in;
  Dsp_Write(p, EVOLL, 0);
  Dsp_Write(p, EVOLR, 0);
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
  p->pause_music_ctr = 0;
  p->base.port_to_snes[0] = 0;
  p->base.port_to_snes[1] = 0;
  p->base.port_to_snes[3] = 0;
  p->enable_some_randomstuff = 0;
  p->is_chan_on = 0;
  p->extra_tempo = 0;
  if (!p->var_3F8)
    p->base.port_to_snes[2] = 0;
  memset(p->base.input_ports, 0, sizeof(p->base.input_ports));
  memset(p->last_value_from_snes, 0, sizeof(p->last_value_from_snes));
  memset(p->new_value_from_snes, 0, sizeof(p->new_value_from_snes));
}

static void Channel_SetInstrument(SmasSpcPlayer *p, Channel *c, uint8 instrument) {
  c->instrument_id = instrument;
  if (instrument & 0x80)
    instrument = instrument + 54 + p->percussion_base_id;
  const uint8 *ip = p->ram + instrument * 6 + 0x3d00;
  if (p->is_chan_on & p->cur_chan_bit)
    return;
  uint8 reg = c->index * 16;
  if (ip[0] & 0x80) {
    // noise
    p->reg_FLG = (p->reg_FLG & 0x20) | ip[0] & 0x1f;
    p->reg_NON |= p->cur_chan_bit;
    Dsp_Write(p, reg + V0SRCN, 0);
  } else {
    Dsp_Write(p, reg + V0SRCN, ip[0]);
  }
  Dsp_Write(p, reg + V0ADSR1, ip[1]);
  Dsp_Write(p, reg + V0ADSR2, ip[2]);
  Dsp_Write(p, reg + V0GAIN, ip[3]);
  c->instrument_pitch_base = ip[4] << 8 | ip[5];
}

static void PitchSlideToNote_Check(SmasSpcPlayer *p, Channel *c) {
  if (c->pitch_slide_length || p->ram[c->pattern_cur_ptr] != 0xf9)
    return;

  if (p->cur_chan_bit & p->is_chan_on) {
    c->pattern_cur_ptr += 4;
    return;
  }
  c->pattern_cur_ptr++;
  c->pitch_slide_delay_left = p->ram[c->pattern_cur_ptr++];
  c->pitch_slide_length = p->ram[c->pattern_cur_ptr++];
  ComputePitchAdd(c, p->ram[c->pattern_cur_ptr++] + p->global_transposition + c->channel_transpositionb);
}

static void SetupEchoParameter_EDL(SmasSpcPlayer *p, uint8 a) {
  p->echo_parameter_EDL = a;
  if (a != p->last_written_edl) {
    a = (p->last_written_edl & 0xf) ^ 0xff;
    if (p->echo_stored_time & 0x80)
      a += p->echo_stored_time;
    p->echo_stored_time = a;

    Dsp_Write(p, EON, 0);
    Dsp_Write(p, EFB, 0);
    Dsp_Write(p, EVOLR, 0);
    Dsp_Write(p, EVOLL, 0);
    Dsp_Write(p, FLG, p->reg_FLG | 0x20);

    p->last_written_edl = p->echo_parameter_EDL;
    Dsp_Write(p, EDL, p->echo_parameter_EDL);
  }
  Dsp_Write(p, ESA, (p->echo_parameter_EDL * 8 ^ 0xff) + 0x3d);
}

static void HandleEffect(SmasSpcPlayer *p, Channel *c, uint8 effect) {
  uint8 arg = kEffectByteLength[effect - 0xe0] ? p->ram[c->pattern_cur_ptr++] : 0;

  switch (effect) {
  case 0xe0:
    Channel_SetInstrument(p, c, arg);
    break;
  case 0xe1:
    c->pan_flag_with_phase_invert = arg;
    c->pan_value = (arg & 0x1f) << 8;
    break;
  case 0xe2:
    c->pan_num_ticks = arg;
    c->pan_target_value = p->ram[c->pattern_cur_ptr++];
    c->pan_add_per_tick = SpcDivHelper(c->pan_target_value - (c->pan_value >> 8), arg);
    break;
  case 0xe3: // vibrato on
    c->vibrato_delay_ticks = arg;
    c->vibrato_rate = p->ram[c->pattern_cur_ptr++];
    c->vibrato_depth_target = c->vib_depth = p->ram[c->pattern_cur_ptr++];
    c->vibrato_fade_num_ticks = 0;
    break;
  case 0xe4: // vibrato off
    c->vibrato_depth_target = c->vib_depth = 0;
    c->vibrato_fade_num_ticks = 0;
    break;
  case 0xe5:
    if (!p->pause_music_ctr && !p->some_volume_flag)
      p->master_volume = arg << 8;
    break;
  case 0xe6:
    p->master_volume_fade_ticks = arg;
    p->master_volume_fade_target = p->ram[c->pattern_cur_ptr++];
    p->master_volume_fade_add_per_tick = SpcDivHelper(p->master_volume_fade_target - (p->master_volume >> 8), arg);
    break;
  case 0xe7:
    p->tempo = (p->extra_tempo + arg) << 8;
    break;
  case 0xe8:
    p->tempo_fade_num_ticks = arg;
    p->tempo_fade_final = p->ram[c->pattern_cur_ptr++];
    p->tempo_fade_add = SpcDivHelper(p->tempo_fade_final - (p->tempo >> 8), arg);
    break;
  case 0xe9:
    p->global_transposition = arg;
    break;
  case 0xea:
    c->channel_transpositiona = arg;
    if (!(p->is_chan_on & p->cur_chan_bit))
      c->channel_transpositionb = arg;
    break;
  case 0xeb:
    c->tremolo_delay_ticks = arg;
    c->tremolo_rate = p->ram[c->pattern_cur_ptr++];
    c->tremolo_depth = p->ram[c->pattern_cur_ptr++];
    break;
  case 0xec:
    c->tremolo_depth = 0;
    break;
  case 0xed:
    c->channel_volume = arg << 8;
    break;
  case 0xee:
    c->volume_fade_ticks = arg;
    c->volume_fade_target = p->ram[c->pattern_cur_ptr++];
    c->volume_fade_addpertick = SpcDivHelper(c->volume_fade_target - (c->channel_volume >> 8), arg);
    break;
  case 0xef:
    c->pattern_start_ptr = p->ram[c->pattern_cur_ptr++] << 8 | arg;
    c->subroutine_num_loops = p->ram[c->pattern_cur_ptr++];
    c->saved_pattern_ptr = c->pattern_cur_ptr;
    c->pattern_cur_ptr = c->pattern_start_ptr;
    break;
  case 0xf0:
    c->vibrato_fade_num_ticks = arg;
    c->vibrato_fade_add_per_tick = arg ? c->vib_depth / arg : 0xff;
    break;
  case 0xf1:
  case 0xf2:
  case 0xf3:
    assert(0);
    break;
  case 0xf4:
    c->fine_tuneb = arg;
    if (!(p->is_chan_on & p->cur_chan_bit))
      c->fine_tunea = arg;
    break;
  case 0xf5:
    p->reg_EON = p->echo_channels = arg;
    p->echo_volume_left = p->ram[c->pattern_cur_ptr++] << 8;
    p->echo_volume_right = p->ram[c->pattern_cur_ptr++] << 8;
    p->reg_FLG &= ~0x20;
    break;
  case 0xf6:  // echo off
    p->echo_volume_left = 0;
    p->echo_volume_right = 0;
    p->reg_FLG |= 0x20;
    break;
  case 0xf7: {
    static const int8_t kEchoFirParameters[] = {
      127, 0, 0, 0, 0, 0, 0, 0,
      88, -65, -37, -16, -2, 7, 12, 12,
      12, 33, 43, 43, 19, -2, -13, -7,
      52, 51, 0, -39, -27, 1, -4, -21,
    };
    SetupEchoParameter_EDL(p, arg);
    p->reg_EFB = p->ram[c->pattern_cur_ptr++];
    const int8_t *ep = kEchoFirParameters + p->ram[c->pattern_cur_ptr++] * 8;
    for (int i = 0; i < 8; i++)
      Dsp_Write(p, FIR0 + i * 16, *ep++);
    break;
  }
  case 0xf8:
    p->echo_volume_fade_ticks = arg;
    p->echo_volume_fade_target_left = p->ram[c->pattern_cur_ptr++];
    p->echo_volume_fade_target_right = p->ram[c->pattern_cur_ptr++];
    p->echo_volume_fade_add_left = SpcDivHelper(p->echo_volume_fade_target_left - (p->echo_volume_left >> 8), arg);
    p->echo_volume_fade_add_right = SpcDivHelper(p->echo_volume_fade_target_right - (p->echo_volume_right >> 8), arg);
    break;
  case 0xf9:
    if (p->is_chan_on & p->cur_chan_bit) {
      c->pattern_cur_ptr += 2;
    } else {
      c->pitch_slide_delay_left = arg;
      c->pitch_slide_length = p->ram[c->pattern_cur_ptr++];
      ComputePitchAdd(c, p->ram[c->pattern_cur_ptr++] + p->global_transposition + c->channel_transpositionb);
    }
    break;
  case 0xfa:
    p->percussion_base_id = arg;
    break;
  default:
    Not_Implemented();
  }
}

static void Sfx_TerminateSfx4(SmasSpcPlayer *p) {
  if (p->base.port_to_snes[0] == 17) {
    p->var_3F8 = 0xff;
    Dsp_Write(p, KOF, 0xff);
  }
  p->base.port_to_snes[0] = 0;
  p->port_to_snes_b[0] = 0;
  p->is_chan_on &= ~0x10;
  if (p->echo_channels & 0x10) {
    p->reg_EON |= 0x10;
    Dsp_Write(p, EON, p->reg_EON);
  }
  p->channel[4].pitch_slide_length = 0;
  p->channel[4].channel_transpositionb = p->channel[4].channel_transpositiona;
  p->channel[4].fine_tunea = p->channel[4].fine_tuneb;
  p->channel[4].pitch_envelope_num_ticksa = p->channel[4].pitch_envelope_num_ticksb;
  Channel_SetInstrument(p, &p->channel[4], p->channel[4].instrument_id);
}

static void Port0_HandleCmd(SmasSpcPlayer *p) {
  uint8 cmd;

  if (p->new_value_from_snes[0]) {
    p->port_to_snes_b[0] = p->new_value_from_snes[0];
    p->new_value_from_snes[0] &= 0x7f;
  }
  if (p->new_value_from_snes[0] == 0x43 || p->new_value_from_snes[0] == 0x12 ||
      p->new_value_from_snes[0] == 0x11 || 
      p->base.port_to_snes[0] != 0x11 && p->base.port_to_snes[0] != 0x1d) {

    if (p->new_value_from_snes[0] == 0x7f) {
      p->extra_tempo = 10;
      p->tempo = (HIBYTE(p->tempo) + 11) << 8;
      p->new_value_from_snes[3] = cmd = 0x1d;
      goto label_a;
    } else if (p->new_value_from_snes[0]) {
      cmd = p->new_value_from_snes[0];
      goto label_a;
    }
  }
  if (p->var_c)
    goto label_b;
  if (!p->base.port_to_snes[0])
    return;
  goto label_c;

label_a:
  p->base.port_to_snes[0] = cmd;
  if (p->var_3F8 && p->base.port_to_snes[0] == 18)
    p->var_3F8 = 0;
  p->var_c = 2;
  Dsp_Write(p, KOF, 0x10);
  p->is_chan_on |= 0x10;

  p->channel[4].pitch_envelope_num_ticksa = 0;
  p->channel[4].pitch_slide_length = 0;
  p->channel[4].fine_tunea = 0;
  p->channel[4].channel_transpositionb = 0;
  if (p->base.port_to_snes[0] == 0x3b || p->base.port_to_snes[0] == 0x43) {
    p->reg_EON &= ~0x10;
    Dsp_Write(p, EON, p->reg_EON);
  }
  return;

label_b:
  if (--p->var_c)
    return;
  goto is_ff;

label_c:
  if (--p->port0_note_length_left)
    goto note_continue;
  p->sfx_sound_ptr_cur++;

  for (;;) {
    cmd = p->ram[p->sfx_sound_ptr_cur];
    if (cmd == 0) {
      Sfx_TerminateSfx4(p);
      return;
    }

    if (!(cmd & 0x80)) {
      p->port0_note_length = cmd;
      cmd = p->ram[++p->sfx_sound_ptr_cur];
      if (!(cmd & 0x80)) {
        uint8 volume = cmd;
        Dsp_Write(p, V4VOLL, cmd);
        cmd = p->ram[++p->sfx_sound_ptr_cur];
        if (cmd & 0x80) {
          Dsp_Write(p, V4VOLR, volume);
        } else {
          Dsp_Write(p, V4VOLR, cmd);
          cmd = p->ram[++p->sfx_sound_ptr_cur];
        }
      }
    }

    if (cmd == 0xe0) {
      const uint8 *ip = p->ram + 0x166D + (p->ram[++p->sfx_sound_ptr_cur] * 9);
      Dsp_Write(p, V4VOLL, ip[0]);
      Dsp_Write(p, V4VOLR, ip[1]);
      Dsp_Write(p, V4PL, ip[2]);
      Dsp_Write(p, V4PH, ip[3]);
      Dsp_Write(p, V4SRCN, ip[4]);
      Dsp_Write(p, V4ADSR1, ip[5]);
      Dsp_Write(p, V4ADSR2, ip[6]);
      Dsp_Write(p, V4GAIN, ip[7]);
      p->channel[4].instrument_pitch_base = ip[8] << 8;
      p->sfx_sound_ptr_cur++;
    } else if (cmd == 0xf1 || cmd == 0xf9) {
      if (cmd == 0xf9) {
        PlayNote(p, &p->channel[4], p->ram[++p->sfx_sound_ptr_cur]);
        Write_KeyOn(p, 0x10);
      }
      p->channel[4].pitch_slide_delay_left = p->ram[++p->sfx_sound_ptr_cur];
      p->channel[4].pitch_slide_length = p->ram[++p->sfx_sound_ptr_cur];
      ComputePitchAdd(&p->channel[4], p->ram[++p->sfx_sound_ptr_cur]);
      p->port0_note_length_left = p->port0_note_length;
      goto note_continue;
    } else if (cmd == 0xff) {
is_ff:
      p->sfx_sound_ptr_cur = WORD(p->ram[0x17D8 + (p->base.port_to_snes[0] - 1) * 2]);
    } else {
      PlayNote(p, &p->channel[4], cmd);
      Write_KeyOn(p, 0x10);

      p->port0_note_length_left = p->port0_note_length;
note_continue:
      p->did_affect_volumepitch_flag = 0;
      if (p->channel[4].pitch_slide_length) {
        Chan_DoAnyFade(&p->channel[4].pitch, p->channel[4].pitch_add_per_tick,
                       p->channel[4].pitch_target, --p->channel[4].pitch_slide_length);
        p->cur_chan_bit = 0;
        WritePitch(p, &p->channel[4], p->channel[4].pitch);
      } else if (p->port0_note_length_left == 2) {
        Dsp_Write(p, KOF, 0x10);
      }
      break;
    }
  }
}

static void Sfx_TerminateSfx6(SmasSpcPlayer *p) {
  p->base.port_to_snes[3] = 0;
  p->port_to_snes_b[3] = 0;
  p->is_chan_on &= ~0x40;
  p->reg_NON = 0;
  Dsp_Write(p, NON, 0);
  p->channel[6].pitch_slide_length = 0;
  p->channel[6].channel_transpositionb = p->channel[6].channel_transpositiona;
  p->channel[6].fine_tunea = p->channel[6].fine_tuneb;
  p->channel[6].pitch_envelope_num_ticksa = p->channel[6].pitch_envelope_num_ticksb;
  Channel_SetInstrument(p, &p->channel[6], p->channel[6].instrument_id);
}

static void Port3_HandleCmd(SmasSpcPlayer *p) {
  uint8 cmd;

  if (p->new_value_from_snes[3]) {
    p->port_to_snes_b[3] = p->new_value_from_snes[3];
    p->new_value_from_snes[3] &= 0x7f;
  }

  if (p->base.port_to_snes[3] == 29 ||
      (p->new_value_from_snes[3] != 5 && p->base.port_to_snes[3] == 5) ||
      p->new_value_from_snes[3] == 0) {

    if (p->port3_timeout)
      goto label_b;
    if (p->base.port_to_snes[3])
      goto label_c; 
    return;
  }

  p->base.port_to_snes[3] = p->new_value_from_snes[3];
  p->port3_timeout = 2;
  Dsp_Write(p, KOF, 0x40);
  p->is_chan_on |= 0x40;
  p->channel[6].pitch_envelope_num_ticksa = 0;
  p->channel[6].pitch_slide_length = 0;
  p->channel[6].fine_tunea = 0;
  p->channel[6].channel_transpositionb = 0;
  return;

label_b:
  if (--p->port3_timeout)
    return;
  p->port3_cur_ptr = WORD(p->ram[0x173c + (p->base.port_to_snes[3] - 1) * 2]);
  goto lbl_begin;


label_c:
  if (--p->port3_timer2)
    goto note_continue;
  p->port3_cur_ptr++;

lbl_begin:
  for (;;) {
    cmd = p->ram[p->port3_cur_ptr];
    if (cmd == 0) {
      Sfx_TerminateSfx6(p);
      return;
    }

    if (!(cmd & 0x80)) {
      p->port3_note_length = cmd;
      cmd = p->ram[++p->port3_cur_ptr];
      if (!(cmd & 0x80)) {
        uint8 volume = cmd;
        Dsp_Write(p, V6VOLL, cmd);
        cmd = p->ram[++p->port3_cur_ptr];
        if (cmd & 0x80) {
          Dsp_Write(p, V6VOLR, volume);
        } else {
          Dsp_Write(p, V6VOLR, cmd);
          cmd = p->ram[++p->port3_cur_ptr];
        }
      }
    }

    if (cmd == 0xe0) {
      p->reg_NON = 0;
      Dsp_Write(p, NON, 0);
      while ((cmd = p->ram[++p->port3_cur_ptr]) & 0x80) {
        p->reg_FLG = (p->reg_FLG & 0x20) | (cmd & 0x1f);
        Dsp_Write(p, FLG, p->reg_FLG);
        p->reg_NON = 0x40;
        Dsp_Write(p, NON, p->reg_NON);
      }
      const uint8 *ip = p->ram + 0x166D + (cmd * 9);
      Dsp_Write(p, V6VOLL, ip[0]);
      Dsp_Write(p, V6VOLR, ip[1]);
      Dsp_Write(p, V6PL, ip[2]);
      Dsp_Write(p, V6PH, ip[3]);
      Dsp_Write(p, V6SRCN, ip[4]);
      Dsp_Write(p, V6ADSR1, ip[5]);
      Dsp_Write(p, V6ADSR2, ip[6]);
      Dsp_Write(p, V6GAIN, ip[7]);
      p->channel[6].instrument_pitch_base = ip[8] << 8;
      p->port3_cur_ptr++;
    } else if (cmd == 0xf1 || cmd == 0xf9) {
      if (cmd == 0xf9) {
        PlayNote(p, &p->channel[6], p->ram[++p->port3_cur_ptr]);
        Write_KeyOn(p, 0x40);
      }
      p->channel[6].pitch_slide_delay_left = p->ram[++p->port3_cur_ptr];
      p->channel[6].pitch_slide_length = p->ram[++p->port3_cur_ptr];
      ComputePitchAdd(&p->channel[6], p->ram[++p->port3_cur_ptr]);
      p->port3_timer2 = p->port3_note_length;
      goto note_continue;
    } else if (cmd == 0xff) {
      p->port3_cur_ptr--;
    } else {
      PlayNote(p, &p->channel[6], cmd);
      Write_KeyOn(p, 0x40);
      p->port3_timer2 = p->port3_note_length;
note_continue:
      p->did_affect_volumepitch_flag = 0;
      if (p->channel[6].pitch_slide_length) {
        Chan_DoAnyFade(&p->channel[6].pitch, p->channel[6].pitch_add_per_tick,
          p->channel[6].pitch_target, --p->channel[6].pitch_slide_length);
        p->cur_chan_bit = 0;
        WritePitch(p, &p->channel[6], p->channel[6].pitch);
      } else if (p->port3_timer2 == 2) {
        Dsp_Write(p, KOF, 0x40);
      }
      break;
    }
  }
}

static void Chan5_SetInstrumentB(SmasSpcPlayer *p) {
  Dsp_Write(p, V5SRCN, 0x20);
  Dsp_Write(p, V5ADSR1, 0);
  Dsp_Write(p, V5ADSR2, 0);
  Dsp_Write(p, V5GAIN, 0xe8);
  p->channel[5].instrument_pitch_base = 0x400;
}

static void Randomstuff_Disable(SmasSpcPlayer *p) {
  Dsp_Write(p, KOF, 0x20);
  if (p->echo_channels & 0x20) {
    p->reg_EON |= 0x20;
    Dsp_Write(p, EON, 0x20);
  }
  p->enable_some_randomstuff = 0;
  p->is_chan_on &= ~0x20;
  Channel_SetInstrument(p, &p->channel[5], p->channel[5].instrument_id);
  p->chan5_var27 = 0;
  p->channel[5].pitch_slide_length = 0;
  p->channel[5].fine_tunea = p->channel[5].fine_tuneb;
  p->channel[5].pitch_envelope_num_ticksa = p->channel[5].pitch_envelope_num_ticksb;
  p->channel[5].channel_transpositionb = p->channel[5].channel_transpositiona;
}

static void Port1_FuncA(SmasSpcPlayer *p) {
  if (p->chan5_var25 == 0x10) {
    p->enable_some_randomstuff = 0x10;
    p->chan5_var27 = 3;
    Dsp_Write(p, KOF, 0x20);
    p->is_chan_on |= 0x20;
    p->channel[5].pitch_envelope_num_ticksa = 0;
    p->channel[5].pitch_slide_length = 0;
    p->channel[5].fine_tunea = 0;
    p->channel[5].channel_transpositionb = 0;
  } else if (p->chan5_var25 == 0x20) {
    Randomstuff_Disable(p);
  } else if (p->chan5_var27) {
    if (--p->chan5_var27)
      return;
    Chan5_SetInstrumentB(p);
    Write_KeyOn(p, 0x20);
    p->reg_EON &= ~0x20;
    Dsp_Write(p, EON, p->reg_EON);
    p->channel[5].pitch_slide_length = 1;
    p->channel[5].pitch_slide_delay_left = 0;
    ComputePitchAdd(&p->channel[5], 0xa4);
  } else if (p->enable_some_randomstuff == 0x10) {
    p->did_affect_volumepitch_flag = 0;
    if (p->channel[5].pitch_slide_length) {
      Chan_DoAnyFade(&p->channel[5].pitch, p->channel[5].pitch_add_per_tick,
          p->channel[5].pitch_target, --p->channel[5].pitch_slide_length);
      p->cur_chan_bit = 0;
      WritePitch(p, &p->channel[5], p->channel[5].pitch);
      uint8 vol = p->some_volume_flag ? 10 : 24;
      Dsp_Write(p, V5VOLL, vol);
      Dsp_Write(p, V5VOLR, vol);
    } else {
      p->channel[5].pitch_slide_length = 0x80;
      p->channel[5].pitch_slide_delay_left = 0;
      ComputePitchAdd(&p->channel[5], 0xa4 + (p->lfsr_value & 3));
    }
  }
}

static void Chan7_WriteInstrumentData(SmasSpcPlayer *p, uint8 a) {
  const uint8 *ip = p->ram + 0x166D + (a * 9);
  Dsp_Write(p, V7VOLL, ip[0]);
  Dsp_Write(p, V7VOLR, ip[1]);
  Dsp_Write(p, V7PL, ip[2]);
  Dsp_Write(p, V7PH, ip[3]);
  Dsp_Write(p, V7SRCN, ip[4]);
  Dsp_Write(p, V7ADSR1, ip[5]);
  Dsp_Write(p, V7ADSR2, ip[6]);
  Dsp_Write(p, V7GAIN, ip[7]);
  p->channel[7].instrument_pitch_base = ip[8] << 8;
}

static void Port1_HandleCmd(SmasSpcPlayer *p) {
  if (p->new_value_from_snes[1] == 0xff) {
    assert(0);
    return;
  } else if (p->new_value_from_snes[1] == 0xf0) {
    assert(0);
    return;
  }
  p->chan5_var25 = p->new_value_from_snes[1] & 0xf0;
  p->new_value_from_snes[1] &= 0xf;

  if (p->new_value_from_snes[1] == 1) {
    p->base.port_to_snes[1] = 1;
    p->chan7_timer = 4;
    Dsp_Write(p, KOF, 0x80);
    p->is_chan_on |= 0x80;
    p->channel[7].pitch_envelope_num_ticksa = 0;
    p->channel[7].pitch_slide_length = 0;
    p->channel[7].fine_tunea = 0;
    p->channel[7].channel_transpositionb = 0;
  } else if (p->base.port_to_snes[1] != 1 && p->new_value_from_snes[1] == 4) {
    p->base.port_to_snes[1] = 4;
    p->chan7_timer = 2;
    Dsp_Write(p, KOF, 0x80);
    p->is_chan_on |= 0x80;
    p->channel[7].pitch_envelope_num_ticksa = 0;
    p->channel[7].pitch_slide_length = 0;
    p->channel[7].channel_transpositionb = 0;
    p->channel[7].fine_tunea = 0;
  } else if (p->base.port_to_snes[1] == 1) {
    if (p->chan7_timer) {
      if (--p->chan7_timer)
        return;
      p->some_timer = 48;
      Chan7_WriteInstrumentData(p, 8);
      PlayNote(p, &p->channel[7], 0xb2);
      p->channel[7].pitch_slide_delay_left = 0;
      p->channel[7].pitch_slide_length = 5;
      ComputePitchAdd(&p->channel[7], 0xb5);
      Dsp_Write(p, V7VOLL, 0x38);
      Dsp_Write(p, V7VOLR, 0x38);
      Write_KeyOn(p, 0x80);
    } else if (--p->some_timer) {
      if (p->some_timer == 42) {
        p->channel[7].pitch_slide_delay_left = 0;
        p->channel[7].pitch_slide_length = 18;
        ComputePitchAdd(&p->channel[7], 0xb9);
      }
    } else {
      p->base.port_to_snes[1] = 0;
      p->is_chan_on &= ~0x80;
      p->channel[7].pitch_slide_length = 0;
      p->channel[7].channel_transpositionb = p->channel[7].channel_transpositiona;
      p->channel[7].fine_tunea = p->channel[7].fine_tuneb;
      p->channel[7].pitch_envelope_num_ticksa = p->channel[7].pitch_envelope_num_ticksb;
      Channel_SetInstrument(p, &p->channel[7], p->channel[7].instrument_id);
      return;
    }
    if (p->some_timer == 2)
      Dsp_Write(p, KOF, 0x80);
    p->did_affect_volumepitch_flag = 0;
    if (p->channel[7].pitch_slide_length) {
      Chan_DoAnyFade(&p->channel[7].pitch, p->channel[7].pitch_add_per_tick,
        p->channel[7].pitch_target, --p->channel[7].pitch_slide_length);
      p->cur_chan_bit = 0;
      WritePitch(p, &p->channel[7], p->channel[7].pitch);
    }
  } else if (p->base.port_to_snes[1] == 4) {
    Chan7_Func1605(p);
  }
}

static void Chan7_Func1605(SmasSpcPlayer *p) {
  static const uint8 kChan7Notes[] = {0xB7, 0xB5, 0xB8, 0xB5, 0x70 };
  if (p->chan7_timer != 0) {
    if (!--p->chan7_timer) {
      p->chan7_note_index = 5;
      p->some_timer = 1;
      Chan7_WriteInstrumentData(p, 1);
    }
    return;
  }

  if (--p->some_timer == 0) {
    p->some_timer = 4;
    if (--p->chan7_note_index != 0) {
      PlayNote(p, &p->channel[7], kChan7Notes[p->chan7_note_index]);
      Dsp_Write(p, V7VOLL, 20);
      Dsp_Write(p, V7VOLR, 20);
      Write_KeyOn(p, 0x80);
    } else {
      p->base.port_to_snes[1] = 0;
      p->is_chan_on &= ~0x80;
      p->channel[7].pitch_slide_length = 0;
      p->channel[7].channel_transpositionb = p->channel[7].channel_transpositiona;
      p->channel[7].fine_tunea = p->channel[7].fine_tuneb;
      p->channel[7].pitch_envelope_num_ticksa = p->channel[7].pitch_envelope_num_ticksb;
      Channel_SetInstrument(p, &p->channel[7], p->channel[7].instrument_id);
    }
  }
  if (p->some_timer == 2)
    Dsp_Write(p, KOF, 0x80);
}

static void SmasSpcPlayer_Initialize(SpcPlayer *p_in) {
  SmasSpcPlayer *p = (SmasSpcPlayer *)p_in;
  dsp_reset(p->base.dsp);
  Spc_Reset(p);
  Spc_Loop_Part1(p);
}

static void SmasSpcPlayer_GenerateSamples(SpcPlayer *p_in) {
  SmasSpcPlayer *p = (SmasSpcPlayer *)p_in;
  assert(p->timer_cycles <= 64);
  assert(p->base.dsp->sampleOffset <= 534);

  for (;;) {
    if (p->timer_cycles >= 64) {
      Spc_Loop_Part2(p, p->timer_cycles >> 6);
      Spc_Loop_Part1(p);
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

SpcPlayer *SmasSpcPlayer_Create(void) {
  SmasSpcPlayer *p = (SmasSpcPlayer *)malloc(sizeof(SmasSpcPlayer));
  memset(p, 0, sizeof(SmasSpcPlayer));
  p->base.dsp = dsp_init(p->ram);
  p->base.ram = p->ram;
  p->base.initialize = &SmasSpcPlayer_Initialize;
  p->base.gen_samples = &SmasSpcPlayer_GenerateSamples;
  p->base.upload = &SmasSpcPlayer_Upload;
  p->base.copy_vars = &SmasSpcPlayer_CopyVariables;
  p->reg_write_history = 0;
  return &p->base;
}


// =======================================
#define WITH_SPC_PLAYER_DEBUGGING 0
#if WITH_SPC_PLAYER_DEBUGGING

#include <SDL.h>

static DspRegWriteHistory my_write_hist;
static SmasSpcPlayer my_spc_snapshot;
static int loop_ctr;

bool CompareSpcImpls(SmasSpcPlayer *p, SmasSpcPlayer *p_org, Apu *apu) {
  SmasSpcPlayer_CopyVariablesToRam(p);
  memcpy(p->ram + 0x120, apu->ram + 0x120, 256 - 32);  // stack
  memcpy(p->ram + 0xf1, apu->ram + 0xf1, 15);  // dsp regs
  memcpy(p->ram + 0x10, apu->ram + 0x10, 8);  // temp regs
  memcpy(p->ram + 0x44, apu->ram + 0x44, 1);  // chn
  p->ram[0x46] = apu->ram[0x46]; // chn
  int errs = 0;
  static const uint16 ranges[][2] = {
    {0x0, 0x500},
    {0x1500, 0x2c00},
    {0x3c00, 0xffff},
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
  if (SDL_Init(SDL_INIT_AUDIO) != 0) {
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
  if (device == 0) {
    printf("Failed to open audio device: %s\n", SDL_GetError());
    return;
  }
  int16_t *audioBuffer = (int16_t *)malloc(735 * 4); // *2 for stereo, *2 for sizeof(int16)
  SDL_PauseAudioDevice(device, 0);

  SmasSpcPlayer *p = (SmasSpcPlayer *)SmasSpcPlayer_Create();

  FILE *f = fopen("d:/code/smw/smb1_dis/audio.spc", "rb");
  fread(p->ram, 1, 65536, f);
  fclose(f);

  p->reg_write_history = &my_write_hist;

  bool run_both = 1;

  if (!run_both) {
    SmasSpcPlayer_Initialize(&p->base);

    p->base.input_ports[0] = 4;

    for (;;) {
      SmasSpcPlayer_GenerateSamples(&p->base);

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
    int tgt = 0x57b;
    uint8 ticks_next = 0;
    bool apu_debug = 0;
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

//      if (apu->spc->pc == 0x14c1) {
//        apu_debug = 1;
//      }

      if (apu->spc->pc == tgt) {
        tgt ^= 0x57B ^ 0x57C;
        if (tgt == 0x57B) {
          uint8 ticks = ticks_next;
          ticks_next = apu->spc->y;
          my_spc_snapshot = *p;
          for (;;) {
            my_write_hist.count = 0;
            if (is_initialize) {
              SmasSpcPlayer_Initialize(&p->base);
            } else {
              Spc_Loop_Part2(p, ticks);
              Spc_Loop_Part1(p);
            }
            if (CompareSpcImpls(p, &my_spc_snapshot, apu))
              break;
            *p = my_spc_snapshot;
          }
          is_initialize = false;

          if (cycle_counter == 0)
            apu->inPorts[2] = p->base.input_ports[2] = 15;
          if (cycle_counter == 10000)
            apu->inPorts[0] = p->base.input_ports[0] = 0x7f;
//          if (cycle_counter == 2000)
//            apu->inPorts[3] = p->base.input_ports[3] = cycle_counter / 500;
          if (cycle_counter % 1000 == 0)
            apu->inPorts[3] = p->base.input_ports[3] = cycle_counter / 1000 + 1;
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
