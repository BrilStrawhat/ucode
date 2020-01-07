#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int i = 0;
    int size;

    if (sub == NULL || str == NULL)
        return -1;
    size = mx_strlen(sub);
    while(mx_strstr(str, sub) != NULL) {
        str = mx_strstr(str, sub);
        str += size;
        i++;
    }
    return i;
}
