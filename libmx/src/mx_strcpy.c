char *mx_strcpy(char *dst, const char *src) {
    int i = 0;

    while (dst[i] != '\0' || src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    return dst;
}
