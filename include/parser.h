#ifndef FLITA_HW2AND3_PARSER_H
#define FLITA_HW2AND3_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "graph.h"

void checkFile(FILE *filePtr);

int getFileLen(FILE *inputFilePtr);

char *getData(FILE *inputFilePtr, int inputFileLen);

int getNodesNum(const char *data, int inputFileLen);

int getEdgesNum(const char *data);

#endif
