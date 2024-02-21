#include <stdio.h>

// Производит поиск ближайшего слева элемента в массиве
int binarySearchNearestLeft(const int *a, const int n, const int x) {
    if (x < a[0]) {
        return 0;
    } else if (x > a[n - 1]) {
        return n;
    }

    int left = -1;
    int right = n;

    while (right - left > 1) {
        int middle = (left + right) / 2;

        if (a[middle] <= x && a[middle + 1] > x) {
            return middle + 1;
        }

        if (a[middle] > x) {
            right = middle;
        } else {
            left = middle;
        }
    }

    return left + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int array[n];

    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        array[i] = element;
    }

    for (int j = 0; j < k; j++) {
        int number;
        scanf("%d", &number);

        printf("%d\n", binarySearchNearestLeft(array, n, number));
    }
}