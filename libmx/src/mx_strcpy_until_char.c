#include "libmx.h"

char *mx_strcpy_until_char(char *dst, const char *src, char delim) {
    int i;
    
    for (i = 0; src[i] != delim && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}
