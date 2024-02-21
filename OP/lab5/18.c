#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++){
        long long int n;
        scanf("%lld", &n);

        long long int sum = (1 + n) * n / 2;
        int two_pow_number = 1;

        while (two_pow_number <= n){
            sum -= two_pow_number * 2;
            two_pow_number *= 2;
        }

        printf("%lld\n", sum);
    }

    return 0;
}