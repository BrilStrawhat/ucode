#include "libmx.h"

static int check_and_read(char **fd_arr, int fd,
                          size_t buf_size, long *read_result)
{
    if (fd < 0) 
        return -2;
    if (*fd_arr == NULL) {
        *fd_arr = mx_strnew(buf_size);
    }
    if (*fd_arr == NULL) // if buf_size < 0;
        return -2;
    if (**fd_arr == '\0') {
        *read_result = read(fd, *fd_arr, buf_size);
        if (*read_result == -1) {
            mx_strdel(fd_arr);
            return -2;
        }
    }
    return *read_result;
}

static void fill_result(int *result, char **str, char delim) {
    *result += mx_get_char_index(*str, delim);
    mx_shift_str(*str, mx_get_char_index(*str, delim) + 1);
    if (*str[0] == '\0')
        mx_strdel(str);
}

static void costil(char **lineptr) {
    if (*lineptr != NULL)
        mx_strdel(lineptr);
}

static int costil_2(char *fd_arr, char **lineptr, int result) {
    mx_strdel(&fd_arr);
    mx_strdel(lineptr);
    return (result == 0) ? -1 : result;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char *fd_arr[256] = { NULL };
    long read_result = -1;
    int result = 0;

    costil(lineptr);
    while (1) {
        if (check_and_read(&fd_arr[fd], fd, buf_size, &read_result) == -2)
            return -2;
        *lineptr = mx_strjoin_until_char(lineptr, fd_arr[fd], delim);
        if (mx_get_char_index(fd_arr[fd], delim) != -1) {
            fill_result(&result, &fd_arr[fd], delim);
            return result;
        }
        if (read_result == 0) {
            return costil_2(fd_arr[fd], lineptr, result);
        }
        result += mx_strlen(fd_arr[fd]);
        mx_strdel(&fd_arr[fd]);
    }
}
