#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
                 int c, size_t n) {
    unsigned char *ptr_dst = (unsigned char*)dst;
    unsigned char *ptr_src = (unsigned char*)src;
    int i;
    c = (unsigned char)(c & 0xFF);

    if (dst == NULL && src == NULL)
        return NULL;
    for (i = 0; n > 0; i++, n--) {
        ptr_dst[i] = ptr_src[i];
        if (ptr_src[i] == c)
            return (char *)dst + i + 1;
    }
    return NULL;
}
