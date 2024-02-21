#include <stdio.h>

int countDigits(int number) {
    int result = 0;

    while (number > 0) {
        result++;
        number /= 10;
    }

    return result;
}

long long int power(int a, int n) {
    int x = a;
    long long int result = 1;

    while (n > 0) {
        if (n & 1) {
            result *= x;
        }
        n >>= 1;
        x *= x;
    }

    return result;
}

long long int convertToBin(int number) {
    long long int result = 0;
    int k = 1;

    while (number != 0) {
        int digit = number & 1;
        result += k * digit;
        k *= 10;
        number >>= 1;
    }

    return result;
}

int isBinPoly(int x) {
    long long int bin_number = convertToBin(x);
    long long int bin_number_copy = bin_number;
    long long int reversed_bin_number = 0;
    long long int k = power(10, countDigits(bin_number) - 1);
    int is_poly = 0;

    while (bin_number_copy != 0) {
        int digit = bin_number_copy % 10;
        reversed_bin_number += k * digit;
        k /= 10;
        bin_number_copy /= 10;
    }

    if ((reversed_bin_number ^ bin_number) == 0) {
        is_poly = 1;
    }

    return is_poly;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d", isBinPoly(x));
}