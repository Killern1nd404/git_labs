#include <stdio.h>
#include <stdbool.h>

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

int arrays_unification(const int a_len, const int *array_a, const int b_len, const int *array_b, int *c_len, int *array_c) {
    *c_len = a_len;

    for (int i = 0; i < a_len; i++) {
        array_c[i] = array_a[i];
    }

    for (int i = 0; i < b_len; i++) {
        bool is_element_in_c = false;

        for (int j = 0; j < *c_len && !is_element_in_c; j++) {
            if (array_b[i] == array_c[j]) {
                is_element_in_c = true;
            }
        }

        if (!is_element_in_c) {
            (*c_len)++;
            array_c[(*c_len) - 1] = array_b[i];
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
    int array_c[100];
    int c_len;

    arrays_unification(a_len, array_a, b_len, array_b, &c_len, array_c);

    printArray(array_c, c_len);

    return 0;
}