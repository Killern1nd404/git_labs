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

int isTrianglePossible(int a, int b, int c) {
    int function_a = a;
    int function_b = b;
    int function_c = c;

    sort3(&function_a, &function_b, &function_c);

    return function_a + function_b > function_c;
}


int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%d", isTrianglePossible(a, b, c));
}