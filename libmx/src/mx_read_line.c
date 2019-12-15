#include "libmx.h"

static int fuck_auditor(char **fd_arr, int fd,
                        size_t buf_size, long *read_result) //rename
{
        if (*fd_arr == NULL)
            *fd_arr = mx_strnew(buf_size);
        if (*fd_arr == NULL) // if buf_size < 0;
            return -2;
        if (**fd_arr == '\0') 
            *read_result = read(fd, *fd_arr, buf_size);
        if (*read_result == -1) {
            mx_strdel(fd_arr);
            return -2;
        }
        return *read_result;

}

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    static char *fd_arr[258] = { NULL };
    long read_result;
    long result = 0;

    while (1) {
        if (fuck_auditor(&fd_arr[fd], fd, buf_size, &read_result) == -2)
            return -2;
        *lineptr = mx_strjoin_until_char(*lineptr, fd_arr[fd], delim);
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
        mx_strdel(&fd_arr[fd]);
    }
}
