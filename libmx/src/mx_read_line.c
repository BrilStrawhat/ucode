#include "libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    /*if (buf_size < 0)*/
        /*return 0;*/
    static char *fd_arr[255] = { NULL };
    long read_result;
    
    if (fd_arr[fd - 3] != NULL) {
        fd_arr[fd - 3] = mx_strnew(buf_size);
    }
    if (mx_get_char_index(fd_arr[fd -3], delim) == -1) {
        read_result = read(fd, fd_arr[fd - 3], buf_size);
        if (read_result == -1)
            return -2;
        
    } 
}
