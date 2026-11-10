#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // if argc is not 2, usage and return 1
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // store the argv[1] in variable called filename
    const char *filename = argv[1];

    // print the filename
    printf("Filename: %s\n", filename);
    return 0;
}