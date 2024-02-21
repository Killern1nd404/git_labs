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

bool check_is_a_in_b(const int a_len, const int *array_a, const int b_len, const int *array_b) {
    for (int i = 0; i < a_len; i++) {
        bool is_element_in_b = false;

        for (int j = 0; j < b_len && !is_element_in_b; j++) {
            if (array_a[i] == array_b[j]) {
                is_element_in_b = true;
            }
        }

        if (!is_element_in_b) {
            return false;
        }
    }

    return true;
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
    bool is_a_in_b = check_is_a_in_b(a_len, array_a, b_len, array_b);

    if (is_a_in_b) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}