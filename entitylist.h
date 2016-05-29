#ifndef ENTITYLIST_H
#define ENTITYLIST_H

typedef struct entitylist{
    /* data */
    int length;
    int allocated;
    entity* entities;
} entitylist;


#endif /* end of include guard: ENTITYLIST_H */
