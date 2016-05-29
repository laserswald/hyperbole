/*
 * Copy me if you can.
 * by 20h
 */

#ifndef __IND_H__
#define __IND_H__

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void die(char *fmt, ...);
void edie(char *fmt, ...);
void *reallocz(void *p, int l, int z);
void *mallocz(int l, int z);
void *memdup(void *p, int l);
void *memdupz(void *p, int l);
void *memdupcat(void *p, int lp, void *c, int lc);
char *vsmprintf(char *fmt, va_list fmtargs, int size);
char *smprintf(char *fmt, ...);

char *readtoeoffd(int fd, int *len);

char *sgets(char *s, int size, char **p);

#endif

