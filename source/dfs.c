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

LinkedListNode_t *createListNode(int vertex) {
    LinkedListNode_t *node = (LinkedListNode_t *) malloc(sizeof(LinkedListNode_t));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

bool isInList(LinkedListNode_t *head, int vertex) {
    LinkedListNode_t *temp = head;
    while (temp != NULL) {
        if (temp->vertex == vertex) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void freeLinkedList(LinkedListNode_t *head) {
    LinkedListNode_t *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void dfs(Graph_t *graph, int vertex, int *visited, int *numVertices, int *numEdges) { // !!!! другие числа, не как в структуре!
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