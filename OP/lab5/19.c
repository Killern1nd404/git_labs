#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int given_candy = 0;
    int days = 0;
    int candies_reserve = 0;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (given_candy >= k) {
            break;
        }

        if (a < 8) {
            if (candies_reserve >= (8 - a)) {
                given_candy += 8;
                candies_reserve -= 8 - a;
            } else {
               given_candy += a + candies_reserve;
               candies_reserve = 0;
            }
        } else {
            given_candy += 8;
            candies_reserve += a - 8;
        }

        days++;
    }

    if (days > n || given_candy < k) {
        days = -1;
    }

    printf("%d", days);

    return 0;
}