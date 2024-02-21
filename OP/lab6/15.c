#include <stdio.h>

/*int power(int a, int n) {
    int x = a;
    int result = 1;

    while (n > 0) {
        if (n & 1) {
            result *= x;
        }
        n >>= 1;
        x *= x;
    }

    return result;
}*/

int countDigits(int number) {
    int result = 0;

    while (number > 0) {
        result++;
        number /= 10;
    }

    return result;
}

int getHalfSum(int *x, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += *x % 10;
        *x /= 10;
    }

    return sum;
}

int isLuckyTicket(int x) {
    int half_digits = countDigits(x) / 2;
    int sum1 = getHalfSum(&x, half_digits);
    int sum2 = getHalfSum(&x, half_digits);

    return sum1 == sum2;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", isLuckyTicket(n));
}