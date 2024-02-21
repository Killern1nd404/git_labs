#include <stdio.h>

// Производит поиск ближайшего справа элемента в массиве
int binarySearchNearestRight(const int *a, const int n, const int x) {
    if (x > a[n - 1]) {
        return n + 1;
    } else if (x < a[0]) {
        return 1;
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (a[middle] >= x && a[middle - 1] < x) {
            return middle + 1;
        }

        if (a[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
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

        printf("%d\n", binarySearchNearestRight(array, n, number));
    }
}