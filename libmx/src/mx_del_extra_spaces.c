#include "libmx.h"

 char *mx_del_extra_spaces(const char *str) {
    char *temp = mx_strtrim(str);
    char *buff = mx_strnew(mx_strlen(str) - 1);
    char *result;

    for (int i = 0, j = 0; i < mx_strlen(temp); i++) {
        if (mx_isspace(temp[i]) == true && mx_isspace(temp[i + 1]) == true)
            continue;
        buff[j] = temp[i];
        j++;
    }
    result = mx_strnew(mx_strlen(buff) - 1);
    result = mx_strcpy(result, buff);
    free(buff);
    free(temp);
    return result;
}
