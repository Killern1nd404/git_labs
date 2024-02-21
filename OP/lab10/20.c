#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// Проверяет равенство элементов
int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

// Выполняет поиск элемента пары в начале
int binSearchForBegin(int *array, const int begin, const int end, int first, long double x) {
    int left = begin;
    int right = end;

    while (right - left >= 0) {
        int middle = left + (right - left) / 2;
        if ((fabsl(x - (first + array[middle])) < DBL_EPSILON) && (middle == begin || !(fabsl(x - (first + array[middle - 1])) < DBL_EPSILON))) {
            return middle;
        } else if ((x - first - array[middle]) > DBL_EPSILON) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

// Выполняет поиск элемента пары в конце
int binSearchForEnd(int *array, const int begin, const int end, int element) {
    int left = begin;
    int right = end;

    while (right - left >= 0) {
        int middle = left + (right - left) / 2;

        if ((middle == end || array[middle + 1] != element) && array[middle] == element) {
            return middle;
        } else if (array[middle] <= element) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

// Выполняет поиск второго элемента
int searchForSecond(int *array, const int begin, const int end, int element, long double x) {
    int second_number = 0;
    int region_start = binSearchForBegin(array, begin, end, element, x);

    if (region_start != -1) {
        int element_2 = array[region_start];
        int region_end = binSearchForEnd( array, region_start, end, element_2 );

        second_number = region_end - region_start + 1;
    }

    return second_number;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int array[n];
        long long int sum = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &array[j]);

            sum += array[j];
        }

        qsort(array, n, sizeof(int), compare_ints);
        long double mid = sum / (long double)n;
        long long int pairs = 0;

        for (int j = 0; j < n - 1; j++) {
            pairs += searchForSecond(array, j + 1, n - 1, array[j], 2*mid);
        }

        printf( "%lld\n", pairs );
    }
}