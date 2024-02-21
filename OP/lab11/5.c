#include <stdio.h>

int checkSorting(int *array, int size) {
    if (size == 1) {
        return 1;
    } else if (array[size - 1] < array[size - 2]) {
        return 0;
    }

    checkSorting(array, size - 1);
}

int main() {
    int a[5] = {5, 4, 6, 7, 8};

    printf("%d", checkSorting(a, 5));
}