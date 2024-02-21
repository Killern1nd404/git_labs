#include <stdio.h>

int max2(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", max2(a, b));
}