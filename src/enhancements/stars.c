#include "stars.h"
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "../config.h"

#define STAR_COUNT 150

// Structure to represent a star
typedef struct {
    int32_t x;
    int32_t y;
    int32_t size;
    int32_t contrast;
    float mod;
} Star;

struct {
    Star stars[STAR_COUNT];
    int32_t g_window_width;
    int32_t g_window_height;
} g_stars;

void Star_Create(Star *star){
    int seed = rand();
    star->x = seed % g_stars.g_window_width;
    star->y = -(seed % g_stars.g_window_height);
    star->size = seed % 8;
    star->mod = seed % 100 / 100.0f;
    star->contrast = seed % 255;
}

// Function to initialize stars
void Stars_Init(SDL_Window *window) {
    SDL_GetWindowSize(window, &g_stars.g_window_width, &g_stars.g_window_height);

    srand(time(NULL));
    for (int i = 0; i < STAR_COUNT; i++) {
        Star_Create(&g_stars.stars[i]);
    }
}

// Function to update stars
void Star_Update(Star *star) {
    star->y += 2 + ( star->mod * 4 );
    if(star->y > g_stars.g_window_height) {
        Star_Create(star);
    }
}

void Stars_Draw(SDL_Renderer *renderer) {
    SDL_GetRendererOutputSize(renderer, &g_stars.g_window_width, &g_stars.g_window_height);
    for (int i = 0; i < STAR_COUNT; i++) {
        Star *star = &g_stars.stars[i];
        Star_Update(star);
        SDL_Rect rect = { star->x, star->y, star->size, star->size };
        SDL_SetRenderDrawColor(renderer, 255, 255, star->contrast, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}
