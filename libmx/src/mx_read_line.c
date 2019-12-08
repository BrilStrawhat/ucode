#include "libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    static char *fd_arr[2][258] = { { NULL } };
    static int i = 0;
    long read_result;
    long char_index;
    char shift;

    if (buf_size < 0)
        return 0;
    if (fd_arr[1][fd] == NULL) {
        fd_arr[0][fd] = mx_strnew(buf_size);
        fd_arr[1][fd] = fd_arr[0][fd];  // save org pointer 
    }
    while (1) {
        i++;
        if (fd_arr[0][fd][0] == '\0') {
            read_result = read(fd, fd_arr[0][fd], buf_size);
            printf("i = %d read:%s\n", i, fd_arr[0][fd]);
        }
        if (read_result == -1)
            return -2;
        char_index = mx_get_char_index(fd_arr[0][fd], delim);
        if (char_index == 0 && fd_arr[0][fd][0] != '\0') {
            // Write to shift array? If yes, will delete next line.
            // fd_arr[0][fd]++;
            mx_memmove(&fd_arr[0][fd][0], &fd_arr[0][fd][1],
                       mx_strlen(fd_arr[0][fd]) * 2 - 1);
            read(fd, &shift, 1);
            printf("i = %d shift fd_arr[0]= %s\n", i, fd_arr[0][fd]);
            return 0;
        }
        *lineptr = mx_strjoin_until_char(*lineptr, fd_arr[0][fd], delim);
        printf("i = %d join:%s\n", i, fd_arr[0][fd]);
        if (char_index != -1) {
            break;
        }
        fd_arr[0][fd][0] = '\0';
    }
    return char_index;
}
