#pragma once
#include "types.h"

typedef struct Dsp Dsp;
typedef struct SpcPlayer SpcPlayer;

typedef void SpcPlayer_Initialize_Func(SpcPlayer *p);
typedef void SpcPlayer_GenerateSamples_Func(SpcPlayer *p);
typedef void SpcPlayer_Upload_Func(SpcPlayer *p, const uint8_t *data);
typedef void SpcPlayer_CopyVariables_Func(SpcPlayer *p, bool copy_to_ram);


typedef struct SpcPlayer {
  Dsp *dsp;
  uint8 *ram;
  uint8 input_ports[4];

  SpcPlayer_Initialize_Func *initialize;
  SpcPlayer_GenerateSamples_Func *gen_samples;
  SpcPlayer_Upload_Func *upload;
  SpcPlayer_CopyVariables_Func *copy_vars;
} SpcPlayer;


SpcPlayer *SmwSpcPlayer_Create(void);
SpcPlayer *SmasSpcPlayer_Create(void);

