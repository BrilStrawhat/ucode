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

    /*char *str = "mamamam";
    char *sub = "ma";
    char *replace = "REPLACE";
    printf("%s\n", mx_replace_substr(str, sub, replace));
    printf("%s\n", str);*/

    /*char dst[50] = "what ar\0e you doing, memset?";*/
    /*char src[50] = "bla-bla-bla";*/
    /*printf("%s\n", strncpy(dst, src, 8));*/
    /*printf("%s\n", mx_strncpy(dst, src, 8));*/
    //bug^^

    /*char *one = "asvasfda";*/
    /*char *two = "fdf";*/
    /*printf("%s\n", memmem(one, 15, two, 3));*/
    /*printf("%s\n", mx_memmem(one, 15, two, 3));*/
    //wtf^^

    /*char src[] = "asdf is check of memmove";*/
    /*char dst[4] = "shit";*/
    /*memmove(dst, src, 4);*/
    /*printf("%s\n", dst);*/
    /*printf("%s\n", (one, 15, two, 3));*/

    /*char one[] = "asdf is check of memmove";*/
    /*char mx_one[] = "asdf is check of memmove";*/
    /*char two[] = "asdf is check of memmove";*/
    /*//char two[4] = "shit";*/
    /*printf("org:\n%s\n", one);*/
    /*memcpy(one + 1, one, 5);*/
    /*mx_memcpy(mx_one + 1, mx_one, 5);*/
    /*printf("memcpy:\n%s\n", one);*/
    /*printf("mx_memcpy:\n%s\n", mx_one);*/
    /*memmove(one + 1, one, 5);*/
    /*printf("memmove:\n%s\n", two);*/
    //WTF^^
    //rework bug^^
    
    /*char src[] = "asdf is check of memmove";*/
    /*char mx_one[] = "asdf is check of memmove";*/
    /*char *dst = malloc(16);*/
    /*char *a_dst = "shitasdasdasdasdiiiiia";*/
    /*printf("%zu\n", malloc_size(dst));*/
    /*printf("%zu\n", sizeof(*dst));*/
    /*mx_strcpy(dst, a_dst);*/
    /*printf("%s\n", dst);*/
    /*memmove(dst, src, 10);*/
    /*printf("memmove:\n%s\n", dst);*/
    //WTF^^
    
    int fd = open("test_file", O_RDONLY);
    size_t buf_size = 20;
    // int read_result;
    // static char *fd_arr[255] = { NULL };
    // fd_arr[fd - 3] = mx_strnew(buf_size);
    // read_result = read(fd, fd_arr[fd - 3], buf_size);
    // printf("\n%d\n", read_result);
    // printf("chec:  %s\n", fd_arr[fd - 3]);
    char *lineptr = NULL;
    int res;
    res = mx_read_line(&lineptr, buf_size, '\n', fd);
    printf("res = %d\n lineptr = %s\n", res, lineptr);
}
