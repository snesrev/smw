
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "snes.h"
#include "cpu.h"
#include "apu.h"
#include "dma.h"
#include "ppu.h"
#include "cart.h"
#include "input.h"
#include "../tracing.h"
#include "../variables.h"
#include "../common_rtl.h"

extern bool g_is_uploading_apu;
void RtlSetUploadingApu(bool uploading);

int snes_frame_counter;
static const double apuCyclesPerMaster = (32040 * 32) / (1364 * 262 * 60.0);

static uint8_t snes_readReg(Snes* snes, uint16_t adr);
static void snes_writeReg(Snes* snes, uint16_t adr, uint8_t val);

Snes* snes_init(uint8_t *ram) {
  Snes* snes = malloc(sizeof(Snes));
  snes->ram = ram;
  snes->debug_cycles = false;
  snes->debug_apu_cycles = false;
  snes->runningWhichVersion = 0;

  snes->cpu = cpu_init(snes, 0);
  snes->apu = apu_init();
  snes->dma = dma_init(snes);
  snes->my_ppu = ppu_init(snes);
  snes->snes_ppu = ppu_init(snes);
  snes->ppu = snes->snes_ppu;
  snes->cart = cart_init(snes);
  snes->input1 = input_init(snes);
  snes->input2 = input_init(snes);
  return snes;
}

void snes_free(Snes* snes) {
  cpu_free(snes->cpu);
  apu_free(snes->apu);
  dma_free(snes->dma);
  ppu_free(snes->ppu);
  cart_free(snes->cart);
  input_free(snes->input1);
  input_free(snes->input2);
  free(snes);
}

void snes_saveload(Snes *snes, SaveLoadInfo *sli) {
  cpu_saveload(snes->cpu, sli);
  apu_saveload(snes->apu, sli);
  dma_saveload(snes->dma, sli);
  ppu_saveload(snes->ppu, sli);
  cart_saveload(snes->cart, sli);

  sli->func(sli, &snes->hPos, offsetof(Snes, openBus) + 1 - offsetof(Snes, hPos));
  sli->func(sli, snes->ram, 0x20000);
  sli->func(sli, &snes->ramAdr, 4);

  snes->runningWhichVersion = 0;
}

void snes_reset(Snes* snes, bool hard) {
  cart_reset(snes->cart); // reset cart first, because resetting cpu will read from it (reset vector)
  cpu_reset(snes->cpu);
  apu_reset(snes->apu);
  dma_reset(snes->dma);
  ppu_reset(snes->my_ppu);
  ppu_reset(snes->snes_ppu);
  input_reset(snes->input1);
  input_reset(snes->input2);
  if (hard)
    memset(snes->ram, 0, 0x20000);
  snes->ramAdr = 0;
  snes->hPos = 0;
  snes->vPos = 0;
  snes->frames = 0;
  snes->cpuCyclesLeft = 52; // 5 reads (8) + 2 IntOp (6)
  snes->cpuMemOps = 0;
  snes->apuCatchupCycles = 0.0;
  snes->hIrqEnabled = false;
  snes->vIrqEnabled = false;
  snes->nmiEnabled = false;
  snes->hTimer = 0x1ff;
  snes->vTimer = 0x1ff;
  snes->inNmi = false;
  snes->inIrq = false;
  snes->inVblank = false;
  memset(snes->portAutoReadX, 0, sizeof(snes->portAutoReadX));
  snes->autoJoyRead = false;
  snes->autoJoyTimer = 0;
  snes->ppuLatch = false;
  snes->multiplyA = 0xff;
  snes->multiplyResult = 0xfe01;
  snes->divideA = 0xffff;
  snes->divideResult = 0x101;
  snes->fastMem = false;
  snes->openBus = 0;
}

void snes_runFrame(Snes *snes) {
  snes_frame_counter++;

  bool old = true;
  for (;;) {
    snes_runCycle(snes);
    if (snes->inVblank != 0 && snes->inVblank != old) {
      break;
    }
    old = snes->inVblank;
  }
}

void snes_handle_pos_stuff(Snes *snes) {
  // check for h/v timer irq's
  if (snes->vIrqEnabled && snes->hIrqEnabled) {
    if (snes->vPos == (snes->vTimer + 1) && snes->hPos == (4 * snes->hTimer)) {
      snes->inIrq = true;
      snes->cpu->irqWanted = true; // request IRQ on CPU
    }
  } else if (snes->vIrqEnabled && !snes->hIrqEnabled) {
    if (snes->vPos == (snes->vTimer + 1) && snes->hPos == 1024) {
      snes->inIrq = true;
      snes->cpu->irqWanted = true; // request IRQ on CPU
    }
  } else if (!snes->vIrqEnabled && snes->hIrqEnabled) {
    if (snes->hPos == (4 * snes->hTimer)) {
      snes->inIrq = true;
      snes->cpu->irqWanted = true; // request IRQ on CPU
    }
  }

  if (snes->hPos == 0) {
    // end of hblank, do most vPos-tests
    bool startingVblank = false;
    if (snes->vPos == 0) {
      // end of vblank
      snes->inVblank = false;
      snes->inNmi = false;
      dma_initHdma(snes->dma);
    } else if (snes->vPos == 225) {
      // ask the ppu if we start vblank now or at vPos 240 (overscan)
      startingVblank = !ppu_checkOverscan(snes->ppu);
    } else if (snes->vPos == 240) {
      // if we are not yet in vblank, we had an overscan frame, set startingVblank
      if (!snes->inVblank) startingVblank = true;
    }
    if (startingVblank) {
      // if we are starting vblank
      ppu_handleVblank(snes->ppu);
      snes->inVblank = true;
      snes->inNmi = true;
      if (snes->nmiEnabled) {
        //snes->cpu->nmiWanted = true; // request NMI on CPU
      }
      if (snes->autoJoyRead) {
        // TODO: this starts a little after start of vblank
        snes->autoJoyTimer = 0;
      }
    }
  } else if (snes->hPos == 512) {
    // render the line halfway of the screen for better compatibility
    if (!snes->inVblank && !snes->disableRender) {
      ppu_runLine(snes->ppu, snes->vPos);
    }
  } else if (snes->hPos == 1024) {
    // start of hblank
    if (!snes->inVblank)
      dma_doHdma(snes->dma);
  }
  // handle autoJoyRead-timer
  //if (snes->autoJoyTimer > 0) snes->autoJoyTimer -= 2;
  // increment position
  // TODO: exact frame timing (line 240 on odd frame is 4 cycles shorter,
  //   even frames in interlace is 1 extra line)
  snes->hPos += 2;
  if (snes->hPos == 1364) {
    snes->hPos = 0;
    snes->vPos++;
    if (snes->vPos == 262) {
      snes->vPos = 0;
      snes->frames++;
//      snes_catchupApu(snes); // catch up the apu at the end of the frame
    }
  }
}

void snes_runCycle(Snes* snes) {
  snes->apuCatchupCycles += apuCyclesPerMaster * 2.0;

  input_cycle(snes->input1);
  input_cycle(snes->input2);

  // if not in dram refresh, if we are busy with hdma/dma, do that, else do cpu cycle
  if (snes->hPos < 536 || snes->hPos >= 576) {
    snes_runCpu(snes);
  }

  snes_handle_pos_stuff(snes);
 }
#define IS_ADR(x) (x == 0xffffff)

void snes_runCpu(Snes *snes) {
  uint32_t pc = snes->cpu->k << 16 | snes->cpu->pc;

  if (snes->debug_cycles) {
    char line[80];
    getProcessorStateCpu(snes, line);
    puts(line);
    line[0] = 0;
  }
  snes->cpuMemOps = 0;
  cpu_runOpcode(snes->cpu);
}

void snes_catchupApu(Snes* snes) {
  if (snes->apuCatchupCycles > 10000)
    snes->apuCatchupCycles = 10000;

  int catchupCycles = (int) snes->apuCatchupCycles;

  for(int i = 0; i < catchupCycles; i++) {
    apu_cycle(snes->apu);
  }
  snes->apuCatchupCycles -= (double) catchupCycles;
}

uint8_t snes_readBBus(Snes* snes, uint8_t adr) {
  if(adr < 0x40) {
    return ppu_read(snes->ppu, adr);
  }
  if(adr < 0x80) {
//    assert(0);
    if (!g_is_uploading_apu)
      return 0;
    snes->apuCatchupCycles = 32;
    snes_catchupApu(snes); // catch up the apu before reading
    return snes->apu->outPorts[adr & 0x3];
  }
  if(adr == 0x80) {
    uint8_t ret = snes->ram[snes->ramAdr++];
    snes->ramAdr &= 0x1ffff;
    return ret;
  }

  assert(0);
  return snes->openBus;
}

void snes_writeBBus(Snes* snes, uint8_t adr, uint8_t val) {
  if(adr < 0x40) {
    ppu_write(snes->ppu, adr, val);
    return;
  }
  if(adr < 0x80) {
    RtlApuWrite(0x2100 + adr, val);
    return;
  }
  switch(adr) {
    case 0x80: {
      snes->ram[snes->ramAdr++] = val;
      snes->ramAdr &= 0x1ffff;
      break;
    }
    case 0x81: {
      snes->ramAdr = (snes->ramAdr & 0x1ff00) | val;
      break;
    }
    case 0x82: {
      snes->ramAdr = (snes->ramAdr & 0x100ff) | (val << 8);
      break;
    }
    case 0x83: {
      snes->ramAdr = (snes->ramAdr & 0x0ffff) | ((val & 1) << 16);
      break;
    }
  }
}

static uint16_t SwapInputBits(uint16_t x) {
  uint16_t r = 0;
  for (int i = 0; i < 16; i++, x >>= 1)
    r = r * 2 + (x & 1);
  return r;
}

static uint8_t snes_readReg(Snes* snes, uint16_t adr) {
  switch(adr) {
    case 0x4210: {
      uint8_t val = 0x2; // CPU version (4 bit)
      val |= snes->inNmi << 7;

      return val | (snes->openBus & 0x70);
    }
    case 0x4211: {
      uint8_t val = snes->inIrq << 7;
      snes->inIrq = false;
      snes->cpu->irqWanted = false;
      return val | (snes->openBus & 0x7f);
    }
    case 0x4212: {
      uint8_t val = (snes->autoJoyTimer > 0);
      val |= (snes->hPos >= 1024) << 6;
      val |= snes->inVblank << 7;
      return val | (snes->openBus & 0x3e);
    }
    case 0x4213:
      return snes->ppuLatch << 7; // IO-port
    case 0x4214:
      return snes->divideResult & 0xff;
    case 0x4215:
      return snes->divideResult >> 8;
    case 0x4216:
      return snes->multiplyResult & 0xff;
    case 0x4217:
      return snes->multiplyResult >> 8;
    case 0x4218:
      return SwapInputBits(snes->input1->currentState) & 0xff;
    case 0x4219:
      return SwapInputBits(snes->input1->currentState) >> 8;
    case 0x421a:
    case 0x421c:
    case 0x421e:
    case 0x421b:
    case 0x421d:
    case 0x421f:
      return 0;

    default: {
      return snes->openBus;
    }
  }
}

static void snes_writeReg(Snes* snes, uint16_t adr, uint8_t val) {
  switch(adr) {
    case 0x4200: {
      snes->autoJoyRead = val & 0x1;
      if(!snes->autoJoyRead) snes->autoJoyTimer = 0;
      snes->hIrqEnabled = val & 0x10;
      snes->vIrqEnabled = val & 0x20;
      snes->nmiEnabled = val & 0x80;
      if(!snes->hIrqEnabled && !snes->vIrqEnabled) {
        snes->inIrq = false;
        snes->cpu->irqWanted = false;
      }
      // TODO: enabling nmi during vblank with inNmi still set generates nmi
      //   enabling virq (and not h) on the vPos that vTimer is at generates irq (?)
      break;
    }
    case 0x4201: {
      if(!(val & 0x80) && snes->ppuLatch) {
        // latch the ppu
        ppu_read(snes->ppu, 0x37);
      }
      snes->ppuLatch = val & 0x80;
      break;
    }
    case 0x4202: {
      snes->multiplyA = val;
      break;  
    }
    case 0x4203: {
      snes->multiplyResult = snes->multiplyA * val;
      break;
    }
    case 0x4204: {
      snes->divideA = (snes->divideA & 0xff00) | val;
      break;
    }
    case 0x4205: {
      snes->divideA = (snes->divideA & 0x00ff) | (val << 8);
      break;
    }
    case 0x4206: {
      if(val == 0) {
        snes->divideResult = 0xffff;
        snes->multiplyResult = snes->divideA;
      } else {
        snes->divideResult = snes->divideA / val;
        snes->multiplyResult = snes->divideA % val;
      }
      break;
    }
    case 0x4207: {
      snes->hTimer = (snes->hTimer & 0x100) | val;
      break;
    }
    case 0x4208: {
      snes->hTimer = (snes->hTimer & 0x0ff) | ((val & 1) << 8);
      break;
    }
    case 0x4209: {
      snes->vTimer = (snes->vTimer & 0x100) | val;
      break;
    }
    case 0x420a: {
      snes->vTimer = (snes->vTimer & 0x0ff) | ((val & 1) << 8);
      break;
    }
    case 0x420b: {
      if (val == 2) {
        uint32_t t = snes->dma->channel[1].aBank << 16 | snes->dma->channel[1].aAdr;
        int data = snes_read(snes, t) | snes_read(snes, t + 1) << 8;

        if (0)printf("DMA: 0x%x -> 0x%x (ppu 0x%x), 0x%x bytes, data 0x%x\n",
               t, snes->dma->channel[1].bAdr,
               snes->ppu->vramPointer, snes->dma->channel[1].size, data);
      }
      dma_startDma(snes->dma, val, false);
      while (dma_cycle(snes->dma)) {}
      break;
    }
    case 0x420c: {
      dma_startDma(snes->dma, val, true);
      break;
    }
    case 0x420d: {
      snes->fastMem = val & 0x1;
      break;
    }
    default: {
      break;
    }
  }
}

uint8_t snes_read(Snes* snes, uint32_t adr) {
  uint8_t bank = adr >> 16;
  adr &= 0xffff;
  if(bank == 0x7e || bank == 0x7f) {
    return snes->ram[((bank & 1) << 16) | adr]; // ram
  }
  if(bank < 0x40 || (bank >= 0x80 && bank < 0xc0)) {
    if(adr < 0x2000) {
      return snes->ram[adr]; // ram mirror
    }
    if(adr >= 0x2100 && adr < 0x2200) {
      return snes_readBBus(snes, adr & 0xff); // B-bus
    }
    if (adr == 0x4016 || adr == 0x4017) {
      return input_read(snes->input1) | (snes->openBus & 0xfc);
    }
    if(adr >= 0x4200 && adr < 0x4220 || adr >= 0x4218 && adr < 0x4220) {
      return snes_readReg(snes, adr); // internal registers
    }
    if(adr >= 0x4300 && adr < 0x4380) {
      return dma_read(snes->dma, adr); // dma registers
    }
  }
  // read from cart
  return cart_read(snes->cart, bank, adr);
}

void LogWrite(Snes *snes, uint32_t adr, uint8_t val) {
  printf("@%d: Write to 0x%x = 0x%.2x: 0x%x: r18=0x%x: r20=0x%x: a = 0x%x, x = 0x%x, y = 0x%x, c = %d\n",
         snes_frame_counter, adr, val, snes->cpu->k << 16 | snes->cpu->pc,
         snes->ram[0x12] | snes->ram[0x13] << 8, 
          snes->ram[0x14] | snes->ram[0x15] << 8,
         snes->cpu->a, snes->cpu->x, snes->cpu->y, snes->cpu->c);
}

void snes_write(Snes* snes, uint32_t adr, uint8_t val) {
  uint8_t bank = adr >> 16;
  adr &= 0xffff;
  if(bank == 0x7e || bank == 0x7f) {
    uint32_t addr = ((bank & 1) << 16) | adr; 
    snes->ram[addr] = val; // ram
    if (IS_ADR(addr)) {
      LogWrite(snes, adr, val);
    }
  }
  if(bank < 0x40 || (bank >= 0x80 && bank < 0xc0)) {
    if(adr < 0x2000) {
      snes->ram[adr] = val; // ram mirror
      if (IS_ADR(adr)) {
        LogWrite(snes, adr, val);
      }
    }
    if(adr >= 0x2100 && adr < 0x2200) {
      snes_writeBBus(snes, adr & 0xff, val); // B-bus
    }
    if(adr >= 0x4200 && adr < 0x4220) {
      snes_writeReg(snes, adr, val); // internal registers
    }
    if(adr >= 0x4300 && adr < 0x4380) {
      dma_write(snes->dma, adr, val); // dma registers
    }
  }
  // write to cart
  cart_write(snes->cart, bank, adr, val);
}


uint8_t snes_cpuRead(Snes* snes, uint32_t adr) {
  snes->cpuMemOps++;
  snes->cpuCyclesLeft += 8;
  return snes_read(snes, adr);
}

void snes_cpuWrite(Snes* snes, uint32_t adr, uint8_t val) {
  snes->cpuMemOps++;
  snes->cpuCyclesLeft += 8;
  snes_write(snes, adr, val);
}

