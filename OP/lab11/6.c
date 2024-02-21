#include <stdio.h>

int getFirstMinIndex(int *a, int size, int min_index) {
    if (size == 1) {
        return min_index;
    } else {
        if (a[size - 1] <= a[min_index]) {
            min_index = size - 1;
        }

        getFirstMinIndex(a, size - 1, min_index);
    }
}

int main() {
    int a[1] = {1};
    int n = 2;
    printf("%d", getFirstMinIndex(a, n, 0));
}