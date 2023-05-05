#include "../include/parser.h"

FILE *openFile(char *filePath) {
    FILE *filePtr = fopen(filePath, "rb");
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
    printf("%s", data);
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


