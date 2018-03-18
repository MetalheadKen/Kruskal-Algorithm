#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct _Set {
    int parent;     /* The parent node of tree */
    int depth;      /* The depth of tree */
} Set;

typedef struct _Set_Algo {
    void (*Init)(Set *, int);

    int  (*Find)(Set *, int);
    void (*Merge)(Set *, int, int);
    bool (*Equal)(int, int);
} _Set_Algo;

Set *Create_Set(int);

extern _Set_Algo Set_Algo;

#endif /* DISJOINT_SET_H_ */
