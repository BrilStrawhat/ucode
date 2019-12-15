#include "libmx.h"

static int newstr(char **fd_arr, size_t buf_size) {
        if (*fd_arr == NULL)
            *fd_arr = mx_strnew(buf_size);
        if (*fd_arr == NULL) // if buf_size < 0;
            return -2;
        return 0;
}

static int fillstr(int fd, char *str, size_t buf_size, long *read_result) {
        if (*str == '\0') 
            *read_result = read(fd, str, buf_size);
        if (*read_result == -1) {
            mx_strdel(&str);
            return -2;
        }
        return *read_result;;
}


int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    static char *fd_arr[258] = { NULL };
    long read_result;
    long result = 0;

    while (1) {
        // if (fd_arr[fd] == NULL)
            // fd_arr[fd] = mx_strnew(buf_size);
        // if (fd_arr[fd] == NULL) // if buf_size < 0;
            // return -2;
        if (newstr(&fd_arr[fd], buf_size) == -2)
            return -2;
        if (fillstr(fd, fd_arr[fd], buf_size, &read_result) == -2)
            return -2;
        // if (*fd_arr[fd] == '\0') 
            // read_result = read(fd, fd_arr[fd], buf_size);
        // if (read_result == -1) {
            // mx_strdel(&fd_arr[fd]);
            // return -2;
        // }
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
