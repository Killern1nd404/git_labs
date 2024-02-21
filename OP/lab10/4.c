#include <stdio.h>
#include <stdlib.h>

// Производит ввод элементов в массив
int inputArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    return *a;
}

// Проверяет равенство чисел
int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

// Проверяет, меньше или равно ли число другого
int isLessOrEqual(int a, int b) {
    return a <= b;
}

// Проверяет, меньше ли число другого
int isLess(int a, int b) {
    return a < b;
}

// Выполняет поиск элемента по предикату
int binarySearchPredicate(int *const arr, const size_t size, int x, int (*comp)(int, int)) {
    int left = -1;
    int right = size;

    while (right - left > 1) {
        int middle = left + (right - left) / 2;

        if (comp(arr[middle], x)) {
            left = middle;
        } else {
            right = middle;
        }
    }

    if (comp(1, 1)) {
        return left > -1 && (right < size || arr[left] == x) ? left : -1;
    } else {
        return right < size && arr[right] >= x && arr[0] <= x ? right : -1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int array[n];
    inputArray(array, n);
    qsort(array, n, sizeof(array[0]), compare_ints);

    int k;
    scanf("%d", &k);

    for (int j = 0; j < k; j++) {
        int l, r;
        scanf("%d %d", &l, &r);

        int left = binarySearchPredicate(array, n, l, isLess);
        int right = binarySearchPredicate(array, n, r, isLessOrEqual);
        int is_left = left < array[0];
        int is_right = right > array[n - 1];
        int requests = 0;

        if (right != -1) {
            if (left == -1) {
                requests = right + 1;
            } else {
                requests = right - left + 1;
            }
        } else if (left != -1) {
            requests = n - left;
        } else if (is_left && is_right) {
            requests = n;
        }

        printf("%d\n", requests);
    }
}