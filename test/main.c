#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "libmx.h"

int main() {
    for (int i = 1; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            printf("i = %d; j = %d\n", i, j);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            printf("i = %d; j = %d\n", j, i);
        }
        printf("\n");
    }
    // printf("\n");
    // for (int i = 6; i > 1; i--) {
        // for (int j = 6; j >= i; j--) {
            // printf("i = %d; j = %d\n", i, j);
        // }
        // printf("\n");
    // }

}
