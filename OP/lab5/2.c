#include <stdio.h>

int main() {
    long int n;
    int k;
    scanf("%ld %d", &n, &k);

    for (int i = 0; i < k; i++) {
        if (n % 10 != 0) {
            n -= 1;
        } else {
            n /= 10;
        }
    }

    printf("%ld", n);

    return 0;
}