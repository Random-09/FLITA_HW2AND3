#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"
#include "include/graph.h"
#include "include/dfs.h"

// Program that implements a graph data structure using incidence matrix

int main() {
    for (int i = 0; i < 199; i++) {
        printf("%d", i);
        char *filePath = (char*)malloc(100 * sizeof(char));
        sprintf(filePath, "../graphs/matrix_of_incendence%d.txt", i);
        FILE *inputFilePtr = fopen(filePath, "rb");
        free(filePath);
        checkFile(inputFilePtr);
        int inputFileLen = getFileLen(inputFilePtr);
        char *data = getData(inputFilePtr, inputFileLen);
        int verticesNum = getNodesNum(data, inputFileLen);
        int edgesNum = getEdgesNum(data);
        Graph_t *graph = initGraph(verticesNum, edgesNum);
        strToGraph(graph, data);
        free(data);
        fclose(inputFilePtr);
        char outputFilePath[100];
        sprintf(outputFilePath, "../outputs/matrix_of_incendence%d.dot", i);
        char pngFilePath[100];
        sprintf(pngFilePath, "../pngs/matrix_of_incendence%d.png", i);
        FILE *outputFilePtr = fopen(outputFilePath, "w");
        checkFile(outputFilePtr);
        drawGraph(graph, outputFilePtr, outputFilePath, pngFilePath);
        puts("!");
        fclose(outputFilePtr);
        checkGraphConnection(graph);
        freeGraph(graph);
    }
    return EXIT_SUCCESS;
}

// graph->graphPtr
// data->buffer
