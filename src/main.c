#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void dump_hex(const unsigned char *data, long size)
{

    long limit = 256;
    long filesize = size;

    if (filesize < limit)
    {
        limit = filesize;
    }

    for (long off = 0; off < limit; off += 16)
    {
        printf("%08X: ", off);

        for (int j = 0; j < 16; j++)
        {
            if (off + j < limit)
            {
                printf("%02X ", data[off + j]);
            }
            else
            {
                printf("   ");
            }
        }

        printf(" |");

        for (int j = 0; j < 16; j++)
        {
            if (off + j < limit)
            {
                unsigned char c = data[off + j];
                printf("%c", isprint(c) ? c : '.');
            }
        }
        printf("|\n");
    }
}

int main(int argc, char *argv[])
{
    // if argc is not 2, usage and return 1.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // store the argv[1] in variable called filename.
    const char *filename = argv[1];

    // print the filename
    printf("Filename: %s\n", filename);

    // read the file in binary.
    FILE *pFile = fopen(filename, "rb");
    // checks if its not empty.
    if (pFile == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }
    // jumpt to the end.
    fseek(pFile, 0, SEEK_END);
    // get the size of the file.
    long filesize = ftell(pFile);
    // it will jump back to the start.
    rewind(pFile);

    // check if the size of the file is vaild or not.
    if (filesize <= 0)
    {
        fprintf(stderr, "Error: File is either empty or not accessible.\n");
        fclose(pFile);
        return 1;
    }

    // allocate the memory for the file data.
    unsigned char *data = malloc(filesize);
    if (data == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(pFile);
        return 1;
    }

    // read the file data into the allocated memory.
    size_t bytesRead = fread(data, sizeof(unsigned char), filesize, pFile);
    if (bytesRead != (size_t)filesize)
    {
        fprintf(stderr, "Error: Failed to read the entire file.\n");
        free(data);
        fclose(pFile);
        return 1;
    }

    fclose(pFile);
    printf("Size of the file: %ld bytes\n", filesize);

    dump_hex(data, filesize);
    free(data);
    return 0;
}