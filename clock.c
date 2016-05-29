#include <stdlib.h>
#include "clock.h"

Clock* Clock_new(){
    Clock* c = malloc(sizeof(Clock));
    c->elapsed_frames = 0;
    return c;
}

void Clock_free(Clock *c){
    free(c);
}

void Clock_tick(Clock *c){

}

int Clock_getFramesPerSecond(Clock *c){

}


