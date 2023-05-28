#include "animated.h"
#include "../../third_party/json/cJSON.h"
#include "../util.h"
#include "types.h"

Entry* g_entries;
uint32_t g_count = 0;
uint32_t g_current = 0;

bool Animated_Init(SDL_Window *window, SDL_Renderer* renderer, const char* path){
    if(StringEndsWithNoCase(path, ".gif")){
        Frame_DecodeGIF(&g_entries, &g_count, path, renderer);
        return true;
    }

    if(StringEndsWithNoCase(path, ".json")){
        Frame_DecodeJSON(&g_entries, &g_count, path, renderer);
        return true;
    }

    return false;
}

bool Animated_Draw(SDL_Renderer *renderer, Frame *texture){
    if(g_count == 0){
        return false;
    }

    Entry* entry = &g_entries[g_current];

    (*texture) = entry->texture;

    if(entry->timer <= entry->duration){
        entry->timer++;
    }

    entry->timer = 0;
    g_current = (g_current + 1) % g_count;

    return true;
}