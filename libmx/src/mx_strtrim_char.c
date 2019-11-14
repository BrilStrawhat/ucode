#include "libmx.h"

char *mx_strtrim_char(const char *str, char c) {
    int begin;
    int end;
    char *result;

    if (str == NULL)
        return NULL;
    for (begin = 0; str[begin] == c; begin++);
    for (end = mx_strlen(str); str[end - 1] == c; end--);
    result = mx_strnew(end - begin);
    result = mx_strncpy(result, str + begin, end - begin);
    return result;
}
