#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"
#include "include/graph.h"
#include "include/dfs.h"

// Program that implements a graph data structure using incidence matrix

int main() {
    FILE *inputFilePtr = fopen("../test.txt", "rb");
    checkFile(inputFilePtr);
    int inputFileLen = getFileLen(inputFilePtr);                          // <---- strlen
    char *data = getData(inputFilePtr, inputFileLen);
    int verticesNum = getNodesNum(data, inputFileLen);
    int edgesNum = getEdgesNum(data);
    printf("%d %d\n", edgesNum, verticesNum);
    Graph_t *graph = initGraph(verticesNum, edgesNum);
    strToGraph(graph, data);
    free(data);
    fclose(inputFilePtr);
    FILE *outputFilePtr = fopen("../output.dot", "w");
    checkFile(outputFilePtr);
    drawGraph(graph, outputFilePtr, "../output.dot", "../output.png");
    fclose(outputFilePtr);
    freeGraph(graph);
    return EXIT_SUCCESS;
}

// graph->graphPtr
// data->buffer
