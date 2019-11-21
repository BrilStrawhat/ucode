#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    char *result = NULL;
    char buff;
    int length;

    if (fd != -1) {
        for (length = 0; read(fd, &buff, 1) > 0; length++);
        close(fd);
        result = mx_strnew(length);
        fd = open(file, O_RDONLY);
        for (int i = 0; i < length; i++) {
           read(fd, &buff, 1);
           result[i] = buff;
        }
        close(fd);
        return result;
    }
    return NULL;
}
