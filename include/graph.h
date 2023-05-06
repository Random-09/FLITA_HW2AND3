#ifndef FLITA_HW2AND3_GRAPH_H
#define FLITA_HW2AND3_GRAPH_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph {
    bool **matrix;
    int verticesNum;
    int edgesNum;
} Graph_t;

Graph_t *initGraph(int verticesNum, int edgesNum);

void strToGraph(Graph_t *graph, char *data);

void drawGraph(Graph_t *graph, FILE *outputFilePtr, char *outputFileName, char *pngFileName);

void freeGraph(Graph_t *graph);

#endif
