#include <stdio.h>
#include <stdlib.h>
#include "Disjoint_Set.h"

#define EDGE_LENGTH  13
#define POINT_LENGTH 11

typedef struct _Edge {
    int start, end;
    int weight;
} Edge;

Edge *Kruskal(Edge *, Edge *);
int  Compare(const void *, const void *);

int main(void)
{
    Edge edge[EDGE_LENGTH], min_tree[EDGE_LENGTH];

    /* Graphic setting */
    edge[0].start  =  1; edge[0].end  =  2; edge[0].weight  = 32;
    edge[1].start  =  1; edge[1].end  =  4; edge[1].weight  = 17;
    edge[2].start  =  2; edge[2].end  =  5; edge[2].weight  = 45;
    edge[3].start  =  3; edge[3].end  =  4; edge[3].weight  = 18;
    edge[4].start  =  4; edge[4].end  =  5; edge[4].weight  = 10;
    edge[5].start  =  5; edge[5].end  =  6; edge[5].weight  = 28;
    edge[6].start  =  3; edge[6].end  =  7; edge[6].weight  =  5;
    edge[7].start  =  4; edge[7].end  =  8; edge[7].weight  =  3;
    edge[8].start  =  5; edge[8].end  =  9; edge[8].weight  = 25;
    edge[9].start  =  6; edge[9].end  = 10; edge[9].weight  =  6;
    edge[10].start =  7; edge[10].end =  8; edge[10].weight = 59;
    edge[11].start =  8; edge[11].end =  9; edge[11].weight =  4;
    edge[12].start =  9; edge[12].end = 10; edge[12].weight = 12;

    /* Find the Minimum Spanning Tree */
    Kruskal(edge, min_tree);

    printf("Left   Right   Weight\n");
    for (int i = 0; i < EDGE_LENGTH; i++) {
        if (min_tree[i].weight) {
            printf("%2d      %2d       %2d\n", 
                        min_tree[i].start, min_tree[i].end, min_tree[i].weight);
        }
    }

    return 0;
}

Edge *Kruskal(Edge *edge, Edge *min_tree)
{
    _Set_Algo *algo = &Set_Algo;

    /* Initializer the disjoint set */
    Set *set  = Create_Set(POINT_LENGTH);

    for (int i = 0; i < EDGE_LENGTH; i++) {
        min_tree[i].start  = 0;
        min_tree[i].end    = 0;
        min_tree[i].weight = 0;
    }

    /* Arrange weight of Edge in ascending order */
    qsort(edge, EDGE_LENGTH, sizeof(edge[0]), Compare);

    /* Find the Minimum Spanning Tree */
    Edge *temp = edge;
    for (int i = 0; i < EDGE_LENGTH; i++) {
        int index_A = algo->Find(set, temp->start);
        int index_B = algo->Find(set, temp->end);

        if (!algo->Equal(index_A, index_B)) {
            algo->Merge(set, index_A, index_B);

            min_tree[i].start  = temp->start;
            min_tree[i].end    = temp->end;
            min_tree[i].weight = temp->weight;
        }
        temp++;
    }

    free(set);

    return min_tree;
}

int Compare(const void *numberA, const void *numberB)
{
    Edge *edgeA = (Edge *) numberA;
    Edge *edgeB = (Edge *) numberB;

    return edgeA->weight - edgeB->weight;
}
