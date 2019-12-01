#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char temp = (unsigned char)(c & 0xFF);
    unsigned char *ptr_s = (unsigned char *)s;

    for (; n >= 0; n--) {
        if (ptr_s[n] == temp)
            return (unsigned char *)s + n;
    }
    return NULL;
}
