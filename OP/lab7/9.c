#include <stdio.h>

int countBinDigits(int number) {
    int result = 0;

    while (number) {
        result++;
        number >>= 1;
    }

    return result;
}

int deleteEvenBits(int x) {
    int bin_number_length = countBinDigits(x);
    int result = 0;

    for (int i = 0; i < bin_number_length; i += 2) {
        result <<= 1;
        result |= x >> (bin_number_length - i - 1) & 1;
    }

    return result;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d", deleteEvenBits(x));
}
