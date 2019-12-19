#include "libmx.h"

static int check_and_read(char **fd_arr, int fd,
                        size_t buf_size, long *read_result)
{
        write(1, "check_and_read strart\n", 30);
        if (*fd_arr == NULL) {
            // write(1, "success\n", 20);
            *fd_arr = mx_strnew(buf_size);
            // if (**fd_arr == '\0') {
                // write(1, "strnew success\n", 1);
            // }
        }
        if (*fd_arr == NULL) // if buf_size < 0;
            return -2;
        if (**fd_arr == '\0') {
            // write(1, "read?\n", 20);
            *read_result = read(fd, *fd_arr, buf_size);
            // printf("errno:%s", strerror(errno));
            // printf("%s\n", *fd_arr);
        }
        if (*read_result == -1) {
            mx_strdel(fd_arr);
            return -2;
        }
        write(1, "check_and_read end\n", 3);
        return *read_result;

}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char *fd_arr[256] = { NULL };
    long read_result;
    long result = 0;

    while (1) {
        write(1, "while start\n", 20);
        write(1, "wtf\n", 20);
        check_and_read(&fd_arr[fd], fd, buf_size, &read_result);
        // if (check_and_read(&fd_arr[fd], fd, buf_size, &read_result) == -2)
            // return -2;
        *lineptr = mx_strjoin_until_char(*lineptr, fd_arr[fd], delim);
        if (*lineptr == NULL)
            write(1, "lineptr\n", 20);
        if (mx_get_char_index(fd_arr[fd], delim) != -1) {
            result += mx_get_char_index(fd_arr[fd], delim);
            mx_shift_str(fd_arr[fd], mx_get_char_index(fd_arr[fd], delim) + 1);
            return result;
        }
        if (read_result == 0) {
            mx_strdel(&fd_arr[fd]);
            return (result == 0) ? -1 : result;
        }
        result += mx_strlen(fd_arr[fd]);
        write(1, "before del\n", 20);
        mx_strdel(&fd_arr[fd]);
        write(1, "while end\n", 20);
    }
}
