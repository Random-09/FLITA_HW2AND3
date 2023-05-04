#include "../include/parser.h"

FILE *openFile(char *filePath) {
    FILE *filePtr = fopen(filePath, "r");
    if (filePtr == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
    return filePtr;
}

int getFileLen(FILE *filePtr) {
    fseek(filePtr, 0, SEEK_END);
    int fileLen = ftell(filePtr);
    fseek(filePtr, 0, SEEK_SET);
    return fileLen;
}

char *getData(FILE *filePtr, int fileLen) {
    char *data;
    data = (char *) malloc(sizeof(char) * fileLen);
    fread(data, sizeof(char), fileLen, filePtr);
    return data;
}

int getNodesNum(const char *data, int fileLen) {
    int count = 1;
    for (int i = 0; i < fileLen; i++) {
        if (data[i] == '\n')
            count++;
    }
    return count;
}

int getEdgesNum(const char *data) {
    int count = 0;
    int i = 0;
    while (data[i] != '\n') {
        if (data[i] == '0' || data[i] == '1')
            count++;
        i++;
    }
    return count;
}

Graph_t *initGraph(int nodesNum, int edgesNum) {
    Graph_t *graph = (Graph_t *) malloc(sizeof(Graph_t));
    graph->nodesNum = nodesNum;
    graph->edgesNum = edgesNum;
    graph->matrix = (bool **) malloc(nodesNum * sizeof(bool *));
    for (int i = 0; i < nodesNum; i++) {
        graph->matrix[i] = (bool *) malloc(edgesNum * sizeof(bool));
    }
    graph->edges = (int *) malloc(edgesNum * sizeof(int));
    return graph;
}

void strToGraph(Graph_t *graph, char *data) {
    char *token;
    for (int i = 0; i < graph->nodesNum; i++) {
        for (int j = 0; j < graph->edgesNum; j++) {
            token = strtok_r(data, "\n ", &data);
            if (*token == '0')
                graph->matrix[i][j] = false;
            else if (*token == '1')
                graph->matrix[i][j] = true;
        }
    }
}

void freeGraph(Graph_t *graph) {
    for (int i = 0; i < graph->nodesNum; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph->edges);
    free(graph);
}
