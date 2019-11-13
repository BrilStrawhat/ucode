#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
   char *result;

   result = mx_strnew(mx_strlen(s1));
   for (int i = 0; i < n || s1[i] != '\0'; i++) {
        result[i] = s1[i];
   }
   return result;
}
