#include "smw_rtl.h"
#include "variables.h"
#include <time.h>
#include "common_cpu_infra.h"
#include "snes/snes.h"
#include "src/funcs.h"

const uint8 *ptr_layer1_data;
const uint8 *ptr_layer2_data;
uint8 ptr_layer2_is_bg;

uint8 *ptr_lo_map16_data;
uint8 *ptr_lo_map16_data_bak;

bool g_lunar_magic;


void AddSprXPos(uint8 k, uint16 x) {
  AddHiLo(&spr_xpos_hi[k], &spr_xpos_lo[k], x);
}

void AddSprYPos(uint8 k, uint16 y) {
  AddHiLo(&spr_ypos_hi[k], &spr_ypos_lo[k], y);
}

void AddSprXYPos(uint8 k, uint16 x, uint16 y) {
  AddHiLo(&spr_xpos_hi[k], &spr_xpos_lo[k], x);
  AddHiLo(&spr_ypos_hi[k], &spr_ypos_lo[k], y);
}

uint16 GetSprXPos(uint8 k) {
  return PAIR16(spr_xpos_hi[k], spr_xpos_lo[k]);
}

uint16 GetSprYPos(uint8 k) {
  return PAIR16(spr_ypos_hi[k], spr_ypos_lo[k]);
}

void SetSprXPos(uint8 k, uint16 x) {
  spr_xpos_hi[k] = x >> 8;
  spr_xpos_lo[k] = x;
}

void SetSprYPos(uint8 k, uint16 y) {
  spr_ypos_hi[k] = y >> 8;
  spr_ypos_lo[k] = y;
}

void SetSprXYPos(uint8 k, uint16 x, uint16 y) {
  SetHiLo(&spr_xpos_hi[k], &spr_xpos_lo[k], x);
  SetHiLo(&spr_ypos_hi[k], &spr_ypos_lo[k], y);
}

void SmwSavePlaythroughSnapshot() {
  char buf[128];
  snprintf(buf, sizeof(buf), "playthrough/%d_%d_%d.sav", ow_level_number_lo, misc_exit_level_action, (int)time(NULL));
  RtlSaveSnapshot(buf, false);
}

void UploadOAMBuffer() {  // 008449
  memcpy(g_ppu->oam, g_ram + 0x200, 0x220);
  RtlPpuWrite(OAMADDH, 0x80);
  RtlPpuWrite(OAMADDL, mirror_oamaddress_lo);
}


void SmwDrawPpuFrame(void) {
  SimpleHdma hdma_chans[3];

  Dma *dma = g_dma;

  dma_startDma(dma, mirror_hdmaenable, true);

  SimpleHdma_Init(&hdma_chans[0], &dma->channel[5]);
  SimpleHdma_Init(&hdma_chans[1], &dma->channel[6]);
  SimpleHdma_Init(&hdma_chans[2], &dma->channel[7]);

  int trigger = g_snes->vIrqEnabled ? g_snes->vTimer + 1 : -1;

  for (int i = 0; i <= 224; i++) {
    ppu_runLine(g_ppu, i);
    SimpleHdma_DoLine(&hdma_chans[0]);
    SimpleHdma_DoLine(&hdma_chans[1]);
    SimpleHdma_DoLine(&hdma_chans[2]);
    //    dma_doHdma(snes->dma);
    if (i == trigger) {
      SmwVectorIRQ();
      trigger = g_snes->vIrqEnabled ? g_snes->vTimer + 1 : -1;
    }
  }
}

void SmwRunOneFrameOfGame(void) {
  if (*(uint16 *)reset_sprites_y_function_in_ram == 0)
    SmwVectorReset();
  SmwRunOneFrameOfGame_Internal();
  SmwVectorNMI();
}


void LoadStripeImage_UploadToVRAM(const uint8 *pp) {  // 00871e
  while (1) {
    if ((*pp & 0x80) != 0)
      break;
    uint16 vram_addr = pp[0] << 8 | pp[1];
    if (g_lunar_magic)
      vram_addr = LmHook_LoadStripeImage(vram_addr);

    uint8 vmain = __CFSHL__(pp[2], 1);
    uint8 fixed_addr = (uint8)(pp[2] & 0x40) >> 3;
    uint16 num = (swap16(WORD(pp[2])) & 0x3FFF) + 1;
    pp += 4;

    if (fixed_addr) {
      if (vram_addr != 0xffff) {
        uint16 *dst = g_ppu->vram + vram_addr;
        uint16 src_data = WORD(*pp);
        int ctr = (num + 1) >> 1;
        if (vmain) {
          for (int i = 0; i < ctr; i++)
            dst[i * 32] = src_data;
        } else {
          // uhm...?
          uint8 *dst_b = (uint8 *)dst;
          for (int i = 0; i < num; i++)
            dst_b[i + ((i & 1) << 1)] = src_data;
          for (int i = 0; i < num; i += 2)
            dst_b[i + 1] = src_data >> 8;
        }
      }
      pp += 2;
    } else {
      if (vram_addr != 0xffff) {
        uint16 *dst = g_ppu->vram + vram_addr;
        uint16 *src = (uint16 *)pp;
        if (vmain) {
          for (int i = 0; i < (num >> 1); i++)
            dst[i * 32] = src[i];
        } else {
          for (int i = 0; i < (num >> 1); i++)
            dst[i] = src[i];
        }
      }
      pp += num;
    }
  }
}

