#include <stdio.h>

// Производит бинарный поиск элемента в массиве
int binarySearch(const int *a, const int n, const int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return -1;
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

        if (binarySearch(array, n, number) != -1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}