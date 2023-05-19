#include <stddef.h>
typedef struct Channel {
  uint16 pattern_order_ptr_for_chan;
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
  uint8 pitch_envelope_num_ticks;
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
  uint8 channel_transposition;
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
  uint8 fine_tune;
  uint8 cutk;
} Channel;
typedef struct SfxRegs {
  uint8 priority;
  uint8 chan_idx_x2;
  uint16 chan_voice_bitset_ptr;
  uint8 cur_sound;
  uint16 chan_voice_mask_ptr;
  uint16 chan_voice_index_ptr;
  uint8 current_sound;
  uint8 some_value;
  uint16 cur_ptr;
  uint8 enabled_voices;
  uint8 voices_to_setup;
  uint8 chan_idx;
  uint8 voices_remaining;
  uint8 cur_sound_index;
  uint8 voice_id;
  uint8 init_flag;
  uint16 chan_voice_index;
  uint8 voice_index;
} SfxRegs;
typedef struct SfxChan {
  uint8 voice_bitset;
  uint8 instr_timer;
  uint8 subnote;
  uint8 repeat_pt;
  uint8 note;
  uint8 ptr_idx;
  uint8 voice_index;
  uint8 phase_setting;
  uint8 voice_index_mult8;
  uint8 release_timer;
  uint8 phase_options;
  uint8 volume;
  uint8 target_node;
  uint8 phase_invert;
  uint8 instr_timers;
  uint16 ptr;
  uint8 ptr_index;
  uint8 repeat_ctr;
  uint8 enable_pitch_slide;
  uint8 release_flag;
  uint8 enable_pitch_slide_legato;
  uint16 adsr_settings;
  uint8 channel_mask;
  uint8 legato;
  uint8 disable;
  uint8 target_note;
  uint8 subnote_delta;
  uint8 update_adsr;
} SfxChan;
struct SpcPlayer {
  uint8 new_value_from_snes[4];
  uint8 port_to_snes[4];
  uint8 last_value_from_snes[4];
  uint16 counter_sf0c;
  uint16 always_zero;
  uint16 temp_accum;
  uint8 ttt;
  uint8 did_affect_volumepitch_flag;
  uint16 addr0;
  uint16 addr1;
  uint16 lfsr_value;
  uint8 is_chan_on;
  uint8 fast_forward;
  uint16 word_20;
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
  uint16 p_echoBuffer;
  uint16 memset_ptr;
  uint8 memset_ctr;
  uint8 disable_sfx2;
  uint8 byte_4B1;
  Channel channel[8];
  uint8 ram[65536]; // rest of ram
  uint8 last_written_edl;
  uint8 input_ports[4];
};
struct MemMap {
uint16 off, org_off;
};
struct MemMap2 {
uint16 off, org_off, size;
};
const MemMap kChannel_Maps[] = {
{offsetof(Channel, pattern_order_ptr_for_chan), 0x8030},
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
{offsetof(Channel, pitch_envelope_num_ticks), 0x280},
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
{offsetof(Channel, channel_transposition), 0x2f0},
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
{offsetof(Channel, fine_tune), 0x381},
{offsetof(Channel, cutk), 0x400},
};
const MemMap2 kSpcPlayer_Maps[] = {
{offsetof(SpcPlayer, new_value_from_snes), 0x0, 4},
{offsetof(SpcPlayer, port_to_snes), 0x4, 4},
{offsetof(SpcPlayer, last_value_from_snes), 0x8, 4},
{offsetof(SpcPlayer, counter_sf0c), 0xc, 2},
{offsetof(SpcPlayer, always_zero), 0xe, 2},
{offsetof(SpcPlayer, temp_accum), 0x10, 2},
{offsetof(SpcPlayer, ttt), 0x12, 1},
{offsetof(SpcPlayer, did_affect_volumepitch_flag), 0x13, 1},
{offsetof(SpcPlayer, addr0), 0x14, 2},
{offsetof(SpcPlayer, addr1), 0x16, 2},
{offsetof(SpcPlayer, lfsr_value), 0x18, 2},
{offsetof(SpcPlayer, is_chan_on), 0x1a, 1},
{offsetof(SpcPlayer, fast_forward), 0x1b, 1},
{offsetof(SpcPlayer, word_20), 0x20, 2},
{offsetof(SpcPlayer, sfx1.cur_ptr), 0x22, 2},
{offsetof(SpcPlayer, sfx1.chan_voice_bitset_ptr), 0x24, 2},
{offsetof(SpcPlayer, sfx1.chan_voice_mask_ptr), 0x26, 2},
{offsetof(SpcPlayer, sfx1.chan_voice_index), 0x28, 2},
{offsetof(SpcPlayer, sfx_chans_1[0].ptr), 0x2a, 2},
{offsetof(SpcPlayer, sfx_chans_1[1].ptr), 0x2c, 2},
{offsetof(SpcPlayer, sfx_chans_1[2].ptr), 0x2e, 2},
{offsetof(SpcPlayer, music_ptr_toplevel), 0x40, 2},
{offsetof(SpcPlayer, block_count), 0x42, 1},
{offsetof(SpcPlayer, sfx_timer_accum), 0x43, 1},
{offsetof(SpcPlayer, chn), 0x44, 1},
{offsetof(SpcPlayer, key_ON), 0x45, 1},
{offsetof(SpcPlayer, key_OFF), 0x46, 1},
{offsetof(SpcPlayer, cur_chan_bit), 0x47, 1},
{offsetof(SpcPlayer, reg_FLG), 0x48, 1},
{offsetof(SpcPlayer, reg_NON), 0x49, 1},
{offsetof(SpcPlayer, reg_EON), 0x4a, 1},
{offsetof(SpcPlayer, echo_stored_time), 0x4c, 1},
{offsetof(SpcPlayer, echo_parameter_EDL), 0x4d, 1},
{offsetof(SpcPlayer, reg_EFB), 0x4e, 1},
{offsetof(SpcPlayer, global_transposition), 0x50, 1},
{offsetof(SpcPlayer, main_tempo_accum), 0x51, 1},
{offsetof(SpcPlayer, tempo), 0x52, 2},
{offsetof(SpcPlayer, tempo_fade_num_ticks), 0x54, 1},
{offsetof(SpcPlayer, tempo_fade_final), 0x55, 1},
{offsetof(SpcPlayer, tempo_fade_add), 0x56, 2},
{offsetof(SpcPlayer, master_volume), 0x58, 2},
{offsetof(SpcPlayer, master_volume_fade_ticks), 0x5a, 1},
{offsetof(SpcPlayer, master_volume_fade_target), 0x5b, 1},
{offsetof(SpcPlayer, master_volume_fade_add_per_tick), 0x5c, 2},
{offsetof(SpcPlayer, vol_dirty), 0x5e, 1},
{offsetof(SpcPlayer, percussion_base_id), 0x5f, 1},
{offsetof(SpcPlayer, echo_volume_left), 0x60, 2},
{offsetof(SpcPlayer, echo_volume_right), 0x62, 2},
{offsetof(SpcPlayer, echo_volume_fade_add_left), 0x64, 2},
{offsetof(SpcPlayer, echo_volume_fade_add_right), 0x66, 2},
{offsetof(SpcPlayer, echo_volume_fade_ticks), 0x68, 1},
{offsetof(SpcPlayer, echo_volume_fade_target_left), 0x69, 1},
{offsetof(SpcPlayer, echo_volume_fade_target_right), 0x6a, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].ptr), 0xd0, 2},
{offsetof(SpcPlayer, p_echoBuffer), 0xd2, 2},
{offsetof(SpcPlayer, sfx2.cur_ptr), 0xd4, 2},
{offsetof(SpcPlayer, sfx2.chan_voice_bitset_ptr), 0xd6, 2},
{offsetof(SpcPlayer, sfx2.chan_voice_mask_ptr), 0xd8, 2},
{offsetof(SpcPlayer, sfx2.chan_voice_index_ptr), 0xda, 2},
{offsetof(SpcPlayer, sfx_chans_2[0].ptr), 0xdc, 2},
{offsetof(SpcPlayer, sfx_chans_2[1].ptr), 0xde, 2},
{offsetof(SpcPlayer, sfx3.cur_ptr), 0xe0, 2},
{offsetof(SpcPlayer, sfx3.chan_voice_bitset_ptr), 0xe2, 2},
{offsetof(SpcPlayer, sfx3.chan_voice_mask_ptr), 0xe4, 2},
{offsetof(SpcPlayer, sfx3.chan_voice_index_ptr), 0xe6, 2},
{offsetof(SpcPlayer, sfx_chans_3[0].ptr), 0xe8, 2},
{offsetof(SpcPlayer, sfx_chans_3[1].ptr), 0xea, 2},
{offsetof(SpcPlayer, memset_ptr), 0xee, 2},
{offsetof(SpcPlayer, memset_ctr), 0x390, 1},
{offsetof(SpcPlayer, sfx1.cur_sound), 0x392, 1},
{offsetof(SpcPlayer, sfx1.cur_sound_index), 0x393, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].ptr_idx), 0x394, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].ptr_idx), 0x395, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].ptr_idx), 0x396, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].ptr_idx), 0x397, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].instr_timer), 0x398, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].instr_timer), 0x399, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].instr_timer), 0x39a, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].instr_timer), 0x39b, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].disable), 0x39c, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].disable), 0x39d, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].disable), 0x39e, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].disable), 0x39f, 1},
{offsetof(SpcPlayer, sfx1.chan_idx), 0x3a0, 1},
{offsetof(SpcPlayer, sfx1.voices_to_setup), 0x3a1, 1},
{offsetof(SpcPlayer, sfx1.voice_index), 0x3a2, 1},
{offsetof(SpcPlayer, sfx1.voices_remaining), 0x3a3, 1},
{offsetof(SpcPlayer, sfx1.init_flag), 0x3a4, 1},
{offsetof(SpcPlayer, sfx1.voice_id), 0x3a5, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].voice_bitset), 0x3a6, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].voice_bitset), 0x3a7, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].voice_bitset), 0x3a8, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].voice_bitset), 0x3a9, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].channel_mask), 0x3aa, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].channel_mask), 0x3ab, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].channel_mask), 0x3ac, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].channel_mask), 0x3ad, 1},
{offsetof(SpcPlayer, sfx1.chan_idx_x2), 0x3ae, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].voice_index), 0x3af, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].voice_index), 0x3b0, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].voice_index), 0x3b1, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].voice_index), 0x3b2, 1},
{offsetof(SpcPlayer, sfx1.enabled_voices), 0x3b3, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].voice_index_mult8), 0x3b4, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].voice_index_mult8), 0x3b5, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].voice_index_mult8), 0x3b6, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].voice_index_mult8), 0x3b7, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].volume), 0x3b8, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].phase_options), 0x3b9, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].volume), 0x3ba, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].phase_options), 0x3bb, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].volume), 0x3bc, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].phase_options), 0x3bd, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].volume), 0x3be, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].phase_options), 0x3bf, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].release_flag), 0x3c0, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].release_timer), 0x3c1, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].release_flag), 0x3c2, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].release_timer), 0x3c3, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].release_flag), 0x3c4, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].release_timer), 0x3c5, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].release_flag), 0x3c6, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].release_timer), 0x3c7, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].repeat_ctr), 0x3c8, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].repeat_ctr), 0x3c9, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].repeat_ctr), 0x3ca, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].repeat_ctr), 0x3cb, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].repeat_pt), 0x3cc, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].repeat_pt), 0x3cd, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].repeat_pt), 0x3ce, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].repeat_pt), 0x3cf, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].adsr_settings), 0x3d0, 2},
{offsetof(SpcPlayer, sfx_chans_1[1].adsr_settings), 0x3d2, 2},
{offsetof(SpcPlayer, sfx_chans_1[2].adsr_settings), 0x3d4, 2},
{offsetof(SpcPlayer, sfx_chans_1[3].adsr_settings), 0x3d6, 2},
{offsetof(SpcPlayer, sfx_chans_1[0].update_adsr), 0x3d8, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].update_adsr), 0x3d9, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].update_adsr), 0x3da, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].update_adsr), 0x3db, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].note), 0x3dc, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].subnote), 0x3dd, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].subnote_delta), 0x3de, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].target_note), 0x3df, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].enable_pitch_slide), 0x3e0, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].legato), 0x3e1, 1},
{offsetof(SpcPlayer, sfx_chans_1[0].enable_pitch_slide_legato), 0x3e2, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].note), 0x3e3, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].subnote), 0x3e4, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].subnote_delta), 0x3e5, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].target_note), 0x3e6, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].enable_pitch_slide), 0x3e7, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].legato), 0x3e8, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].enable_pitch_slide_legato), 0x3e9, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].note), 0x3ea, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].subnote), 0x3eb, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].subnote_delta), 0x3ec, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].target_node), 0x3ed, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].enable_pitch_slide), 0x3ee, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].legato), 0x3ef, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].enable_pitch_slide_legato), 0x3f0, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].note), 0x3f1, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].subnote), 0x3f2, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].subnote_delta), 0x3f3, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].target_note), 0x3f4, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].enable_pitch_slide), 0x3f5, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].legato), 0x3f6, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].enable_pitch_slide_legato), 0x3f7, 1},
{offsetof(SpcPlayer, sfx2.current_sound), 0x3f8, 1},
{offsetof(SpcPlayer, sfx2.cur_sound_index), 0x3f9, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].ptr_idx), 0x3fa, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].ptr_index), 0x3fb, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].instr_timers), 0x3fc, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].instr_timers), 0x3fd, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].disable), 0x3fe, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].disable), 0x3ff, 1},
{offsetof(SpcPlayer, sfx2.chan_idx), 0x440, 1},
{offsetof(SpcPlayer, sfx2.voices_to_setup), 0x441, 1},
{offsetof(SpcPlayer, sfx2.voice_index), 0x442, 1},
{offsetof(SpcPlayer, sfx2.voices_remaining), 0x443, 1},
{offsetof(SpcPlayer, sfx2.init_flag), 0x444, 1},
{offsetof(SpcPlayer, sfx2.voice_id), 0x445, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].voice_bitset), 0x446, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].voice_bitset), 0x447, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].channel_mask), 0x448, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].channel_mask), 0x449, 1},
{offsetof(SpcPlayer, sfx2.chan_idx_x2), 0x44a, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].voice_index), 0x44b, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].voice_index), 0x44c, 1},
{offsetof(SpcPlayer, sfx2.enabled_voices), 0x44d, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].voice_index_mult8), 0x44e, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].voice_index_mult8), 0x44f, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].volume), 0x450, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].phase_setting), 0x451, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].volume), 0x452, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].phase_setting), 0x453, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].release_flag), 0x454, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].release_timer), 0x455, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].release_flag), 0x456, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].release_timer), 0x457, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].repeat_ctr), 0x458, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].repeat_ctr), 0x459, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].repeat_pt), 0x45a, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].repeat_pt), 0x45b, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].adsr_settings), 0x45c, 2},
{offsetof(SpcPlayer, sfx_chans_2[1].adsr_settings), 0x45e, 2},
{offsetof(SpcPlayer, sfx_chans_2[0].update_adsr), 0x460, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].update_adsr), 0x461, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].note), 0x462, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].subnote), 0x463, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].subnote_delta), 0x464, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].target_note), 0x465, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].enable_pitch_slide), 0x466, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].legato), 0x467, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].enable_pitch_slide_legato), 0x468, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].note), 0x469, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].subnote), 0x46a, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].subnote_delta), 0x46b, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].target_note), 0x46c, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].enable_pitch_slide), 0x46d, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].legato), 0x46e, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].enable_pitch_slide_legato), 0x46f, 1},
{offsetof(SpcPlayer, sfx3.current_sound), 0x470, 1},
{offsetof(SpcPlayer, sfx3.cur_sound_index), 0x471, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].ptr_idx), 0x472, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].ptr_idx), 0x473, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].instr_timers), 0x474, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].instr_timers), 0x475, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].disable), 0x476, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].disable), 0x477, 1},
{offsetof(SpcPlayer, sfx3.chan_idx), 0x478, 1},
{offsetof(SpcPlayer, sfx3.voices_to_setup), 0x479, 1},
{offsetof(SpcPlayer, sfx3.voice_index), 0x47a, 1},
{offsetof(SpcPlayer, sfx3.voices_remaining), 0x47b, 1},
{offsetof(SpcPlayer, sfx3.init_flag), 0x47c, 1},
{offsetof(SpcPlayer, sfx3.voice_id), 0x47d, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].voice_bitset), 0x47e, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].voice_bitset), 0x47f, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].channel_mask), 0x480, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].channel_mask), 0x481, 1},
{offsetof(SpcPlayer, sfx3.chan_idx_x2), 0x482, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].voice_index), 0x483, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].voice_index), 0x484, 1},
{offsetof(SpcPlayer, sfx3.enabled_voices), 0x485, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].voice_index_mult8), 0x486, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].voice_index_mult8), 0x487, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].volume), 0x488, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].phase_invert), 0x489, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].volume), 0x48a, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].phase_invert), 0x48b, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].release_flag), 0x48c, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].release_timer), 0x48d, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].release_flag), 0x48e, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].release_timer), 0x48f, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].repeat_ctr), 0x490, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].repeat_ctr), 0x491, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].repeat_pt), 0x492, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].repeat_pt), 0x493, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].adsr_settings), 0x494, 2},
{offsetof(SpcPlayer, sfx_chans_3[1].adsr_settings), 0x496, 2},
{offsetof(SpcPlayer, sfx_chans_3[0].update_adsr), 0x498, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].update_adsr), 0x499, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].note), 0x49a, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].subnote), 0x49b, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].subnote_delta), 0x49c, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].target_node), 0x49d, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].enable_pitch_slide), 0x49e, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].legato), 0x49f, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].enable_pitch_slide_legato), 0x4a0, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].note), 0x4a1, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].subnote), 0x4a2, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].subnote_delta), 0x4a3, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].target_node), 0x4a4, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].enable_pitch_slide), 0x4a5, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].legato), 0x4a6, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].enable_pitch_slide_legato), 0x4a7, 1},
{offsetof(SpcPlayer, disable_sfx2), 0x4a9, 1},
{offsetof(SpcPlayer, byte_4B1), 0x4b1, 1},
{offsetof(SpcPlayer, sfx3.some_value), 0x4ba, 1},
{offsetof(SpcPlayer, sfx1.priority), 0x4bb, 1},
{offsetof(SpcPlayer, sfx2.priority), 0x4bc, 1},
{offsetof(SpcPlayer, sfx3.priority), 0x4bd, 1},
};
