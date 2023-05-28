#pragma once

#include <SDL.h>

typedef struct Frame {
    int32_t width;
    int32_t height;
    SDL_Texture *texture;
} Frame;

typedef struct Entry {
    Frame texture;
    uint32_t duration;
    uint32_t timer;
} Entry;

void Frame_Load(Frame *frame, const char *path, SDL_Renderer *renderer);
void Frame_DecodeGIF(Entry **entries, uint32_t *frames, const char *path, SDL_Renderer *renderer);
void Frame_DecodeJSON(Entry **entries, uint32_t *frames, const char *path, SDL_Renderer *renderer);