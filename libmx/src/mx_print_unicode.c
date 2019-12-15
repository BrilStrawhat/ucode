#include "libmx.h"

static void print(int b1, int b2, int b3, int b4) {
    if (b1 != 0)
        mx_printchar(b1);
    if (b2 != 0)
        mx_printchar(b2);
    if (b3 != 0)
        mx_printchar(b3);
    if (b4 != 0)
        mx_printchar(b4);
}

static void large(int c) {
    int b1 = 0;
    int b2 = 0;
    int b3 = 0;
    int b4 = 0;

    b1 = (c >> 18 & 0x07) | 0xF0;
    b2 = (c >> 12 & 0x3F) | 0x80;
    b3 = (c >> 6  & 0x3F) | 0x80;
    b4 = (c >> 0  & 0x3F) | 0x80;
    print(b1, b2, b3, b4);
}

static void not_large_but_not_small(int c) {
    int b1 = 0;
    int b2 = 0;
    int b3 = 0;
    int b4 = 0;

    b1 = (c >> 12 & 0x0F) | 0xE0;
    b2 = (c >> 6  & 0x3F) | 0x80;
    b3 = (c >> 0  & 0x3F) | 0x80;
    print(b1, b2, b3, b4);
}

void mx_print_unicode(wchar_t c) {
    int b1 = 0;
    int b2 = 0;
    int b3 = 0;
    int b4 = 0;

    if (c < 0x80)
        b1 = c;
    else if (c < 0x0800) {
        b1 = (c >> 6  & 0x1F) | 0xC0;
        b2 = (c >> 0  & 0x3F) | 0x80;
    }
    else if (c < 0x010000) {
        not_large_but_not_small(c);
        return;
    }
    else {
        large(c);
        return;
    }
    print(b1, b2, b3, b4);
}
