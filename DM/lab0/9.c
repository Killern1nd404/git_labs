#include <stdio.h>

int inputArray(int *a, int n) {
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

int get_sorted_sum_a_and_b(const int a_len, const int *array_a, const int b_len, const int *array_b, int *c_len, int *array_c) {
    int a_index = 0;
    int b_index = 0;

    while (a_index < a_len && b_index < b_len) {
        if (array_a[a_index] > array_b[b_index]) {
            b_index++;
        } else if (array_a[a_index] < array_b[b_index]) {
            a_index++;
        } else {
            array_c[*c_len] = array_a[a_index];
            a_index++;
            b_index++;
            (*c_len)++;
        }
    }
}

int main() {
    int a_len;
    int b_len;
    scanf("%d", &a_len);
    int array_a[a_len];
    inputArray(array_a, a_len);
    scanf("%d", &b_len);
    int array_b[b_len];
    inputArray(array_b, b_len);
    int c_len = 0;
    int array_c[100];

    get_sorted_sum_a_and_b(a_len, array_a, b_len, array_b, &c_len, array_c);

    printArray(array_c, c_len);

    return 0;
}