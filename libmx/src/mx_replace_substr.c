#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,const char *replace) {
    char *result;
    char *begin_ptr;
    int count_sub;
    int i_sub;

    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    count_sub = mx_count_substr(str, sub);
    result = mx_strnew(mx_strlen(str) - 1 +
            ((mx_strlen(replace) - mx_strlen(sub)) * count_sub));
    begin_ptr = result;
    for(; count_sub > 0; count_sub--) {
        i_sub = mx_get_substr_index(str, sub);
        mx_strncpy(result, str, i_sub);
        mx_strcpy(&result[i_sub], replace);
        result += i_sub + mx_strlen(replace);
        str += i_sub + mx_strlen(sub);
    }
    mx_strcpy(result, str);
    return begin_ptr;
}
