#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    char *result;
    char *begin_ptr;
    int count_sub;
    int i_sub;
    int i_res;

    count_sub = mx_count_substr(str, sub);
    if (count_sub == 0)
        return mx_strdup(str);
    result = mx_strnew(mx_strlen(str) - 1 +
            ((mx_strlen(replace) - mx_strlen(sub)) * count_sub));
    begin_ptr = result;
    while (count_sub > 0) {
	      i_sub = mx_get_substr_index(str, sub);
        mx_strncpy(result, str, i_sub);
        result += i_sub;
        str += i_sub;
        count_sub--;
    }
    i_sub = mx_get_char_index(str, '\0');
    mx_strncpy(result, str, i_sub);
    return begin_ptr;
}
