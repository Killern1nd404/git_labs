#include <stdio.h>
#include <memory.h>
#include <malloc.h>

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

int inputArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    return *a;
}

int printArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void merge(const int *a, const size_t n, const int *b, const size_t m, const int *c) {

}

void mergeSort_(int *a, size_t l, size_t r, int *buffer) {
    size_t n = r - l;

    if (n <= 1) {
        return;
    }

    size_t m = (r + l) / 2;
    mergeSort_(a, l, m, buffer);
    mergeSort(a, m, r, buffer);
    merge(a+l, m - l, a + m, r - m, buffer);
    memcpy(a + l, buffer, sizeof(int) *n);
}

void mergeSort(int *a, const size_t n) {
    int *buffer = (int*)malloc(n*sizeof(int));
    mergeSort_(a, 0, n, buffer);
    free(buffer);
}