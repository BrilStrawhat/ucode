#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int first_len = mx_strlen(s1);

    for (int i = 0; i < mx_strlen(s2); i++) {
        s1[first_len] = s2[i];
        first_len++;
    }
    return s1;
}
