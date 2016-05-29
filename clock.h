#ifndef CLOCK_H

#define CLOCK_H

typedef struct _Clock {
    int elapsed_frames;
} Clock;

Clock* Clock_new();
void Clock_free(Clock *c);
void Clock_tick(Clock *c);
int Clock_getFramesPerSecond(Clock *c);

#endif /* end of include guard: CLOCK */
