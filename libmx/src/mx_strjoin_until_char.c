#include "libmx.h"

char *mx_strjoin_until_char(const char *s1, const char *s2, char delim) {
    char *result;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return (char*)s2;
    if (s2 == NULL)
        return (char*)s1;
    result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    result = mx_strcat(result, s1);
    result = mx_strcat_until_char(result, s2, delim);
    return result;
}

