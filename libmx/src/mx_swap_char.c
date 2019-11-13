void mx_swap_char(char *s1, char *s2) {
    char buffer = *s2;
    *s2 = *s1;
    *s1 = buffer;
}    
