#include "libmx.h"

int main(void) {
/*    char *ch_arr[] = {
                         "spike",
                         "tom",
                         "jerry"
                     };
    const char delim[3] = "qw";
    mx_print_strarr(ch_arr, delim);*/

//    int i = -2147483648;

/*    char **stringarr;
    int size_of_arr = 4;
    int size_of_string = 10;
    
    stringarr = malloc(size_of_arr * sizeof(char*));
    for (int i = 0; i < size_of_arr; i++) {
        stringarr[i] = malloc(size_of_string * sizeof(char));
    }
    stringarr[0] = "qwertyu";
    stringarr[1] = "asdfghj";
    stringarr[2] = "asdfghj";
    stringarr[3] = "asdfghj";
    stringarr[4] = NULL;
    mx_del_strarr(&stringarr);    */


    //const char str[10] = "qwerty";
    //const char *p_str = "ytrewq";
    const char c_str = 'a';
    printf("%d\n", mx_get_char_index(&c_str, 'a'));
}