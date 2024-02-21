#include <stdio.h>

int search(int *a, int size, int x) {
    if (size == 0 || a[size - 1] > x) {
        return -1;
    } else if (a[size - 1] == x) {
        return size - 1;
    } else {
        search(a, size - 1, x);
    }
}

int main() {
    int a[5] = {10, 9, 8, 2, 0};

    printf("%d", search(a, 5, 3));
}