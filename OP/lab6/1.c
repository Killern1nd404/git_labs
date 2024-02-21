#include <stdio.h>

float abs(float x) {
    return x > 0 ? x : -1*x;
}

int main() {
    int y = 4;
    y >>= 1;
    printf("%d", y);

    float x;
    scanf("%f", &x);

    printf("%f", abs(x));
}