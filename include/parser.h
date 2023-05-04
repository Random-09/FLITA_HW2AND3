#ifndef FLITA_HW2AND3_PARSER_H
#define FLITA_HW2AND3_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 50

typedef struct Graph {
    bool** matrix;
    int* edges;
    int numVertices;
    int numEdges;
} Graph_t;


FILE* openFile(char *filePath);

void createGraph();

void freeGraph();

void parse(FILE *filePtr);

#endif
