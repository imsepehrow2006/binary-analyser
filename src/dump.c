#include <stdio.h>
#include <ctype.h>

void dump_hex(const unsigned char *data, long size)
{

    long limit = 256;

    if (size < limit)
    {
        limit = size;
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