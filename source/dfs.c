#include "../include/dfs.h"

void checkGraphConnection(Graph_t *graph) {
    int verticesCount = 0;
    bool *visitedVertices;
    visitedVertices = (bool *) calloc(graph->verticesNum, sizeof(bool));
    dfs(graph, 0, visitedVertices, &verticesCount);
    free(visitedVertices);
    if (graph->verticesNum == verticesCount)
        puts("Graph is connected");
    else
        puts("Graph is not connected");
}

void dfs(Graph_t *graph, int vertex, bool *visitedVertices, int *verticesCount) {
    visitedVertices[vertex] = true;
    (*verticesCount)++;
    for (int i = 0; i < graph->edgesNum; i++) {
        if (graph->matrix[vertex][i] == 1) {
            for (int j = 0; j < graph->verticesNum; j++) {
                if (graph->matrix[j][i] == 1 && visitedVertices[j] == 0) {
                    dfs(graph, j, visitedVertices, verticesCount);
                }
            }
        }
    }
}