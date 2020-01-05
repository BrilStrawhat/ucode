#include "libmx.h"

char *mx_strdup_del(char *str) {
    int len;
    char *res;
    
    len = mx_strlen(str);
    res = mx_strnew(len - 1);
    res = (mx_strcpy(res, str));
    mx_strdel(&str);
    return res;
}
