#include "libmx.h"

char *mx_str_until_char_dup(const char *s1, char  c) {
    char *result;
    int len;
    
    for (len = 0; s1[len] != c; len++);
    result = mx_strnew(len);
    for (int  i = 0; i < len || s1[i] != '\0'; i++) {
        result[i] = s1[i];
    }
    return result;
}
