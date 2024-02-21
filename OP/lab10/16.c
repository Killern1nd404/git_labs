#include <stdio.h>

// Производит ввод элементов в массив
int inputArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    return *a;
}

// Проверяет возвожность разделить массив
int canSplitToSegment(int *a, const size_t size, int k, const long long sum) {
    int counter = 1;
    long long new_sum = 0;

    for (long long i = 0; i < size; i++) {
        if (new_sum + a[i] > sum) {
            counter++;
            new_sum = 0;
        }
        if (a[i] > sum || counter > k) {
            return 0;
        }

        new_sum += a[i];
    }

    return 1;
}

// Вычисляет максимальную минимальную сумму отрезка
long long int getMinSumOnSegment(int *a, const size_t size, int k) {
    long long int left = 0;
    long long int right = size * 1e9;

    while (left + 1 < right) {
        long long int middle = left + (right - left) / 2;

        if (canSplitToSegment(a, size, k, middle))
            right = middle;
        else
            left = middle;

    }

    return right;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int array[n];
    inputArray(array, n);

    printf("%lld", getMinSumOnSegment(array, n, k));
}