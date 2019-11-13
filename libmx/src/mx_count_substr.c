#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int i = 0;
    int size = mx_strlen(sub);

    if (sub == NULL || str == NULL)
        return -1;
    while(mx_strstr(str, sub) != NULL) {
        str = mx_strstr(str, sub);
        str += size;
        i++;
    }
    return i;
}
