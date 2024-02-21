#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int likes_number = 0;

        for (int j = 0; j < n; j++) {
            int r;
            scanf("%d", &r);

            if (r != 2) {
                likes_number++;
            }
        }

        printf("%d\n", likes_number);
    }

    return 0;
}