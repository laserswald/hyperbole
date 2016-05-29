#ifndef ENTITY_H
#define ENTITY_H

#include "world.h"

// Entity parts.
typedef struct updateable{
    // Just pass in the containing type
    void (*update)(void* this);
}updateable;

typedef struct renderable{
    // Just pass in the containing type
    void (*render)(void* this);
}renderable;

typedef struct entity{
    struct renderable;
    struct updateable;
}entity;


void default_update(void* this);
void default_render(void* this);

#endif /* end of include guard: ENTITY_H */
