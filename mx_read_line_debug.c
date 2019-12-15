#include "libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    static char *fd_arr[258] = { NULL };
    static int i = 0;
    long read_result;
    long char_index;
    long result = 0;

    if (buf_size < 0)
        return 0;
    while (1) {
        i++;
        if (fd_arr[fd] == NULL)
            fd_arr[fd] = mx_strnew(buf_size);
        if (fd_arr[fd][0] == '\0') {
            read_result = read(fd, fd_arr[fd], buf_size);
            // if (read(fd, fd_arr[fd], buf_size) == -1)
                // return -2;
            // else if (read(fd, fd_arr[fd], buf_size) == 0)
                // return -1;
            printf("i = %d read_result = %ld, read:%s|\n", i, read_result, fd_arr[fd]);
            printf("errno:%s\n", strerror(errno));
        }
        if (read_result == -1) {
            mx_strdel(&fd_arr[fd]);
            return -2;
        }
        char_index = mx_get_char_index(fd_arr[fd], delim);
        // if (char_index == 0) {
            // mx_memmove(&fd_arr[fd][0], &fd_arr[fd][1],
                       // mx_strlen(fd_arr[fd])); // How you works?? Write mx_cut_str
            // printf("i = %d shift fd_arr= %s\n", i, fd_arr[fd]);
            // return result;
        // }
        *lineptr = mx_strjoin_until_char(*lineptr, fd_arr[fd], delim);
        printf("i = %d join:%s\n", i, fd_arr[fd]);
        if (char_index != -1) {
            printf("buff = %s, char_index = %ld\n", fd_arr[fd], char_index);
            for (int i = 0; i < char_index + 1; i++) {
                mx_memmove(&fd_arr[fd][0], &fd_arr[fd][1],
                           mx_strlen(fd_arr[fd]));
            }
            printf("AFTER:buff =%s, char_index = %ld\n", fd_arr[fd], char_index);
            result += char_index;
            break;
        }
        if (read_result == 0) {
            mx_strdel(&fd_arr[fd]);
            return -1;
        }
        result += mx_strlen(fd_arr[fd]);
        mx_strdel(&fd_arr[fd]); // what if fd = 1 or fd = 2 etc 
    }
    return result;
}
