#include <stdio.h>

void printOct(int x) {
    int result = 0;
    int k = 1;
    while (x != 0) {
        int digit = x & 7;
        printf("%d\n", digit);
        result += k * digit;
        k *= 10;
        x >>= 3;
        printf("%d\n", x);
    }
    printf("%d", result);
}

int main() {
    int x;
    scanf("%d", &x);

    printOct(x);
}