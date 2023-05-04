#include "../include/parser.h"

FILE* openFile(char *filePath) {
    FILE *filePtr = fopen(filePath, "w");   // <---- reallocate all file code to parse()
    if (filePtr == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
    return filePtr;
}


void parse(FILE *filePtr) {
    fseek(filePtr, 0, SEEK_END);
    int fileLen = ftell(filePtr);
    fseek(filePtr, 0, SEEK_SET);
    char *buffer;
    buffer = (char *) malloc(sizeof(char) * fileLen);
    char *symb;
    while(fgets(buffer, MAX_LINE_LEN, filePtr) != NULL) {
        symb = strtok(buffer, " ");
        while (symb != NULL) {
            symb = strtok(NULL, " ");
        }
    }
    free(buffer);
    fclose(filePtr);
}