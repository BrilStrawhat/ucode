#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *ptr_dst = (unsigned char *)dst;
    const unsigned char *ptr_src = (unsigned char *)src;
    unsigned char arr[len];

    for (size_t i = 0; i < len; i++)
        arr[i] = ptr_src[i];
    for (size_t i = 0; i < len; i++)
        ptr_dst[i] = arr[i];
    return dst;
}
