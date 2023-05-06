#include "../include/dfs.h"

void stackPush(StackNode_t **stackTop, int vertex) {
    StackNode_t *node = malloc(sizeof(StackNode_t));
    node->vertex = vertex;
    node->next = *stackTop;
    *stackTop = node;
}

int stackPop(StackNode_t **stackTop) {
    int vertex = (*stackTop)->vertex;
    StackNode_t *temp = *stackTop;
    *stackTop = (*stackTop)->next;
    free(temp);
    return vertex;
}

void dfs(Graph_t *graph, int vertex, int *visited, int *numVertices,
         int *numEdges) { // !!!! другие числа, не как в структуре!
    visited[vertex] = 1;
    (*numVertices)++;
    for (int i = 0; i < graph->edgesNum; i++) {
        if (graph->matrix[vertex][i] == 1) {
            (*numEdges)++;
            for (int j = 0; j < graph->verticesNum; j++) {
                if (graph->matrix[j][i] == 1 && visited[j] == 0) {
                    dfs(graph, j, visited, numVertices, numEdges);
                }
            }
        }
    }
}