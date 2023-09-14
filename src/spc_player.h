#include <stdint.h>
#include <stddef.h>
#include "types.h"
#include "snes/dsp.h"

typedef struct Channel {
  uint16 pattern_order_ptr_for_chan;
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
  uint8 some_value;
  uint16 cur_ptr;
  uint8 enabled_voices;
  uint8 voices_to_setup;
  uint8 chan_idx;
  uint8 voices_remaining;
  uint8 cur_sound_index;
  uint8 voice_id;
  uint8 init_flag;
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
  uint8 voice_index_mult8;
  uint8 release_timer;
  uint8 volume;
  uint8 target_note;
  uint8 phase_invert;
  uint16 ptr;
  uint8 repeat_ctr;
  uint8 enable_pitch_slide;
  uint8 release_flag;
  uint8 enable_pitch_slide_legato;
  uint16 adsr_settings;
  uint8 channel_mask;
  uint8 legato;
  uint8 disable;
  uint8 subnote_delta;
  uint8 update_adsr;
} SfxChan;


typedef struct SpcPlayer {
  DspRegWriteHistory *reg_write_history;
  uint8 timer_cycles;
  Dsp *dsp;

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
  SfxRegs sfx1;
  SfxRegs sfx2;
  SfxRegs sfx3;
  SfxChan sfx_chans_1[4];
  SfxChan sfx_chans_2[2];
  SfxChan sfx_chans_3[2];
  uint8 last_written_edl;
  uint8 input_ports[4];
  uint8 ram[65536]; // rest of ram
} SpcPlayer;

SpcPlayer *SpcPlayer_Create();
void SpcPlayer_GenerateSamples(SpcPlayer *p);
void SpcPlayer_Initialize(SpcPlayer *p);
void SpcPlayer_Upload(SpcPlayer *p, const uint8_t *data);
void SpcPlayer_CopyVariablesFromRam(SpcPlayer *p);
void SpcPlayer_CopyVariablesToRam(SpcPlayer *p);