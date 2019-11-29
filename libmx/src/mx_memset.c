#include "libmx.h"

 void *mx_memset(void *b, int c, size_t len) {
     unsigned char *ptr = (unsigned char*)b;

     c = (c & 0xFF);
     while (len > 0) {
         *ptr++ = c;
         len--;
     }
     return b;
 }
