#include <stdio.h>
#include <stdlib.h>

// Проверяет равенство чисел
int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;

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

// Проверяет можно ли поставить бутылки
int isAbleNBottles(int *array, long long int n, int height) {
    int region[n];

    for (int i = 0; i < n; i++) {
        region[i] = array[i];
    }

    qsort(region, n, sizeof(int), compare_ints);
    int is_size_even = (n % 2 == 0);
    int index = 0;

    while (index + 2 <= n - !is_size_even && height >= 0) {
        height -= region[index];
        index += 2;
    }

    if (!is_size_even && height >= 0) {
        height -= region[n - 1];
    }

    return height >= 0;
}

int main() {
    int n, h;
    scanf( "%d %d", &n, &h );

    if (n > 2) {
        int heights[n];
        inputArray(heights, n);

        long long int left = 0;
        long long int right = n + 1;

        while ((right - left) > 1) {
            long long int middle = (left + right) / 2;

            if (isAbleNBottles(heights, middle, h)) {
                left = middle;
            } else {
                right = middle;
            }
        }

        printf( "%lld", left );
    } else {
        printf("%d", n);
    }
}