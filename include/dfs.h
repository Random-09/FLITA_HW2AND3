#ifndef FLITA_HW2AND3_DFS_H
#define FLITA_HW2AND3_DFS_H

#include <stdlib.h>
#include "graph.h"

typedef struct StackNode {
    int vertex;
    struct StackNode *next;
} StackNode_t;

typedef struct LinkedListNode {
    int vertex;
    struct LinkedList *next;
} LinkedListNode_t;

void stackPush();

int stackPop();

void createListNode();

void freeLinkedList();

void

void dfs(Graph_t *graph, int vertex, int *visited, int *numVertices, int *numEdges);


#endif
