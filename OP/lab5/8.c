#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int odd_numbers = 0;
        int even_numbers = 0;

        for (int j = 0; j < 2*n; j++) {
            int a;
            scanf("%d", &a);

            if (a % 2 == 0) {
                even_numbers++;
            } else {
                odd_numbers++;
            }
        }

        if (odd_numbers == even_numbers) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}