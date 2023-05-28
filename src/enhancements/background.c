#include "background.h"
#include "../config.h"
#include "../util.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Supported backgrounds
#include "stars.h"
#include "animated.h"

int32_t g_window_width;
int32_t g_window_height;
Frame g_background;

// Function to initialize the background

void Background_Init(SDL_Window *window, SDL_Renderer* renderer) {

    if(StringEqualsNoCase(g_config.background, "stars")) {
        Stars_Init(window);
        return;
    }

    if(Animated_Init(window, renderer, g_config.background)){
        return;
    }

    Frame_Load(&g_background, g_config.background, renderer);
}

// Function to draw the background

void Background_Draw(SDL_Renderer *renderer) {
    SDL_GetRendererOutputSize(renderer, &g_window_width, &g_window_height);

    if(StringEqualsNoCase(g_config.background, "stars")) {
        Stars_Draw(renderer);
        return;
    }

    // This only works if the background is animated
    Animated_Draw(renderer, &g_background);

    if(g_background.texture == NULL) {
        return;
    }

    int new_width = !g_config.ignore_aspect_ratio ? g_window_height * g_background.width / g_background.height : g_window_width;
    SDL_Rect rect = { g_window_width / 2 - new_width / 2, 0, new_width, g_window_height };
    SDL_RenderCopy(renderer, g_background.texture, NULL, &rect);
}

void Background_Exit(void){

}
