// #include "libmx.h"

char *mx_strjoin_until_path(char **s1, const char *s2, char delim);
    // char *result;

    // if (*s1 == NULL && s2 == NULL)
        // return NULL;
    // if (*s1 == NULL) {
        // if (mx_get_char_index(s2, delim) < 0)
            // result = mx_strnew(mx_strlen(s2));
        // else
            // result = mx_strnew(mx_get_char_index(s2, delim) + 1);
        // result = mx_strcat_until_char(result, s2, delim);
        // return mx_strcat(result, delim);
    // }
    // if (s2 == NULL)
        // return (char*)*s1;
    // result = mx_strnew(mx_strlen(*s1) + mx_strlen(s2) + 1);
    // result = mx_strcat(result, *s1);
    // result = mx_strcat_until_char(result, s2, delim);
    // mx_strdel(s1);
    // return mx_strcat(result, delim);
// }

