#include "background.h"
#include "../config.h"
#include "../util.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../../third_party/stb/stb_image.h"

// Supported backgrounds
#include "stars.h"

int32_t g_window_width;
int32_t g_window_height;

struct {
    int32_t width;
    int32_t height;
    SDL_Texture *texture;
} g_background;

// Function to initialize the background

void Background_Init(SDL_Window *window, SDL_Renderer* renderer) {

    if(StringEqualsNoCase(g_config.background, "stars")) {
        Stars_Init(window);
        return;
    }

    int channels;
    unsigned char* data = stbi_load(g_config.background, &g_background.width, &g_background.height, &channels, STBI_rgb_alpha);
    if (!data) {
        Die("Failed to load background image");
    }

    printf("Channels: %d\n", channels);

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(data, g_background.width, g_background.height, 8 * channels, g_background.width * 4, SDL_PIXELFORMAT_RGBA32);

    if (!surface) {
        Die(SDL_GetError());
    }

    g_background.texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!g_background.texture) {
        Die("Failed to create background texture");
    }

    free(surface);
}

// Function to draw the background

void Background_Draw(SDL_Renderer *renderer) {
    SDL_GetRendererOutputSize(renderer, &g_window_width, &g_window_height);

    if(StringEqualsNoCase(g_config.background, "stars")) {
        Stars_Draw(renderer);
        return;
    }

    if(g_background.texture != NULL) {
        int new_width = !g_config.ignore_aspect_ratio ? g_window_height * g_background.width / g_background.height : g_window_width;
        SDL_Rect rect = { g_window_width / 2 - new_width / 2, 0, new_width, g_window_height };
        SDL_RenderCopy(renderer, g_background.texture, NULL, &rect);
    }
}
