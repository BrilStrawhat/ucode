#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char temp = (unsigned char)(c & 0xFF);
    unsigned char *ptr_s = (unsigned char *)s;

    for (int i = 0; n >= 0; n--, i++) {
        if (ptr_s[i] == temp)
            return (unsigned char *)s + i;
    }
    return NULL;
}
