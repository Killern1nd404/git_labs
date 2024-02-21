#include <stdio.h>
#include <stdlib.h>

// Проверяет равенство чисел
int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// Производит ввод элементов в массив
int inputArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    return *a;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    inputArray(a, n);

    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);

        a[i] -= b;
    }

    qsort(a, n, sizeof(int), compare_ints);
    long long int result = 0;

    for (int i = 0; i < n - 1; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (a[middle] + a[i] > 0) {
                result += (right - middle + 1);
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
    }

    printf("%lld", result);
}