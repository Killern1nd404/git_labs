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

void sort3(float *a, float *b, float *c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
}

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    sort3(&a, &b, &c);

    printf("%f %f %f", a, b, c);
}