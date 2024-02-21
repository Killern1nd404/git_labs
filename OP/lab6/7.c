#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float a, b;
    scanf("%f %f", &a, &b);

    swap(&a, &b);
    printf("%f %f", a, b);
}