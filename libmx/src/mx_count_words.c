#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int counter = 0;
 
    if (delimiter < 0 || delimiter > 127)
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter)
            break; 
        if (i == 0 && str[i + 1] == '\0' && str[i] != '\0') {
            return 1;
        }
    }
    if (str[0] != delimiter && str[1] != delimiter && str[0] != '\0')
        counter++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter && str[i + 1] != delimiter 
            && str[i] != '\0' && str[i + 1] != '\0') {
            counter++;
        }
    }
    return counter;
}
