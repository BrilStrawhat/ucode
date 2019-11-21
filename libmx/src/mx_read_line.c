#include "libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0)
        return 0;
    size_t read_result;
    static char line[buf_size] = { '\0' };
    
   if (line[0] != '\0') {
       if (mx_get_char_index(line, delim) > 0

}
