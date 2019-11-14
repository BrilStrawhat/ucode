#include "libmx.h"

char *mx_strdup(const char *str) {
    int len;
    char *res;
    
    len = mx_strlen(str);
    res = mx_strnew(len - 1);
    res = (mx_strcpy(res, str));
    return res;
}
