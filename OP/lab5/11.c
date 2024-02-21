#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int years_number = 0;

    while (a <= b) {
        a *= 3;
        b *= 2;
        years_number++;
    }

    printf("%d", years_number);

    return 0;
}