#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len,
                const void *little, size_t little_len) {
    unsigned char *ptr_big = (unsigned char *)big;
    unsigned char *ptr_little = (unsigned char *)little;

    if (big_len < little_len || little_len == 0 || big_len == 0
        || big == NULL || little == NULL) {
        return NULL;
    }
    for (size_t j = 0; j < big_len; j++) {
        if (ptr_big[j] == ptr_little[0]) {
            for (size_t i = 0, k = j; ptr_little[i] == ptr_big[k]; i++, k++) {
                if (i == little_len - 1)
                    return (char *)big + j;
            }
        }
    }
    return NULL;
}
