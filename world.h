#ifndef WORLD
#define WORLD

typedef struct _world {
    /* data */
    Clock* c;
    SDL_Surface* screen;
    RenderList* renders;
    UpdateList* updates;
}world;

void* world_create(Clock* c);

#endif /* end of include guard: WORLD */
