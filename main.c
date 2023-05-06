#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"
#include "include/graph.h"
#include "include/dfs.h"

// Program that implements a graph data structure using incidence matrix

int main() {
    FILE *inputFilePtr = fopen("../test.txt", "rb");
    checkFile(inputFilePtr);
    int inputFileLen = getFileLen(inputFilePtr);
    char *data = getData(inputFilePtr, inputFileLen);
    int verticesNum = getNodesNum(data, inputFileLen);
    int edgesNum = getEdgesNum(data);
    Graph_t *graph = initGraph(verticesNum, edgesNum);
    strToGraph(graph, data);
    free(data);
    fclose(inputFilePtr);
    FILE *outputFilePtr = fopen("../output.dot", "w");
    checkFile(outputFilePtr);
    drawGraph(graph, outputFilePtr, "../output.dot", "../output.png");
    fclose(outputFilePtr);
    checkGraphConnection(graph);
    freeGraph(graph);
    return EXIT_SUCCESS;
}
