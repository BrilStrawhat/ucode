#include "libmx.h"

char *mx_strtrim(const char *str) {
    int begin;
    int end;
    char *result;

    if (str == NULL)
        return NULL;
    for (begin = 0; mx_isspace(str[begin]) == true; begin++);
    for (end = mx_strlen(str); mx_isspace(str[end - 1]) == true; end--);
    result = mx_strnew(end - begin);
    result = mx_strncpy(result, str + begin, end - begin);
    return result;
}
