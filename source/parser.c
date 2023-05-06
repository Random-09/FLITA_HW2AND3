#include "../include/parser.h"

void checkFile(FILE *filePtr) {
    if (filePtr == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
}

int getFileLen(FILE *inputFilePtr) {
    fseek(inputFilePtr, 0, SEEK_END);
    int fileLen = ftell(inputFilePtr) - 1; // Adjust necessary for correct work on Windows (otherwise reads garbage at EOF)
    fseek(inputFilePtr, 0, SEEK_SET);
    return fileLen;
}

char *getData(FILE *filePtr, int inputFileLen) {
    char *data;
    data = (char *) malloc(sizeof(char) * inputFileLen);
    fread(data, sizeof(char), inputFileLen, filePtr);
    data[inputFileLen] = '\0';
    return data;
}

int getNodesNum(const char *data, int inputFileLen) {
    int count = 1;
    for (int i = 0; i < inputFileLen; i++) {
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