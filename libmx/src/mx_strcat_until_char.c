#include "libmx.h"

char *mx_strcat_until_char(char *s1, const char *s2, char delim) {
    int first_len = mx_strlen(s1);

    if (mx_get_char_index(s2, delim) < 0) {
        return mx_strcat(s1, s2);
    }
    for (int i = 0; i < mx_get_char_index(s2, delim); i++) {
        s1[first_len] = s2[i];
        first_len++;
    }
    return s1;
}
