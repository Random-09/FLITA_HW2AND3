#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"

// Program that implements a graph data structure using incidence matrix

int main() {
    FILE *filePtr = openFile("../test.txt");
    parse(filePtr);
    return EXIT_SUCCESS;
}



// Automatic file loop 1...200
// Vertices->Nodes