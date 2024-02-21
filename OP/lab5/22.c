#include <stdio.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int previous_number = 0;
    int moves = 0;

    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);

        if (b <= previous_number) {
            moves += ((previous_number - b) / d) + 1;
            previous_number = b + (((previous_number - b) / d) + 1)*d;
        } else {
            previous_number = b;
        }
    }

    printf("%d", moves);

    return 0;
}