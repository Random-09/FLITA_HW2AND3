#ifndef FLITA_HW2AND3_PARSER_H
#define FLITA_HW2AND3_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 50

typedef struct {
    bool **matrix;
    int *edges;
    int nodesNum;
    int edgesNum;
} Graph_t;


FILE *openFile(char *filePath);

int getFileLen(FILE *filePtr);

char *getData(FILE *filePtr, int fileLen);

int getNodesNum(const char *data, int fileLen);

int getEdgesNum(const char *data);

Graph_t *initGraph(int nodesNum, int edgesNum);

void strToGraph(Graph_t *graph, char *data);

void freeGraph(Graph_t *graph);

#endif
