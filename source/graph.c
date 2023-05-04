#include "../include/graph.h"

Graph_t *initGraph(int verticesNum, int edgesNum) {
    Graph_t *graph = (Graph_t *) malloc(sizeof(Graph_t));
    graph->verticesNum = verticesNum;
    graph->edgesNum = edgesNum;
    graph->matrix = (bool **) malloc(verticesNum * sizeof(bool *));
    for (int i = 0; i < verticesNum; i++) {
        graph->matrix[i] = (bool *) malloc(edgesNum * sizeof(bool));
    }
    graph->visited = (bool *) malloc(edgesNum * sizeof(bool));
    return graph;
}

void strToGraph(Graph_t *graph, char *data) {
    char *token;
    for (int i = 0; i < graph->verticesNum; i++) {
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
    for (int i = 0; i < graph->verticesNum; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph->visited);
    free(graph);
}