#ifndef FLITA_HW2AND3_GRAPH_H
#define FLITA_HW2AND3_GRAPH_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph {
    bool **matrix;
    bool *visited;
    int verticesNum;
    int edgesNum;
} Graph_t;

Graph_t *initGraph(int verticesNum, int edgesNum);

void strToGraph(Graph_t *graph, char *data);

void freeGraph(Graph_t *graph);

#endif
