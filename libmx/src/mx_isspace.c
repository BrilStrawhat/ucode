#include "libmx.h"

bool mx_isspace(int c) {
    if (c == '\t' || c == '\n' || c == '\v'
        || c == '\f' || c == '\r' || c == ' ')
        return true;
    else
        return false;
}
