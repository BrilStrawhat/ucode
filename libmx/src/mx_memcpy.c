#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *ptr_dst = (unsigned char*)dst;
    unsigned char *ptr_src = (unsigned char*)src;

    if (dst == NULL && src == NULL)
        return NULL;
    while (n-- > 0)
        *ptr_dst++ = *ptr_src++;
    return dst;
}
