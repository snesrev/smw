#include "types.h"
#include "../util.h"
#include "../../third_party/stb/stb_image.h"
#include "../../third_party/json/cJSON.h"
#include "../../third_party/gifdec/gifdec.h"

#define MAX_FRAMES 1024

void Frame_Load(Frame *frame, const char *filename, SDL_Renderer *renderer){
    int channels;
    unsigned char* data = stbi_load(filename, &frame->width, &frame->height, &channels, STBI_rgb_alpha);

    printf("%s\n", filename);

    if (!data) {
        Die("Failed to load background image");
    }

    printf("Channels: %d\n", channels);

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(data, frame->width, frame->height, 8 * channels, frame->width * 4, SDL_PIXELFORMAT_RGBA32);

    if (!surface) {
        Die(SDL_GetError());
    }

    frame->texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!frame->texture) {
        Die(SDL_GetError());
    }

    free(surface);
}

void Frame_DecodeGIF(Entry **entries, uint32_t *frames, const char *path, SDL_Renderer *renderer){
    gd_GIF* gif = gd_open_gif(path);
    uint8_t* color = &gif->gct.colors[gif->bgindex * 3];
    uint8_t* buffer = malloc(gif->width * gif->height * 3);
    (*entries) = malloc(sizeof(Entry) * MAX_FRAMES);

    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 0x00);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    int ret;
    uint32_t count = 0;

    while(true){
        ret = gd_get_frame(gif);

        if (ret < 0) {
            Die("Failed to decode GIF");
        }

        Entry* entry = &(*entries)[count];
        Frame* frame = &entry->texture;

        SDL_Surface* surface = SDL_CreateRGBSurface(0, gif->width, gif->height, 32, 0, 0, 0, 0);
        SDL_LockSurface(surface);
        gd_render_frame(gif, buffer);
        color = buffer;
        for (int i = 0; i < gif->height; i++) {
            for (int j = 0; j < gif->width; j++) {
                uint32_t pixel = 0;
                if (!gd_is_bgcolor(gif, color))
                    pixel = SDL_MapRGB(surface->format, color[0], color[1], color[2]);
                else if (((i >> 2) + (j >> 2)) & 1)
                    pixel = SDL_MapRGB(surface->format, 0x7F, 0x7F, 0x7F);
                else
                    pixel = SDL_MapRGB(surface->format, 0x00, 0x00, 0x00);
                void *addr = surface->pixels + (i * surface->pitch + j * sizeof(pixel));
                memcpy(addr, &pixel, sizeof(pixel));
                color += 3;
            }
        }

        SDL_UnlockSurface(surface);
        frame->texture = SDL_CreateTextureFromSurface(renderer, surface);
        frame->width = gif->width;
        frame->height = gif->height;
        entry->duration = gif->gce.delay / 2;

        if (!frame->texture) {
            Die(SDL_GetError());
        }

        count++;
        free(surface);

        if (ret == 0) {
            break;
        }
    }

    gd_close_gif(gif);

    (*frames) = count;
    (*entries) = realloc((*entries), sizeof(Entry) * count);
}

void Frame_DecodeJSON(Entry **entries, uint32_t *max_frames, const char *path, SDL_Renderer *renderer){
    char* data = (char*)ReadWholeFile(path, NULL);
    uint32_t count = 0;

    if(!data){
        Die("Failed to load JSON");
    }

    cJSON* json = cJSON_Parse(data);

    if(!json){
        Die("Failed to parse JSON");
    }

    (*entries) = malloc(sizeof(Entry) * MAX_FRAMES);

    cJSON* item = NULL;
    cJSON* frames = cJSON_GetObjectItem(json, "frames");

    cJSON_ArrayForEach(item, frames){
        const char* path = cJSON_GetObjectItem(item, "image")->valuestring;
        cJSON* duration = cJSON_GetObjectItem(item, "duration");

        Entry* entry = &(*entries)[count];
        Frame* frame = &entry->texture;

        printf("Loading %s\n", path);

        Frame_Load(frame, path, renderer);
        entry->duration = duration->valueint;

        count++;
    }

    (*max_frames) = count;
    (*entries) = realloc((*entries), sizeof(Entry) * count);
}