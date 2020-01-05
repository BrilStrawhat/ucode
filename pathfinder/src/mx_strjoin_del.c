#include "libmx.h"

char *mx_strjoin_del(char *s1, const char *s2) {
    char *result;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return (char*)s2;
    if (s2 == NULL)
        return (char*)s1;
    result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    result = mx_strcat(result, s1);
    result = mx_strcat(result, s2);
    mx_strdel(&s1);
    return result;
}
