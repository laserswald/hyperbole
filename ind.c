/*
 * Copy me if you can.
 * by 20h
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include "ind.h"

// Print an error and die.
void
edie(char *fmt, ...)
{
	va_list fmtargs;

	va_start(fmtargs, fmt);
	vfprintf(stderr, fmt, fmtargs);
	va_end(fmtargs);
	fprintf(stderr, ": ");

	perror(NULL);

	exit(1);
}

// Die with an error message sent to standard error.
void
die(char *fmt, ...)
{
	va_list fmtargs;

	va_start(fmtargs, fmt);
	vfprintf(stderr, fmt, fmtargs);
	va_end(fmtargs);

	exit(1);
}

// Reallocate a zero-terminated pointer.
void *
reallocz(void *p, int l, int z)
{
        p = realloc(p, l);
        if(p == NULL)
		edie("realloc");
        if(z)
		memset(p, 0, l);

        return p;
}

// Allocate a new zero-terminated pointer
void *
mallocz(int l, int z)
{
	return reallocz(NULL, l, z);
}

void *
memdup(void *p, int l)
{
        char *ret;

        ret = reallocz(NULL, l, 2);
        memmove(ret, p, l);

        return (void *)ret;
}
void *
memdupz(void *p, int l)
{
	char *ret;

	ret = reallocz(NULL, l+1, 2);
	memmove(ret, p, l);

	return (void *)ret;
}

void *
memdupcat(void *p, int lp, void *c, int lc)
{
	p = reallocz(p, lp+lc, 0);
	memset(&((char *)p)[lp], 0, lc);

	memmove(&((char *)p)[lp], c, lc);

	return p;
}

char *
vsmprintf(char *fmt, va_list fmtargs, int size)
{
	char *ret;

	ret = reallocz(NULL, ++size, 2);
	vsnprintf(ret, size, fmt, fmtargs);

	return ret;
}

char *
smprintf(char *fmt, ...)
{
	va_list fmtargs;
	char *ret;
	int len;

	va_start(fmtargs, fmt);
	len = vsnprintf(NULL, 0, fmt, fmtargs);
	va_end(fmtargs);

	va_start(fmtargs, fmt);
	ret = vsmprintf(fmt, fmtargs, len);
	va_end(fmtargs);

	return ret;
}

// Read in an entire file into a string
char *
readtoeoffd(int fd, int *len)
{
	char *ret, buf[4096];
	int olen, nlen, rl;

	for (nlen = 0, olen = 0, ret = NULL;
			(rl = read(fd, buf, sizeof(buf))); olen = nlen) {
		if (rl > 0) {
			nlen += rl;
			ret = reallocz(ret, nlen+1, 0);
			ret[nlen] = '\0';

			memmove(&ret[olen], buf, rl);
		}
	}

	*len = nlen;
	return ret;
}


/// Get the next line from a string.
//
// s    : The line from the string. 
// size : Maximum size of the string to be extracted.
// p    : The buffer to extract the string from. 
// 
// Returns: the extracted string.
char *
sgets(char *s, int size, char **p)
{
	char *np;
	int cl;

    // We need a source string
	if (*p == NULL)
		return NULL;

    // Find the first newline
	np = strchr(*p, '\n');
	if (np == NULL) {
        // No newline? CL is now the index of last char.
		cl = strlen(*p);
        // If CL is less than one, 
		if (cl < 1) {
            // P is now nothing, and return nothing.
			*p = NULL;
			return NULL;
		}
	} else {
        // Got a newline? CL is now the index of the newline.
		cl = np - *p;
	}

    // If CL is the 
	if (cl >= size)
		cl = size - 1;
	memmove(s, *p, cl);
	s[cl] = '\0';

	if (np == NULL) {
		*p = NULL;
	} else {
		*p = np+1;
	}

	return s;
}

