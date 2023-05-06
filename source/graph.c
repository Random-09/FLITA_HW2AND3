#include "../include/graph.h"

Graph_t *initGraph(int verticesNum, int edgesNum) {
    Graph_t *graph = (Graph_t *) malloc(sizeof(Graph_t));
    graph->verticesNum = verticesNum;
    graph->edgesNum = edgesNum;
    graph->matrix = (bool **) malloc(verticesNum * sizeof(bool *));
    for (int i = 0; i < verticesNum; i++) {
        graph->matrix[i] = (bool *) malloc(edgesNum * sizeof(bool));
    }
//    graph->visited = (bool *) malloc(edgesNum * sizeof(bool));                <---- May not be necessary
    return graph;
}

void strToGraph(Graph_t *graph, char *data) {                   // <---- READS GARBAGE
    char *token;
    for (int i = 0; i < graph->verticesNum; i++) {
        for (int j = 0; j < graph->edgesNum; j++) {
            token = strtok_r(data, "\n ", &data);
            if (*token == '0') {
                graph->matrix[i][j] = false;
            }
            else if (*token == '1') {
                graph->matrix[i][j] = true;
            }
        }
        puts("");
    }
}

void drawGraph(Graph_t *graph, FILE *outputFilePtr, char *outputFileName, char *pngFileName) {          // rename drawGraph
    fputs("digraph G {\n", outputFilePtr);
    fputs("\tedge[dir=none]\n", outputFilePtr);
    printf("%d %d", graph->verticesNum, graph->edgesNum);
    bool *hasConnections;
    hasConnections = (bool *) calloc(graph->verticesNum, sizeof(bool));
    for (int i = 0; i < graph->edgesNum; i++) {
        int buffer[2];
        int connectionCounter = 0;
        for (int j = 0; j < graph->verticesNum; j++) {
            if (graph->matrix[j][i] == true) {
                hasConnections[j] = true;
                buffer[connectionCounter] = j;
                connectionCounter++;
            }
        }
        if (connectionCounter > 0) {
            if (connectionCounter == 1)
                buffer[1] = buffer[0];
            fprintf(outputFilePtr, "\ta%d -> a%d\n", buffer[0], buffer[1]);
        }
    }
    for (int k = 0; k < graph->verticesNum; k++) {
        if (!hasConnections[k])
            fprintf(outputFilePtr, "\ta%d\n", k);
    }
    free(hasConnections);
    fputs("}", outputFilePtr);
    char str[50];
    sprintf(str, "dot -Tpng %s -o %s", outputFileName, pngFileName);
    system(str);
}

void freeGraph(Graph_t *graph) {
    for (int i = 0; i < graph->verticesNum; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph->visited);
    free(graph);
}