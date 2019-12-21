#include "libmx.h"

char *mx_strdup_until_char(const char *s1, char  delim) {
    char *result;
    
    if (mx_get_char_index(s1, delim) < 0)
        result = mx_strnew(mx_strlen(s1));
    else
        result = mx_strnew(mx_get_char_index(s1, delim));
    result = mx_strcpy_until_char(result, s1, delim);
    return result;
}
