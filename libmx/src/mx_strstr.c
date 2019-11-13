#include "libmx.h"

char *strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        if (*haystack == needle[0]) {
            for (int i = 0; needle[i] == haystack[i]; i++) {
                if (needle[i] == '\0')
                    return haystack;
            }
        }
    haystack++;
    }
    return NULL;
}
