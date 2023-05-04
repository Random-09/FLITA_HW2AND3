#ifndef FLITA_HW2AND3_PARSER_H
#define FLITA_HW2AND3_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "graph.h"

FILE *openFile(char *filePath);

int getFileLen(FILE *filePtr);

char *getData(FILE *filePtr, int fileLen);

int getNodesNum(const char *data, int fileLen);

int getEdgesNum(const char *data);

#endif
