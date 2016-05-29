#include "rect.h"
#include "dbg.h"
bool Rect_collide(SDL_Rect* a, SDL_Rect* b){
    int aleft   = a->x;
    int aright  = a->x + a->w;
    int atop    = a->y;
    int abottom = a->y + a->h; 

    int bleft   = b->x;
    int bright  = b->x + b->w;
    int btop    = b->y;
    int bbottom = b->y + b->h; 
    
    if (abottom < btop ||
        atop > bbottom ||
        aleft > bright ||
        aright < bleft    )
       return false; 
    return (true);
}

