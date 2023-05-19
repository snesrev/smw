#pragma once
typedef struct SaveLoadInfo SaveLoadInfo;
typedef void SaveLoadInfoFunc(SaveLoadInfo *info, void *data, size_t data_size);
struct SaveLoadInfo {
  SaveLoadInfoFunc *func;
};

//#define SL(x) sli->func(sli, &x, sizeof(x))