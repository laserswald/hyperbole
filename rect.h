#ifndef RECT_H

#define RECT_H

#include <stdbool.h>
#include <SDL/SDL.h>
#include "colors.h"

/** Checks if two SDL_Rects collide in the same context.
 * This only works if the two rectangles are in the same plane of space. If 
 * they do collide in the same space, returns true.
 * If not, returns false.
 */
bool Rect_collide(SDL_Rect* a, SDL_Rect* b);

/** Draws the rectangle on to the surface with the color.
 *
 */
int Rect_draw(SDL_Rect rect, SDL_Surface* surface, RGBColor rgb, bool fill);

#endif /* end of include guard: RECT_H */
