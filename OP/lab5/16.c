#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        long int s;
        scanf("%ld", &s);

        int max_expense = 0;
        int pow = 1000000000;

        while (s > 0) {
            while (s < pow) {
                pow /= 10;
            }
            max_expense += pow;
            s -= pow - pow / 10;
        }

        printf("%d\n", max_expense);
    }

    return 0;
}