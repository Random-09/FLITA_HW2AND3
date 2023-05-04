#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"

// Program that implements a graph data structure using incidence matrix

int main() {
    FILE *filePtr = openFile("../test.txt");
    int fileLen = getFileLen(filePtr);
    char *data = getData(filePtr, fileLen);
    int nodesNum = getNodesNum(data, fileLen);
    int edgesNum = getEdgesNum(data);
    Graph_t *graph = initGraph(nodesNum, edgesNum);


    freeGraph(graph);
    free(data);
    fclose(filePtr);
    return EXIT_SUCCESS;
}



// strtok_r! strdup!

// Automatic file loop 1...200
// Vertices->Nodes