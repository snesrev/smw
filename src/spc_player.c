#include "spc_player.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"
#include "snes/spc.h"
#include "snes/dsp_regs.h"
#include "tracing.h"

void Sfx1_HandleCmdFromSnes(SpcPlayer *p);
void Sfx2_HandleCmdFromSnes(SpcPlayer *p);
void Sfx3_HandleCmdFromSnes(SpcPlayer *p);
void Sfx1_Process(SpcPlayer *p);
void Sfx2_Process(SpcPlayer *p);
void Sfx3_Process(SpcPlayer *p);

typedef struct MemMap {
  uint16 off, org_off;
} MemMap;

typedef struct MemMapSized {
  uint16 off, org_off, size;
} MemMapSized;
static const MemMap kChannel_Maps[] = {
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
#pragma warning (disable: 4267)
static const MemMapSized kSpcPlayer_Maps[] = {
{offsetof(SpcPlayer, input_ports), 0x0, 4},
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
{offsetof(SpcPlayer, timer_cycles), 0x1c, 1},
{offsetof(SpcPlayer, word_20), 0x20, 2},
{offsetof(SpcPlayer, sfx1.cur_ptr), 0x22, 2},
{offsetof(SpcPlayer, sfx1.chan_voice_bitset_ptr), 0x24, 2},
{offsetof(SpcPlayer, sfx1.chan_voice_mask_ptr), 0x26, 2},
{offsetof(SpcPlayer, sfx1.chan_voice_index_ptr), 0x28, 2},
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
{offsetof(SpcPlayer, sfx_chans_1[0].phase_invert), 0x3b9, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].volume), 0x3ba, 1},
{offsetof(SpcPlayer, sfx_chans_1[1].phase_invert), 0x3bb, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].volume), 0x3bc, 1},
{offsetof(SpcPlayer, sfx_chans_1[2].phase_invert), 0x3bd, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].volume), 0x3be, 1},
{offsetof(SpcPlayer, sfx_chans_1[3].phase_invert), 0x3bf, 1},
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
{offsetof(SpcPlayer, sfx_chans_1[2].target_note), 0x3ed, 1},
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
{offsetof(SpcPlayer, sfx2.cur_sound), 0x3f8, 1},
{offsetof(SpcPlayer, sfx2.cur_sound_index), 0x3f9, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].ptr_idx), 0x3fa, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].ptr_idx), 0x3fb, 1},
{offsetof(SpcPlayer, sfx_chans_2[0].instr_timer), 0x3fc, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].instr_timer), 0x3fd, 1},
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
{offsetof(SpcPlayer, sfx_chans_2[0].phase_invert), 0x451, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].volume), 0x452, 1},
{offsetof(SpcPlayer, sfx_chans_2[1].phase_invert), 0x453, 1},
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
{offsetof(SpcPlayer, sfx3.cur_sound), 0x470, 1},
{offsetof(SpcPlayer, sfx3.cur_sound_index), 0x471, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].ptr_idx), 0x472, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].ptr_idx), 0x473, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].instr_timer), 0x474, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].instr_timer), 0x475, 1},
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
{offsetof(SpcPlayer, sfx_chans_3[0].target_note), 0x49d, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].enable_pitch_slide), 0x49e, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].legato), 0x49f, 1},
{offsetof(SpcPlayer, sfx_chans_3[0].enable_pitch_slide_legato), 0x4a0, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].note), 0x4a1, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].subnote), 0x4a2, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].subnote_delta), 0x4a3, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].target_note), 0x4a4, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].enable_pitch_slide), 0x4a5, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].legato), 0x4a6, 1},
{offsetof(SpcPlayer, sfx_chans_3[1].enable_pitch_slide_legato), 0x4a7, 1},
{offsetof(SpcPlayer, disable_sfx2), 0x4a9, 1},
{offsetof(SpcPlayer, byte_4B1), 0x4b1, 1},
{offsetof(SpcPlayer, sfx3.some_value), 0x4ba, 1},
{offsetof(SpcPlayer, sfx1.priority), 0x4bb, 1},
{offsetof(SpcPlayer, sfx2.priority), 0x4bc, 1},
{offsetof(SpcPlayer, sfx3.priority), 0x4bd, 1},
{offsetof(SpcPlayer, last_written_edl), 0x4be, 1 },


};

static void PlayNote(SpcPlayer *p, Channel *c, uint8 note);

static void Dsp_Write(SpcPlayer *p, uint8_t reg, uint8 value) {
  DspRegWriteHistory *hist = p->reg_write_history;
  if (hist) {
    if (hist->count < 256) {
      if (hist->count == 9 && reg == 0x5d) {
        reg += 0;
      }
      hist->addr[hist->count] = reg;
      hist->val[hist->count] = value;
      hist->count++;
    }
  }
  if (p->dsp)
    dsp_write(p->dsp, reg, value);
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

static void SetupEchoParameter_EDL(SpcPlayer *p, uint8 a) {
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
  Dsp_Write(p, ESA, (p->echo_parameter_EDL * 8 ^ 0xff) + 0x16);
}

static void WriteVolumeToDsp(SpcPlayer *p, Channel *c, uint16 volume) {
  static const uint8 kVolumeTable[22] = {0, 1, 3, 7, 13, 21, 30, 41, 52, 66, 81, 94, 103, 110, 115, 119, 122, 124, 125, 126, 127, 127};
  if (p->is_chan_on & p->cur_chan_bit)
    return;
  for (int i = 0; i < 2; i++) {
    int j = volume >> 8;
    uint8 t;
    if (j >= 21) {
      // Undefined behavior
      t = p->ram[j + 0x1E1D] + ((p->ram[j + 0x1E1D + 1] - p->ram[j + 0x1E1D]) * (uint8)volume >> 8);
    } else {
      t = kVolumeTable[j] + ((kVolumeTable[j + 1] - kVolumeTable[j]) * (uint8)volume >> 8);
    }
    
     
    t = t * c->final_volume >> 8;
    if ((c->pan_flag_with_phase_invert << i) & 0x80)
      t = -t;
    Dsp_Write(p, V0VOLL + i + c->index * 16, t);
    volume = 0x1400 - volume;
  }
}

static void WritePitchInner(SpcPlayer *p, Channel *c, uint16 pitch) {
  static const uint16 kBaseNoteFreqs[13] = {2143, 2270, 2405, 2548, 2700, 2860, 3030, 3211, 3402, 3604, 3818, 4045, 4286};
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

static void WritePitch(SpcPlayer *p, Channel *c, uint16 pitch) {
  if ((pitch >> 8) >= 0x34) {
    pitch += (pitch >> 8) - 0x34;
  } else if ((pitch >> 8) < 0x13) {
    pitch += (uint8)(((pitch >> 8) - 0x13) * 2) - 256;
  }
  WritePitchInner(p, c, pitch);
}

static void Music_ResetChan(SpcPlayer *p) {
  Channel *c = &p->channel[7];
  p->cur_chan_bit = 0x80;
  do {
    HIBYTE(c->channel_volume) = 0xff;
    c->pan_flag_with_phase_invert = 10;
    c->pan_value = 10 << 8;
    c->instrument_id = 0;
    c->fine_tune = 0;
    c->channel_transposition = 0;
    c->pitch_envelope_num_ticks = 0;
    c->cutk = 0;
    c->vib_depth = 0;
    c->tremolo_depth = 0;
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

static void Channel_SetInstrument_NoSetId(SpcPlayer *p, Channel *c, uint8 instrument) {
  if (instrument & 0x80)
    instrument = instrument + 54 + p->percussion_base_id;
  const uint8 *ip = p->ram + instrument * 6 + 0x6c00;
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

static void Channel_SetInstrument(SpcPlayer *p, Channel *c, uint8 instrument) {
  c->instrument_id = instrument;
  Channel_SetInstrument_NoSetId(p, c, instrument);
}

static void ComputePitchAdd(Channel *c, uint8 pitch) {
  c->pitch_target = pitch & 0x7f;
  c->pitch_add_per_tick = SpcDivHelper(c->pitch_target - (c->pitch >> 8), c->pitch_slide_length);
}

static void PitchSlideToNote_Check(SpcPlayer *p, Channel *c) {
  if (c->pitch_slide_length || p->ram[c->pattern_order_ptr_for_chan] != 0xf9)
    return;
  c->pattern_order_ptr_for_chan++;
  c->pitch_slide_delay_left = p->ram[c->pattern_order_ptr_for_chan++];
  c->pitch_slide_length = p->ram[c->pattern_order_ptr_for_chan++];
  ComputePitchAdd(c, p->ram[c->pattern_order_ptr_for_chan++] + p->global_transposition + c->channel_transposition);
}

static const uint8 kEffectByteLength[31] = {
  1, 1, 2, 3, 0, 1, 2, 1, 2, 1, 1, 3, 0, 1, 2, 3, 1, 3, 3, 0, 1, 3, 0, 3, 3, 3, 1, 2, 0, 0, 0};

static void HandleEffect(SpcPlayer *p, Channel *c, uint8 effect) {
  uint8 arg = kEffectByteLength[effect - 0xe0] ? p->ram[c->pattern_order_ptr_for_chan++] : 0;

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
    c->pan_target_value = p->ram[c->pattern_order_ptr_for_chan++];
    c->pan_add_per_tick = SpcDivHelper(c->pan_target_value - (c->pan_value >> 8), arg);
    break;
  case 0xe3: // vibrato on
    c->vibrato_delay_ticks = arg;
    c->vibrato_rate = p->ram[c->pattern_order_ptr_for_chan++];
    c->vibrato_depth_target = c->vib_depth = p->ram[c->pattern_order_ptr_for_chan++];
    c->vibrato_fade_num_ticks = 0;
    break;
  case 0xe4: // vibrato off
    c->vibrato_depth_target = c->vib_depth = 0;
    c->vibrato_fade_num_ticks = 0;
    break;
  case 0xe5:
    p->master_volume = arg << 8;
    break;
  case 0xe6:
    p->master_volume_fade_ticks = arg;
    p->master_volume_fade_target = p->ram[c->pattern_order_ptr_for_chan++];
    p->master_volume_fade_add_per_tick = SpcDivHelper(p->master_volume_fade_target - (p->master_volume >> 8), arg);
    break;
  case 0xe7:
    p->tempo = arg << 8;
    break;
  case 0xe8:
    p->tempo_fade_num_ticks = arg;
    p->tempo_fade_final = p->ram[c->pattern_order_ptr_for_chan++];
    p->tempo_fade_add = SpcDivHelper(p->tempo_fade_final - (p->tempo >> 8), arg);
    break;
  case 0xe9:
    p->global_transposition = arg;
    break;
  case 0xea:
    c->channel_transposition = arg;
    break;
  case 0xeb:
    c->tremolo_delay_ticks = arg;
    c->tremolo_rate = p->ram[c->pattern_order_ptr_for_chan++];
    c->tremolo_depth = p->ram[c->pattern_order_ptr_for_chan++];
    break;
  case 0xec:
    c->tremolo_depth = 0;
    break;
  case 0xed:
    c->channel_volume = arg << 8;
    break;
  case 0xee:
    c->volume_fade_ticks = arg;
    c->volume_fade_target = p->ram[c->pattern_order_ptr_for_chan++];
    c->volume_fade_addpertick = SpcDivHelper(c->volume_fade_target - (c->channel_volume >> 8), arg);
    break;
  case 0xef:
    c->pattern_start_ptr = p->ram[c->pattern_order_ptr_for_chan++] << 8 | arg;
    c->subroutine_num_loops = p->ram[c->pattern_order_ptr_for_chan++];
    c->saved_pattern_ptr = c->pattern_order_ptr_for_chan;
    c->pattern_order_ptr_for_chan = c->pattern_start_ptr;
    break;
  case 0xf0:
    c->vibrato_fade_num_ticks = arg;
    c->vibrato_fade_add_per_tick = arg ? c->vib_depth / arg : 0xff;
    break;
  case 0xf1: // note pitch envelope to
  case 0xf2:
    c->pitch_envelope_direction = (effect == 0xf1);
    c->pitch_envelope_delay = arg;
    c->pitch_envelope_num_ticks = p->ram[c->pattern_order_ptr_for_chan++];
    c->pitch_envelope_slide_value = p->ram[c->pattern_order_ptr_for_chan++];
    break;
  case 0xf3:
    c->pitch_envelope_num_ticks = 0;
    break;
  case 0xf4:
    c->fine_tune = arg;
    break;
  case 0xf5:
    p->reg_EON = arg;
    p->echo_volume_left = p->ram[c->pattern_order_ptr_for_chan++] << 8;
    p->echo_volume_right = p->ram[c->pattern_order_ptr_for_chan++] << 8;
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
    p->reg_EFB = p->ram[c->pattern_order_ptr_for_chan++];
    const int8_t *ep = kEchoFirParameters + p->ram[c->pattern_order_ptr_for_chan++] * 8;
    for (int i = 0; i < 8; i++)
      Dsp_Write(p, FIR0 + i * 16, *ep++);
    break;
  }
  case 0xf8:
    p->echo_volume_fade_ticks = arg;
    p->echo_volume_fade_target_left = p->ram[c->pattern_order_ptr_for_chan++];
    p->echo_volume_fade_target_right = p->ram[c->pattern_order_ptr_for_chan++];
    p->echo_volume_fade_add_left = SpcDivHelper(p->echo_volume_fade_target_left - (p->echo_volume_left >> 8), arg);
    p->echo_volume_fade_add_right = SpcDivHelper(p->echo_volume_fade_target_right - (p->echo_volume_right >> 8), arg);
    break;
  case 0xf9:
    c->pitch_slide_delay_left = arg;
    c->pitch_slide_length = p->ram[c->pattern_order_ptr_for_chan++];
    ComputePitchAdd(c, p->ram[c->pattern_order_ptr_for_chan++] + p->global_transposition + c->channel_transposition);
    break;
  case 0xfa:
    p->percussion_base_id = arg;
    break;
  case 0xfb:
    c->pattern_order_ptr_for_chan++;
    break;
  case 0xfc:
    c->cutk = arg + 1;
    break;
  case 0xfd:
    p->fast_forward = arg + 1;
    p->key_OFF |= ~p->is_chan_on;
    break;
  case 0xfe:
    p->fast_forward = arg;
    p->key_OFF |= ~p->is_chan_on;
    break;
  default:
    Not_Implemented();
  }
}

static bool WantWriteKof(SpcPlayer *p, Channel *c) {
  int loops = c->subroutine_num_loops;
  int ptr = c->pattern_order_ptr_for_chan;

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

void CalcFinalVolume(SpcPlayer *p, Channel *c, uint8 vol) {
  int t = (p->master_volume >> 8) * vol >> 8;
  t = t * c->channel_volume_master >> 8;
  t = t * (c->channel_volume >> 8) >> 8;
  c->final_volume = t * t >> 8;
}

static void CalcTremolo(SpcPlayer *p, Channel *c, uint8 a) {
  if (a & 0x80)
    a = (a * 2) ^ 0xff;
  else
    a = (a * 2);
  a = a * c->tremolo_depth >> 8;
  CalcFinalVolume(p, c, a ^ 0xff);
}

static void HandleTremolo(SpcPlayer *p, Channel *c) {
  p->did_affect_volumepitch_flag |= 0x80;
  CalcTremolo(p, c, (c->tremolo_rate * p->main_tempo_accum >> 8));
}

static void CalcVibratoAddPitch(SpcPlayer *p, Channel *c, uint16 pitch, uint8 value) {
  int t = value << 2;
  t ^= (t & 0x100) ? 0xff : 0;
  int r = (c->vib_depth >= 0xf1) ?
      (uint8)t * (c->vib_depth & 0xf) :
      (uint8)t * c->vib_depth >> 8;
  WritePitch(p, c, pitch + (value & 0x80 ? -r : r));
}

static void HandlePanAndSweep(SpcPlayer *p, Channel *c) {
  p->did_affect_volumepitch_flag = 0;
  if (c->tremolo_depth && c->tremolo_hold_count == c->tremolo_delay_ticks) {
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

static void HandleNoteTick(SpcPlayer *p, Channel *c) {
  if (c->note_keyoff_ticks_left != 0 && (--c->note_keyoff_ticks_left == 0 || c->note_ticks_left == 2)) {
    if (WantWriteKof(p, c) && !(p->cur_chan_bit & p->is_chan_on))
      Dsp_Write(p, KOF, p->cur_chan_bit);
  }

  p->did_affect_volumepitch_flag = 0;
  if (c->pitch_slide_length) {
    if (c->pitch_slide_delay_left) {
      c->pitch_slide_delay_left--;
    } else {
      p->did_affect_volumepitch_flag = 0x80;

      if (--c->pitch_slide_length == 0) {
        c->pitch = c->pitch_target << 8 | c->fine_tune;
      } else {
        c->pitch += c->pitch_add_per_tick;
      }
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

static void Chan_HandleTick(SpcPlayer *p, Channel *c) {
  if (c->volume_fade_ticks) {
    if (--c->volume_fade_ticks == 0) {
      c->channel_volume = c->volume_fade_target << 8;
    } else {
      c->channel_volume += c->volume_fade_addpertick;
    }
    p->vol_dirty |= p->cur_chan_bit;
  }
  if (c->tremolo_depth) {
    if (c->tremolo_delay_ticks == c->tremolo_hold_count) {
      p->vol_dirty |= p->cur_chan_bit;
      if (c->tremolo_count & 0x80 && c->tremolo_depth == 0xff) {
        c->tremolo_count = 0x80;
      } else {
        c->tremolo_count += c->tremolo_rate;
      }
      CalcTremolo(p, c, c->tremolo_count);
    } else {
      c->tremolo_hold_count++;
      CalcFinalVolume(p, c, 0xff);
    }
  } else {
    CalcFinalVolume(p, c, 0xff);
  }

  if (c->pan_num_ticks) {
    if (--c->pan_num_ticks == 0)
      c->pan_value = c->pan_target_value << 8;
    else
      c->pan_value += c->pan_add_per_tick;
    p->vol_dirty |= p->cur_chan_bit;
  }

  if (p->vol_dirty & p->cur_chan_bit)
    WriteVolumeToDsp(p, c, c->pan_value);
}

static void Music_HandleCmdFromSnes(SpcPlayer *p) {
  Channel *c;
  int t;
  uint8 a = p->input_ports[0];
  p->input_ports[0] = 255;

  if (a == 0xf0) {  // 0xf0 - pausemusic
    p->key_OFF |= ~p->is_chan_on;
  } else {
    if (a != 0xf1 && a != 255 && a != p->port_to_snes[0]) start_playing_sound: {
      p->port_to_snes[0] = a;
      p->music_ptr_toplevel = WORD(p->ram[0x5820 + (a - 1) * 2]);
      p->counter_sf0c = 2;
      p->key_OFF |= ~p->is_chan_on;
      return;
    }
    if (p->port_to_snes[0] == 0)
      return;
    if (p->counter_sf0c == 0)
      goto label_a;
    if (--p->counter_sf0c != 0) {
      Music_ResetChan(p);
      return;
    }
    for (;;) next_phrase: {
      t = WORD(p->ram[p->music_ptr_toplevel]);
      p->music_ptr_toplevel += 2;
      if ((t >> 8) != 0)
        break;
      if (t == 0) {
        a = 0;
        goto start_playing_sound;
      }
      if (t == 0x80) {
        p->fast_forward = 0x80;
      } else if (t == 0x81) {
        p->fast_forward = 0;
      } else {
        if (sign8(--p->block_count))
          p->block_count = t;
        t = WORD(p->ram[p->music_ptr_toplevel]);
        p->music_ptr_toplevel += 2;
        if (p->block_count != 0)
          p->music_ptr_toplevel = t;
      }
    }
    for (int i = 0; i < 8; i++)
      p->channel[i].pattern_order_ptr_for_chan = WORD(p->ram[t]), t += 2;

    c = p->channel, p->cur_chan_bit = 1;
    do {
      if (HIBYTE(c->pattern_order_ptr_for_chan) && c->instrument_id == 0)
        Channel_SetInstrument(p, c, 0);
      c->subroutine_num_loops = 0;
      c->volume_fade_ticks = 0;
      c->pan_num_ticks = 0;
      c->note_ticks_left = 1;
    } while (c++, p->cur_chan_bit <<= 1);
label_a:
    p->vol_dirty = 0;
    c = p->channel, p->cur_chan_bit = 1;
    do {
      if (!HIBYTE(c->pattern_order_ptr_for_chan))
        continue;
      if (!--c->note_ticks_left) {
        for (;;) {
          uint8 cmd = p->ram[c->pattern_order_ptr_for_chan++];
          if (cmd == 0) {
            if (!c->subroutine_num_loops)
              goto next_phrase;
            c->pattern_order_ptr_for_chan = (--c->subroutine_num_loops == 0) ? c->saved_pattern_ptr : c->pattern_start_ptr;
            continue;
          }
          if (!(cmd & 0x80)) {
            static const uint8 kNoteVol[16] = { 25, 50, 76, 101, 114, 127, 140, 152, 165, 178, 191, 203, 216, 229, 242, 252 };
            static const uint8 kNoteGateOffPct[8] = { 50, 101, 127, 152, 178, 203, 229, 252 };
            c->note_length = cmd;
            cmd = p->ram[c->pattern_order_ptr_for_chan++];
            if (!(cmd & 0x80)) {
              c->note_gate_off_fixedpt = kNoteGateOffPct[cmd >> 4 & 7];
              c->channel_volume_master = kNoteVol[cmd & 0xf];
              cmd = p->ram[c->pattern_order_ptr_for_chan++];
            }
          }
          if (cmd >= 0xe0) {
            HandleEffect(p, c, cmd); 
            continue;
          }
          if ((c->cutk | p->fast_forward) == 0)
            PlayNote(p, c, cmd);
          c->note_ticks_left = c->note_length;
          t = c->note_ticks_left * c->note_gate_off_fixedpt >> 8;
          c->note_keyoff_ticks_left = (t != 0) ? t : 1;
          PitchSlideToNote_Check(p, c);
          break;
        }
      } else if (!p->fast_forward) {
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
      if (HIBYTE(c->pattern_order_ptr_for_chan))
        Chan_HandleTick(p, c);
    } while (c++, p->cur_chan_bit <<= 1);
  }
}

static void PlayNote(SpcPlayer *p, Channel *c, uint8 note) {
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

  //static const char *const kNoteNames[] = { "C-", "C#", "D-", "D#", "E-", "F-", "F#", "G-", "G#", "A-", "A#", "B-" };
  //if (c->index==0)
  //  printf("%s%d\n", kNoteNames[(note & 0x7f) % 12], (note & 0x7f) / 12 + 1);

  c->pitch = ((note & 0x7f) + p->global_transposition + c->channel_transposition) << 8 | c->fine_tune;
  c->vibrato_count = c->vibrato_fade_num_ticks << 7;
  c->vibrato_hold_count = 0;
  c->vibrato_change_count = 0;
  c->tremolo_count = 0;
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

static void Spc_Loop_Part1(SpcPlayer *p) {
  Dsp_Write(p, KOF, p->key_OFF);
  Dsp_Write(p, PMON, 0);
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
}

static void Spc_Loop_Part2(SpcPlayer *p, uint8 ticks) {
  int t = p->sfx_timer_accum + (uint8)(ticks * 0x20);
  p->sfx_timer_accum = t;
  if (t >= 0x100) {
    Sfx1_HandleCmdFromSnes(p);
    Sfx2_HandleCmdFromSnes(p);
    Sfx3_HandleCmdFromSnes(p);

    if (p->echo_stored_time != p->echo_parameter_EDL)
      p->echo_stored_time++;
  }

  t = p->main_tempo_accum + (uint8)(ticks * HIBYTE(p->tempo));
  p->main_tempo_accum = t;
  if (t >= 256) {
    do {
      Music_HandleCmdFromSnes(p);
    } while (p->fast_forward);
  } else if (p->port_to_snes[0]) {
    Channel *c = p->channel;
    for (p->cur_chan_bit = 1; p->cur_chan_bit != 0; p->cur_chan_bit <<= 1, c++) {
      if (HIBYTE(c->pattern_order_ptr_for_chan))
        HandlePanAndSweep(p, c);
    }
  }
}

static void Vector_Reset_Spc(SpcPlayer *p) {
  dsp_reset(p->dsp);

  memset(&p->ram[0x500], 0, 0x1000);
  memset(&p->ram[0x20], 0, 0xf);
  memset(&p->ram[0xd0], 0, 0x1f);

  memset(&p->ram[0x391], 0, 0x6f);
  memset(&p->ram[0x440], 0, 0x7f);

  SpcPlayer_CopyVariablesFromRam(p);

//  memset(&p->new_value_from_snes, 0, sizeof(SpcPlayer) - offsetof(SpcPlayer, new_value_from_snes));

  for (int i = 0; i < 8; i++)
    p->channel[i].index = i;
  SetupEchoParameter_EDL(p, 1);
  p->reg_FLG |= 0x20;
  Dsp_Write(p, MVOLL, 0x60);
  Dsp_Write(p, MVOLR, 0x60);
  Dsp_Write(p, DIR, 0x6d);
  HIBYTE(p->tempo) = 16;
  p->timer_cycles = 0;
}

void Sfx_Chan_Reset(SpcPlayer *p, SfxRegs *sr, SfxChan *s) {
  s->disable = 0xff;
  s->update_adsr = 0;
  sr->enabled_voices &= s->channel_mask;
  p->is_chan_on &= s->channel_mask;
  p->cur_chan_bit |= s->voice_bitset;
  p->key_OFF |= s->voice_bitset;
  Channel *c = &p->channel[s->voice_index >> 1];
  Channel_SetInstrument_NoSetId(p, c, c->instrument_id);
  c->final_volume = s->volume;
  c->pan_flag_with_phase_invert = s->phase_invert;
  if (!sr->enabled_voices) {
    sr->cur_sound = 0;
    sr->priority = 0;
    sr->init_flag = 0;
  }
}

static const uint16 kSfx1InstrListPtrs[] = {
  0x2b71, 0x2baf, 0x2bb7, 0x2bc4, 0x2bd1, 0x2bfc, 0x2c2f, 0x2c37,
  0x2cff, 0x2d12, 0x2d1a, 0x2d27, 0x2d4b, 0x2d5d, 0x2d5f, 0x2d76,
  0x2d95, 0x2d97, 0x2d99, 0x2da6, 0x2da8, 0x2daa, 0x2dac, 0x2dc8,
  0x2de7, 0x2dfe, 0x2e00, 0x2e17, 0x2e19, 0x2e1b, 0x2e1d, 0x2e34,
  0x2e36, 0x2e38, 0x2e3a, 0x2e68, 0x2eaf, 0x2ed0, 0x2ef6, 0x2f2c,
  0x2f37, 0x2f3f, 0x2f47, 0x2f4a, 0x2f4d, 0x2f50, 0x2fb0, 0x2fb8,
  0x2fc3, 0x2fdd, 0x2fe5, 0x3040, 0x3048, 0x3055, 0x305d, 0x3065,
  0x3070, 0x3078, 0x307b, 0x308b, 0x309b, 0x30a8, 0x30d6, 0x30e1,
  0x312a, 0x313f
};

static const uint8 kSfx1Conf[] = {
  5, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 4, 0, 0,
  0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
  2, 2
};

void Sfx1_HandleCmdFromSnes(SpcPlayer *p) {
  uint8 a = p->input_ports[1];
  p->input_ports[1] = 255;
  if (a == 255 || a == 0 || a != 1 && a != 2 && p->sfx1.priority) {
    if (p->sfx1.cur_sound)
      Sfx1_Process(p);
    return;
  }
  if (p->sfx1.cur_sound) {
    p->sfx1.enabled_voices = 0;
    Sfx_Chan_Reset(p, &p->sfx1, &p->sfx_chans_1[0]);
    Sfx_Chan_Reset(p, &p->sfx1, &p->sfx_chans_1[1]);
    Sfx_Chan_Reset(p, &p->sfx1, &p->sfx_chans_1[2]);
    Sfx_Chan_Reset(p, &p->sfx1, &p->sfx_chans_1[3]);
  }
  for (int i = 0; i != 4; i++)
    p->sfx_chans_1[i].legato = 0;
  p->sfx1.cur_sound_index = (a - 1) * 2;

  p->sfx1.cur_ptr = kSfx1InstrListPtrs[p->sfx1.cur_sound_index >> 1];
  p->sfx1.cur_sound = a;

  switch (kSfx1Conf[a - 1]) {
  case 0:
    p->sfx1.voices_to_setup = 1;
    p->sfx1.priority = 0;
    break;
  case 1:
    p->sfx1.voices_to_setup = 1;
    p->sfx1.priority = 1;
    break;
  case 2:
    p->sfx1.voices_to_setup = 2;
    p->sfx1.priority = 0;
    break;
  case 3:
    p->sfx1.voices_to_setup = 3;
    p->sfx1.priority = 1;
    break;
  case 4:
    p->sfx1.voices_to_setup = 4;
    p->sfx1.priority = 0;
    break;
  case 5:
    p->sfx1.voices_to_setup = 4;
    p->sfx1.priority = 0;
    break;
  }
}

static const uint16 kSfx2InstrListPtrs[] = {
  0x3ab1, 0x3ac3, 0x3ad5, 0x3af1, 0x3af3, 0x3af5, 0x3b0c, 0x3b28,
  0x3b2a, 0x3b3a, 0x3b42, 0x3b5e, 0x3b73, 0x3b85, 0x3b92, 0x3ba9,
  0x3bb4, 0x3bc1, 0x3be7, 0x3c08, 0x3c33, 0x3c3b, 0x3c43, 0x3c56,
  0x3c90, 0x3cff, 0x3d46, 0x3d4e, 0x3d65, 0x3d81, 0x3d9b, 0x3da8,
  0x3dbf, 0x3dd6, 0x3ded, 0x3e04, 0x3e20, 0x3e41, 0x3e66, 0x3e94,
  0x3eb0, 0x3ecc, 0x3ece, 0x3f03, 0x3f18, 0x3f20, 0x3f44, 0x3f5e,
  0x3f75, 0x3f82, 0x3f8a, 0x3f97, 0x3f9f, 0x401f, 0x4036, 0x4066,
  0x407c, 0x407e, 0x4086, 0x4088, 0x408a, 0x408c, 0x409e, 0x40a6,
  0x40b1, 0x40b4, 0x40bc, 0x40ce, 0x40d1, 0x40de, 0x40f5, 0x410c,
  0x412c, 0x4143, 0x415a, 0x4162, 0x416f, 0x41a9, 0x41c7, 0x41d9,
  0x41ee, 0x421c, 0x4224, 0x4236, 0x424d, 0x4268, 0x4288, 0x429a,
  0x42af, 0x42bf, 0x42d4, 0x42d6, 0x42fe, 0x4310, 0x4322, 0x4334,
  0x433c, 0x4347, 0x4352, 0x43c1, 0x43cc, 0x43e8, 0x43fa, 0x4422,
  0x442f, 0x4441, 0x4443, 0x4446, 0x444e, 0x446f, 0x447f, 0x448f,
  0x449c, 0x44a4, 0x44b9, 0x44ce, 0x44ed, 0x4598, 0x459a, 0x4618,
  0x462d, 0x4642, 0x4657, 0x466c, 0x4679, 0x4686, 0x468e
};

static const uint8 kSfx2Conf[] = {
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 1, 1, 0, 2, 2, 0, 1, 0, 3, 1, 0,
  0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 1, 3, 0, 0,
  0, 0, 0, 0, 1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3,
  3, 0, 0, 1, 0, 2, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0,
  0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0,
  0, 3, 3, 3, 3, 0, 3, 2, 2, 2, 2, 1, 1, 1, 2
};

void Sfx2_HandleCmdFromSnes(SpcPlayer *p) {
  uint8 a = p->input_ports[2];
  p->input_ports[2] = 255;
  if (a == 255 || a == 0 || a != 0x71 && a != 0x7e && p->sfx2.priority) {
    if (p->sfx2.cur_sound)
      Sfx2_Process(p);
    return;
  }
  if (p->sfx2.cur_sound) {
    p->sfx2.enabled_voices = 0;
    Sfx_Chan_Reset(p, &p->sfx2, &p->sfx_chans_2[0]);
    Sfx_Chan_Reset(p, &p->sfx2, &p->sfx_chans_2[1]);
  }
  for (int i = 0; i != 2; i++)
    p->sfx_chans_2[i].legato = 0;
  p->sfx2.cur_sound_index = (a - 1) * 2;
  p->sfx2.cur_ptr = kSfx2InstrListPtrs[p->sfx2.cur_sound_index >> 1];
  p->sfx2.cur_sound = a;
  switch (kSfx2Conf[a - 1]) {
  case 0:
    p->sfx2.voices_to_setup = 1;
    p->sfx2.priority = 0;
    break;
  case 1:
    p->sfx2.voices_to_setup = 1;
    p->sfx2.priority = 1;
    break;
  case 2:
    p->sfx2.voices_to_setup = 2;
    p->sfx2.priority = 0;
    break;
  case 3:
    p->sfx2.voices_to_setup = 2;
    p->sfx2.priority = 1;
    break;
  }
}

static const uint16 kSfx3InstrListPtrs[] = {
  0x4eed, 0x4ef5, 0x4f00, 0x4f4b, 0x4f5b, 0x4f6b, 0x4f73, 0x4f89,
  0x4f9f, 0x4fb6, 0x4fe1, 0x4ff7, 0x4fff, 0x500c, 0x5047, 0x50a8,
  0x50c4, 0x50d1, 0x50d4, 0x50f0, 0x511a, 0x5130, 0x5142, 0x5175,
  0x5178, 0x5188, 0x518b, 0x51b9, 0x51c1, 0x51d4, 0x51f0, 0x51fd,
  0x5200, 0x5208, 0x5229, 0x5231, 0x5239, 0x5241, 0x524e, 0x5256,
  0x5277, 0x5293, 0x52a5, 0x52b0, 0x52c6, 0x52f1, 0x530b
};

static const uint8 kSfx3Conf[] = {
  0, 1, 2, 3, 3, 2, 4, 4, 2, 5, 3, 2, 2, 4, 3, 2, 
  2, 5, 2, 4, 4, 2, 2, 2, 4, 2, 4, 2, 2, 2, 2, 5,
  5, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 4, 2, 4, 2
};

void Sfx3_HandleCmdFromSnes(SpcPlayer *p) {
  uint8 a = p->input_ports[3];
  p->input_ports[3] = 255;
  if (a == 255 || a == 0 || a != 1 && (p->sfx3.some_value == 2 || a != 2 && p->sfx3.priority)) {
    if (p->sfx3.cur_sound)
      Sfx3_Process(p);
    return;
  }
  if (p->sfx3.cur_sound) {
    p->sfx3.enabled_voices = 0;
    Sfx_Chan_Reset(p, &p->sfx3, &p->sfx_chans_3[0]);
    Sfx_Chan_Reset(p, &p->sfx3, &p->sfx_chans_3[1]);
  }
  for (int i = 0; i != 2; i++)
    p->sfx_chans_3[i].legato = 0;
  p->sfx3.cur_sound_index = (a - 1) * 2;
  p->sfx3.cur_ptr = kSfx3InstrListPtrs[p->sfx3.cur_sound_index >> 1];
  p->sfx3.cur_sound = a;
  
  if (p->sfx3.cur_sound >= 0xfe) {
    Sfx3_Process(p);
    return;
  }

  switch (kSfx3Conf[a - 1]) {
  case 0:
    p->sfx3.voices_to_setup = 1;
    p->sfx3.some_value = 0;
    p->sfx3.priority = 1;
    break;
  case 1:
    p->sfx3.voices_to_setup = 1;
    p->sfx3.some_value = 2;
    break;
  case 2:
    p->sfx3.voices_to_setup = 1;
    p->sfx3.priority = 0;
    break;
  case 3:
    p->sfx3.voices_to_setup = 2;
    p->sfx3.priority = 0;
    break;
  case 4:
    p->sfx3.voices_to_setup = 2;
    p->sfx3.priority = 1;
    break;
  case 5:
    p->sfx3.voices_to_setup = 1;
    p->sfx3.priority = 1;
    break;
  }
}

uint8 SfxChan_GetByte(SpcPlayer *p, SfxChan *s) {
  return p->ram[s->ptr + s->ptr_idx++];
}

void Sfx_RunChan(SpcPlayer *p, SfxRegs *sr, SfxChan *s) {
  if (s->disable == 0xff)
    return;
  if (--s->instr_timer == 0) {
    if (!s->legato) {
      s->enable_pitch_slide = 0;
      s->subnote_delta = 0;
      s->target_note = 0;
      if (s->release_flag != 0xff) {
        p->key_OFF |= s->voice_bitset;
        s->release_timer = 2;
        s->instr_timer = 1;
        s->release_flag = 0xff;
      }
      if (--s->release_timer)
        return;
      s->release_flag = 0;
      p->cur_chan_bit &= s->channel_mask;
      p->reg_NON &= s->channel_mask;
    }
    // chan0_loop_cmds
    uint8 a;
next:    
    a = SfxChan_GetByte(p, s);
    if (a == 0xf9) {
      s->adsr_settings = SfxChan_GetByte(p, s);
      s->adsr_settings |= SfxChan_GetByte(p, s) << 8;
      s->ptr_idx += 2;
      s->update_adsr = 0xff;
      goto next;
    }
    if (a == 0xf5 || a == 0xf8) {
      s->enable_pitch_slide_legato = (a == 0xf5) ? 0xf5 : 0;
      s->subnote_delta = SfxChan_GetByte(p, s);
      s->target_note = SfxChan_GetByte(p, s);
      s->enable_pitch_slide = 0xff;
      a = SfxChan_GetByte(p, s);
    }
    if (a == 0xff) {
      Sfx_Chan_Reset(p, sr, s);
      return;
    }
    if (a == 0xfe) {
      s->repeat_ctr = SfxChan_GetByte(p, s);
      s->repeat_pt = s->ptr_idx;
      a = SfxChan_GetByte(p, s);
    }
    if (a == 0xfb || a == 0xfd) {
      if (a != 0xfb && --s->repeat_ctr == 0)
        goto next;
      s->ptr_idx = s->repeat_pt;
      a = SfxChan_GetByte(p, s);
    }
    if (a == 0xfc) {
      p->reg_NON |= s->voice_bitset;
      goto next;
    }
    Channel *c = &p->channel[s->voice_index >> 1];
    Channel_SetInstrument_NoSetId(p, c, a);
    c->final_volume = SfxChan_GetByte(p, s);
    c->pan_flag_with_phase_invert = 0;
    WriteVolumeToDsp(p, c, SfxChan_GetByte(p, s) << 8);
    a = SfxChan_GetByte(p, s);
    if (a != 0xf6) {
      s->note = a;
      s->subnote = 0;
    }
    WritePitchInner(p, c, s->note << 8 | s->subnote);
    s->instr_timer = SfxChan_GetByte(p, s);
    if (s->update_adsr) {
      Dsp_Write(p, s->voice_index_mult8 | V0ADSR1, s->adsr_settings);
      Dsp_Write(p, s->voice_index_mult8 | V0ADSR2, s->adsr_settings >> 8);
    }
    if (!s->legato)
      p->key_ON |= s->voice_bitset;
  }
  // chan0_instr_end
  if (s->enable_pitch_slide != 0xff)
    return;

  if (s->enable_pitch_slide_legato)
    s->legato = 0xff;

  if (s->note >= s->target_note) {
    int t = s->subnote - s->subnote_delta;
    s->subnote = t;
    if (t & 256 && --s->note == s->target_note)
      s->enable_pitch_slide = s->legato = 0;
  } else {
    int t = s->subnote + s->subnote_delta;
    s->subnote = t;
    if (t & 256 && ++s->note == s->target_note)
      s->enable_pitch_slide = s->legato = 0;
  }
  WritePitchInner(p, &p->channel[s->voice_index >> 1], s->note << 8 | s->subnote);
}

void Sfx1_Init(SpcPlayer *p);
void Sfx2_Init(SpcPlayer *p);
void Sfx3_Init(SpcPlayer *p);

void Sfx1_Process(SpcPlayer *p) {
  if (p->sfx1.init_flag != 0xff) {
    Sfx1_Init(p);
    for (int i = 0; i < 4; i++) {
      SfxChan *s = &p->sfx_chans_1[i];
      s->ptr = WORD(p->ram[p->sfx1.cur_ptr + i * 2]);
      s->voice_index_mult8 = s->voice_index * 8;
      s->ptr_idx = 0;
      s->instr_timer = 1;
    }
  }
  for (int i = 0; i < 4; i++)
    Sfx_RunChan(p, &p->sfx1, &p->sfx_chans_1[i]);
}

void Sfx2_Process(SpcPlayer *p) {
  if (p->sfx2.init_flag != 0xff) {
    Sfx2_Init(p);
    for (int i = 0; i < 2; i++) {
      SfxChan *s = &p->sfx_chans_2[i];
      s->ptr = WORD(p->ram[p->sfx2.cur_ptr + i * 2]);
      s->voice_index_mult8 = s->voice_index * 8;
      s->ptr_idx = 0;
      s->instr_timer = 1;
    }
  }
  for (int i = 0; i < 2; i++)
    Sfx_RunChan(p, &p->sfx2, &p->sfx_chans_2[i]);
}

void Sfx3_Process(SpcPlayer *p) {
  if (p->sfx3.init_flag != 0xff) {
    Sfx3_Init(p);
    for (int i = 0; i < 2; i++) {
      SfxChan *s = &p->sfx_chans_3[i];
      s->ptr = WORD(p->ram[p->sfx3.cur_ptr + i * 2]);
      s->voice_index_mult8 = s->voice_index * 8;
      s->ptr_idx = 0;
      s->instr_timer = 1;
    }
  }
  for (int i = 0; i < 2; i++)
    Sfx_RunChan(p, &p->sfx3, &p->sfx_chans_3[i]);
}

void Sfx_Init(SpcPlayer *p, SfxRegs *sr, SfxChan *channels, int which_sfx) {
  int num = (which_sfx == 0) ? 4 : 2;
  static const uint16 kSomeAddrs[3][3] = {
    {0x3a6, 0x3aa, 0x3af},
    {0x446, 0x448, 0x44b},
    {0x47e, 0x480, 0x483},
  };
  sr->voice_id = 9;
  sr->voices_remaining = p->is_chan_on;
  sr->init_flag = 0xff;
  sr->chan_idx = sr->chan_idx_x2 = 0;
  for (int i = 0; i < num; i++) {
    channels[i].voice_bitset = 0;
    channels[i].voice_index = 0;
    channels[i].channel_mask = 0xff;
    channels[i].disable = 0xff;
  }

  while (--sr->voice_id) {
    int t = sr->voices_remaining;
    sr->voices_remaining <<= 1;
    if (!(t & 0x80)) {
      if (!sr->voices_to_setup)
        return;
      sr->voices_to_setup--;
      SfxChan *c = &channels[sr->chan_idx];
      c->disable = 0;
      sr->chan_voice_bitset_ptr = kSomeAddrs[which_sfx][0] + sr->chan_idx;
      sr->chan_voice_mask_ptr = kSomeAddrs[which_sfx][1] + sr->chan_idx;
      sr->chan_voice_index_ptr = kSomeAddrs[which_sfx][2] + sr->chan_idx;
      sr->chan_idx += 1, sr->chan_idx_x2 += 2;

      sr->voice_index = (sr->voice_id - 1) * 2;
      c->voice_index = sr->voice_index;
      int t = sr->voice_id - 1;
      c->volume = p->channel[t].final_volume |
        p->channel[t].pan_flag_with_phase_invert << 8;
      int m = 1 << t;
      p->is_chan_on |= m;
      p->cur_chan_bit &= ~m;
      p->reg_EON &= ~m;
      sr->enabled_voices |= m;
      c->voice_bitset = m;
      c->channel_mask = ~m;
    }
  }
}

void Sfx1_Init(SpcPlayer *p) {
  Sfx_Init(p, &p->sfx1, p->sfx_chans_1, 0);
}

void Sfx2_Init(SpcPlayer *p) {
  Sfx_Init(p, &p->sfx2, p->sfx_chans_2, 1);
}

void Sfx3_Init(SpcPlayer *p) {
  Sfx_Init(p, &p->sfx3, p->sfx_chans_3, 2);
}

SpcPlayer *SpcPlayer_Create(void) {
  SpcPlayer *p = (SpcPlayer *)malloc(sizeof(SpcPlayer));
  memset(p, 0, sizeof(SpcPlayer));
  p->dsp = dsp_init(p->ram);
  p->reg_write_history = 0;
  return p;
}

void SpcPlayer_Initialize(SpcPlayer *p) {
  Vector_Reset_Spc(p);
  Spc_Loop_Part1(p);
}

void SpcPlayer_CopyVariablesToRam(SpcPlayer *p) {
  Channel *c = p->channel;
  for (int i = 0; i < 8; i++, c++) {
    for (const MemMap *m = &kChannel_Maps[0]; m != &kChannel_Maps[countof(kChannel_Maps)]; m++)
      memcpy(&p->ram[(m->org_off & 0x7fff) + i * 2], (uint8 *)c + m->off, m->org_off & 0x8000 ? 2 : 1);
  }
  for (const MemMapSized *m = &kSpcPlayer_Maps[0]; m != &kSpcPlayer_Maps[countof(kSpcPlayer_Maps)]; m++)
    memcpy(&p->ram[m->org_off], (uint8 *)p + m->off, m->size);
}

void SpcPlayer_CopyVariablesFromRam(SpcPlayer *p) {
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

void SpcPlayer_GenerateSamples(SpcPlayer *p) {
  assert(p->timer_cycles <= 64);

  assert(p->dsp->sampleOffset <= 534);

  for (;;) {
    if (p->timer_cycles >= 64) {
      Spc_Loop_Part2(p, p->timer_cycles >> 6);
      Spc_Loop_Part1(p);
      p->timer_cycles &= 63;
    }

    // sample rate 32000
    int n = 534 - p->dsp->sampleOffset;
    if (n > (64 - p->timer_cycles))
      n = (64 - p->timer_cycles);

    p->timer_cycles += n;

    for (int i = 0; i < n; i++)
      dsp_cycle(p->dsp);

    if (p->dsp->sampleOffset == 534)
      break;
  }
}

void SpcPlayer_Upload(SpcPlayer *p, const uint8_t *data) {
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
  p->port_to_snes[0] = 0;
  p->input_ports[0] = p->input_ports[1] = p->input_ports[2] = p->input_ports[3] = 255;
  p->music_ptr_toplevel = WORD(p->ram[0x581e]);
  p->counter_sf0c = 2;
  p->key_OFF |= ~p->is_chan_on;
}

// =======================================
#define WITH_SPC_PLAYER_DEBUGGING 0

#if WITH_SPC_PLAYER_DEBUGGING

#include <SDL.h>

static DspRegWriteHistory my_write_hist;
static SpcPlayer my_spc, my_spc_snapshot;
static int loop_ctr;

bool CompareSpcImpls(SpcPlayer *p, SpcPlayer *p_org, Apu *apu) {
  SpcPlayer_CopyVariablesToRam(p);
  memcpy(p->ram + 0x18, apu->ram + 0x18, 2); //lfsr_value
  memcpy(p->ram + 0x110, apu->ram + 0x110, 256-16);  // stack
  memcpy(p->ram + 0xf1, apu->ram + 0xf1, 15);  // dsp regs
  memcpy(p->ram + 0x10, apu->ram + 0x10, 8);  // temp regs
  memcpy(p->ram + 0x20, apu->ram + 0x20, 2);  // temp regs
  p->ram[0x44] = apu->ram[0x44]; // chn
  memcpy(p->ram + 0xee, apu->ram + 0xee, 2);  // memset ptr
  p->ram[0x390] = apu->ram[0x390]; // memset count
  int errs = 0;
  static const uint16 ranges[][2] = {
    {0x0, 0x4ff},
    {0x1500, 0xffff},
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
  for (int i = 0; i != n; i++) {
    if (i >= my_write_hist.count || i >= apu->hist.count || my_write_hist.addr[i] != apu->hist.addr[i] || my_write_hist.val[i] != apu->hist.val[i]) {
      if (errs == 0)
        printf("@%d\n", loop_ctr);
      printf("%d: ", i);
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

  memset(&my_spc, 0, sizeof(my_spc));
  FILE *f = fopen("../spc1.bin", "rb");
  fread(my_spc.ram, 1, 65536, f);
  fclose(f);

  my_spc.reg_write_history = &my_write_hist;

  bool run_both = true;// false;// false;

  if (!run_both) {
    SpcPlayer *p = &my_spc;
    Dsp *dsp = dsp_init(p->ram);
    dsp_reset(dsp);
    p->dsp = dsp;
    SpcPlayer_Initialize(p);

    p->input_ports[0] = 4;

    for (;;) {
      SpcPlayer_GenerateSamples(p);

      int16_t audioBuffer[736 * 2];
      dsp_getSamples(p->dsp, audioBuffer, 736);
      SDL_QueueAudio(device, audioBuffer, 736 * 2 * have.channels);
      while (SDL_GetQueuedAudioSize(device) >= 736 * 4 * 3/* 44100 * 4 * 300*/)
        SDL_Delay(1);

    }

  } else {
    SpcPlayer *p = &my_spc;
    Dsp *dsp = dsp_init(p->ram);
    dsp_reset(dsp);
    p->dsp = dsp;

    Apu *apu = apu_init();
    apu_reset(apu);
    apu->spc->pc = 0x1500;

    memcpy(apu->ram, my_spc.ram, 65536);

    CompareSpcImpls(&my_spc, &my_spc_snapshot, apu);

 //   g_debug_apu_cycles = true;

    uint64_t cycle_counter = 0;
    int tgt = 0x15C4;
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
        dsp_cycle(p->dsp);

      if (apu->spc->pc == tgt) {
        tgt ^= 0x15C4 ^ 0x15C5;
        if (tgt == 0x15C4) {
          uint8 ticks = ticks_next;
          ticks_next = apu->spc->y;
          my_spc_snapshot = my_spc;
          for (;;) {
            my_write_hist.count = 0;
            if (is_initialize)
              SpcPlayer_Initialize(&my_spc);
            else {
              Spc_Loop_Part2(&my_spc, ticks);
              Spc_Loop_Part1(&my_spc);
            }
            if (CompareSpcImpls(&my_spc, &my_spc_snapshot, apu))
              break;
            my_spc = my_spc_snapshot;
          }
          is_initialize = false;

          if (cycle_counter % 1000 == 0)
            apu->inPorts[3] = my_spc.input_ports[3] = 3 + cycle_counter / 1000;
          //else if (cycle_counter % 1000 == 990)
          //  apu->inPorts[3] = my_spc.input_ports[3] = 1;
          cycle_counter++;
        }
      }

      if (p->dsp->sampleOffset == 534) {
        int16_t audioBuffer[736 * 2];
        dsp_getSamples(p->dsp, audioBuffer, 736);
        SDL_QueueAudio(device, audioBuffer, 736 * 2 * have.channels);
        while (SDL_GetQueuedAudioSize(device) >= 736 * 4 * 3/* 44100 * 4 * 300*/) {
          SDL_Delay(1);
        }
      }
    }
  }
}
#endif  // WITH_SPC_PLAYER_DEBUGGING
