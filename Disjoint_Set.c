#include <stdlib.h>
#include "Disjoint_Set.h"

static void Init(Set *set, int length)
{
    for (int i = 0; i < length; i++) {
        set[i].parent = i;
        set[i].depth  = 0;
    }
}

static int Find(Set *set, int index)
{
    while (set[index].parent != index) {
        index = set[index].parent;
    }

    return index;
}

static void Merge(Set *set, int indexA, int indexB)
{
    Set *a = set + indexA, *b = set + indexB;

    if (a->depth == b->depth) {
        b->parent = a->parent;
        a->depth  = a->depth + 1;
    } else if (a->depth < b->depth) {
        a->parent = b->parent;
    } else {
        b->parent = a->parent;
    }
}

static bool Equal(int a, int b)
{
    return a == b;
}

Set *Create_Set(int length)
{
    Set *set = (Set *) calloc(length, sizeof(Set));
    Init(set, length);

    return set;
}

_Set_Algo Set_Algo = {
    .Init  = Init,
    .Find  = Find,
    .Merge = Merge,
    .Equal = Equal,
};
