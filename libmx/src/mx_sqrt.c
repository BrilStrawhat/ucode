int mx_sqrt(int x) {
    float s0 = 1;
    float s1 = x;

    while (s1 > 1) {
        s1 /= 10;
        s0 *= 10;
    }

    for (s1 = s0; s1 > 0; s1 /= 10) {
        s0 = (s0 + x / s0) / 2;
    }
    return s0;
}
