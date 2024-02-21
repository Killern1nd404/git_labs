#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int bad_amount = 1;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a == 1) {
            bad_amount = -1;
        }
    }

    printf("%d", bad_amount);

    return 0;
}