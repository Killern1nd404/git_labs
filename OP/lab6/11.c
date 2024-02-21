#include <stdio.h>

int power(int a, int n) {
    int x = a;
    int result = 1;

    while (n > 0) {
        if (n & 1) {
            result *= x;
        }
        n >>= 1;
        x *= x;
    }

    return result;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort2(int *a, int *b) {
    if (*a > *b) {
        swap(a, b);
    }
}

void sort3(int *a, int *b, int *c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
}

int isTriangleTypeLength(int a, int b, int c) {
    int function_a = a;
    int function_b = b;
    int function_c = c;
    int triangle_type = -1;

    sort3(&function_a, &function_b, &function_c);

    if (function_a + function_b > function_c) {
        if (power(function_a, 2) + power(function_b, 2) == power(function_c, 2)) {
            triangle_type = 1;
        } else if (power(function_a, 2) + power(function_b, 2) > power(function_c, 2)) {
            triangle_type = 0;
        } else {
            triangle_type = 2;
        }
    }

    return triangle_type;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%d", isTriangleTypeLength(a, b, c));
}