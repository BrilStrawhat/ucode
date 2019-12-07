#include "libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    // if (buf_size < 0)
        // return 0;
    static char *fd_arr[2][255] = { { NULL } };
    long read_result;
    long write_count = 0;
    long char_index;
    
    if (fd_arr[1][fd - 3] == NULL) {
        fd_arr[0][fd - 3] = mx_strnew(buf_size);
        fd_arr[1][fd - 3] = fd_arr[0][fd - 3];  // save org pointer 
    }
    while (1) {
        // printf("i = %d\n", i++);
        char_index = mx_get_char_index(fd_arr[0][fd - 3], delim);
        if (char_index == -1) {
            read_result = read(fd, fd_arr[0][fd - 3], buf_size);
            printf("\nread_line:%s\n", fd_arr[0][fd - 3]);
            // printf("errno:%s\n", strerror(errno));
        }
        if (read_result == -1)
            return -2;
        // printf("fd_arr[]:%s\n", fd_arr[fd - 3]);
        if (char_index == 0) {
            fd_arr[0][fd - 3]++;
            return 0;
        }
        *lineptr = mx_strjoin_until_char(*lineptr, fd_arr[0][fd - 3], delim);
        printf("read_line, lineptr:%s char_index:%ld\n", *lineptr, char_index);
        write_count += (char_index > 0) ? char_index : 0;
        if (read_result != 0 && char_index == -1) {
            write_count += buf_size;
            continue;
        }
        if (read_result == 0 && write_count == 0)
            return 0;
        fd_arr[0][fd - 3] += write_count;
        printf("CTO%c\n", *fd_arr[0][fd - 3]);
        if (*fd_arr[0][fd - 3] == '\0') {
            printf("\nfree\n");
            mx_strdel(&fd_arr[1][fd - 3]);
        }
        return write_count;
    } 
    return write_count;
}
/* ВИкористати read_result для підрахунку зчитаних байтів*/
