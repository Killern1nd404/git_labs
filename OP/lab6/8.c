#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort2(float *a, float *b) {
    if (*a > *b) {
        swap(a, b);
    }
}

int main() {
    float a, b;
    scanf("%f %f", &a, &b);

    sort2(&a, &b);

    printf("%f %f", a, b);
}