#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    for (int j = 0; haystack[j] != '\0'; j++) {
        if (haystack[j] == needle[0]) {
            for (int i = 0, k = j; needle[i] == haystack[k]; i++, k++) {
                if (needle[i + 1] == '\0')
                    return (char*)haystack + j;
            }
        }
    }
    return NULL;
}
