char *mx_strcat(char *s1, const char *s2) {
    int first_len = (int)sizeof s1;

    for (int i = 0; i < (int)sizeof s2; i++) {
        s1[first_len] = s2[i];
        first_len++;
    }
    return s1;
}
