#include <stdio.h>
#include <stdlib.h>

// Производит ввод элементов в массив
int inputArray(long long int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    return *a;
}

// Проверяет равенство чисел
int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

// Производит вычесление максимальной медианы
long long int getMaxMedian(long long int *region, long long int *array, const int size, long long int k) {
    long long int result;

    if (k >= region[size / 2]) {
        result = array[size - 1] + (k - region[size / 2]) / (size / 2 + 1);
    } else {
        long long int index = 0;
        long long int left = 0;
        long long int right = size / 2;

        while (left <= right) {
            long long int middle = left + (right - left) / 2;

            if (region[middle] <= k && region[middle + 1] > k) {
                index = middle;
                break;
            } else if (region[middle] < k) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        result = array[size / 2 + index] + ((k - region[index]) / (index + 1));
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    long long int array[n];
    inputArray(array, n);
    qsort(array, n, sizeof(int), compare_ints);
    long long int region[n / 2 + 1];
    region[0] = 0;

    for (int i = 1, j = n / 2 + 1; j < n; i++, j++)
        region[i] = (array[j] - array[j - 1]) * i + region[i - 1];

    printf("%lld", getMaxMedian(region, array, n, k));
}