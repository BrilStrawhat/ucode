#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    char **result; 

    if (s == NULL)
        return NULL;
    result = malloc(mx_count_words(s, c) * sizeof(char*));
    if (mx_count_words(s, c) == 1) {
        result[0] = mx_strtrim_char(s, c);
        return result;
    }
    for (int i = 0, j = 0; s[i] != '\0'; i++, j++) {
        if (s[i] == c && s[i + 1] != c
            && s[i] != '\0' && s[i + 1] != '\0') {
            result[j] = mx_str_until_char_dup(s, c);
        }
    }
    return result;
}
