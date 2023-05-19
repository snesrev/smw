#include "ppu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "snes.h"
#include "snes_regs.h"

static void ppu_handlePixel(Ppu *ppu, int x, int y);
static int ppu_getPixel(Ppu *ppu, int x, int y, bool sub, int *r, int *g, int *b);
static uint16_t ppu_getOffsetValue(Ppu *ppu, int col, int row);
static int ppu_getPixelForBgLayer(Ppu *ppu, int x, int y, int layer, bool priority);
static void ppu_handleOPT(Ppu *ppu, int layer, int *lx, int *ly);
static void ppu_calculateMode7Starts(Ppu *ppu, int y);
static int ppu_getPixelForMode7(Ppu *ppu, int x, int layer, bool priority);
static bool ppu_getWindowState(Ppu *ppu, int layer, int x);

// array for layer definitions per mode:
//   0-7: mode 0-7; 8: mode 1 + l3prio; 9: mode 7 + extbg

//   0-3; layers 1-4; 4: sprites; 5: nonexistent
static const int layersPerMode[10][12] = {
  {4, 0, 1, 4, 0, 1, 4, 2, 3, 4, 2, 3},
  {4, 0, 1, 4, 0, 1, 4, 2, 4, 2, 5, 5},
  {4, 0, 4, 1, 4, 0, 4, 1, 5, 5, 5, 5},
  {4, 0, 4, 1, 4, 0, 4, 1, 5, 5, 5, 5},
  {4, 0, 4, 1, 4, 0, 4, 1, 5, 5, 5, 5},
  {4, 0, 4, 1, 4, 0, 4, 1, 5, 5, 5, 5},
  {4, 0, 4, 4, 0, 4, 5, 5, 5, 5, 5, 5},
  {4, 4, 4, 0, 4, 5, 5, 5, 5, 5, 5, 5},
  {2, 4, 0, 1, 4, 0, 1, 4, 4, 2, 5, 5},
  {4, 4, 1, 4, 0, 4, 1, 5, 5, 5, 5, 5}
};

static const int prioritysPerMode[10][12] = {
  {3, 1, 1, 2, 0, 0, 1, 1, 1, 0, 0, 0},
  {3, 1, 1, 2, 0, 0, 1, 1, 0, 0, 5, 5},
  {3, 1, 2, 1, 1, 0, 0, 0, 5, 5, 5, 5},
  {3, 1, 2, 1, 1, 0, 0, 0, 5, 5, 5, 5},
  {3, 1, 2, 1, 1, 0, 0, 0, 5, 5, 5, 5},
  {3, 1, 2, 1, 1, 0, 0, 0, 5, 5, 5, 5},
  {3, 1, 2, 1, 0, 0, 5, 5, 5, 5, 5, 5},
  {3, 2, 1, 0, 0, 5, 5, 5, 5, 5, 5, 5},
  {1, 3, 1, 1, 2, 0, 0, 1, 0, 0, 5, 5},
  {3, 2, 1, 1, 0, 0, 0, 5, 5, 5, 5, 5}
};

static const int layerCountPerMode[10] = {
  12, 10, 8, 8, 8, 8, 6, 5, 10, 7
};

static const int bitDepthsPerMode[10][4] = {
  {2, 2, 2, 2},
  {4, 4, 2, 5},
  {4, 4, 5, 5},
  {8, 4, 5, 5},
  {8, 2, 5, 5},
  {4, 2, 5, 5},
  {4, 5, 5, 5},
  {8, 5, 5, 5},
  {4, 4, 2, 5},
  {8, 7, 5, 5}
};

void PpuDrawWholeLineOldPpu(Ppu *ppu, int line) {
  // actual line
  if (PPU_mode(ppu) == 7)
    ppu_calculateMode7Starts(ppu, line);
  for (int x = 0; x < 256; x++) {
    ppu_handlePixel(ppu, x, line);
  }
}

static void ppu_handlePixel(Ppu *ppu, int x, int y) {
  int r = 0, r2 = 0;
  int g = 0, g2 = 0;
  int b = 0, b2 = 0;
  if (!PPU_forcedBlank(ppu)) {
    int mainLayer = ppu_getPixel(ppu, x, y, false, &r, &g, &b);
    bool colorWindowState = ppu_getWindowState(ppu, 5, x);
    if (
      PPU_clipMode(ppu) == 3 ||
      (PPU_clipMode(ppu) == 2 && colorWindowState) ||
      (PPU_clipMode(ppu) == 1 && !colorWindowState)
      ) {
      r = 0;
      g = 0;
      b = 0;
    }
    int secondLayer = 5; // backdrop
    bool mathEnabled = mainLayer < 6 && (PPU_mathEnabled(ppu) >> mainLayer & 1) && !(
      PPU_preventMathMode(ppu) == 3 ||
      (PPU_preventMathMode(ppu) == 2 && colorWindowState) ||
      (PPU_preventMathMode(ppu) == 1 && !colorWindowState)
      );
    if ((mathEnabled && PPU_addSubscreen(ppu)) || PPU_pseudoHires(ppu) || PPU_mode(ppu) == 5 || PPU_mode(ppu) == 6) {
      secondLayer = ppu_getPixel(ppu, x, y, true, &r2, &g2, &b2);
    }
    // TODO: subscreen pixels can be clipped to black as well
    // TODO: math for subscreen pixels (add/sub sub to main)
    if (mathEnabled) {
      if (PPU_subtractColor(ppu)) {
        r -= (PPU_addSubscreen(ppu) && secondLayer != 5) ? r2 : PPU_fixedColorR(ppu);
        g -= (PPU_addSubscreen(ppu) && secondLayer != 5) ? g2 : PPU_fixedColorG(ppu);
        b -= (PPU_addSubscreen(ppu) && secondLayer != 5) ? b2 : PPU_fixedColorB(ppu);
      } else {
        r += (PPU_addSubscreen(ppu) && secondLayer != 5) ? r2 : PPU_fixedColorR(ppu);
        g += (PPU_addSubscreen(ppu) && secondLayer != 5) ? g2 : PPU_fixedColorG(ppu);
        b += (PPU_addSubscreen(ppu) && secondLayer != 5) ? b2 : PPU_fixedColorB(ppu);
      }
      if (PPU_halfColor(ppu) && (secondLayer != 5 || !PPU_addSubscreen(ppu))) {
        r >>= 1;
        g >>= 1;
        b >>= 1;
      }
      if (r > 31) r = 31;
      if (g > 31) g = 31;
      if (b > 31) b = 31;
      if (r < 0) r = 0;
      if (g < 0) g = 0;
      if (b < 0) b = 0;
    }
    if (!(PPU_pseudoHires(ppu) || PPU_mode(ppu) == 5 || PPU_mode(ppu) == 6)) {
      r2 = r; g2 = g; b2 = b;
    }
  }
  int row = y - 1;
  uint8 *pixelBuffer = (uint8 *)&ppu->renderBuffer[row * ppu->renderPitch + (x + ppu->extraLeftRight) * 4];
  pixelBuffer[0] = ((b << 3) | (b >> 2)) * PPU_brightness(ppu) / 15;
  pixelBuffer[1] = ((g << 3) | (g >> 2)) * PPU_brightness(ppu) / 15;
  pixelBuffer[2] = ((r << 3) | (r >> 2)) * PPU_brightness(ppu) / 15;
  pixelBuffer[3] = 0;
}

static int ppu_getPixel(Ppu *ppu, int x, int y, bool sub, int *r, int *g, int *b) {
  // figure out which color is on this location on main- or subscreen, sets it in r, g, b
  // returns which layer it is: 0-3 for bg layer, 4 or 6 for sprites (depending on palette), 5 for backdrop
  int actMode = PPU_mode(ppu) == 1 && PPU_bg3priority(ppu) ? 8 : PPU_mode(ppu);
  actMode = PPU_mode(ppu) == 7 && PPU_m7extBg(ppu) ? 9 : actMode;
  int layer = 5;
  int pixel = 0;
  for (int i = 0; i < layerCountPerMode[actMode]; i++) {
    int curLayer = layersPerMode[actMode][i];
    int curPriority = prioritysPerMode[actMode][i];
    bool layerActive = IS_SCREEN_ENABLED(ppu, sub, curLayer) && (
      !IS_SCREEN_WINDOWED(ppu, sub, curLayer) || !ppu_getWindowState(ppu, curLayer, x)
      );
    if (layerActive) {
      if (curLayer < 4) {
        // bg layer
        int lx = x;
        int ly = y;
        if (PPU_mosaicEnabled(ppu, curLayer) && PPU_mosaicSize(ppu) > 1) {
          lx -= lx % PPU_mosaicSize(ppu);
          ly -= (ly - ppu->mosaicStartLine) % PPU_mosaicSize(ppu);
        }
        if (PPU_mode(ppu) == 7) {
          pixel = ppu_getPixelForMode7(ppu, lx, curLayer, curPriority);
        } else {
          lx += ppu->hScroll[curLayer];
          if (PPU_mode(ppu) == 5 || PPU_mode(ppu) == 6) {
            lx *= 2;
            lx += (sub || PPU_mosaicEnabled(ppu, curLayer)) ? 0 : 1;
            if (PPU_interlace(ppu)) {
              ly *= 2;
              ly += (ppu->evenFrame || PPU_mosaicEnabled(ppu, curLayer)) ? 0 : 1;
            }
          }
          ly += ppu->vScroll[curLayer];
          if (PPU_mode(ppu) == 2 || PPU_mode(ppu) == 4 || PPU_mode(ppu) == 6) {
            ppu_handleOPT(ppu, curLayer, &lx, &ly);
          }
          pixel = ppu_getPixelForBgLayer(
            ppu, lx & 0x3ff, ly & 0x3ff,
            curLayer, curPriority
          );
        }
      } else {
        // get a pixel from the sprite buffer
        pixel = 0;
        if ((ppu->objBuffer.data[x + kPpuExtraLeftRight] >> 12) == SPRITE_PRIO_TO_PRIO_HI(curPriority))
          pixel = ppu->objBuffer.data[x + kPpuExtraLeftRight] & 0xff;
      }
    }
    if (pixel > 0) {
      layer = curLayer;
      break;
    }
  }
  if (PPU_directColor(ppu) && layer < 4 && bitDepthsPerMode[actMode][layer] == 8) {
    *r = ((pixel & 0x7) << 2) | ((pixel & 0x100) >> 7);
    *g = ((pixel & 0x38) >> 1) | ((pixel & 0x200) >> 8);
    *b = ((pixel & 0xc0) >> 3) | ((pixel & 0x400) >> 8);
  } else {
    uint16_t color = ppu->cgram[pixel & 0xff];
    *r = color & 0x1f;
    *g = (color >> 5) & 0x1f;
    *b = (color >> 10) & 0x1f;
  }
  if (layer == 4 && pixel < 0xc0) layer = 6; // sprites with palette color < 0xc0
  return layer;
}

static void ppu_handleOPT(Ppu *ppu, int layer, int *lx, int *ly) {
  int x = *lx;
  int y = *ly;
  int column = 0;
  if (PPU_mode(ppu) == 6) {
    column = ((x - (x & 0xf)) - ((ppu->hScroll[layer] * 2) & 0xfff0)) >> 4;
  } else {
    column = ((x - (x & 0x7)) - (ppu->hScroll[layer] & 0xfff8)) >> 3;
  }
  if (column > 0) {
    // fetch offset values from layer 3 tilemap
    int valid = layer == 0 ? 0x2000 : 0x4000;
    uint16_t hOffset = ppu_getOffsetValue(ppu, column - 1, 0);
    uint16_t vOffset = 0;
    if (PPU_mode(ppu) == 4) {
      if (hOffset & 0x8000) {
        vOffset = hOffset;
        hOffset = 0;
      }
    } else {
      vOffset = ppu_getOffsetValue(ppu, column - 1, 1);
    }
    if (PPU_mode(ppu) == 6) {
      // TODO: not sure if correct
      if (hOffset & valid) *lx = (((hOffset & 0x3f8) + (column * 8)) * 2) | (x & 0xf);
    } else {
      if (hOffset & valid) *lx = ((hOffset & 0x3f8) + (column * 8)) | (x & 0x7);
    }
    // TODO: not sure if correct for interlace
    if (vOffset & valid) *ly = (vOffset & 0x3ff) + (y - ppu->vScroll[layer]);
  }
}

static uint16_t ppu_getOffsetValue(Ppu *ppu, int col, int row) {
  int x = col * 8 + ppu->hScroll[2];
  int y = row * 8 + ppu->vScroll[2];
  int tileBits = PPU_bigTiles(ppu, 2) ? 4 : 3;
  int tileHighBit = PPU_bigTiles(ppu, 2) ? 0x200 : 0x100;
  uint16_t tilemapAdr = PPU_bgTilemapAdr(ppu, 2) + (((y >> tileBits) & 0x1f) << 5 | ((x >> tileBits) & 0x1f));
  if ((x & tileHighBit) && PPU_bgTilemapWider(ppu, 2)) tilemapAdr += 0x400;
  if ((y & tileHighBit) && PPU_bgTilemapHigher(ppu, 2)) tilemapAdr += PPU_bgTilemapWider(ppu, 2) ? 0x800 : 0x400;
  return ppu->vram[tilemapAdr & 0x7fff];
}

static int ppu_getPixelForBgLayer(Ppu *ppu, int x, int y, int layer, bool priority) {
  // figure out address of tilemap word and read it
  bool wideTiles = PPU_bigTiles(ppu, layer) || PPU_mode(ppu) == 5 || PPU_mode(ppu) == 6;
  int tileBitsX = wideTiles ? 4 : 3;
  int tileHighBitX = wideTiles ? 0x200 : 0x100;
  int tileBitsY = PPU_bigTiles(ppu, layer) ? 4 : 3;
  int tileHighBitY = PPU_bigTiles(ppu, layer) ? 0x200 : 0x100;
  uint16_t tilemapAdr = PPU_bgTilemapAdr(ppu, layer) + (((y >> tileBitsY) & 0x1f) << 5 | ((x >> tileBitsX) & 0x1f));
  if ((x & tileHighBitX) && PPU_bgTilemapWider(ppu, layer)) tilemapAdr += 0x400;
  if ((y & tileHighBitY) && PPU_bgTilemapHigher(ppu, layer)) tilemapAdr += PPU_bgTilemapWider(ppu, layer) ? 0x800 : 0x400;
  uint16_t tile = ppu->vram[tilemapAdr & 0x7fff];
  // check priority, get palette
  if (((bool)(tile & 0x2000)) != priority) return 0; // wrong priority
  int paletteNum = (tile & 0x1c00) >> 10;
  // figure out position within tile
  int row = (tile & 0x8000) ? 7 - (y & 0x7) : (y & 0x7);
  int col = (tile & 0x4000) ? (x & 0x7) : 7 - (x & 0x7);
  int tileNum = tile & 0x3ff;
  if (wideTiles) {
    // if unflipped right half of tile, or flipped left half of tile
    if (((bool)(x & 8)) ^ ((bool)(tile & 0x4000))) tileNum += 1;
  }
  if (PPU_bigTiles(ppu, layer)) {
    // if unflipped bottom half of tile, or flipped upper half of tile
    if (((bool)(y & 8)) ^ ((bool)(tile & 0x8000))) tileNum += 0x10;
  }
  // read tiledata, ajust palette for mode 0
  int bitDepth = bitDepthsPerMode[PPU_mode(ppu)][layer];
  if (PPU_mode(ppu) == 0) paletteNum += 8 * layer;
  // plane 1 (always)
  int paletteSize = 4;
  uint16_t plane1 = ppu->vram[(PPU_bgTileAdr(ppu, layer) + ((tileNum & 0x3ff) * 4 * bitDepth) + row) & 0x7fff];
  int pixel = (plane1 >> col) & 1;
  pixel |= ((plane1 >> (8 + col)) & 1) << 1;
  // plane 2 (for 4bpp, 8bpp)
  if (bitDepth > 2) {
    paletteSize = 16;
    uint16_t plane2 = ppu->vram[(PPU_bgTileAdr(ppu, layer) + ((tileNum & 0x3ff) * 4 * bitDepth) + 8 + row) & 0x7fff];
    pixel |= ((plane2 >> col) & 1) << 2;
    pixel |= ((plane2 >> (8 + col)) & 1) << 3;
  }
  // plane 3 & 4 (for 8bpp)
  if (bitDepth > 4) {
    paletteSize = 256;
    uint16_t plane3 = ppu->vram[(PPU_bgTileAdr(ppu, layer) + ((tileNum & 0x3ff) * 4 * bitDepth) + 16 + row) & 0x7fff];
    pixel |= ((plane3 >> col) & 1) << 4;
    pixel |= ((plane3 >> (8 + col)) & 1) << 5;
    uint16_t plane4 = ppu->vram[(PPU_bgTileAdr(ppu, layer) + ((tileNum & 0x3ff) * 4 * bitDepth) + 24 + row) & 0x7fff];
    pixel |= ((plane4 >> col) & 1) << 6;
    pixel |= ((plane4 >> (8 + col)) & 1) << 7;
  }
  // return cgram index, or 0 if transparent, palette number in bits 10-8 for 8-color layers
  return pixel == 0 ? 0 : paletteSize * paletteNum + pixel;
}

static void ppu_calculateMode7Starts(Ppu *ppu, int y) {
  // expand 13-bit values to signed values
  int hScroll = ((int16_t)(ppu->m7matrix[6] << 3)) >> 3;
  int vScroll = ((int16_t)(ppu->m7matrix[7] << 3)) >> 3;
  int xCenter = ((int16_t)(ppu->m7matrix[4] << 3)) >> 3;
  int yCenter = ((int16_t)(ppu->m7matrix[5] << 3)) >> 3;
  // do calculation
  int clippedH = hScroll - xCenter;
  int clippedV = vScroll - yCenter;
  clippedH = (clippedH & 0x2000) ? (clippedH | ~1023) : (clippedH & 1023);
  clippedV = (clippedV & 0x2000) ? (clippedV | ~1023) : (clippedV & 1023);
  if (PPU_mosaicEnabled(ppu, 0) && PPU_mosaicSize(ppu) > 1) {
    y -= (y - ppu->mosaicStartLine) % PPU_mosaicSize(ppu);
  }
  uint8_t ry = PPU_m7yFlip(ppu) ? 255 - y : y;
  ppu->m7startX = (
    ((ppu->m7matrix[0] * clippedH) & ~63) +
    ((ppu->m7matrix[1] * ry) & ~63) +
    ((ppu->m7matrix[1] * clippedV) & ~63) +
    (xCenter << 8)
    );
  ppu->m7startY = (
    ((ppu->m7matrix[2] * clippedH) & ~63) +
    ((ppu->m7matrix[3] * ry) & ~63) +
    ((ppu->m7matrix[3] * clippedV) & ~63) +
    (yCenter << 8)
    );
}

static int ppu_getPixelForMode7(Ppu *ppu, int x, int layer, bool priority) {
  uint8_t rx = PPU_m7xFlip(ppu) ? 255 - x : x;
  int xPos = (ppu->m7startX + ppu->m7matrix[0] * rx) >> 8;
  int yPos = (ppu->m7startY + ppu->m7matrix[2] * rx) >> 8;
  bool outsideMap = xPos < 0 || xPos >= 1024 || yPos < 0 || yPos >= 1024;
  xPos &= 0x3ff;
  yPos &= 0x3ff;
  if (!PPU_m7largeField(ppu)) outsideMap = false;
  uint8_t tile = outsideMap ? 0 : ppu->vram[(yPos >> 3) * 128 + (xPos >> 3)] & 0xff;
  uint8_t pixel = outsideMap && !PPU_m7charFill(ppu) ? 0 : ppu->vram[tile * 64 + (yPos & 7) * 8 + (xPos & 7)] >> 8;
  if (layer == 1) {
    if (((bool)(pixel & 0x80)) != priority) return 0;
    return pixel & 0x7f;
  }
  return pixel;
}

static bool ppu_getWindowState(Ppu *ppu, int layer, int x) {
  uint32 winflags = GET_WINDOW_FLAGS(ppu, layer);

  if (!(winflags & kWindow1Enabled) && !(winflags & kWindow2Enabled)) {
    return false;
  }
  if ((winflags & kWindow1Enabled) && !(winflags & kWindow2Enabled)) {
    bool test = x >= ppu->window1left && x <= ppu->window1right;
    return (winflags & kWindow1Inversed) ? !test : test;
  }
  if (!(winflags & kWindow1Enabled) && (winflags & kWindow2Enabled)) {
    bool test = x >= ppu->window2left && x <= ppu->window2right;
    return (winflags & kWindow2Inversed) ? !test : test;
  }
  bool test1 = x >= ppu->window1left && x <= ppu->window1right;
  bool test2 = x >= ppu->window2left && x <= ppu->window2right;
  if (winflags & kWindow1Inversed) test1 = !test1;
  if (winflags & kWindow2Inversed) test2 = !test2;
  switch (ppu->wbgobjlog >> (layer * 2) & 3) {
  case 0: return test1 || test2;
  case 1: return test1 && test2;
  case 2: return test1 != test2;
  case 3: return test1 == test2;
  }
  return false;
}
