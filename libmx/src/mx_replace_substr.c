#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    char *result;
    int count_sub;
    int i_sub;
    int i_res;
    int costil = mx_strlen(replace) - mx_strlen(sub);

    count_sub = mx_count_substr(str, sub);
    if (count_sub == 0)
        return mx_strdup(str);
    result = mx_strnew(mx_strlen(str) - 1 +
            ((mx_strlen(replace) - mx_strlen(sub)) * count_sub));
    i_sub = mx_get_substr_index(str, sub);
    mx_strncpy(result, str, i_sub);
    while (count_sub > 0) {
        mx_strncpy(&result[i_sub], replace, mx_strlen(replace));
        i_sub += mx_strlen(sub);
        i_res = i_sub;
        i_sub += mx_get_substr_index(&str[i_sub], sub);
        mx_strncpy(&result[i_res], &str[i_res - costil], mx_get_substr_index(&str[i_res - costil], sub));
        count_sub--;
    }
    mx_strncpy(&result[i_res], &str[i_res - costil], mx_strlen(&str[i_res - costil]));
    return result;
}
