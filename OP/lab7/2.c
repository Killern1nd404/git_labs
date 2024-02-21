#include <stdio.h>

int deleteOctNumber(int x, int digit) {
    int result = 0;
    int k = 1;

    while (x != 0) {
        int oct_digit = x & 7;

        if (oct_digit != digit) {
            result += k * oct_digit;
            k *= 10;
        }

        x >>= 3;
    }

    return result;
}

int main() {
    int x, digit;
    scanf("%d %d", &x, &digit);

    printf("%d", deleteOctNumber(x, digit));
}