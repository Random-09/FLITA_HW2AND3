#ifndef FLITA_HW2AND3_DFS_H
#define FLITA_HW2AND3_DFS_H

#include <stdlib.h>
#include "graph.h"

void checkGraphConnection(Graph_t *graph);

void dfs(Graph_t *graph, int vertex, bool *visitedVertices, int *verticesCount);


#endif
