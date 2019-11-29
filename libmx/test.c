#include "libmx.h"

int main(void) {
    char *str = "This is the test   the really good the test";
    char *sub = "the";
    //char *rap_sub = "yo yo yo";
    char *test = mx_strnew(mx_strlen(str) - 1);
    int i_sub;

    mx_strcpy(test, str);
    i_sub = mx_get_substr_index(str, sub);
    i_sub = mx_get_substr_index(str + i_sub, sub);
    mx_strnreplace(test + i_sub, sub, mx_strlen(sub));
    printf("%d\n", i_sub);
    printf("%s\n", test);
}
