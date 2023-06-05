#include "smbll_consts.h"
#include "smbll_funcs.h"
#include "smbll_rtl.h"
#include "smbll_variables.h"

void (*funcs_1BA38[4])() = {&Smbll_MaybePauseMenu_State0, &Smbll_MaybePauseMenu_State1, &Smbll_MaybePauseMenu_State2,
                            &Smbll_MaybePauseMenu_State3};  // weak

uint8 byte_17FD9[72] = {0u,  0u,  0u,  0u,  0u,  0u,  0u,  12u, 28u, 28u, 0u,  0u,  0u,  12u, 28u, 44u, 28u, 28u,
                        28u, 45u, 44u, 28u, 28u, 28u, 44u, 45u, 44u, 45u, 61u, 28u, 28u, 28u, 45u, 28u, 44u, 45u,
                        64u, 28u, 28u, 28u, 28u, 28u, 28u, 28u, 61u, 28u, 44u, 28u, 28u, 28u, 45u, 45u, 76u, 28u,
                        28u, 86u, 86u, 28u, 86u, 28u, 86u, 28u, 89u, 89u, 89u, 93u, 89u, 89u, 89u, 89u, 89u, 28u};  // weak

void Smbll_SetupLayer2Bg() {
  uint16 i;   // si
  uint16 v1;  // ax
  int16 v2;   // ax

  Smbll_sub_18F08();
  enable_layer3_bgflag = 0;
  smbll_varF35 = area_data_addr_index;
  if (area_data_addr_index == 35 && HIBYTE(screen_left_xpos16) == 12)
    area_data_addr_index = 71;
  for (i = 0; i != 256; i += 2) {
    *(uint16 *)&layer2_bgdata[i] = 0;
    *(uint16 *)&layer2_bgdata[i + 256] = 0;
    *(uint16 *)&layer2_bgdata[i + 512] = 0;
    *(uint16 *)&layer2_bgdata[i + 768] = 0;
    *(uint16 *)&layer2_bgdata[i + 1024] = 0;
    *(uint16 *)&layer2_bgdata[i + 1280] = 0;
    *(uint16 *)&layer2_bgdata[i + 1536] = 0;
    *(uint16 *)&layer2_bgdata[i + 1792] = 0;
    *(uint16 *)&layer2_bgdata[i + 2048] = 0;
    *(uint16 *)&layer2_bgdata[i + 2304] = 0;
    *(uint16 *)&layer2_bgdata[i + 2560] = 0;
    *(uint16 *)&layer2_bgdata[i + 2816] = 0;
    *(uint16 *)&layer2_bgdata[i + 3072] = 0;
    *(uint16 *)&layer2_bgdata[i + 3328] = 0;
    *(uint16 *)&layer2_bgdata[i + 3584] = 0;
    *(uint16 *)&layer2_bgdata[i + 3840] = 0;
    *(uint16 *)&layer2_bgdata[i + 4096] = 0;
    *(uint16 *)&layer2_bgdata[i + 4352] = 0;
    *(uint16 *)&layer2_bgdata[i + 4608] = 0;
  }
  layer2_bg_0EC0 = 0;
  if (override_area_data_addr_index)
    *(uint16 *)&area_data_addr_index = override_area_data_addr_index;
  *(uint16 *)&R2_ = kword_2AE02[(uint16)(2 * area_data_addr_index) >> 1];
  while (1) {
    while (1) {
      *(uint16 *)&R4_ = *(uint16 *)&kbyte_2B6A1[*(uint16 *)&R2_];
      ++*(uint16 *)&R2_;
      ++*(uint16 *)&R2_;
      *(uint16 *)&tempEF = (uint16)(*(uint16 *)&R4_ & 0x3F0) >> 4;
      *(uint16 *)&tempF1 = R4_ & 0xF;
      *(uint16 *)&tempED = (uint8)((uint16)(*(uint16 *)&R4_ & 0xE000 | (*(uint16 *)&R4_ >> 1) & 0xE00) >> 8);
      if ((tempED & 0xF0) == 224)
        break;
      LOBYTE(v2) = HIBYTE(layer2_bg_0EC0);
      HIBYTE(v2) = layer2_bg_0EC0;
      *(uint16 *)&tempEB = *(uint16 *)&tempED + v2;
      if (*(uint16 *)&tempEF < 0x10u) {
        if (Smbll_SetupLayer2Bg_Callfunc(2 * *(uint16 *)&tempEF, 2 * *(uint16 *)&area_data_addr_index))
          return;
      } else {
        Smbll_SetupLayer2BgB();
      }
    }
    if (*(uint16 *)&tempEF == 63)
      break;
    Smbll_SetupLayer2BgA();
  }
  ++layer2_bg_0EC0;
  ++layer2_bg_0EC0;
  LOBYTE(v1) = HIBYTE(layer2_bg_0EC0);
  HIBYTE(v1) = layer2_bg_0EC0;
  *(uint16 *)&layer2_bgdata[v1] = -1;
  Smbll_GenerateLayer2Map16();
}

uint16 Smbll_SetupLayer2Bg_Callfunc(uint16 k, uint16 j) {
  uint16 v2;   // di
  uint16 v3;   // si
  uint16 v5;   // di
  uint16 v6;   // si
  uint16 v7;   // ax
  uint16 v8;   // di
  uint16 v9;   // si
  uint16 v10;  // si
  uint16 v11;  // si
  uint16 v12;  // ax
  int16 v13;   // si
  uint16 v14;  // si
  int v15;     // edx
  uint16 v16;  // di
  uint16 v17;  // di
  int16 v18;   // si
  uint16 v19;  // si
  uint8 v20;   // al
  uint16 v21;  // si
  uint8 v22;   // al
  uint8 v23;   // al
  uint8 v24;   // al
  uint8 v25;   // al
  uint8 v26;   // al
  uint16 v27;  // si
  uint8 v28;   // al
  uint8 v29;   // al
  uint16 v30;  // si
  uint8 v31;   // al
  uint16 v32;  // si
  uint16 v33;  // di
  uint8 v34;   // al
  uint16 v35;  // si
  uint16 v36;  // di
  uint8 v37;   // al
  uint16 v38;  // si
  uint16 v39;  // di
  uint8 v40;   // al
  uint16 v41;  // di
  uint16 v42;  // si
  uint16 v43;  // si
  uint16 v44;  // si
  uint16 v45;  // di
  uint16 v46;  // si
  uint8 v47;   // al
  uint16 v48;  // si
  uint16 m;    // di
  uint16 v50;  // si
  uint16 v51;  // si
  uint8 v52;   // al
  uint16 v53;  // si
  uint8 v54;   // al
  uint16 v55;  // si
  int v56;     // edx
  uint16 v57;  // si
  uint16 v58;  // di
  uint16 v59;  // di
  uint16 v60;  // si
  uint16 v61;  // si
  uint16 v62;  // di
  uint16 v63;  // si
  uint16 v64;  // si
  uint16 v65;  // si
  uint16 v66;  // si
  uint16 i;    // di
  uint16 v68;  // si
  uint16 n;    // si

  switch (byte_17FD9[j >> 1] + (k >> 1)) {
  case 0:
  case 1: goto LABEL_174;
  case 2: v63 = *(uint16 *)&tempEB; break;
  case 3:
    v64 = *(uint16 *)&tempEB;
    do {
      if (layer2_bgdata[v64 + 32] == 31) {
        layer2_bgdata[v64 + 16] = kbyte_28CF3[3];
        layer2_bgdata[v64 + 17] = kbyte_28CF3[4];
        layer2_bgdata[v64 + 32] = kbyte_28CF3[5];
        layer2_bgdata[v64 + 33] = kbyte_28CF3[6];
        layer2_bgdata[v64 + 48] = kbyte_28CF3[7];
        layer2_bgdata[v64 + 49] = kbyte_28CF3[8];
        layer2_bgdata[v64 + 64] = kbyte_28CF3[9];
        layer2_bgdata[v64++ + 65] = kbyte_28CF3[10];
        --tempF1;
      } else {
        layer2_bgdata[v64 + 32] = kbyte_28CF3[0];
        layer2_bgdata[v64 + 48] = kbyte_28CF3[1];
        layer2_bgdata[v64 + 64] = kbyte_28CF3[2];
      }
      ++v64;
      --tempF1;
    } while ((tempF1 & 0x80u) == 0);
    return 0;
  case 4:
    v65 = *(uint16 *)&tempEB;
    if (layer2_bgdata[*(uint16 *)&tempEB + 32] == 12) {
      layer2_bgdata[*(uint16 *)&tempEB + 16] = kbyte_28D68[0];
      layer2_bgdata[v65 + 17] = kbyte_28D68[1];
      layer2_bgdata[v65 + 32] = kbyte_28D68[2];
      layer2_bgdata[v65 + 33] = kbyte_28D68[3];
      layer2_bgdata[v65 + 48] = kbyte_28D68[4];
      layer2_bgdata[v65 + 49] = kbyte_28D68[5];
      layer2_bgdata[v65 + 64] = kbyte_28D68[6];
      layer2_bgdata[v65 + 65] = kbyte_28D68[7];
    } else {
      layer2_bgdata[*(uint16 *)&tempEB + 16] = kbyte_28D68[8];
      layer2_bgdata[v65 + 17] = kbyte_28D68[9];
      layer2_bgdata[v65 + 32] = kbyte_28D68[10];
      layer2_bgdata[v65 + 33] = kbyte_28D68[11];
      layer2_bgdata[v65 + 48] = kbyte_28D68[12];
      layer2_bgdata[v65 + 49] = kbyte_28D68[13];
      layer2_bgdata[v65 + 64] = kbyte_28D68[14];
      layer2_bgdata[v65 + 65] = kbyte_28D68[15];
    }
    --*(uint16 *)&tempF1;
    --*(uint16 *)&tempF1;
    --*(uint16 *)&tempF1;
    *(uint16 *)&tempEB += 48;
    *(uint16 *)&tempEF = 1;
LABEL_174:
    v61 = *(uint16 *)&tempEB;
    v62 = *(uint16 *)&tempEF;
    do {
      layer2_bgdata[v61 + 32] = kbyte_28BE5[v62];
      layer2_bgdata[v61 + 33] = kbyte_28BE5[v62 + 2];
      v61 += 16;
      --tempF1;
    } while ((tempF1 & 0x80u) == 0);
    return 0;
  case 5:
    v66 = *(uint16 *)&tempEB;
    for (i = 0; i != 20; i += 4) {
      layer2_bgdata[v66 + 32] = kbyte_28E0E[i];
      layer2_bgdata[v66 + 33] = kbyte_28E0E[i + 1];
      layer2_bgdata[v66 + 34] = kbyte_28E0E[i + 2];
      layer2_bgdata[v66 + 35] = kbyte_28E0E[i + 3];
      v66 += 16;
    }
    return 0;
  case 6:
    v59 = 0;
    v60 = *(uint16 *)&tempEB;
    do {
      layer2_bgdata[v60 + 32] = kbyte_28BB2[v59];
      layer2_bgdata[v60 + 33] = kbyte_28BB2[v59 + 1];
      v60 += 16;
      v59 += 2;
    } while (v59 != 8);
    return 0;
  case 7:
    v55 = *(uint16 *)&tempEB;
    *(uint16 *)&tempF1 = 6;
    v56 = *(uint16 *)&tempEB;
    layer2_bgdata[*(uint16 *)&tempEB + 32] = kbyte_28AF7[0];
    layer2_bgdata[v56 + 33] = kbyte_28AF7[1];
    do {
      layer2_bgdata[v55 + 48] = kbyte_28AF7[2];
      layer2_bgdata[v55 + 49] = kbyte_28AF7[3];
      v55 += 16;
      --tempF1;
    } while (tempF1);
    layer2_bgdata[v55 + 48] = kbyte_28AF7[4];
    layer2_bgdata[v55 + 49] = kbyte_28AF7[5];
    layer2_bgdata[v55 + 64] = kbyte_28AF7[6];
    layer2_bgdata[v55 + 65] = kbyte_28AF7[7];
    layer2_bgdata[v55 + 66] = kbyte_28AF7[8];
    return 0;
  case 8:
    v57 = *(uint16 *)&tempEB + 1;
    tempE5 = 0;
    v58 = 0;
    do {
      layer2_bgdata[v57] = kbyte_28B5D[v58];
      layer2_bgdata[v57 + 1] = kbyte_28B5D[v58 + 1];
      layer2_bgdata[v57 + 2] = kbyte_28B5D[v58 + 2];
      layer2_bgdata[v57 + 3] = kbyte_28B5D[v58 + 3];
      v58 += 4;
      v57 += 16;
      ++tempE5;
    } while (tempE5 != 4);
    return 0;
  case 9: goto LABEL_201;
  case 0xA:
    ++*(uint16 *)&tempEB;
LABEL_201:
    v68 = *(uint16 *)&tempEB + 16;
    layer2_bgdata[(uint16)(*(uint16 *)&tempEB + 16)] = 103;
    layer2_bgdata[v68 + 1] = 105;
    layer2_bgdata[v68 + 16] = 104;
    layer2_bgdata[v68 + 17] = 106;
    return 0;
  case 0xB: *(uint16 *)&layer2_bgdata[*(uint16 *)&tempEB] = 6938; return 0;
  case 0xC:
  case 0xE:
  case 0x10:
  case 0x12:
  case 0x14:
  case 0x16:
  case 0x18:
  case 0x1A: goto LABEL_84;
  case 0xD:
  case 0xF:
  case 0x11:
  case 0x13:
  case 0x15:
  case 0x17:
  case 0x19:
  case 0x1B:
    ++*(uint16 *)&tempEB;
LABEL_84:
    v32 = *(uint16 *)&tempEB;
    *(uint16 *)&tempE2 = *(uint16 *)&tempEB;
    v33 = kword_287FF[(uint16)(2 * *(uint16 *)&tempEF) >> 1];
    while (2) {
      v34 = kbyte_2B46D[v33];
      if (!v34)
        goto LABEL_89;
      if (v34 != 0xFF) {
        if (v34 == 0xFE) {
          *(uint16 *)&tempE2 += 16;
          v32 = *(uint16 *)&tempE2;
          ++v33;
          continue;
        }
        layer2_bgdata[v32] = kbyte_2B46D[v33];
LABEL_89:
        ++v33;
        if ((++v32 & 0xF) == 0)
          v32 += 240;
        continue;
      }
      return 0;
    }
  case 0x1C:
    v48 = *(uint16 *)&tempEB;
    for (m = 0; m != 36; m += 6) {
      layer2_bgdata[v48 + 32] = kbyte_289E6[m];
      Smbll_sub_28A66();
      layer2_bgdata[v48 + 32] = kbyte_289E6[m + 1];
      Smbll_sub_28A66();
      layer2_bgdata[v48 + 32] = kbyte_289E6[m + 2];
      Smbll_sub_28A66();
      layer2_bgdata[v48 + 32] = kbyte_289E6[m + 3];
      Smbll_sub_28A66();
      layer2_bgdata[v48 + 32] = kbyte_289E6[m + 4];
      Smbll_sub_28A66();
      layer2_bgdata[v48 + 32] = kbyte_289E6[m + 5];
      v48 += 16;
    }
    return 0;
  case 0x1D:
  case 0x1E:
  case 0x1F:
    --*(uint16 *)&tempEF;
    v41 = 4 * (*(uint16 *)&tempF1 | (16 * (tempEF & 3)));
    v42 = *(uint16 *)&tempEB;
    layer2_bgdata[*(uint16 *)&tempEB] = kbyte_292E2[v41];
    layer2_bgdata[v42 + 1] = kbyte_292E2[v41 + 1];
    layer2_bgdata[v42 + 16] = kbyte_292E2[v41 + 2];
    layer2_bgdata[v42 + 17] = kbyte_292E2[v41 + 3];
    return 0;
  case 0x20: goto LABEL_134;
  case 0x21:
    ++*(uint16 *)&tempEB;
LABEL_134:
    v46 = *(uint16 *)&tempEB;
    goto LABEL_135;
  case 0x22: goto LABEL_132;
  case 0x23:
    ++*(uint16 *)&tempEB;
LABEL_132:
    v46 = *(uint16 *)&tempEB + 16;
LABEL_135:
    v45 = 0;
    goto LABEL_136;
  case 0x24:
    v45 = kword_28833[15];
    v46 = *(uint16 *)&tempEB + 2;
    goto LABEL_136;
  case 0x25:
    v45 = kword_28833[16];
    v46 = *(uint16 *)&tempEB + 18;
    goto LABEL_136;
  case 0x26:
    v45 = kword_28833[17];
    v46 = *(uint16 *)&tempEB + 1;
    goto LABEL_136;
  case 0x27:
    v45 = kword_28833[18];
    v46 = *(uint16 *)&tempEB + 17;
    goto LABEL_136;
  case 0x28:
    v45 = kword_28833[19];
    v46 = *(uint16 *)&tempEB + 32;
    goto LABEL_136;
  case 0x29:
    v45 = kword_28833[20];
    v46 = *(uint16 *)&tempEB + 1;
    goto LABEL_136;
  case 0x2A:
    v45 = kword_28833[21];
    v46 = *(uint16 *)&tempEB + 18;
LABEL_136:
    *(uint16 *)&tempE2 = v46;
    while (1) {
      v47 = kbyte_2B2EF[v45];
      if (v47 == 0xFF)
        return 0;
      if (v47 != 0xFE) {
        layer2_bgdata[v46] = Smbll_SetupLayer2Bg_Helper1(v46, v47);
        ++v45;
        if ((++v46 & 0xF) == 0)
          v46 += 240;
        continue;
      }
      ++v45;
      if (((*(uint16 *)&tempE2 + 16) & 0xF0) == 0)
        return 0;
      v46 = *(uint16 *)&tempE2 + 15;
      if (((tempE2 + 15) & 0xF) == 15)
        v46 = *(uint16 *)&tempE2 - 225;
      *(uint16 *)&tempE2 = v46;
    }
  case 0x2B:
    v21 = *(uint16 *)&tempEB + 16;
    layer2_bgdata[(uint16)(*(uint16 *)&tempEB + 16) + 48] = 78;
    if (layer2_bgdata[v21])
      v22 = 56;
    else
      v22 = 52;
    layer2_bgdata[v21] = v22;
    v23 = layer2_bgdata[v21 + 16];
    if (!v23 || v23 == 18)
      v24 = 64;
    else
      v24 = 68;
    layer2_bgdata[v21 + 16] = v24;
    v25 = layer2_bgdata[v21 + 32];
    if (!v25 || v25 == 18)
      v26 = 76;
    else
      v26 = 77;
    layer2_bgdata[v21 + 32] = v26;
    v27 = v21 + 1;
    v28 = layer2_bgdata[v27];
    switch (v28) {
    case 0u:
    case 0x12u: v29 = 53; break;
    case 0x18u:
    case 7u: v29 = 54; break;
    case 0x17u: v29 = 61; break;
    default: v29 = 57; break;
    }
    layer2_bgdata[v27] = v29;
    layer2_bgdata[v27 + 16] = 65;
    layer2_bgdata[v27 + 32] = 72;
    layer2_bgdata[v27 + 48] = 78;
    v30 = v27 + 1;
    while (--tempF1) {
      v31 = layer2_bgdata[v30];
      if (v31) {
        if (v31 == 24) {
          layer2_bgdata[v30] = 54;
          layer2_bgdata[v30 + 1] = 53;
        } else {
          layer2_bgdata[v30] = 58;
          layer2_bgdata[v30 + 1] = 57;
        }
        layer2_bgdata[v30 + 16] = 66;
        layer2_bgdata[v30 + 17] = 65;
      } else {
        layer2_bgdata[v30] = 54;
        layer2_bgdata[v30 + 1] = 53;
        layer2_bgdata[v30 + 16] = 66;
        layer2_bgdata[v30 + 17] = 65;
      }
      layer2_bgdata[v30 + 32] = 71;
      layer2_bgdata[v30 + 33] = 72;
      layer2_bgdata[v30 + 48] = 78;
      layer2_bgdata[v30 + 49] = 78;
      v30 += 2;
      if ((v30 & 0xF) == 0)
        v30 += 240;
    }
    layer2_bgdata[v30 + 16] = 66;
    layer2_bgdata[v30 + 32] = 71;
    layer2_bgdata[v30 + 48] = 78;
    layer2_bgdata[v30 + 49] = 78;
    if (layer2_bgdata[v30]) {
      layer2_bgdata[v30] = 58;
      layer2_bgdata[v30 + 1] = 59;
      layer2_bgdata[v30 + 17] = 69;
      layer2_bgdata[v30 + 33] = 74;
    } else {
      layer2_bgdata[v30] = 54;
      layer2_bgdata[v30 + 1] = 55;
      layer2_bgdata[v30 + 17] = 67;
      layer2_bgdata[v30 + 33] = 73;
    }
    return 0;
  case 0x2C:
    v10 = *(uint16 *)&tempEB;
    *(uint16 *)&tempE6 = *(uint16 *)&tempF1;
    tempE8 = 0;
    do {
      layer2_bgdata[v10] = 9;
      layer2_bgdata[v10 + 16] = 14;
      layer2_bgdata[v10 + 48] = 14;
      layer2_bgdata[v10 + 80] = 14;
      layer2_bgdata[v10 + 32] = 18;
      layer2_bgdata[v10 + 64] = 18;
      v11 = v10 + 1;
      v12 = v11 & 0xF;
      if ((v11 & 0xF) == 0) {
        v12 = v11 + 240;
        v11 += 240;
        ++*(uint16 *)&tempE8;
      }
      if ((--tempE6 & 0x80u) != 0)
        break;
      layer2_bgdata[v11] = 9;
      layer2_bgdata[v11 + 16] = 15;
      layer2_bgdata[v11 + 48] = 15;
      layer2_bgdata[v11 + 80] = 15;
      layer2_bgdata[v11 + 32] = 19;
      layer2_bgdata[v11 + 64] = 19;
      v10 = v11 + 1;
      v12 = v10 & 0xF;
      if ((v10 & 0xF) == 0) {
        v12 = v10 + 240;
        v10 += 240;
        ++*(uint16 *)&tempE8;
      }
      --tempE6;
    } while ((tempE6 & 0x80u) == 0);
    v13 = *(uint16 *)&tempEB;
    LOBYTE(v12) = tempF1;
    if (tempF1 >= 4u)
      LOBYTE(v12) = 4;
    *((uint8 *)&layer2_map16_table[22527] + *(uint16 *)&tempEB + 1) = kbyte_28425[v12];
    if (*(uint16 *)&tempE8)
      v13 += 240;
    layer2_bgdata[(uint16)(*(uint16 *)&tempF1 + v13) + 1] = kbyte_2842A[v12];
    return 0;
  case 0x2D:
  case 0x2E:
  case 0x2F:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3A:
  case 0x3B:
  case 0x3C:
    v38 = *(uint16 *)&tempEB;
    *(uint16 *)&tempE2 = *(uint16 *)&tempEB;
    v39 = kword_28833[(uint16)(2 * *(uint16 *)&tempEF) >> 1];
    while (2) {
      v40 = kbyte_2AE92[v39];
      if (!v40)
        goto LABEL_113;
      if (v40 != 0xFF) {
        if (v40 != 0xFE) {
          layer2_bgdata[v38] = v40;
LABEL_113:
          ++v39;
          if ((++v38 & 0xF) == 0)
            v38 += 240;
          continue;
        }
        *(uint16 *)&tempE2 += 16;
        v38 = *(uint16 *)&tempE2;
        if ((tempE2 & 0xF0) != 240) {
          ++v39;
          continue;
        }
      }
      return 0;
    }
  case 0x3D: v5 = 14; goto LABEL_5;
  case 0x3E:
    v5 = 0;
LABEL_5:
    v6 = *(uint16 *)&tempEB + 1;
    layer2_bgdata[(uint16)(*(uint16 *)&tempEB + 1)] = kbyte_28298[v5];
    layer2_bgdata[v6 + 1] = kbyte_28298[v5 + 1];
    layer2_bgdata[v6 + 16] = kbyte_28298[v5 + 2];
    layer2_bgdata[v6 + 17] = kbyte_28298[v5 + 3];
    layer2_bgdata[v6 + 32] = kbyte_28298[v5 + 6];
    layer2_bgdata[v6 + 33] = kbyte_28298[v5 + 7];
    tempE4 = 48;
    for (tempE5 = 0;; tempE5 = 0) {
      v7 = *(uint16 *)&tempE4 + v6;
      v6 = v7;
      if ((uint8)v7 >= 0xD0u)
        break;
      layer2_bgdata[v7] = kbyte_28298[v5 + 4];
      layer2_bgdata[v7 + 1] = kbyte_28298[v5 + 5];
      layer2_bgdata[v7 + 16] = kbyte_28298[v5 + 6];
      layer2_bgdata[v7 + 17] = kbyte_28298[v5 + 7];
      tempE4 = 32;
    }
    layer2_bgdata[v7] = kbyte_28298[v5 + 8];
    layer2_bgdata[v7 + 1] = kbyte_28298[v5 + 9];
    layer2_bgdata[v7 + 16] = kbyte_28298[v5 + 10];
    layer2_bgdata[v7 + 17] = kbyte_28298[v5 + 11];
    layer2_bgdata[v7 + 32] = kbyte_28298[v5 + 12];
    layer2_bgdata[v7 + 33] = kbyte_28298[v5 + 13];
    return 0;
  case 0x3F:
    v2 = *(uint16 *)&tempF1;
    v3 = *(uint16 *)&tempEB;
    layer2_bgdata[*(uint16 *)&tempEB] = kbyte_28256[*(uint16 *)&tempF1];
    layer2_bgdata[v3 + 16] = kbyte_28256[v2 + 1];
    layer2_bgdata[v3 + 32] = kbyte_28256[v2 + 2];
    layer2_bgdata[v3 + 48] = kbyte_28256[v2 + 3];
    layer2_bgdata[v3 + 64] = kbyte_28256[v2 + 4];
    return 0;
  case 0x40: goto LABEL_40;
  case 0x41: ++*(uint16 *)&tempEB; goto LABEL_40;
  case 0x42: goto LABEL_38;
  case 0x43:
    ++*(uint16 *)&tempEB;
LABEL_38:
    *(uint16 *)&tempEB += 16;
LABEL_40:
    v17 = 0;
    goto LABEL_41;
  case 0x44: goto LABEL_36;
  case 0x45: ++*(uint16 *)&tempEB; goto LABEL_36;
  case 0x46: goto LABEL_34;
  case 0x47:
    ++*(uint16 *)&tempEB;
LABEL_34:
    *(uint16 *)&tempEB += 16;
LABEL_36:
    v17 = 1;
LABEL_41:
    v18 = *(uint16 *)&tempEB;
    layer2_bgdata[*(uint16 *)&tempEB] = kbyte_28495[v17];
    v19 = v18 + 16;
    --tempF1;
    do {
      if (layer2_bgdata[v19] == 14) {
        v20 = 13;
      } else if (layer2_bgdata[v19] == 2) {
        v20 = 11;
      } else {
        v20 = kbyte_28497[v17];
      }
      layer2_bgdata[v19] = v20;
      v19 += 16;
      --tempF1;
    } while ((tempF1 & 0x80u) == 0);
    return 0;
  case 0x48: goto LABEL_28;
  case 0x49: ++*(uint16 *)&tempEB; goto LABEL_28;
  case 0x4A: goto LABEL_26;
  case 0x4B:
    ++*(uint16 *)&tempEB;
LABEL_26:
    *(uint16 *)&tempEB += 16;
LABEL_28:
    v14 = *(uint16 *)&tempEB;
    v15 = *(uint16 *)&tempF1;
    *(uint16 *)&tempF1 = kbyte_2842A[*(uint16 *)&tempF1 + 28];
    v16 = kbyte_2842A[v15 + 33];
    do {
      layer2_bgdata[v14++] = kbyte_2842A[v16++ + 5];
      if ((v14 & 0xF) == 0)
        v14 += 240;
      --tempF1;
    } while ((tempF1 & 0x80u) == 0);
    return 0;
  case 0x4C:
    for (n = 128; n < 0x1000u; n += 240) {
      do {
        *(uint16 *)&layer2_bgdata[n] = 1027;
        *(uint16 *)&layer2_bgdata[n + 16] = 2313;
        *(uint16 *)&layer2_bgdata[n + 32] = 2313;
        *(uint16 *)&layer2_bgdata[n + 48] = 2313;
        *(uint16 *)&layer2_bgdata[n + 64] = 2313;
        *(uint16 *)&layer2_bgdata[n + 80] = 2313;
        *(uint16 *)&layer2_bgdata[n + 96] = 2313;
        n += 2;
      } while ((n & 0xF) != 0);
    }
    return 1;
  case 0x4D:
  case 0x51:
  case 0x52:
  case 0x55: goto LABEL_97;
  case 0x4E:
  case 0x54:
    ++*(uint16 *)&tempEB;
LABEL_97:
    v35 = *(uint16 *)&tempEB;
    goto LABEL_98;
  case 0x4F: v35 = *(uint16 *)&tempEB + 16; goto LABEL_98;
  case 0x50:
  case 0x53:
    v35 = *(uint16 *)&tempEB + 17;
LABEL_98:
    *(uint16 *)&tempE2 = v35;
    v36 = kword_2881F[(uint16)(2 * *(uint16 *)&tempEF) >> 1];
    while (2) {
      v37 = kbyte_2B52C[v36];
      if (!v37)
        goto LABEL_103;
      if (v37 != 0xFF) {
        if (v37 == 0xFE) {
          *(uint16 *)&tempE2 += 16;
          v35 = *(uint16 *)&tempE2;
          ++v36;
          continue;
        }
        layer2_bgdata[v35] = kbyte_2B52C[v36];
LABEL_103:
        ++v36;
        if ((++v35 & 0xF) == 0)
          v35 += 240;
        continue;
      }
      return 0;
    }
  case 0x56:
    v50 = *(uint16 *)&tempEB;
    do {
      layer2_bgdata[v50 + 32] = 9;
      layer2_bgdata[v50 + 33] = 11;
      v50 += 2;
      --tempF1;
    } while ((tempF1 & 0x80u) == 0);
    return 0;
  case 0x57:
    v51 = *(uint16 *)&tempEB;
    do {
      if (layer2_bgdata[v51 + 32] == 9)
        v52 = 10;
      else
        v52 = 4;
      layer2_bgdata[v51 + 32] = v52;
      layer2_bgdata[v51 + 48] = 1;
      v51 += 32;
      --tempF1;
    } while ((tempF1 & 0x80u) == 0);
    return 0;
  case 0x58:
    v53 = *(uint16 *)&tempEB;
    do {
      if (layer2_bgdata[v53 + 33] == 11)
        v54 = 10;
      else
        v54 = 4;
      layer2_bgdata[v53 + 33] = v54;
      layer2_bgdata[v53 + 49] = 1;
      v53 += 32;
      --tempF1;
    } while ((tempF1 & 0x80u) == 0);
    return 0;
  case 0x59: ++*(uint16 *)&tempEB; goto LABEL_121;
  case 0x5A:
LABEL_121:
    v43 = *(uint16 *)&tempEB + 32;
    layer2_bgdata[(uint16)(*(uint16 *)&tempEB + 32)] = kbyte_28793;
    layer2_bgdata[v43 + 1] = kbyte_28794;
    layer2_bgdata[v43 + 16] = kbyte_28795;
    layer2_bgdata[v43 + 17] = kbyte_28796;
    layer2_bgdata[v43 + 32] = kbyte_28797;
    layer2_bgdata[v43 + 33] = kbyte_28798;
    return 0;
  case 0x5B: ++*(uint16 *)&tempEB; goto LABEL_123;
  case 0x5C:
LABEL_123:
    v44 = *(uint16 *)&tempEB + 32;
    layer2_bgdata[(uint16)(*(uint16 *)&tempEB + 32) + 16] = kbyte_28793;
    layer2_bgdata[v44 + 17] = kbyte_28794;
    layer2_bgdata[v44 + 32] = kbyte_28795;
    layer2_bgdata[v44 + 33] = kbyte_28796;
    return 0;
  case 0x5D:
    v8 = kword_28351[(uint16)(2 * *(uint16 *)&tempF1) >> 1];
    v9 = *(uint16 *)&tempEB + 16;
    while (kbyte_2B5DE[v8] != 0xFF)
      layer2_bgdata[v9++] = kbyte_2B5DE[v8++];
    return 0;
  }
  do {
    if ((v63 & 0xF0) == 0) {
      layer2_bgdata[v63 + 32] = kbyte_28C12[6];
      layer2_bgdata[v63 + 33] = kbyte_28C12[7];
      layer2_bgdata[v63 + 34] = kbyte_28C12[8];
      goto LABEL_182;
    }
    if (layer2_bgdata[v63 + 32] != 12) {
      layer2_bgdata[v63 + 32] = kbyte_28C12[0];
      layer2_bgdata[v63 + 33] = kbyte_28C12[1];
      layer2_bgdata[v63 + 34] = kbyte_28C12[2];
LABEL_182:
      layer2_bgdata[v63 + 48] = kbyte_28C12[3];
      layer2_bgdata[v63 + 49] = kbyte_28C12[4];
      layer2_bgdata[v63 + 50] = kbyte_28C12[5];
      goto LABEL_184;
    }
    layer2_bgdata[v63 + 32] = kbyte_28C12[9];
    layer2_bgdata[v63 + 33] = kbyte_28C12[10];
    layer2_bgdata[v63 + 34] = kbyte_28C12[11];
    layer2_bgdata[v63 + 48] = kbyte_28C12[12];
    layer2_bgdata[v63 + 49] = kbyte_28C12[13];
    layer2_bgdata[v63 + 50] = kbyte_28C12[14];
    layer2_bgdata[v63 + 64] = kbyte_28C12[15];
    layer2_bgdata[v63 + 65] = kbyte_28C12[16];
    layer2_bgdata[v63 + 66] = kbyte_28C12[17];
    layer2_bgdata[v63 + 80] = kbyte_28C12[18];
    layer2_bgdata[v63 + 81] = kbyte_28C12[19];
    layer2_bgdata[v63 + 82] = kbyte_28C12[20];
    v63 += 32;
    --tempF1;
LABEL_184:
    v63 += 32;
    --tempF1;
  } while ((tempF1 & 0x80u) == 0);
  return 0;
}

uint8 Smbll_SetupLayer2Bg_Helper1(uint16 k, uint8 a) {
  uint8 v2;  // al
  uint8 v3;  // al
  uint8 v4;  // al
  uint8 v5;  // al
  uint8 v6;  // al

  tempE4 = a;
  switch (a) {
  case 0x12u:
    v2 = layer2_bgdata[k];
    if (v2) {
      switch (v2) {
      case 0x18u: return 2;
      case 6u: return 17;
      case 0x16u: return 1;
      case 5u: return 98;
      default: return 16;
      }
    } else {
      return tempE4;
    }
  case 3u:
    if (layer2_bgdata[k])
      return 54;
    else
      return tempE4;
  case 4u:
    v3 = layer2_bgdata[k];
    if (v3) {
      if (v3 == 18)
        return 20;
      else
        return 55;
    } else {
      return tempE4;
    }
  case 5u:
    v4 = layer2_bgdata[k];
    if (v4) {
      if (v4 == 19)
        return 21;
      else
        return 56;
    } else {
      return tempE4;
    }
  case 0x18u:
    v5 = layer2_bgdata[k];
    if (v5) {
      if (v5 == 22) {
        return 30;
      } else if (v5 == 19) {
        return 30;
      } else {
        return 29;
      }
    } else {
      return tempE4;
    }
  case 7u:
    v6 = layer2_bgdata[k];
    if (v6) {
      switch (v6) {
      case 0x16u: return 14;
      case 4u: return 112;
      case 0xBu: return -112;
      default: return 73;
      }
    } else {
      return tempE4;
    }
  }
  return a;
}

void Smbll_sub_28A66() {
  ;
}

void Smbll_SetupLayer2BgB() {
  uint16 v0;  // si
  uint16 v1;  // di

  *(uint16 *)((int8 *)&tempD8.addr + 1) = 512;
  tempD8.addr = koff_28E91[(uint16)(2 * area_type) >> 1];
  if (area_type >= 2u)
    v0 = *(uint16 *)&tempEB;
  else
    v0 = *(uint16 *)&tempEB + 16;
  do {
    v1 = 4 * (*(uint16 *)&tempEF - 16);
    layer2_bgdata[v0 + 32] = *IndirPtr(&tempD8, v1++);
    layer2_bgdata[v0 + 33] = *IndirPtr(&tempD8, v1++);
    layer2_bgdata[v0 + 48] = *IndirPtr(&tempD8, v1);
    layer2_bgdata[v0 + 49] = *IndirPtr(&tempD8, v1 + 1);
    v0 += 2;
    --*(uint16 *)&tempF1;
  } while (*(int16 *)&tempF1 >= 0);
}

void Smbll_SetAllLayer2BgData(uint16 k, uint16 a) {
  *(uint16 *)&layer2_bgdata[k] = a;
  *(uint16 *)&layer2_bgdata[k + 256] = a;
  *(uint16 *)&layer2_bgdata[k + 512] = a;
  *(uint16 *)&layer2_bgdata[k + 768] = a;
  *(uint16 *)&layer2_bgdata[k + 1024] = a;
  *(uint16 *)&layer2_bgdata[k + 1280] = a;
  *(uint16 *)&layer2_bgdata[k + 1536] = a;
  *(uint16 *)&layer2_bgdata[k + 1792] = a;
  *(uint16 *)&layer2_bgdata[k + 2048] = a;
  *(uint16 *)&layer2_bgdata[k + 2304] = a;
  *(uint16 *)&layer2_bgdata[k + 2560] = a;
  *(uint16 *)&layer2_bgdata[k + 2816] = a;
  *(uint16 *)&layer2_bgdata[k + 3072] = a;
  *(uint16 *)&layer2_bgdata[k + 3328] = a;
  *(uint16 *)&layer2_bgdata[k + 3584] = a;
  *(uint16 *)&layer2_bgdata[k + 3840] = a;
}

void Smbll_SetAllLayer2BgDataByte(uint16 k, uint8 a) {
  layer2_bgdata[k] = a;
  layer2_bgdata[k + 256] = a;
  layer2_bgdata[k + 512] = a;
  layer2_bgdata[k + 768] = a;
  layer2_bgdata[k + 1024] = a;
  layer2_bgdata[k + 1280] = a;
  layer2_bgdata[k + 1536] = a;
  layer2_bgdata[k + 1792] = a;
  layer2_bgdata[k + 2048] = a;
  layer2_bgdata[k + 2304] = a;
  layer2_bgdata[k + 2560] = a;
  layer2_bgdata[k + 2816] = a;
  layer2_bgdata[k + 3072] = a;
  layer2_bgdata[k + 3328] = a;
  layer2_bgdata[k + 3584] = a;
  layer2_bgdata[k + 3840] = a;
}

void Smbll_SetupLayer2BgA() {
  uint16 v0;   // di
  uint16 v1;   // ax
  uint16 v2;   // si
  uint16 v3;   // si
  uint16 v4;   // di
  uint16 m;    // si
  uint16 k;    // si
  uint16 j;    // si
  uint16 i;    // si
  uint8 v9;    // al
  uint16 v10;  // si
  uint16 v11;  // di
  uint16 v12;  // ax
  uint16 v13;  // ax
  uint8 t0;

  v1 = koff_28FC1[(uint16)(2 * *(uint16 *)&tempEF) >> 1];
  *(uint16 *)&R0_ = v1;
  switch ((uint8)(2 * tempEF) >> 1) {
  case 0: ++layer2_bg_0EC0; break;
  case 1:
    if (world_number != 1 || area_type == 2) {
      v9 = tempF1;
      if (tempF1 == 2)
        v9 = -1;
    } else {
      v9 = 1;
    }
    if (v9 == 1)
      vblank_which_layer2_scroll_flag = 1;
    Smbll_InitializeGradientHDMA(v9);
    break;
  case 2: Smbll_InitializeGradientHDMA(2u); break;
  case 3:
    v10 = 208;
    v11 = *(uint16 *)&tempF1;
    v12 = *(uint16 *)((char *)kword_2918A + v11);
    do
      Smbll_SetAllLayer2BgData(v10++, v12);
    while (v10 != 224);
    v13 = *(uint16 *)((char *)kword_29190 + v11);
    do
      Smbll_SetAllLayer2BgData(v10++, v13);
    while (v10 != 240);
    Smbll_SetAllLayer2BgData(0xF0u, 0x50u);
    break;
  case 4:
    *(uint16 *)&tileset_graphics_type = *(uint16 *)&tempF1;
    Smbll_HandleTilesetGraphicsUploads();
    break;
  case 5:
    t0 = (area_type == 2) ? 0 : 0x5f;
    for (i = 0; i != 32; ++i)
      Smbll_SetAllLayer2BgDataByte(i, t0);
    break;
  case 6:
    for (j = 0; j != 2048; j += 16) {
      do {
        layer2_bgdata[j] = kbyte_290F7[0];
        layer2_bgdata[j + 1] = kbyte_290F7[1];
        layer2_bgdata[j + 16] = kbyte_290F7[2];
        layer2_bgdata[j + 17] = kbyte_290F7[3];
        j += 2;
      } while ((j & 0xF) != 0);
    }
    break;
  case 7:
    for (k = 0; k != 32; k += 2)
      Smbll_SetAllLayer2BgData(k, 0x202u);
    do {
      Smbll_SetAllLayer2BgData(k, 0x101u);
      k += 2;
    } while (k != 48);
    break;
  case 8:
    for (m = 128; m < 0x1000u; m += 240) {
      do {
        *(uint16 *)&layer2_bgdata[m] = 1027;
        *(uint16 *)&layer2_bgdata[m + 16] = 2313;
        *(uint16 *)&layer2_bgdata[m + 32] = 2313;
        *(uint16 *)&layer2_bgdata[m + 48] = 2313;
        *(uint16 *)&layer2_bgdata[m + 64] = 2313;
        *(uint16 *)&layer2_bgdata[m + 80] = 2313;
        *(uint16 *)&layer2_bgdata[m + 96] = 2313;
        m += 2;
      } while ((m & 0xF) != 0);
    }
    break;
  case 9: enable_layer3_bgflag = tempF1; break;
  case 10:
    *(uint16 *)&tempE4 = 0;
    do {
      v3 = (tempE4 << 8) + 160;
      v4 = 0;
      do {
        layer2_bgdata[v3] = kbyte_29023[v4];
        if ((v3 & 1) != 0) {
          layer2_bgdata[v3 + 16] = 13;
          layer2_bgdata[v3 + 48] = 13;
          layer2_bgdata[v3 + 80] = 13;
          layer2_bgdata[v3 + 32] = 17;
          layer2_bgdata[v3 + 64] = 17;
        } else {
          layer2_bgdata[v3 + 16] = 12;
          layer2_bgdata[v3 + 48] = 12;
          layer2_bgdata[v3 + 80] = 12;
          layer2_bgdata[v3 + 32] = 16;
          layer2_bgdata[v3 + 64] = 16;
        }
        ++v3;
        ++v4;
      } while ((v4 & 0xF) != 0);
      ++*(uint16 *)&tempE4;
    } while (*(uint16 *)&tempE4 != 8);
    break;
  case 11:
    *(uint16 *)&tileset_graphics_type = *(uint16 *)&tempF1 | 0x10;
    Smbll_HandleTilesetGraphicsUploads();
    break;
  case 12:
    v2 = 208;
    v0 = 0;
    do {
      Smbll_SetAllLayer2BgDataByte(v2++, kbyte_28FDB[v0]);
      ++v0;
    } while (v0 != 48);
    break;
  }
}

void Smbll_GenerateLayer2Map16() {
  int16 v0;   // si
  uint16 v1;  // di
  int16 v2;   // ax
  int16 v3;   // si
  uint16 v4;  // di
  int v5;     // rbp
  uint16 v6;  // [rsp+45h] [rbp-3h]

  *(uint16 *)&R0_ = koff_292CC[kword_2923C[*(uint16 *)&area_data_addr_index]];
  *(uint16 *)&R2_ = 2;
  v0 = 0;
  v1 = 0;
  do {
    *(uint16 *)&tempE4 = v0;
    v2 = *(uint16 *)&layer2_bgdata[v1];
    if (v2 == -1)
      break;
    v6 = v1;
    v3 = *(uint16 *)&tempE4;
    v4 = 8 * (uint8)v2;
    v5 = *(uint16 *)&tempE4 >> 1;
    layer2_map16_table[v5] = *(uint16 *)IndirPtr(&R0_, v4);
    v4 += 2;
    layer2_map16_table[v5 + 1] = *(uint16 *)IndirPtr(&R0_, v4);
    v4 += 2;
    layer2_map16_table[v5 + 32] = *(uint16 *)IndirPtr(&R0_, v4);
    layer2_map16_table[v5 + 33] = *(uint16 *)IndirPtr(&R0_, v4 + 2);
    v1 = v6 + 1;
    if ((((uint8)v6 + 1) & 0xF) == 0)
      v3 += 64;
    v0 = v3 + 4;
  } while (v6 != 4607);
  area_data_addr_index = smbll_varF35;
}

void Smbll_ControllerStuff_05C860() {
  if (sram_controller_type_x) {
    saved_joypad_bits |= (uint8)(saved_joypad_bits & 0x80) >> 1;
    saved_joypad_bits = controller_hold2p1 & 0xC0 | saved_joypad_bits & 0x7F;
    controller_press1p1 |= (uint8)(controller_press1p1 & 0x80) >> 1;
    R0_ = controller_press2p1 & 0xC0;
    controller_press1p1 = controller_press2p1 & 0xC0 | controller_press1p1 & 0x7F;
  } else {
    saved_joypad_bits |= controller_hold2p1 & 0xC0;
    controller_press1p1 |= controller_press2p1 & 0xC0;
  }
}

void Smbll_CODE_05C95B() {
  if (smbll_varF03) {
    Smbll_UNUSED_CODE_05C9A5();
  } else {
    world_number = save_buffer;
    offscreen_players_world = save_buffer;
    level_number = g_byte_7FFB01;
    player_other_players_level_number_display = g_byte_7FFB01;
    area_number = save_buffer_area_number_original + ((save_buffer_area_number_original & 0x80u) != 0);
    player_other_players_level = area_number;
    number_of_lives = save_buffer_current_life_count;
    smbll_varF2B = save_buffer_hard_mode_active_flag;
    Smbll_LoadTopScoreFromSram();
  }
}

void Smbll_LoadTopScoreFromSram() {
  uint8 i;  // si

  for (i = 0; i != 6; ++i)
    displayed_score[i] = sram_top_score[i];
}

void Smbll_UNUSED_CODE_05C9A5() {
  uint8 i;  // si

  area_number = sram_initial_selected_level;
  level_number = original_level;
  number_of_lives = 2;
  player_coin_count = 0;
  smbll_varF2B = 0;
  for (i = 0; i != 6; ++i)
    marios_score[i] = 0;
}

void Smbll_DrawCrumblingBridgeSegment(uint8 k) {
  uint8 v1;     // di
  uint8 i;      // si
  OamEnt *oam;  // rbp
  OamEnt *v4;   // rdx
  uint8 v5;     // si

  if (bridge_collapse_offset) {
    v1 = enemy_obj_id[k];
    for (i = 0; i != 32; ++i) {
      oam = get_OamEnt(oam_buf, v1);
      v4 = get_OamEnt(oam_buf, i);
      v4->xpos = oam[64].xpos;
      if ((v1 & 3) == 1 && v4->xpos >= 0xF0u) {
        v4->xpos = -16;
        oam_tile_size_buffer[v1 + 256] = 0;
      }
      oam_tile_size_buffer[i] = oam_tile_size_buffer[v1 + 256];
      oam_tile_size_buffer[v1 + 256] = 0;
      oam[64].xpos = -16;
      ++v1;
    }
  }
  v5 = 0;
  tempE7 = 0;
  do {
    if (bridge_sprite_slot_exists_flag[v5]) {
      Smbll_DrawCrumblingBridgeSegment_Sub(v5);
      tempE7 += 32;
    }
    ++v5;
  } while (v5 < 0xDu);
}

void Smbll_DrawCrumblingBridgeSegment_Sub(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // di
  uint8 v3;  // si
  uint8 v4;  // al
  uint8 v5;  // di
  uint8 v6;  // di
  uint8 v7;  // si
  uint8 a;   // [rsp+46h] [rbp-2h]

  bowser_enemy_slot_plus1 = object_index + 1;
  tempE6 = bridge_animation_frame[k];
  tempE4 = kbyte_2D215[tempE6] - 96;
  tempE5 = kbyte_2D215[tempE6 + 1] - 96;
  v1 = Smbll_DrawCrumblingBridgeSegment_Sub2(tempE7, level_bridge_spr_xpos_lo[k]);
  Smbll_DrawCrumblingBridgeSegment_Sub2(v1, level_bridge_spr_xpos_lo[k] + 8);
  v2 = tempE7;
  Smbll_DrawCrumblingBridgeSegment_Sub3(tempE7, tempE4);
  Smbll_DrawCrumblingBridgeSegment_Sub3(v2 + 16, tempE5);
  v3 = tempE6;
  if (tempE6 >= 4u)
    v4 = 35;
  else
    v4 = 34;
  a = v4;
  v5 = Smbll_DrawCrumblingBridgeSegment_Sub2(tempE7 + 3, v4);
  Smbll_DrawCrumblingBridgeSegment_Sub2(v5, a);
  v6 = tempE7;
  v7 = 8 * v3;
  tempE8 = 8;
  do {
    get_OamEnt(oam_buf, v6)[64].charnum = kbyte_2D1CD[v7];
    v6 += 4;
    ++v7;
    --tempE8;
  } while (tempE8);
  if (!--level_bridge_spr_animation_frame_timer[k]) {
    level_bridge_spr_animation_frame_timer[k] = 3;
    if ((++bridge_animation_frame[k] & 0xF) == 9)
      bridge_sprite_slot_exists_flag[k] = 0;
  }
}

void Smbll_DrawCrumblingBridgeSegment_Sub3(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp
  uint8 v3;     // al

  oam = get_OamEnt(oam_buf, j);
  oam[64].ypos = a;
  v3 = a + 8;
  oam[65].ypos = v3;
  v3 += 8;
  oam[66].ypos = v3;
  oam[67].ypos = v3 + 8;
}

uint8 Smbll_DrawCrumblingBridgeSegment_Sub2(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = a;
  oam[65].xpos = a;
  oam[66].xpos = a;
  oam[67].xpos = a;
  return j + 16;
}

void Smbll_EnemyGfxHandler_Sub1(uint8 k) {
  uint8 v1;     // di
  uint8 v2;     // al
  OamEnt *oam;  // rbp
  uint8 v4;     // si
  uint8 v5;     // si

  v1 = enemy_obj_id[k] + 4;
  v2 = enemy_moving_dir[k];
  if (v2 == 2)
    v2 = 65;
  oam = get_OamEnt(oam_buf, v1);
  oam[64].flags = v2 ^ 0x2B;
  if (enemy_id[k] != 8 && bullet_bill_arr0EA2[k] < 0xAu)
    oam[64].flags ^= 0x20u;
  tempE4 = (enemy_arr0F4F[k] >> 2) & 0xF;
  if ((enemy_state[k] & 0x20) != 0 || tempE4 >= 9u)
    enemy_arr0F4F[k] = 0;
  if (game_engine_subroutine < 9u && !var0E67)
    ++enemy_arr0F4F[k];
  v4 = tempE4;
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[64].ypos = rel_ypos.enemy + 8;
  oam[64].charnum = kbyte_2D220[v4];
  oam_tile_size_buffer[v1 + 256] = 2;
  v5 = object_index;
  tempE4 = obj_xpos_lo.enemy[object_index];
  tempE5 = obj_xpos_hi.enemy[object_index];
  *(uint16 *)&tempE4 -= screen_left_xpos16;
  if (tempE5)
    oam_tile_size_buffer[v1 + 256] = 3;
  if (rel_ypos.enemy >= 0xE0u || obj_ypos_hi.enemy[v5] != 1)
    oam[64].ypos = -16;
}

uint8 Smbll_HandleMarioGoalWalk() {
  uint8 v1;  // al

  if (flagpole_timer_var03fa) {
    tempE4 = obj_xpos_lo.player;
    tempE5 = obj_xpos_hi.player;
    HIBYTE(some_xpos16_var02fd) = 0;
    if ((uint16)(flagpole_player_xpos16 + some_xpos16_var02fd) >= *(uint16 *)&tempE4)
      return 1;
    flagpole_timer_var03fa = 0;
    draw_bubble_var3 = 52;
    mario_goal_walk_var03cf = 52;
  }
  if (mario_goal_walk_var03cf) {
    if (mario_goal_walk_var03cf < 0x28u)
      v1 = -16;
    else
      v1 = -8;
    mario_goal_walk_var03ce = v1;
    if (player_size)
      mario_goal_walk_var03ce -= 16;
    --mario_goal_walk_var03cf;
    obj_xspeed.player = 0;
    player_x_move_force = 0;
    return 0;
  } else {
    scroll_lock = 1;
    player_disable_auto_palette_update = 1;
    Smbll_HandleMarioGoalWalk_Sub();
    mario_goal_walk_var03ce = 0;
    if (flagpole_timer_var03fb) {
      --flagpole_timer_var03fb;
      return 1;
    } else {
      if (!star_flag_task_control)
        ++star_flag_task_control;
      return 0;
    }
  }
}

void Smbll_HandleMarioGoalWalk_Sub() {
  uint8 i;  // si
  int v1;   // rbp

  for (i = 0; i != 32; i += 2) {
    v1 = i >> 1;
    *(uint16 *)&tempE4 = palette_mirror[v1 + 240];
    if ((*(uint16 *)&tempE4 & 0x7C00) != 0)
      *(uint16 *)&tempE4 -= 1024;
    if ((*(uint16 *)&tempE4 & 0x3E0) != 0)
      *(uint16 *)&tempE4 -= 32;
    if ((tempE4 & 0x1F) != 0)
      --*(uint16 *)&tempE4;
    palette_mirror[v1 + 240] = *(uint16 *)&tempE4;
  }
  ++update_entire_palette_flag;
}

void Smbll_BrowserDraw_Sub1() {
  uint8 v0;  // di
  uint8 v1;  // si
  uint8 v2;  // al

  v0 = browser_front_offset;
  v1 = bowser_flame_enemy_index;
  obj_xpos_lo.enemy[bowser_flame_enemy_index] = obj_xpos_lo.enemy[browser_front_offset] - 14;
  obj_xpos_hi.enemy[v1] = obj_xpos_hi.enemy[v0];
  obj_ypos_lo.enemy[v1] = obj_ypos_lo.enemy[v0] + 8;
  v2 = *(&random_byte1 + v1) & 3;
  obj_sub_ypos.enemy[v1] = v2;
  obj_sub_yspeed.enemy[v1] = kbyte_2D397[kbyte_2D393[v2] >= obj_ypos_lo.enemy[v1]];
  enemy_frenzy_buffer = 0;
  enemy_hitbox_ctrl[v1] = 8;
  obj_ypos_hi.enemy[v1] = 1;
  enemy_flag[v1] = 1;
  obj_xpos_fract.enemy[v1] = 0;
  enemy_state[v1] = 0;
}

void Smbll_ProcBowserFlame_Sub(uint8 k) {
  uint8 v1;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v4;     // al
  uint8 v5;     // al
  uint8 v6;     // al
  uint8 v7;     // si
  uint8 v8;     // al
  uint8 v9;     // si
  uint8 v10;    // al
  uint8 v11;    // al
  uint8 v12;    // al

  v1 = enemy_obj_id[k];
  enemy = rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, v1);
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[65].xpos = enemy + 8;
  v4 = rel_ypos.enemy;
  oam[64].ypos = rel_ypos.enemy;
  oam[65].ypos = v4;
  oam[64].flags = 33;
  oam[65].flags = 33;
  v5 = enemy_array_0F58[k] >> 3;
  if (v5 == 3) {
    enemy_array_0F36[k] = 0;
    enemy_array_0F36[k] = 1;
    v6 = obj_xpos_lo.enemy[k];
    enemy_array_0F62[k] = v6 + 16;
    enemy_array_0F6B[k] = __CFADD__(v6, 16) + obj_xpos_hi.enemy[k];
    enemy_array_0F74[k] = rel_ypos.enemy;
    v5 = 0;
    enemy_array_0F58[k] = 0;
  }
  v7 = v5;
  v8 = kbyte_2D4CA[v5];
  oam[64].charnum = v8;
  oam[65].charnum = v8 + 1;
  tempE4 = v7;
  v9 = object_index;
  tempE5 = obj_xpos_lo.enemy[object_index];
  tempE6 = obj_xpos_hi.enemy[object_index];
  *(uint16 *)&tempE5 -= screen_left_xpos16;
  *(uint16 *)&tempE7 = *(uint16 *)&tempE5 + 8;
  tempE9 = 2;
  v10 = tempE6;
  if (tempE6)
    v10 = 1;
  oam_tile_size_buffer[v1 + 256] = tempE9 | v10;
  v11 = tempE8;
  if (tempE8)
    v11 = 1;
  oam_tile_size_buffer[v1 + 260] = tempE9 | v11;
  if (enemy_array_0F36[v9]) {
    tempE5 = enemy_array_0F62[v9];
    tempE6 = enemy_array_0F6B[v9];
    *(uint16 *)&tempE5 -= screen_left_xpos16;
    oam[66].xpos = tempE5;
    oam[66].ypos = enemy_array_0F74[v9] + (enemy_array_0F58[v9] >> 1) + 4;
    oam[66].charnum = kbyte_2D4CD[tempE4];
    oam[66].flags = 40;
    tempE9 = 0;
    v12 = tempE6;
    if (tempE6)
      v12 = 1;
    oam_tile_size_buffer[v1 + 264] = tempE9 | v12;
  }
  ++enemy_array_0F58[object_index];
}

void Smbll_DrawLargePlatform_Sub1() {
  uint8 v0;     // di
  uint8 v1;     // si
  OamEnt *oam;  // rdx
  uint8 v3;     // si
  uint8 v4;     // di
  uint8 v5;     // si
  OamEnt *v6;   // rdx
  uint8 v7;     // al
  OamEnt *v8;   // rdx
  uint8 v9;     // al
  OamEnt *v10;  // rbp
  uint8 v11;    // [rsp+46h] [rbp-2h]

  v0 = 4;
  player_entered_coin_heaven_flag = 4;
  tempE4 = rel_xpos_lo.enemy - 8;
  v1 = 0;
  do {
    oam = get_OamEnt(oam_buf, v0);
    oam->xpos = tempE4 + kbyte_2D603[v1];
    oam->ypos = rel_ypos.enemy - 4;
    v11 = v1;
    tempE5 = v1;
    v3 = v1 + (frame_counter & 0x18);
    oam->flags = kbyte_2D5E3[v3];
    oam->charnum = kbyte_2D5C3[v3];
    v0 += 4;
    v1 = v11 + 1;
  } while (v11 != 4);
  tempE5 = obj_xpos_lo.enemy[object_index];
  tempE6 = obj_xpos_hi.enemy[object_index];
  *(uint16 *)&tempE9 = *(uint16 *)&tempE5 - 8 - screen_left_xpos16;
  *(uint16 *)&tempE8 = *(uint16 *)&tempE9 + 16;
  *(uint16 *)&tempDF = *(uint16 *)&tempE8 + 4;
  *(uint16 *)&tempDD = *(uint16 *)&tempE8 + 12;
  *(uint16 *)&tempE7 = *(uint16 *)&tempE8 + 16;
  *(uint16 *)&tempE6 = *(uint16 *)&tempE7 + 16;
  *(uint16 *)&tempE5 = *(uint16 *)&tempE6 - 16;
  tempE4 = 2;
  v4 = 4;
  v5 = 5;
  do {
    oam_tile_size_buffer[v4] = tempE4 | (*(&tempE5 + v5) != 0);
    v4 += 4;
    --v5;
  } while (v5);
  tempE4 = 0;
  if (secondary_hard_mode) {
    v8 = get_OamEnt(oam_buf, 0);
    v8[3].ypos = -16;
    v8[4].ypos = -16;
    v9 = tempE0;
    if (tempE0)
      v9 = 1;
    oam_tile_size_buffer[0] = tempE4 | v9;
    v8->xpos = tempDF;
  } else {
    v6 = get_OamEnt(oam_buf, 0);
    v6[5].ypos = -16;
    v7 = tempDE;
    if (tempDE)
      v7 = 1;
    oam_tile_size_buffer[0] = tempE4 | v7;
    v6->xpos = tempDD;
  }
  v10 = get_OamEnt(oam_buf, 0);
  v10->ypos = rel_ypos.enemy + ((uint8)(frame_counter & 0x10) >> 4);
  v10->charnum = -25;
  v10->flags = 44;
}

void Smbll_HandleBowserWoozy() {
  uint8 v0;     // si
  OamEnt *oam;  // rbp
  uint8 v2;     // al
  int8 v3;      // al
  uint8 v4;     // al
  int8 v5;      // al

  if (++bowser_woozy_effect_animation_frame >= 0x34u) {
    bowser_feeling_woozy_flag = 0;
  } else {
    v0 = bowser_woozy_effect_animation_frame >> 2;
    oam = get_OamEnt(oam_buf, 0);
    oam[62].xpos = rel_xpos_lo.enemy + kbyte_2D668[bowser_woozy_effect_animation_frame >> 2] + 24;
    oam[63].xpos = rel_xpos_lo.enemy + kbyte_2D675[v0] + 24;
    v2 = kbyte_2D682[v0];
    if (v2)
      v3 = rel_ypos.enemy + v2 + 16;
    else
      v3 = -16;
    oam[62].ypos = v3;
    v4 = kbyte_2D68F[v0];
    if (v4)
      v5 = rel_ypos.enemy + v4 + 16;
    else
      v5 = -16;
    oam[63].ypos = v5;
    oam[62].charnum = kbyte_2D69C[v0];
    oam[63].charnum = kbyte_2D6A9[v0];
    oam[62].flags = kbyte_2D6B6[v0];
    oam[63].flags = kbyte_2D6C3[v0];
  }
}

void Smbll_BowserDraw(uint8 k) {
  uint8 v1;     // di
  uint8 v2;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v5;     // al
  int8 v6;      // al
  uint8 v7;     // si
  uint8 v8;     // si
  uint8 v9;     // di
  uint8 v10;    // di
  int8 v11;     // si
  OamEnt *v12;  // rbp
  OamEnt *v13;  // rbx
  uint8 v14;    // al
  uint8 v15;    // al
  uint8 v16;    // al

  if (bowser_feeling_woozy_flag)
    Smbll_HandleBowserWoozy();
  if (bowser_var0F4C) {
    v1 = bowser_var014B;
    if (bowser_var014B == 8)
      v1 = kbyte_2D666[(bowser_var0F4C & 4) != 0];
  } else {
    if (!enemy_frame_timer[k])
      bowser_var014B = 0;
    v1 = bowser_var014B >> 3;
  }
  bowser_var014C = kbyte_2D65C[v1];
  v2 = enemy_obj_id[k];
  enemy = rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, v2);
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[65].xpos = enemy;
  enemy += 8;
  oam[66].xpos = enemy;
  enemy += 8;
  oam[67].xpos = enemy;
  oam[68].xpos = enemy;
  oam[69].xpos = enemy;
  v5 = rel_ypos.enemy;
  oam[64].ypos = rel_ypos.enemy;
  oam[67].ypos = v5;
  v5 += 16;
  oam[65].ypos = v5;
  oam[68].ypos = v5;
  v5 -= 24;
  oam[66].ypos = v5;
  oam[69].ypos = v5;
  tempDE = enemy_moving_dir[k];
  if (tempDE == 1)
    v6 = 33;
  else
    v6 = 97;
  oam[64].flags = v6;
  oam[65].flags = v6;
  oam[66].flags = v6;
  oam[67].flags = v6;
  oam[68].flags = v6;
  oam[69].flags = v6;
  object_index = k;
  v7 = 6 * bowser_var014C;
  tempDD = 6 * bowser_var014C + 6;
  if (tempDE != 1) {
    tempDD += 42;
    v7 = tempDD - 6;
  }
  do {
    get_OamEnt(oam_buf, v2)[64].charnum = kbyte_2D608[v7];
    oam_tile_size_buffer[v2 + 256] = 2;
    v2 += 4;
    ++v7;
  } while (v7 != tempDD);
  oam_tile_size_buffer[v2 + 252] = 0;
  oam_tile_size_buffer[v2 + 240] = 0;
  v8 = object_index;
  tempE4 = obj_xpos_lo.enemy[object_index];
  tempE5 = obj_xpos_hi.enemy[object_index];
  *(uint16 *)&tempE4 -= screen_left_xpos16;
  *(uint16 *)&tempE6 = *(uint16 *)&tempE4 + 8;
  *(uint16 *)&tempE8 = *(uint16 *)&tempE4 + 16;
  *(uint16 *)&tempE2 = *(uint16 *)&tempE4 + 64;
  v9 = enemy_obj_id[object_index];
  if ((uint16)(*(uint16 *)&tempE4 + 64) >> 8 == 0xFF) {
    enemy_flag[object_index] = 0;
    enemy_state[v8] = 0;
    enemy_id[v8] = 0;
  }
  if (tempE5) {
    oam_tile_size_buffer[v9 + 256] = 3;
    oam_tile_size_buffer[v9 + 260] = 3;
  }
  if (tempE7)
    oam_tile_size_buffer[v9 + 264] = 1;
  if (tempE9) {
    oam_tile_size_buffer[v9 + 268] = 1;
    oam_tile_size_buffer[v9 + 272] = 1;
    oam_tile_size_buffer[v9 + 276] = 1;
  }
  if (bowser_var0F4C) {
    if (!--bowser_var0F4C) {
      if (bowser_var014B == 6) {
        ++bowser_var014B;
        bowser_var0F4C = 40;
        sound_ch1 = 58;
        Smbll_BrowserDraw_Sub1();
      } else {
        bowser_var014B = 0;
      }
    }
  } else {
    bowser_var0F4C = 0;
    if (++bowser_var014B >= 0x30u)
      bowser_var014B = 0;
  }
  if (!bowser_hit_points) {
    v10 = enemy_obj_id[object_index];
    v11 = 6;
    do {
      v12 = get_OamEnt(oam_buf, v10);
      v12[64].flags |= 0x80u;
      v10 += 4;
      --v11;
    } while (v11);
    v8 = object_index;
    v13 = get_OamEnt(oam_buf, enemy_obj_id[object_index]);
    v14 = v13[64].ypos + 8;
    v13[64].ypos = v14;
    v13[67].ypos = v14;
    v15 = v13[65].ypos - 24;
    v13[65].ypos = v15;
    v13[68].ypos = v15;
    v16 = v13[66].ypos + 32;
    v13[66].ypos = v16;
    v13[69].ypos = v16;
  }
  Smbll_DrawCrumblingBridgeSegment(v8);
}

void Smbll_SetLevelMusic() {
  uint8 bubble;  // di
  uint8 v1;      // al

  if (game_mode) {
    if (alt_entrance_ctrl == 2 || (bubble = 5, player_entrance_ctrl != 6) && player_entrance_ctrl != 7) {
      bubble = obj_yspeed.bubble[0];
      if (cloud_type_override)
        bubble = 4;
    }
    v1 = game_engine_subroutine;
    if (game_engine_subroutine != 4 && game_engine_subroutine != 5) {
      if (area_data_addr_index == 57 || area_data_addr_index == 59 || area_data_addr_index == 61)
        v1 = 1;
      else
        v1 = kbyte_2D8F0[bubble];
      if (!set_level_music_flag)
        music_ch1 = v1;
    }
    if (area_data_addr_index == 7)
      set_level_music_flag = v1;
  }
}

void Smbll_HandlePauseMenu() {
  if (game_mode != 2 && game_mode == 1 && game_mode_task == 3 && !var0E67 && inidisp_mirror == 15) {
    if (pausemenu_delay) {
      --pausemenu_delay;
    } else if (game_engine_subroutine != 2 && game_engine_subroutine != 3 && !auto_control_player_var1 && pause_menu_idx < 2u) {
      if (pausemenu_var2) {
        --pausemenu_var2;
      } else if (!pause_menu_idx && (controller_press1p1 & 0x10) != 0) {
        pausemenu_delay = 17;
        music_ch1 = -15;
        sound_ch1 = 67;
        Smbll_PauseMenu_Func6();
      }
    }
  }
}

void Smbll_PauseMenu_Func3() {
  ++pausemenu_var3;
  graphics_upload_ptr.bank = 9;
  graphics_upload_ptr.addr = -16384;
  graphics_upload_size = 2048;
  graphics_upload_vramaddress = 31744;
}

void Smbll_PauseMenu_Func4() {
  ++pausemenu_var3;
  graphics_upload_ptr.bank = 4;
  graphics_upload_ptr.addr = -18432;
  graphics_upload_size = 2048;
  graphics_upload_vramaddress = 31744;
}

void Smbll_PauseMenu_Func5() {
  Smbll_PauseMenu_Func1();
  Smbll_PauseMenu_Func7_Hdma_05E21F();
  w12sel_mirror = 34;
  w34sel_mirror = 2;
  tmw_mirror = 21;
  tsw_mirror = 2;
}

void Smbll_PauseMenu_Func6() {
  Smbll_PauseMenu_Func1();
  Smbll_PauseMenu_Func7_Hdma_05E21F();
  Smbll_PauseMenu_Func2();
  Smbll_PauseMenu_Func3();
  display_pause_menu_flag = 1;
  pausemenu_var1 = 0;
  blinking_cursor_frame_counter = 0;
  pausemenu_var2 = 0;
}

void Smbll_MaybePauseMenuHandler() {
  funcs_1BA38[(uint8)(2 * pause_menu_idx) >> 1]();
}
// 1BA40: using guessed type int (*funcs_1BA38[4])();

void Smbll_PauseMenu_Func2() {
  pausemenu_var4 = 16;
  pausemenu_var5 = 100;
  pausemenu_var6 = 164;
  pausemenu_var7 = 196;
  pausemenu_var8 = 208;
}

void Smbll_MaybePauseMenu_State1() {
  uint8 v0;     // al
  OamEnt *oam;  // rbp

  Smbll_DrawPauseMenuLetters();
  tempF2 = controller_press1p1;
  if ((controller_press1p1 & 0x2C) != 0) {
    if (!cutscene_var1680 || (cutscene_var1680 & 0x10) == 16) {
      if ((tempF2 & 0x20) != 0) {
        if (++pausemenu_var1 >= 3u)
          pausemenu_var1 = 0;
        sound_ch3 = 1;
        blinking_cursor_frame_counter = 0;
      } else {
        if ((tempF2 & 8) == 0) {
          if (++pausemenu_var1 >= 3u) {
            --pausemenu_var1;
            goto LABEL_20;
          }
          goto LABEL_13;
        }
        if ((--pausemenu_var1 & 0x80u) == 0) {
          sound_ch3 = 1;
          blinking_cursor_frame_counter = 0;
        } else {
          ++pausemenu_var1;
        }
      }
    } else {
      if ((tempF2 & 0x20) != 0) {
        v0 = pausemenu_var1 ^ 2;
LABEL_6:
        pausemenu_var1 = v0;
LABEL_13:
        sound_ch3 = 1;
        blinking_cursor_frame_counter = 0;
        goto LABEL_20;
      }
      v0 = (uint8)(tempF2 & 4) >> 1;
      if (v0 != pausemenu_var1)
        goto LABEL_6;
    }
  }
LABEL_20:
  oam = get_OamEnt(oam_buf, 0);
  oam->xpos = 76;
  oam->ypos = kbyte_2DB91[pausemenu_var1];
  oam->charnum = kbyte_2DB94[(uint8)(blinking_cursor_frame_counter & 0x10) >> 4];
  oam->flags = 33;
  oam_tile_size_buffer[0] = 0;
  ++blinking_cursor_frame_counter;
  if ((tempF2 & 0x10) != 0) {
    music_ch1 = -14;
    blinking_cursor_frame_counter = 0;
    if (pausemenu_var1) {
      pausemenu_var2 = 48;
      pause_menu_idx = 2;
      sound_ch1 = 59;
      if (pausemenu_var1 == 2)
        music_ch1 = -13;
    } else {
      pausemenu_var2 = 16;
      LOBYTE(pausemenu_var4) = 16;
      pause_menu_idx = 2;
      sound_ch1 = 67;
    }
    if (cutscene_var1680 != 16 || pausemenu_var1 == 2) {
      pausemenu_var2 = 32;
      if (pausemenu_var1)
        Smbll_SaveGame_Main();
    } else {
      display_pause_menu_flag = 0;
      game_mode_task = 14;
      if (pausemenu_var1)
        Smbll_SaveGame_Main();
    }
  }
}

void Smbll_DrawPauseMenuLetters() {
  uint16 v0;    // di
  uint16 v1;    // si
  int8 v2;      // al
  OamEnt *oam;  // rdx
  uint8 v4;     // al
  OamEnt *v5;   // rdx
  OamEnt *v6;   // rbp

  v0 = 16;
  v1 = 0;
  R1_ = 72;
LABEL_2:
  R0_ = 88;
  while (1) {
    if (cutscene_var1680 && (cutscene_var1680 & 0x10) != 16) {
      v2 = kbyte_2DBE5[v1];
      if (v2 < 0) {
        ++v1;
        if (v2 == -1)
          break;
        goto LABEL_10;
      }
LABEL_12:
      oam = get_OamEnt(oam_buf, v0);
      oam->charnum = v2 - 64;
      oam->xpos = R0_;
      oam->ypos = R1_;
      oam->flags = 33;
      oam_tile_size_buffer[v0] = 0;
      ++v1;
      v0 += 4;
      goto LABEL_10;
    }
    v2 = kbyte_2DB96[v1];
    if (v2 >= 0)
      goto LABEL_12;
    ++v1;
    if (v2 == -1)
      break;
LABEL_10:
    R0_ += 8;
    if (R0_ >= 0xC0u) {
      R1_ += 8;
      goto LABEL_2;
    }
  }
  for (R1_ = 64;; R1_ += 16) {
    R0_ = 64;
    do {
      v4 = R0_;
      v5 = get_OamEnt(oam_buf, v0);
      v5->xpos = R0_;
      R0_ = v4 + 16;
      v5->ypos = R1_;
      v5->charnum = -51;
      v5->flags = 33;
      oam_tile_size_buffer[v0] = 2;
      v0 += 4;
    } while (R0_ < 0xC0u);
    if (R1_ >= 0x80u)
      break;
  }
  v6 = get_OamEnt(oam_buf, 0);
  v6->xpos = 76;
  v6->ypos = kbyte_2DB91[pausemenu_var1];
  v6->charnum = kbyte_2DB94[(uint8)(blinking_cursor_frame_counter & 0x10) >> 4];
  v6->flags = 33;
  oam_tile_size_buffer[0] = 0;
}

void Smbll_MaybePauseMenu_State0() {
  uint16 i;   // si
  int v1;     // rbp
  int16 v2;   // ax
  uint16 v3;  // ax
  uint16 v4;  // si

  if ((int8)pausemenu_var4 <= 0) {
    ++pause_menu_idx;
  } else {
    --pausemenu_var4;
    --pausemenu_var5;
    --pausemenu_var5;
    ++pausemenu_var6;
    ++pausemenu_var6;
    --pausemenu_var7;
    --pausemenu_var7;
    --pausemenu_var7;
    --pausemenu_var7;
    ++pausemenu_var8;
    ++pausemenu_var8;
    ++pausemenu_var8;
    ++pausemenu_var8;
    for (i = 126; (i & 0x8000u) == 0; i -= 2) {
      v1 = i >> 1;
      hdma_data_array[v1] = 255;
      hdma_data_array[v1 + 64] = 255;
      hdma_data_array[v1 + 128] = 255;
      hdma_data_array[v1 + 192] = 255;
    }
    LOBYTE(v2) = HIBYTE(pausemenu_var6);
    HIBYTE(v2) = pausemenu_var6;
    v3 = pausemenu_var5 | v2;
    v4 = pausemenu_var7;
    do {
      hdma_data_array[v4 >> 1] = v3;
      v4 += 2;
    } while (v4 != pausemenu_var8);
  }
  Smbll_DrawPauseMenuLetters();
}

void Smbll_MaybePauseMenu_State3() {
  uint16 i;   // si
  int v1;     // rbp
  int16 v2;   // ax
  uint16 v3;  // ax
  uint16 v4;  // si

  if ((int8)pausemenu_var4 <= 0) {
    pause_menu_idx = 0;
    inidisp_mirror = 15;
    display_pause_menu_flag = 0;
    wobjsel_mirror ^= 3u;
    tmw_mirror ^= 0x10u;
    Smbll_PauseMenu_Func4();
    Smbll_ResetAllSpriteOams_Far();
    hdmaenable_mirror &= ~8u;
  } else {
    ++pausemenu_var5;
    ++pausemenu_var5;
    --pausemenu_var6;
    --pausemenu_var6;
    ++pausemenu_var7;
    ++pausemenu_var7;
    ++pausemenu_var7;
    ++pausemenu_var7;
    --pausemenu_var8;
    --pausemenu_var8;
    --pausemenu_var8;
    --pausemenu_var8;
    --pausemenu_var4;
    for (i = 126; (i & 0x8000u) == 0; i -= 2) {
      v1 = i >> 1;
      hdma_data_array[v1] = 255;
      hdma_data_array[v1 + 64] = 255;
      hdma_data_array[v1 + 128] = 255;
      hdma_data_array[v1 + 192] = 255;
    }
    LOBYTE(v2) = HIBYTE(pausemenu_var6);
    HIBYTE(v2) = pausemenu_var6;
    v3 = pausemenu_var5 | v2;
    v4 = pausemenu_var7;
    do {
      hdma_data_array[v4 >> 1] = v3;
      v4 += 2;
    } while (v4 != pausemenu_var8);
    Smbll_DrawPauseMenuLetters();
  }
}

void Smbll_MaybePauseMenu_State2() {
  if (!--pausemenu_var2 &&
      ((++pause_menu_idx, LOBYTE(pausemenu_var4) = 16, pausemenu_var2 = 16, cutscene_var1680 == 1) || pausemenu_var1 == 2)) {
    Smbll_ResetGame_Main();
  } else {
    Smbll_DrawPauseMenuLetters();
  }
}

void Smbll_PauseMenu_Func7_Hdma_05E21F() {
  uint16 i;  // si
  int v1;    // rbp

  for (i = 126; (i & 0x8000u) == 0; i -= 2) {
    v1 = i >> 1;
    hdma_data_array[v1] = 0;
    hdma_data_array[v1 + 64] = 0;
    hdma_data_array[v1 + 128] = 0;
    hdma_data_array[v1 + 192] = 0;
  }
  WriteRegWord(DMAP3, 0x2641u);
  WriteRegWord(A1T3L, 0xDE7Eu);
  WriteReg(A1B3, 2u);
  WriteReg(DAS30, 0x7Fu);
  w12sel_mirror = 0;
  w34sel_mirror = 0;
  wobjsel_mirror |= 3u;
  tmw_mirror |= 0x10u;
  tsw_mirror = 0;
  hdmaenable_mirror |= 8u;
}

void Smbll_PauseMenu_Func1() {
  uint16 i;  // si
  int v1;    // rbp

  for (i = 416; (i & 0x8000u) == 0; i -= 32) {
    v1 = i >> 1;
    hdma_data_array[v1] = 255;
    hdma_data_array[v1 + 1] = 255;
    hdma_data_array[v1 + 2] = 255;
    hdma_data_array[v1 + 3] = 255;
    hdma_data_array[v1 + 4] = 255;
    hdma_data_array[v1 + 5] = 255;
    hdma_data_array[v1 + 6] = 255;
    hdma_data_array[v1 + 7] = 255;
    hdma_data_array[v1 + 8] = 255;
    hdma_data_array[v1 + 9] = 255;
    hdma_data_array[v1 + 10] = 255;
    hdma_data_array[v1 + 11] = 255;
    hdma_data_array[v1 + 12] = 255;
    hdma_data_array[v1 + 13] = 255;
    hdma_data_array[v1 + 14] = 255;
    hdma_data_array[v1 + 15] = 255;
    hdma_data_array_2[v1] = 255;
    hdma_data_array_2[v1 + 1] = 255;
    hdma_data_array_2[v1 + 2] = 255;
    hdma_data_array_2[v1 + 3] = 255;
    hdma_data_array_2[v1 + 4] = 255;
    hdma_data_array_2[v1 + 5] = 255;
    hdma_data_array_2[v1 + 6] = 255;
    hdma_data_array_2[v1 + 7] = 255;
    hdma_data_array_2[v1 + 8] = 255;
    hdma_data_array_2[v1 + 9] = 255;
    hdma_data_array_2[v1 + 10] = 255;
    hdma_data_array_2[v1 + 11] = 255;
    hdma_data_array_2[v1 + 12] = 255;
    hdma_data_array_2[v1 + 13] = 255;
    hdma_data_array_2[v1 + 14] = 255;
    hdma_data_array_2[v1 + 15] = 255;
  }
}

uint8 Smbll_DebugCode() {
  uint8 v0;  // al
  bool v1;   // cf
  uint8 v2;  // di

  if ((*(&controller_press2p1 + current_player_mirror) & 0xC0) != 0) {
    if ((*(&controller_press2p1 + current_player_mirror) & 0x80) != 0) {
      player_size = 0;
      player_status = 1;
    } else {
      player_size = 0;
      player_status = 2;
    }
  }
  if ((controller_press1p1 & 0x20) != 0) {
    level_free_movement_debug_flag ^= controller_press1p1 & 0x20;
    disable_collision_detection = level_free_movement_debug_flag >> 5;
  }
  if (!level_free_movement_debug_flag)
    return 1;
  player_star_power_timer = 16;
  if ((controller_hold2p1 & 0x10) == 0 || (frame_counter & 7) != 0) {
    if ((frame_counter & 7) == 0 && (controller_press1p1 & 0x80u) != 0) {
      player_size ^= 1u;
      player_status ^= 2u;
      Smbll_GetPlayerColors();
    }
    v0 = saved_joypad_bits & 3;
    if ((saved_joypad_bits & 3) != 0) {
      player_facing_dir = buttons_left_right;
      v1 = __CFADD__(kbyte_2DFED[v0 - 1], obj_xpos_lo.player);
      obj_xpos_lo.player += kbyte_2DFED[v0 - 1];
      obj_xpos_hi.player += kbyte_2DFEF[v0 - 1] + v1;
    }
    if ((saved_joypad_bits & 0xC) != 0) {
      v2 = (uint8)(saved_joypad_bits & 0xC) >> 2;
      v1 = __CFADD__(kbyte_2DFED[v2 - 1], obj_ypos_lo.player);
      obj_ypos_lo.player += kbyte_2DFED[v2 - 1];
      obj_ypos_hi.player += kbyte_2DFEF[v2 - 1] + v1;
    }
  } else if (saved_joypad_bits & 1) {
    level_timer_tens = 9;
    level_timer_ones = 9;
    level_timer_hundreds = 9;
  } else if ((saved_joypad_bits & 2) != 0) {
    level_timer_tens = 0;
    level_timer_ones = 0;
    level_timer_hundreds = 0;
    level_free_movement_debug_flag = 0;
  } else if ((saved_joypad_bits & 4) == 0 && (saved_joypad_bits & 8) != 0) {
    Smbll_GiveExtraLife();
  }
  return 0;
}

void Smbll_InitializeContactSprite(uint8 k) {
  uint8 v1;  // di
  int16 v2;  // ax
  int16 v3;  // ax

  v1 = 0;
  while (contact_sprite_arr1[v1]) {
    if (++v1 == 5) {
      v1 = 0;
      break;
    }
  }
  contact_sprite_arr1[v1] = 1;
  HIBYTE(v2) = obj_xpos_hi.enemy[k];
  LOBYTE(v2) = obj_xpos_lo.enemy[k];
  if ((obj_xspeed.enemy[k] & 0x80u) == 0)
    v3 = v2 + 8;
  else
    v3 = v2 - 8;
  contact_sprite_x_lo[v1] = v3;
  contact_sprite_x_hi[v1] = HIBYTE(v3);
  contact_sprite_y[v1] = rel_ypos.enemy + 12;
}

void Smbll_ProcessContactSprites() {
  uint8 i;   // si
  uint8 v1;  // di
  uint8 v2;  // al
  uint8 v3;  // al

  for (i = 0; i != 5; ++i) {
    v1 = kbyte_2E268[i];
    v2 = contact_sprite_arr1[i];
    if (v2) {
      v3 = v2 & 0xC;
      tempE4 = v3;
      if (v3) {
        if (v3 == 4) {
          Smbll_ContactSprite_Func3(i, v1);
        } else if (v3 == 8) {
          Smbll_CODE_05D3B4(i, v1);
        } else {
          contact_sprite_arr1[i] = 0;
        }
      } else {
        Smbll_ContactSprite_Func1(i, v1);
      }
    }
  }
}

void Smbll_ContactSprite_Func1(uint8 k, uint8 j) {
  OamEnt *oam;  // rbp
  uint8 v3;     // al

  Smbll_ContactSprite_Func2(k);
  oam = get_OamEnt(oam_buf, j);
  oam->ypos = contact_sprite_some_y_pos + 4;
  oam->charnum = 38;
  oam->flags = 37;
  contact_sprite_some_x_pos = contact_sprite_some_x_pos + 4 - screen_left_xpos16;
  oam->xpos = contact_sprite_some_x_pos;
  v3 = HIBYTE(contact_sprite_some_x_pos);
  if (HIBYTE(contact_sprite_some_x_pos))
    v3 = 1;
  oam_tile_size_buffer[j] = v3;
  ++contact_sprite_arr1[k];
}

void Smbll_ContactSprite_Func3(uint8 k, uint8 j) {
  OamEnt *oam;  // rbp
  uint8 v3;     // al

  Smbll_ContactSprite_Func2(k);
  oam = get_OamEnt(oam_buf, j);
  oam->ypos = contact_sprite_some_y_pos;
  oam->charnum = 96;
  oam->flags = 37;
  contact_sprite_some_x_pos -= screen_left_xpos16;
  oam->xpos = contact_sprite_some_x_pos;
  if (HIBYTE(contact_sprite_some_x_pos))
    v3 = 3;
  else
    v3 = 2;
  oam_tile_size_buffer[j] = v3;
  ++contact_sprite_arr1[k];
}

void Smbll_CODE_05D3B4(uint8 k, uint8 j) {
  uint8 v2;     // si
  uint8 v3;     // al
  OamEnt *oam;  // rbp
  uint8 v5;     // al
  uint8 v6;     // al
  uint8 v7;     // al
  uint8 v8;     // al
  uint8 v9;     // al

  tempF1 = k;
  Smbll_ContactSprite_Func2(k);
  v2 = contact_sprite_arr1[k] & 3;
  v3 = kbyte_2E1A7[v2] + contact_sprite_some_y_pos;
  oam = get_OamEnt(oam_buf, j);
  oam->ypos = v3;
  oam[1].ypos = v3;
  v5 = kbyte_2E1AB[v2] + contact_sprite_some_y_pos + 8;
  oam[2].ypos = v5;
  oam[3].ypos = v5;
  oam->charnum = 57;
  oam[1].charnum = 57;
  oam[2].charnum = 57;
  oam[3].charnum = 57;
  oam->flags = 37;
  oam[1].flags = 37;
  oam[2].flags = 37;
  oam[3].flags = 37;
  tempEF = kbyte_2E1A7[v2];
  tempF0 = -1;
  *(uint16 *)&tempED = *(uint16 *)&tempEF + contact_sprite_some_x_pos - screen_left_xpos16;
  v6 = tempEF + contact_sprite_some_x_pos - screen_left_xpos16;
  oam->xpos = v6;
  oam[2].xpos = v6;
  v7 = tempEE;
  if (tempEE)
    v7 = 1;
  oam_tile_size_buffer[j] = v7;
  oam_tile_size_buffer[j + 8] = v7;
  tempEF = kbyte_2E1AB[v2];
  tempF0 = 0;
  *(uint16 *)&tempED = *(uint16 *)&tempEF + contact_sprite_some_x_pos + 8 - screen_left_xpos16;
  v8 = tempEF + contact_sprite_some_x_pos + 8 - screen_left_xpos16;
  oam[1].xpos = v8;
  oam[3].xpos = v8;
  v9 = tempEE;
  if (tempEE)
    v9 = 1;
  oam_tile_size_buffer[j + 4] = v9;
  oam_tile_size_buffer[j + 12] = v9;
  ++contact_sprite_arr1[tempF1];
}

void Smbll_ContactSprite_Func2(uint8 k) {
  uint16 v1;  // ax

  contact_sprite_some_y_pos = contact_sprite_y[k];
  HIBYTE(v1) = contact_sprite_x_hi[k];
  LOBYTE(v1) = contact_sprite_x_lo[k];
  contact_sprite_some_x_pos = v1;
}

void Smbll_CheckIfBowserTouchedLava() {
  uint8 i;   // si
  uint8 v1;  // al
  uint8 v2;  // si
  uint8 v3;  // al

  if (bowser_var0201 != 1 && world_number != 8 && obj_yspeed.bubble[0] == 3) {
    if (bowser_var0096) {
LABEL_16:
      Smbll_CheckIfBowserTouchedLava_Sub2();
      goto LABEL_17;
    }
    if (bowser_enemy_slot_plus1) {
      for (i = 8; (i & 0x80u) == 0; --i) {
        if (enemy_id[i] == 45) {
          if (obj_ypos_lo.enemy[i] < 0xB8u)
            goto LABEL_17;
          if ((enemy_flag[i] & 0x80u) == 0) {
            v1 = obj_xpos_lo.enemy[i];
            LOBYTE(bowser_xpos16) = v1 + 16;
            HIBYTE(bowser_xpos16) = __CFADD__(v1, 16) + obj_xpos_hi.enemy[i];
            bowser_var0096 = 8;
            goto LABEL_15;
          }
        }
      }
      v2 = bowser_enemy_slot_plus1 - 1;
      if (obj_ypos_lo.enemy[(uint8)(bowser_enemy_slot_plus1 - 1)] < 0xB8u)
        goto LABEL_17;
      v3 = obj_xpos_lo.enemy[v2];
      LOBYTE(bowser_xpos16) = v3 + 4;
      HIBYTE(bowser_xpos16) = __CFADD__(v3, 4) + obj_xpos_hi.enemy[v2];
      bowser_var0096 = 4;
LABEL_15:
      sound_ch1 = 37;
      sound_ch3 = 32;
      goto LABEL_16;
    }
  }
LABEL_17:
  Smbll_HandlePaletteAnimations();
}

void Smbll_CheckIfBowserTouchedLava_Sub2() {
  uint8 v0;     // si
  uint8 v1;     // di
  OamEnt *oam;  // rdx
  uint8 v3;     // al

  tempE4 = bowser_var0096;
  if ((uint8)(++bowser_timer_02f9 >> 2) >= 6u) {
    bowser_enemy_slot_plus1 = 0;
    bowser_var0096 = 0;
  } else {
    tempDD = bowser_timer_02f9 >> 2;
    v0 = 8 * (bowser_timer_02f9 >> 2);
    v1 = 32;
    tempE9 = 0;
    do {
      tempE8 = (v0 & 1) - 1;
      tempE7 = kbyte_2E35E[v0];
      *(uint16 *)&tempE7 = bowser_xpos16 + *(uint16 *)&tempE7 - screen_left_xpos16;
      oam = get_OamEnt(oam_buf, v1);
      oam->xpos = tempE7;
      v3 = tempE8;
      if (tempE8)
        v3 = 0;
      oam_tile_size_buffer[v1] = tempE9 | v3;
      oam->ypos = kbyte_2E386[v0] - 40;
      oam->charnum = kbyte_2E3B7[tempDD];
      oam->flags = kbyte_2E3AE[tempE4];
      v1 += 4;
      ++v0;
      --tempE4;
    } while (tempE4);
  }
}

void Smbll_MovePodoboo_Sub1(uint8 k) {
  uint8 v1;     // al
  uint8 v2;     // al
  int v3;       // rbp
  uint8 v4;     // di
  uint8 v5;     // di
  uint8 v6;     // si
  OamEnt *oam;  // rbx
  int16 v8;     // [rsp+43h] [rbp-5h]

  if (podoboo_array_1[k] == 2) {
    v2 = podoboo_array_2[k] >> 3;
    if (v2 < 5u) {
      tempEB = podoboo_array_2[k] >> 3;
      R0_ = obj_xpos_lo.enemy[k];
      R1_ = obj_xpos_hi.enemy[k];
      v8 = *(uint16 *)&R0_ + 8 - screen_left_xpos16;
      v3 = (uint8)(2 * v2) >> 1;
      *(uint16 *)&R0_ = kword_2E46B[v3] + v8;
      *(uint16 *)&R2_ = kword_2E475[v3] + v8;
      v4 = tempEB;
      podoboo_array_3[k] += kbyte_2E493[tempEB];
      R4_ = podoboo_array_3[k] + kbyte_2E47F[v4];
      tempED = podoboo_array_3[k] + kbyte_2E484[v4];
      v5 = enemy_obj_id[k] + 4;
      v6 = tempEB;
      oam = get_OamEnt(oam_buf, v5);
      oam[64].xpos = R0_;
      oam[65].xpos = R2_;
      oam[64].ypos = R4_;
      oam[65].ypos = tempED;
      oam[64].charnum = kbyte_2E489[v6];
      oam[65].charnum = kbyte_2E48E[v6];
      oam[64].flags = 40;
      oam[65].flags = 40;
      if (R1_)
        oam_tile_size_buffer[v5 + 256] = 1;
      if (R3_)
        oam_tile_size_buffer[v5 + 260] = 1;
    } else {
      podoboo_array_2[k] = 48;
    }
  } else if (podoboo_array_1[k] & 1) {
    v1 = podoboo_array_2[k] >> 2;
    if (v1 == 6) {
      ++podoboo_array_1[k];
      podoboo_array_2[k] = 0;
      if (podoboo_array_1[k] == 2)
        podoboo_array_3[k] = obj_ypos_lo.enemy[k];
    } else {
      tempED = kbyte_2E405[v1];
      R0_ = obj_xpos_lo.enemy[k];
      R1_ = obj_xpos_hi.enemy[k];
      *(uint16 *)&R0_ = *(uint16 *)&R0_ + 8 - screen_left_xpos16;
      tempF2 = enemy_obj_id[k] + 4;
      Smbll_MovePodoboo_Sub2(v1);
    }
  }
}

void Smbll_MovePodoboo_Sub2(uint8 j) {
  uint8 i;      // si
  uint8 v2;     // di
  uint8 v3;     // di
  OamEnt *oam;  // rbx

  tempEC = j;
  for (i = 0; i != 4; ++i) {
    tempEB = 4 * tempEC;
    v2 = 4 * tempEC + i;
    tempEE = kbyte_2E3ED[v2] - 40;
    if (!area_type)
      tempEE = -16;
    tempEF = kbyte_2E40B[i];
    *(uint16 *)&tempF0 = *(uint16 *)&R0_ + kword_2E3BD[(uint8)(2 * v2) >> 1];
    v3 = tempF2 + 4 * i;
    oam = get_OamEnt(oam_buf, v3);
    oam[64].xpos = tempF0;
    oam[64].ypos = tempEE;
    oam[64].charnum = tempED;
    oam[64].flags = tempEF;
    if (tempF1)
      oam_tile_size_buffer[v3 + 256] = 1;
  }
}

void Smbll_HandleTurnAroundSmoke() {
  if (!turn_around_smoke_flag)
    Smbll_TurnAroundSmoke_Sub1();
  Smbll_TurnAroundSmoke_Sub2();
  if ((turn_around_smoke_bits[0] & 0x20) != 0) {
    turn_around_smoke_flag = 0;
    turn_around_smoke_flag2 = 0;
  }
}

void Smbll_TurnAroundSmoke_Sub1() {
  uint8 i;  // si

  for (i = 3; (i & 0x80u) == 0; --i)
    turn_around_smoke_bits[i] = kbyte_2E5A0[i];
  ++turn_around_smoke_flag;
}

void Smbll_TurnAroundSmoke_Sub2() {
  uint8 v0;     // si
  uint8 v1;     // di
  uint8 v2;     // al
  uint8 v3;     // al
  OamEnt *oam;  // rbp

  v0 = 3;
  v1 = 48;
  do {
    v2 = turn_around_smoke_bits[v0];
    if ((v2 & 0x80u) != 0)
      goto LABEL_7;
    if (!v2)
      v2 = Smbll_TurnAroundSmoke_Sub3(v0);
    v3 = v2 >> 2;
    if (v3 >= 3u) {
LABEL_7:
      get_OamEnt(oam_buf, v1)->ypos = -8;
    } else {
      oam = get_OamEnt(oam_buf, v1);
      oam->charnum = kbyte_2E59C[v3];
      oam->flags = 56;
      oam->xpos = turn_around_smoke_xpos[v0] - screen_left_xpos_lo;
      oam->ypos = turn_around_smoke_ypos[v0];
    }
    v1 += 4;
    ++turn_around_smoke_bits[v0--];
  } while ((v0 & 0x80u) == 0);
}

uint8 Smbll_TurnAroundSmoke_Sub3(uint8 k) {
  uint8 v1;      // al
  uint8 result;  // al

  if (player_facing_dir & 1)
    v1 = obj_xpos_lo.player + 6;
  else
    v1 = obj_xpos_lo.player + 2;
  turn_around_smoke_xpos[k] = v1;
  if (player_gfx_offset == 24 || player_gfx_offset == 120) {
    result = kbyte_2E598[0] + __CFADD__(rel_ypos.player, (random_byte2 & 4) - 2) + rel_ypos.player + (random_byte2 & 4) - 2;
    turn_around_smoke_ypos[k] = result;
  } else {
    result = -8;
    turn_around_smoke_ypos[k] = -8;
  }
  return result;
}

void Smbll_DrawTitleScreen_Sub() {
  uint16 v0;  // si
  uint16 i;   // di
  uint16 v2;  // ax

  UNUSED_byte_7E0EC8 = 1;
  v0 = *(uint16 *)vram_buffer1;
  for (i = 0;; i += 2) {
    v2 = kTitleScreenLogoAndMenuStripeImage[i >> 1];
    *(uint16 *)&vram_buffer1[v0 + 2] = v2;
    if (v2 == 0xFFFF)
      break;
    v0 += 2;
  }
  *(uint16 *)vram_buffer1 = v0;
  smbll_varF2B = 0;
  Smbll_LoadFileSelectMenu_Main();
}

void Smbll_DrawVine(uint8 j) {
  int v1;       // rdi
  uint8 enemy;  // al
  OamEnt *oam;  // rdx
  int8 i;       // si
  uint8 v5;     // si
  uint8 v6;     // di

  R0_ = j;
  R2_ = enemy_obj_id[vine_obj_offset[j]];
  v1 = R2_;
  Smbll_DrawVine_Sub(R2_, rel_ypos.enemy - 1);
  enemy = rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, (uint8)v1);
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[66].xpos = enemy;
  oam[68].xpos = enemy;
  oam[65].xpos = enemy;
  oam[67].xpos = enemy;
  oam[69].xpos = enemy;
  oam[70].xpos = enemy;
  oam[71].xpos = enemy;
  oam[72].xpos = enemy;
  oam[64].flags = 27;
  oam[66].flags = 27;
  oam[68].flags = 27;
  oam[65].flags = 27;
  oam[67].flags = 27;
  oam[69].flags = 27;
  oam[70].flags = 27;
  oam[71].flags = 27;
  oam[72].flags = 27;
  for (i = 8; i >= 0; --i) {
    get_OamEnt(oam_buf, (uint8)v1)[64].charnum = 44;
    LOBYTE(v1) = v1 + 4;
  }
  if (!R0_)
    get_OamEnt(oam_buf, R2_)[64].charnum = 42;
  v5 = (vine_height >> 4) + 1;
  v6 = R2_ + 4 * v5;
  while (v5 < 9u) {
    get_OamEnt(oam_buf, v6)[64].ypos = -16;
    v6 += 4;
    ++v5;
  }
}

void Smbll_DrawVine_Sub(uint8 j, uint8 a) {
  int8 v2;      // si
  OamEnt *oam;  // rbp
  uint8 v4;     // al
  uint8 v5;     // [rsp+47h] [rbp-1h]

  v2 = 9;
  do {
    oam = get_OamEnt(oam_buf, j);
    oam[64].ypos = a;
    v5 = a;
    tempE4 = obj_xpos_lo.enemy[9];
    tempE5 = obj_xpos_hi.enemy[9];
    *(uint16 *)&tempE4 -= screen_left_xpos16;
    tempDD = 2;
    v4 = tempE5;
    if (tempE5)
      v4 = 1;
    oam_tile_size_buffer[j + 256] = tempDD | v4;
    if (!vine_at_entrance_flag && (int8)oam[64].ypos <= -17)
      oam[64].ypos = -16;
    a = v5 + 16;
    j += 4;
    --v2;
  } while (v2);
}

void Smbll_SpinningCoinSprite_Draw2() {
  uint8 v0;     // di
  OamEnt *v1;   // rbp
  uint8 v2;     // al
  uint8 v3;     // si
  OamEnt *oam;  // rbp

  v0 = bubble_obj_id[0];
  spinning_coin_xpos0E6B = spinning_coin_sprite_xpos - screen_left_xpos16;
  if (spinning_coin_ctr2) {
    if (spinning_coin_ctr2 < 6u) {
      Smbll_SpinningCoinSprite_Draw3(bubble_obj_id[0]);
      v3 = 4 * (spinning_coin_ctr2 - 1);
      R4_ = 3;
      do {
        oam = get_OamEnt(oam_buf, v0);
        oam->charnum = kbyte_2EAB8[v3];
        oam->flags = kbyte_2EACC[v3];
        v0 += 4;
        ++v3;
        --R4_;
      } while ((R4_ & 0x80u) == 0);
      if (!--spinning_coin_ctr) {
        spinning_coin_ctr = 6;
        ++spinning_coin_ctr2;
      }
    }
  } else {
    v1 = get_OamEnt(oam_buf, bubble_obj_id[0]);
    v1->ypos = spinning_coin_sprite_ypos;
    v2 = spinning_coin_xpos0E6B;
    Smbll_SetTwoTileSizes(v0, spinning_coin_xpos0E6B);
    v1->xpos = v2;
    v1->charnum = 38;
    v1->flags = 41;
    if (!--spinning_coin_ctr) {
      spinning_coin_ctr = 6;
      ++spinning_coin_ctr2;
    }
  }
}

void Smbll_SpinningCoinSprite_Draw(uint8 k, uint8 j) {
  OamEnt *oam;  // rbp

  if (!(frame_counter & 1))
    --obj_ypos_lo.misc[k];
  oam = get_OamEnt(oam_buf, j);
  oam->ypos = obj_ypos_lo.misc[k];
  oam->xpos = rel_xpos_lo.misc;
  oam_tile_size_buffer[j] = 2;
  oam->flags = 35;
  oam->charnum = 46;
  Smbll_SpinningCoinSprite_Draw2();
}

void Smbll_SpinningCoinSprite_Draw3(uint8 j) {
  uint8 v1;     // si
  int16 v2;     // ax
  OamEnt *oam;  // rbp
  uint8 v4;     // al
  uint8 v5;     // al
  int16 v6;     // ax
  uint8 v7;     // al
  uint8 v8;     // al

  v1 = spinning_coin_ctr2;
  v2 = spinning_coin_xpos0E6B + (kbyte_2EAA6[spinning_coin_ctr2] | 0xFF00);
  oam = get_OamEnt(oam_buf, j);
  oam->xpos = spinning_coin_xpos0E6B + kbyte_2EAA6[spinning_coin_ctr2];
  oam[1].xpos = v2;
  Smbll_SetTwoTileSizes(j, v2);
  if (HIBYTE(v2)) {
    oam_tile_size_buffer[j] = 1;
    oam_tile_size_buffer[j + 4] = 1;
  }
  v4 = spinning_coin_sprite_ypos + kbyte_2EAB2[v1];
  oam->ypos = v4;
  v5 = v4 + 8;
  oam[1].ypos = v5;
  if (v5 < 0xF8u && v5 >= 0xB0u) {
    oam->ypos = -16;
    oam[1].ypos = -16;
  }
  v6 = spinning_coin_xpos0E6B + kbyte_2EAAC[v1];
  oam[2].xpos = v6;
  oam[3].xpos = v6;
  Smbll_SetTwoTileSizes(j, v6);
  if (HIBYTE(v6)) {
    oam_tile_size_buffer[j + 8] = 1;
    oam_tile_size_buffer[j + 12] = 1;
  }
  v7 = spinning_coin_sprite_ypos + kbyte_2EAB2[v1];
  oam[2].ypos = v7;
  v8 = v7 + 8;
  oam[3].ypos = v8;
  if (v8 < 0xF8u && v8 >= 0xB0u) {
    oam[2].ypos = -16;
    oam[3].ypos = -16;
  }
}

void Smbll_SetTwoTileSizes(uint8 j, uint8 a) {
  if (a >= 0xF8u) {
    oam_tile_size_buffer[j] = 1;
    oam_tile_size_buffer[j + 4] = 1;
  }
}

void Smbll_SpinningCoinSprite_Init(uint8 k) {
  spinning_coin_sprite_ypos = obj_ypos_lo.misc[k] + 4;
  LOBYTE(spinning_coin_sprite_xpos) = obj_xpos_lo.misc[k];
  HIBYTE(spinning_coin_sprite_xpos) = obj_xpos_hi.misc[k];
  spinning_coin_ctr = 6;
  spinning_coin_ctr2 = 0;
}

void Smbll_DrawSpinningCoinSprite(uint8 k) {
  uint8 v1;     // di
  uint8 v2;     // al
  OamEnt *oam;  // rdx
  uint8 v4;     // al

  v1 = misc_spr_oam_id[k];
  if (misc_state[k] < 2u) {
    if ((obj_yspeed.misc[k] & 0x80u) != 0) {
      v2 = obj_ypos_lo.misc[k];
      if (v2 >= 0xB0u)
        v2 = -16;
      oam = get_OamEnt(oam_buf, v1);
      oam->ypos = v2;
      tempE4 = rel_xpos_lo.misc - 4;
      if ((uint8)(rel_xpos_lo.misc - 4) >= 0xF0u)
        v4 = 3;
      else
        v4 = 2;
      oam_tile_size_buffer[v1] = v4;
      oam->xpos = tempE4;
      oam->charnum = kbyte_2EB0D[(frame_counter >> 1) & 3];
      oam->flags = 40;
    } else {
      Smbll_SpinningCoinSprite_Draw2();
    }
  } else {
    Smbll_SpinningCoinSprite_Draw(k, v1);
  }
}

void Smbll_DrawHammer(uint8 k) {
  uint8 v1;     // di
  uint8 v2;     // si
  OamEnt *oam;  // rbp

  v1 = misc_spr_oam_id[k];
  if (!timer_control && (misc_state[k] & 0x7F) == 1)
    v2 = (frame_counter >> 2) & 3;
  else
    v2 = 0;
  oam = get_OamEnt(oam_buf, v1);
  oam->ypos = kHammerFirstSprYPos[v2] + rel_ypos.misc;
  *(uint16 *)&tempE4 = spr_rel_xpos16[6] + kHammerFirstSprXPos[v2] - 8;
  oam->xpos = tempE4;
  oam_tile_size_buffer[v1] = 2;
  if (tempE5)
    oam_tile_size_buffer[v1] = 3;
  oam->charnum = kHammerSecondSprTilenum[v2];
  oam->flags = kHammerSprAttrib[v2];
  if ((offscreen_bits.misc & 0xF) == 15 || (offscreen_bits.misc & 0xF0) != 0)
    misc_state[object_index] = 0;
}

void Smbll_CompressOAMTileSizeBuffer() {
  uint16 v0;  // si
  uint16 v1;  // di
  uint8 v2;   // al
  int8 v3;    // cf
  uint8 v4;   // al
  int8 v5;    // cl
  uint8 v6;   // al
  int8 v7;    // cl
  uint16 v8;  // di
  uint8 v9;   // al
  uint8 v10;  // al
  int8 v11;   // cl
  uint8 v12;  // al
  int8 v13;   // cl

  v0 = 0;
  v1 = 0;
  do {
    v2 = oam_tile_size_buffer[v0 + 12];
    v3 = v2 & 1;
    v4 = v2 >> 1;
    v5 = 0;
    if (v3)
      v5 = 0x80;
    v3 = v4 & 1;
    v6 = (v4 >> 1) + v5;
    v7 = 0;
    if (v3)
      v7 = 0x80;
    oam_tile_size_buffer[1] = (v6 >> 1) + v7;
    oam_tile_size_buffer[1] |= 16 * oam_tile_size_buffer[v0 + 8];
    oam_tile_size_buffer[1] |= 4 * oam_tile_size_buffer[v0 + 4];
    compressed_oam_size_buf[v1] = oam_tile_size_buffer[1] | oam_tile_size_buffer[v0];
    v8 = v1 + 1;
    v9 = oam_tile_size_buffer[v0 + 28];
    v3 = v9 & 1;
    v10 = v9 >> 1;
    v11 = 0;
    if (v3)
      v11 = 0x80;
    v3 = v10 & 1;
    v12 = (v10 >> 1) + v11;
    v13 = 0;
    if (v3)
      v13 = 0x80;
    oam_tile_size_buffer[1] = (v12 >> 1) + v13;
    oam_tile_size_buffer[1] |= 16 * oam_tile_size_buffer[v0 + 24];
    oam_tile_size_buffer[1] |= 4 * oam_tile_size_buffer[v0 + 20];
    compressed_oam_size_buf[v8] = oam_tile_size_buffer[1] | oam_tile_size_buffer[v0 + 16];
    v1 = v8 + 1;
    v0 += 32;
  } while (v0 < 0x200u);
}

void Smbll_DrawBubble(uint8 k) {
  OamEnt *oam;  // rdx
  int8 v2;      // al

  if (!draw_bubble_var3 && obj_ypos_hi.player == 1 && (offscreen_bits.bubble & 8) == 0) {
    oam = get_OamEnt(oam_buf, bubble_obj_id[k]);
    oam->xpos = rel_xpos_lo.bubble;
    oam->ypos = rel_ypos.bubble;
    oam->charnum = -97;
    if (game_engine_subroutine == 7)
      v2 = 10;
    else
      v2 = 42;
    oam->flags = v2;
  }
}

void Smbll_HandlePaletteAnimations() {
  uint8 v0;  // al
  int v1;    // rbp
  uint8 v2;  // si
  uint8 v3;  // al
  int v4;    // rbp
  int v5;    // rbp
  int v6;    // rbp
  int v7;    // rbp
  int v8;    // rbx

  if (error_screen_palette_mirror)
    return;
  if ((++palette_animation_frame_counter & 7) == 0) {
    v0 = ++coin_palette_animation_frame_counter;
    if (coin_palette_animation_frame_counter == 3) {
      coin_palette_animation_frame_counter = 0;
      v0 = 0;
    }
    v1 = (uint8)(8 * v0) >> 1;
    palette_mirror[19] = kword_2EC80[v1];
    palette_mirror[5] = kword_2ECC8[v1];
    palette_mirror[22] = kword_2EC98[v1];
    palette_mirror[20] = kword_2EC80[v1 + 1];
    palette_mirror[6] = kword_2ECC8[v1 + 1];
    palette_mirror[23] = kword_2EC98[v1 + 1];
    palette_mirror[21] = kword_2EC80[v1 + 2];
    palette_mirror[7] = kword_2ECC8[v1 + 2];
    palette_mirror[24] = kword_2EC98[v1 + 2];
    if (!smbll_varF26)
      goto LABEL_7;
    v2 = smbll_varF26 - 1;
    tempE4 = koff_2EDDA[v2];
    tempE5 = HIBYTE(koff_2EDDA[v2]);
    tempE6 = 5;
    switch ((unsigned int)(v2 * 2) >> 1) {
    case 0u:
      v5 = (uint8)((uint8)(palette_animation_frame_counter & 0x38) >> 2) >> 1;
      palette_mirror[115] = kword_2EE7D[v5];
      palette_mirror[116] = kword_2EE8D[v5];
      palette_mirror[125] = kword_2EE9D[v5];
      palette_mirror[126] = kword_2EEAD[v5];
      palette_mirror[127] = kword_2EEBD[v5];
      goto LABEL_7;
    case 1u: goto LABEL_7;
    case 2u:
      v6 = (uint8)(2 * (palette_animation_frame_counter & 0x38)) >> 1;
      palette_mirror[115] = kword_2ECE0[v6];
      palette_mirror[116] = kword_2ECE0[v6 + 1];
      palette_mirror[117] = kword_2ECE0[v6 + 2];
      palette_mirror[118] = kword_2ECE0[v6 + 3];
      palette_mirror[119] = kword_2ECE0[v6 + 4];
      palette_mirror[120] = kword_2ECE0[v6 + 5];
      goto LABEL_7;
    case 3u:
      v7 = (uint8)(palette_animation_frame_counter & 0x38) >> 1;
      palette_mirror[113] = kword_2EECD[v7];
      palette_mirror[114] = kword_2EECD[v7 + 1];
      palette_mirror[115] = kword_2EECD[v7 + 2];
      palette_mirror[116] = kword_2EECD[v7 + 3];
      v8 = (uint8)((uint8)(palette_animation_frame_counter & 0x38) >> 1) >> 1;
      palette_mirror[126] = kword_2EF0D[v8];
      palette_mirror[127] = kword_2EF0D[v8 + 1];
      if (enemy_id[0] == 53)
        goto LABEL_7;
      if (palette_animation0EB7) {
        --palette_animation0EB8;
        --palette_animation0EB9;
        --palette_animation0EB9;
        --palette_animation0EBA;
        --palette_animation0EBA;
        --palette_animation0EB8;
        --palette_animation0EB9;
        --palette_animation0EB9;
        --palette_animation0EBA;
        --palette_animation0EBA;
        if (palette_animation0EB8 == 3)
          palette_animation0EB7 = 0;
      } else {
        if ((random_byte2 & 0xF) != 0) {
LABEL_7:
          update_entire_palette_flag = 1;
          break;
        }
        if (game_engine_subroutine == 8)
          sound_ch3 = 24;
        palette_animation0EB8 = 17;
        palette_animation0EB9 = 31;
        palette_animation0EBA = 31;
        ++palette_animation0EB7;
      }
      *(uint16 *)&tempE4 = palette_animation0EB8 << 10;
      *(uint16 *)&tempE4 |= *(uint16 *)&palette_animation0EBA | (32 * palette_animation0EB9) & 0x1FFF;
      palette_mirror[113] = *(uint16 *)&tempE4;
      goto LABEL_7;
    }
  }
  if ((palette_animation_frame_counter & 3) == 0) {
    v3 = ++palette_animation0E76;
    if (palette_animation0E76 == 3) {
      palette_animation0E76 = 0;
      v3 = 0;
    }
    v4 = (uint8)(8 * v3) >> 1;
    palette_mirror[25] = kword_2ECB0[v4];
    palette_mirror[26] = kword_2ECB0[v4 + 1];
    palette_mirror[27] = kword_2ECB0[v4 + 2];
    update_entire_palette_flag = 1;
  }
}

void Smbll_HandleLevelTileAnimations() {
  int16 v0;  // ax
  int8 v1;   // di

  vram_flag_028d = 0;
  if ((frame_counter & 7) != 0) {
    LOBYTE(graphics_upload_ptr.addr) = frame_counter + 4;
    if (((frame_counter + 4) & 7) == 0) {
      graphics_upload_ptr.bank = 9;
      graphics_upload_ptr.addr = 8 * (graphics_upload_ptr.addr & 0x38) - 19712;
      graphics_upload_vramaddress = 20832;
      graphics_upload_size = 64;
      ++vram_flag_028d;
    }
  } else {
    R4_ = (uint8)(frame_counter & 0x38) >> 3;
    graphics_upload_ptr.bank = 3;
    v0 = 0x8000;
    v1 = (uint8)(frame_counter & 0x38) >> 3;
    while (--v1 >= 0)
      v0 += 2048;
    graphics_upload_ptr.addr = v0 + 0x4000;
    graphics_upload_vramaddress = 7168;
    graphics_upload_size = 1536;
    ++vram_flag_028d;
  }
}

void Smbll_HandleTilesetGraphicsUploads() {
  uint8 v0;  // al

  v0 = tileset_graphics_type;
  if (tileset_graphics_type == 1) {
    tileset_graphics_flag_var2f8 = tileset_graphics_type;
    v0 = kbyte_2F050[current_player];
    tileset_graphics_type = v0;
  }
  Smbll_UploadTilesetGraphics(v0);
  R0_ = *((uint8 *)koff_2F07C + (uint8)(2 * tileset_graphics_type));
  R1_ = *((uint8 *)koff_2F07C + (uint8)(2 * tileset_graphics_type) + 1);
  switch ((uint8)(2 * tileset_graphics_type) >> 1) {
  case 0:
  case 6:
  case 13:
  case 15:
  case 17:
  case 18:
  case 19:
  case 20:
  case 21:
  case 22:
  case 23:
  case 25:
  case 26:
  case 27:
  case 28:
  case 29:
  case 30:
  case 31: break;
  case 1:
  case 3:
  case 24: Smbll_UploadTilesetGraphics(0x11u); break;
  case 2:
  case 5:
  case 11:
  case 12:
  case 14:
  case 16:
    if (area_data_addr_index == 19 || area_data_addr_index == 25 || area_data_addr_index == 47)
      goto LABEL_13;
    Smbll_UploadTilesetGraphics(0x17u);
    break;
  case 4:
    Smbll_UploadTilesetGraphics(0x13u);
    Smbll_UploadTilesetGraphics(0x14u);
    break;
  case 7:
  case 9:
    Smbll_UploadTilesetGraphics(0x16u);
LABEL_13:
    Smbll_UploadTilesetGraphics(0x12u);
    break;
  case 8:
    if (world_number == 8) {
      tileset_graphics_type = 17;
      Smbll_UploadTilesetGraphics(0x11u);
    }
    break;
  case 10: Smbll_UploadTilesetGraphics(0x15u); break;
  }
  tileset_graphics_type = 0;
  vram_flag_028d = 0;
  vram_flag_028c = 1;
}

void Smbll_UploadTilesetGraphics(uint8 a) {
  int v1;  // rbp

  graphics_upload_ptr.bank = kbyte_2F112[(uint8)(2 * a)];
  v1 = (uint8)(2 * a) >> 1;
  graphics_upload_ptr.addr = kword_2F144[v1];
  graphics_upload_vramaddress = kword_2F176[v1];
  graphics_upload_size = kword_2F1A8[v1];
  Smbll_UploadTilesetGraphicsDma();
}

void Smbll_UploadTilesetGraphicsDma() {
  WriteReg(VMAIN, 0x80u);
  WriteRegWord(VMADDL, graphics_upload_vramaddress);
  WriteRegWord(DMAP0, 0x1801u);
  WriteRegWord(A1T0L, graphics_upload_ptr.addr);
  WriteReg(A1B0, graphics_upload_ptr.bank);
  WriteRegWord(DAS0L, graphics_upload_size);
  WriteReg(MDMAEN, 1u);
}

void Smbll_MovePlayerHoriz2_Sub() {
  uint8 v0;  // di
  bool v1;   // cf

  if (smbll_varF04 && area_type == 1) {
    v0 = 1;
    if (!__CFSHL__(frame_counter, 1))
      v0 = 3;
    R0_ = v0;
    if ((v0 & frame_counter) == 0) {
      v1 = __CFADD__(obj_xpos_lo.player++, 1);
      obj_xpos_hi.player += v1;
      ++player_x_scroll;
    }
  }
}

void Smbll_sub_2F282() {
  uint8 v0;     // si
  uint8 v1;     // di
  OamEnt *oam;  // rbp

  if (!var0E67 && smbll_varF04) {
    Smbll_sub_2F2E7();
    v0 = 0;
    v1 = 0;
    do {
      while (get_OamEnt(oam_buf, v1)[64].ypos != 0xF0) {
        v1 += 4;
        if (!v1)
          return;
      }
      oam = get_OamEnt(oam_buf, v1);
      oam[64].ypos = smbll_varF18[v0];
      oam[64].charnum = kbyte_2F276[v0];
      oam[64].flags = 42;
      oam[64].xpos = smbll_varF0C[v0];
      oam_tile_size_buffer[v1 + 256] = 0;
      v1 += 4;
      ++v0;
    } while (v0 != 12);
  }
}

void Smbll_sub_2F2E7() {
  uint8 i;  // si

  for (i = 11; (i & 0x80u) == 0; --i) {
    smbll_varF0C[i] += kbyte_2F2CF[i] + __CFADD__(kbyte_2F2CF[i], smbll_varF0C[i]) + kbyte_2F2CF[i];
    smbll_varF18[i] += kbyte_2F2CF[i];
  }
}

void Smbll_ExtObj34_() {
  uint8 i;  // si

  for (i = 11; (i & 0x80u) == 0; --i) {
    smbll_varF0C[i] = kbyte_2F26A[i];
    smbll_varF18[i] = kbyte_2F25E[i];
  }
  g_byte_7E0F4B = 16;
  sound_ch2 |= 0x10u;
  smbll_varF04 = 1;
}

void Smbll_ExtObj35_() {
  g_byte_7E0F4B = 0;
  sound_ch2 |= 0x20u;
  smbll_varF04 = 0;
}

void Smbll_DrawMushroomIcon() {
  uint8 i;   // di
  uint8 v1;  // di

  for (i = 20; (i & 0x80u) == 0; --i)
    vram_buffer1[i] = kTitleScreenMenuCursorStripeImage[i];
  v1 = 4 * number_of_players;
  vram_buffer1[v1 + 6] = 46;
  vram_buffer1[v1 + 7] = 18;
  --vram_buffer1[0];
  --vram_buffer1[0];
}

uint8 Smbll_TitleScreen_Func1() {
  uint8 v0;  // si
  uint8 v1;  // cf
  bool rv;

  v0 = title_screen_menu_var0717;
  if (title_screen_menu_var0718 || (++title_screen_menu_var0717, v0 = title_screen_menu_var0717, rv = true,
                                    title_screen_menu_var0718 = kbyte_2F72C[v0], v1 = 0, title_screen_menu_var0718)) {
    saved_joypad_bits = kbyte_2F71B[v0];
    --title_screen_menu_var0718;
    rv = false;
  }
  return rv;
}

void Smbll_CODE_039F3E(uint8 j) {
  int8 v1;   // si
  uint8 v2;  // si

  v1 = 7;
  R6_ = 0;
  do {
    R7_ = v1;
    do {
      if (v1 != 1 || j < 0x50u)
        RomPtr_RAM(*(uint16 *)&R6_)[j] = 0;
      --j;
    } while (j != 0xFF);
    --v1;
  } while (v1 >= 0);
  vram_buffer1[2] = -1;
  contact_sprite_arr1[0] = 0;
  contact_sprite_arr1[1] = 0;
  contact_sprite_arr1[2] = 0;
  contact_sprite_arr1[3] = 0;
  contact_sprite_arr1[4] = 0;
  v2 = 64;
  do
    *(&g_byte_7E0F00 + v2++) = 0;
  while (v2);
  if (var0F0B) {
    if (!--var0F0B)
      Smbll_LoadTopScoreFromSram();
  }
}

void Smbll_EnemyGfxHandler_Sub4(uint8 k) {
  uint8 v1;     // di
  OamEnt *oam;  // rbp
  uint8 enemy;  // al
  int8 v4;      // al

  v1 = enemy_obj_id[k];
  oam = get_OamEnt(oam_buf, v1);
  oam[64].xpos = rel_xpos_lo.enemy;
  if (obj_ypos_hi.enemy[k] >= 2u || (enemy = rel_ypos.enemy, rel_ypos.enemy >= 0xE8u))
    enemy = -16;
  oam[64].ypos = enemy;
  if ((obj_yspeed.enemy[k] & 0x80u) != 0)
    v4 = 41;
  else
    v4 = -87;
  oam[64].flags = v4;
  oam[64].charnum = ((uint8)(podoboo_animation_frame_counter & 0x18) >> 2) + 98;
  tempE4 = obj_xpos_lo.enemy[k];
  tempE5 = obj_xpos_hi.enemy[k];
  *(uint16 *)&tempE6 = *(uint16 *)&tempE4 - screen_left_xpos16;
  oam_tile_size_buffer[v1 + 256] = 2;
  if (tempE7)
    oam_tile_size_buffer[v1 + 256] = 3;
}

uint8 Smbll_CODE_05E8CA(uint8 j) {
  uint8 v1;     // si
  int8 v2;      // al
  uint8 v4;     // al
  uint8 v5;     // al
  uint8 v6;     // si
  uint8 v7;     // di
  uint8 v8;     // al
  uint8 v9;     // di
  uint8 v10;    // al
  uint8 v11;    // di
  uint8 v12;    // si
  OamEnt *oam;  // rbp

  enemy_array_F40[9] = 0;
  v1 = object_index;
  if (enemy_id[object_index] >= 4u)
    return 0;
  v2 = enemy_state[object_index];
  if (v2 >= 0 && (v2 & 6) != 0)
    return 0;
  v4 = enemy_state[object_index];
  tempE0 = v4;
  if (v4 == 2 || v4 == 3 || v4 == 4) {
    enemy_array_F40[object_index] = 0;
  } else {
    if ((v4 & 0x80) == 0)
      return 0;
    if (game_engine_subroutine < 0xAu)
      ++enemy_array_F40[object_index];
  }
  tempE4 = enemy_array_F40[v1] & 0xC;
  v5 = enemy_id[v1];
  v6 = tempE4;
  if (v5 == 2)
    v6 = tempE4 + 16;
  if ((tempE0 & 0xF) == 4) {
    v6 += 32;
    R4_ |= 0x80u;
  }
  v7 = j + 8;
  v8 = rel_ypos.enemy + 8;
  if ((uint8)(rel_ypos.enemy + 8) >= 0xF0u)
    v8 = -16;
  if ((R4_ & 0x80u) != 0)
    v8 += 2;
  v9 = Smbll_CODE_05EA10(v6, v7, v8);
  if ((R4_ & 0x80u) == 0)
    v10 = rel_ypos.enemy + 16;
  else
    v10 = rel_ypos.enemy + 18;
  v11 = Smbll_CODE_05EA10(v6 + 2, v9, v10);
  v12 = tempE4;
  oam = get_OamEnt(oam_buf, v11);
  oam[60].flags = R4_ | kbyte_2FB49[tempE4];
  oam[61].flags = R4_ | kbyte_2FB49[v12 + 1];
  oam[62].flags = R4_ | kbyte_2FB49[v12 + 2];
  oam[63].flags = R4_ | kbyte_2FB49[v12 + 3];
  ++enemy_array_F40[9];
  return 1;
}

void Smbll_DrawLevelPreviewSprites_Sub8() {
  uint8 v0;     // di
  uint8 v1;     // si
  uint8 v2;     // di
  uint8 v3;     // di
  uint8 v4;     // di
  uint8 v5;     // di
  uint8 v6;     // di
  OamEnt *oam;  // rbp
  uint8 v8;     // [rsp+45h] [rbp-3h]

  if (enemy_id[object_index] == 53 && !cutscene_0EC4) {
    v0 = enemy_obj_id[object_index];
    v8 = v0;
    v1 = level_preview_sprites_ctr & 0x1F;
    tempDD = kbyte_2FA5D[level_preview_sprites_ctr & 0x1F];
    v2 = Smbll_OffsetYPosAndIncr(v0);
    v3 = Smbll_OffsetYPosAndIncr(v2);
    v4 = Smbll_OffsetYPosAndIncr(v3);
    v5 = Smbll_OffsetYPosAndIncr(v4);
    v6 = Smbll_OffsetYPosAndIncr(v5);
    Smbll_OffsetYPosAndIncr(v6);
    if (v1 < 0x10u) {
      oam = get_OamEnt(oam_buf, v8);
      oam[64].charnum = -1;
      oam[65].charnum = -1;
      oam[66].charnum = -41;
      oam[67].charnum = -41;
      oam[68].charnum = -18;
      oam[69].charnum = -18;
    }
    ++level_preview_sprites_ctr;
  }
}

uint8 Smbll_OffsetYPosAndIncr(uint8 j) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[64].ypos += tempDD;
  return j + 4;
}

uint8 Smbll_CODE_05EA10(uint8 k, uint8 j, uint8 a) {
  OamEnt *oam;  // rbp
  uint8 x;      // al

  oam = get_OamEnt(oam_buf, j);
  oam[64].ypos = a;
  oam[65].ypos = a;
  x = rel_xpos_lo.enemy;
  oam[64].xpos = x;
  oam[65].xpos = x + 8;
  oam[64].charnum = kbyte_2FB09[k];
  oam[65].charnum = kbyte_2FB09[k + 1];
  return j + 8;
}

void Smbll_sub_2FB79() {
  int v0;  // rbp

  v0 = (uint8)((uint8)(frame_counter & 0x18) >> 2) >> 1;
  palette_mirror[102] = kword_2FB59[v0];
  palette_mirror[103] = kword_2FB61[v0];
  palette_mirror[104] = kword_2FB69[v0];
  palette_mirror[109] = kword_2FB71[v0];
  ++update_entire_palette_flag;
}

uint8 Smbll_sub_2FBA4() {
  uint16 v0;  // si
  int v1;     // rbp
  int16 v2;   // ax

  v0 = 0;
  *(uint16 *)&tempE6 = 0;
  do {
    v1 = v0 >> 1;
    *(uint16 *)&tempE4 = palette_mirror[v1];
    if ((*(uint16 *)&tempE4 & 0x7C00) != 0)
      *(uint16 *)&tempE4 -= 1024;
    if ((*(uint16 *)&tempE4 & 0x3E0) != 0)
      *(uint16 *)&tempE4 -= 32;
    if ((tempE4 & 0x1F) != 0)
      --*(uint16 *)&tempE4;
    v2 = *(uint16 *)&tempE4;
    palette_mirror[v1] = *(uint16 *)&tempE4;
    *(uint16 *)&tempE6 |= v2;
    v0 += 2;
  } while (v0 < 0x200u);
  if (*(uint16 *)&tempE6) {
    palette_animation0EB8 = tempE6;
    error_screen_palette_mirror = tempE6;
    update_entire_palette_flag = 1;
    return 0;
  } else {
    palette_animation0EB8 = 0;
    error_screen_palette_mirror = 0;
    return 1;
  }
}

void Smbll_sub_2FC02(uint8 k) {
  uint8 v1;     // di
  OamEnt *oam;  // rbp
  OamEnt *v3;   // rbp
  OamEnt *v4;   // rbp

  if ((obj_xspeed.enemy[k] & 0x80u) != 0)
    tempE4 = R0_;
  else
    tempE4 = R0_ - 24;
  tempE4 = obj_ypos_lo.enemy[k] - tempE4;
  v1 = enemy_obj_id[k];
  if (tempE4 >= 0x18u) {
    oam = get_OamEnt(oam_buf, v1);
    oam[68].flags |= 0x20u;
    oam[69].flags |= 0x20u;
  }
  if (tempE4 >= 0x10u) {
    v3 = get_OamEnt(oam_buf, v1);
    v3[66].flags |= 0x20u;
    v3[67].flags |= 0x20u;
  }
  if (tempE4 >= 8u) {
    v4 = get_OamEnt(oam_buf, v1);
    v4[64].flags |= 0x20u;
    v4[65].flags |= 0x20u;
  }
}

void Smbll_FlagpoleGfxHandler(uint8 k) {
  OamEnt *oam;  // rbp
  uint8 v2;     // si
  uint8 v3;     // si
  uint8 v4;     // al
  uint8 v5;     // al
  uint8 v6;     // al
  uint8 v7;     // al

  tempE4 = obj_xpos_lo.enemy[k];
  tempE5 = obj_xpos_hi.enemy[k];
  *(uint16 *)&tempE4 -= screen_left_xpos16;
  *(uint16 *)&tempE6 = *(uint16 *)&tempE4 + 4;
  *(uint16 *)&tempE8 = *(uint16 *)&tempE4 + 12;
  if ((int16)(*(uint16 *)&tempE4 + 12) > -129) {
    oam = get_OamEnt(oam_buf, 0xF0u);
    oam->xpos = tempE4;
    oam->ypos = obj_ypos_lo.enemy[k];
    oam->flags = 43;
    v2 = (uint8)(frame_counter & 0x18) >> 3;
    if (v2 == 3)
      v2 = 1;
    oam->charnum = kbyte_2FC6D[v2];
    v3 = k;
    if (climbing_ypos_unk) {
      v3 = 2 * flagpole_score;
      oam[1].xpos = tempE6;
      oam[2].xpos = tempE8;
      v4 = flagpole_score_ypos_lo;
      oam[1].ypos = flagpole_score_ypos_lo;
      oam[2].ypos = v4;
      oam[1].charnum = kbyte_2FC61[v3];
      oam[2].charnum = kbyte_2FC61[v3 + 1];
      oam[1].flags = 34;
      oam[2].flags = 34;
      if (v3 < 4u)
        oam[2].flags = 35;
    }
    tempDD = 2;
    v5 = tempE5;
    if (tempE5)
      v5 = 1;
    oam_tile_size_buffer[240] = tempDD | v5;
    tempDD = 0;
    v6 = tempE7;
    if (tempE7)
      v6 = 1;
    oam_tile_size_buffer[244] = tempDD | v6;
    if (v3 < 4u)
      tempDD = 2;
    v7 = tempE9;
    if (tempE9)
      v7 = 1;
    oam_tile_size_buffer[248] = tempDD | v7;
  }
}
