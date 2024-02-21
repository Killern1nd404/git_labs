#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int w, h, n;
        scanf("%d %d %d", &w, &h, &n);

        int lists_number = 1;

        while (w % 2 == 0 || h % 2 == 0) {
            lists_number *= 2;

            if (w % 2 == 0) {
                w /= 2;
            } else {
                h /= 2;
            }
        }

        if (lists_number >= n) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}