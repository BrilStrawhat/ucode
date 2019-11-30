#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *ptr_s1 = (unsigned char *)s1;
    unsigned char *ptr_s2 = (unsigned char *)s2;

    if (n == 0)
        return 0;
    while (n-- >= 0) {
        if (*ptr_s1 != *ptr_s2) {
            return *ptr_s1 - *ptr_s2;
        }
        ptr_s1++;
        ptr_s2++;
    }
    return 0;
}
