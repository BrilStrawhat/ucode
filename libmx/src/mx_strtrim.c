#include "libmx.h"

char *mx_strtrim(const char *str) {
    int begin;
    int end;
    char *result;

    if (str == NULL)
        return NULL;
    for (begin = 0; mx_isspace(str[begin]) == true &&
         str[begin] != '\0'; begin++);
    for (end = mx_strlen(str); mx_isspace(str[end - 1]) == true && end >= 0; end--);
    for (int i = 0; mx_isspace(str[i]) == true; i++) {
        if (str[i + 1] == '\0')
            return mx_strnew(0);
    }
    result = mx_strnew(end - begin);
    result = mx_strncpy(result, str + begin, end - begin);
    return result;
}
