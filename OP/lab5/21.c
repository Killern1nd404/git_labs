#include <stdio.h>

int main() {
    int n, c;
    scanf("%d %d", &n, &c);

    int previous_price;
    scanf("%d", &previous_price);

    int max_prices_difference = 0;
    int max_income = 0;

    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (previous_price - x > max_prices_difference) {
            max_prices_difference = previous_price - x;
        }

        previous_price = x;
    }

    if (max_prices_difference - c > 0) {
        max_income = max_prices_difference - c;
    }

    printf("%d", max_income);

    return 0;
}