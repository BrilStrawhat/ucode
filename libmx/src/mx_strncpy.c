#include <stdbool.h>

char *mx_strncpy(char *dst, const char *src, int len) {
    if (sizeof dst < sizeof src || len < 0
        || len > (int)sizeof src)
        return false;
    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    return dst;
}
