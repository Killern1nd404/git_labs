#include <stdio.h>

int binarySearch(int *a, int n, int x, int left, int right) {
    if (left <= right) {
        int middle = (left + right) / 2;

        if (a[middle] < x) {
            binarySearch(a, n, x, middle + 1, right);
        } else if (a[middle] > x) {
            binarySearch(a, n, x, left, middle - 1);
        } else {
            return middle;
        }
    } else {
        return -1;
    }
}

int main() {
    int a[5] = {1, 2, 3, 3, 4};
    int n = 5;
    int x = 6;

    printf("%d", binarySearch(a, n, x, 0, n - 1));
}