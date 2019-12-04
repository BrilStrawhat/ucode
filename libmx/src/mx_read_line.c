#include "libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    // if (buf_size < 0)
        // return 0;
    static char *fd_arr[255] = { NULL };
    long read_result;
    long write_count = 0;
    long char_index;
    
    if (fd_arr[fd - 3] == NULL)
        fd_arr[fd - 3] = mx_strnew(buf_size);
    while (1) {
        if (mx_get_char_index(fd_arr[fd - 3], delim) == -1) {
            read_result = read(fd, fd_arr[fd - 3], buf_size);
            printf("res:%s\n", strerror(errno));
        }
        if (read_result == -1)
            return -2;
        printf("%s\n", fd_arr[fd - 3]);
        *lineptr = mx_strjoin_until_char(*lineptr, fd_arr[fd - 3], delim);
        char_index = mx_get_char_index(fd_arr[fd - 3], delim);
        write_count += (char_index > 0) ? char_index : 0;
        if (mx_get_char_index(fd_arr[fd - 3], delim != -1))
            return write_count;
    } 
    return write_count;
}
/* ВИкористати read_result для підрахунку зчитаних байтів*/
