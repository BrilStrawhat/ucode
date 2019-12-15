#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    printf("%lu\n", malloc_size(ptr));
    size = 10;
    return ptr;
}
