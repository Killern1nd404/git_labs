#include <stdio.h>
#include <math.h>

int isPrime(int a) {
    int divisors = 0;

    for (int i = 2; i < sqrt(a) && divisors == 0; i+=2) {
        if (a % i == 0) {
            divisors++;
        }
    }

    return divisors == 0 ? 1 : 0;
}

int main() {
    int a;
    scanf("%d", &a);

    printf("%d", isPrime(a));

    return 0;
}