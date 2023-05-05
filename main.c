#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"
#include "include/graph.h"
#include "include/stack.h"

// Program that implements a graph data structure using incidence matrix

int main() {
    FILE *filePtr = openFile("../test.txt");
    int fileLen = getFileLen(filePtr);
    char *data = getData(filePtr, fileLen);
    int verticesNum = getNodesNum(data, fileLen);
    int edgesNum = getEdgesNum(data);
    Graph_t *graph = initGraph(verticesNum, edgesNum);
//    strToGraph(graph, data);
//    puts("!");
//    printGraph(graph);
    freeGraph(graph);
    free(data);
    fclose(filePtr);
    return EXIT_SUCCESS;
}

// graph->graphPtr
// data->buffer

// strtok_r! strdup!

// Automatic file loop 1...200
