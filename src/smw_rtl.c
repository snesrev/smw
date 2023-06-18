#include "smw_rtl.h"
#include "variables.h"
#include <time.h>
#include "common_cpu_infra.h"
#include "snes/snes.h"

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
  memcpy(g_snes->ppu->oam, g_ram + 0x200, 0x220);
  RtlPpuWrite(OAMADDH, 0x80);
  RtlPpuWrite(OAMADDL, mirror_oamaddress_lo);
}
