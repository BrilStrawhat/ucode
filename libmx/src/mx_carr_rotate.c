void mx_carr_rotate(char *arr, int size, int shift) {
    char buffer;

    for (int i = 0; i < shift; i++) {
        buffer = arr[size - 1];
        for (int j = size - 1; j > 0; j--)
             arr[j] = arr[j - 1];
        arr[0] = buffer;
    }
    if (shift < 0) {
        shift *= -1;
    for (int i = 0; i < shift; i++) {
        buffer = arr[0];
        for (int j = 0; j < size - 1; j++)
            arr[j] = arr[j + 1];
        arr[size - 1] = buffer;
        }
    }
}

