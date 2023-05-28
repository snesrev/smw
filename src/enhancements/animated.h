#pragma once
#include "types.h"
#include <stdbool.h>

bool Animated_Init(SDL_Window *window, SDL_Renderer* renderer, const char* path);
bool Animated_Draw(SDL_Renderer *renderer, Frame *texture);