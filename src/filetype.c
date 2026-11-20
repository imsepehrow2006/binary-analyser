#include <stdio.h>

const char *identify_type(const unsigned char *data, long size) {
    if (size < 4) {
        printf("File is too small to show the type.\n");
        return "Unknown";
    }

    if (data[0] == 0x4D && data[1] == 0x5A) {
        return "MZ (A Windows executable file)";
    } else if (data[0] == 0x7F && data[1] == 'E' && data[2] == 'L' && data[3] == 'F') {
        return "ELF (A Linux executable file)";
    } else if (data[0] == 0x89 && data[1] == 'P' && data[2] == 'N' && data[3] == 'G') {
        return "PNG (A PNG image file)";
    } else if (data[0] == 0x25 && data[1] == 'P' && data[2] == 'D' && data[3] == 'F') {
        return "PDF (A PDF document)";
    } else if (data[0] == 0x50 && data[1] == 'K' && data[2] == 0x03 && data[3] == 0x04) {
        return "A Zip (so also .docx, .jar, .apk)";
    } else {
        return "Unknown";
    }

}