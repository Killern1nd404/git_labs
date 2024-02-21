#include <stdio.h>

int countBinDigits(int number) {
    int result = 0;

    while (number) {
        result++;
        number >>= 1;
    }

    return result;
}

int binShiftLeft(int x, int k) {
    int result = x;
    int first_bin_digit_pos = countBinDigits(result) - 1;
    int mask = 1 << first_bin_digit_pos;

    for (int i = 0; i < k; ++i) {
        int digit = (x & mask) >> first_bin_digit_pos;
        result &= ~mask;
        result <<= 1;
        result |= digit;
    }

    return result;
}

int main() {
    int x, k;
    scanf("%d %d", &x, &k);

    printf("%d", binShiftLeft(x, k));
}