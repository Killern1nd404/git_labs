#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int max_fullness = 0;
    int fullness = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        fullness = (fullness - a) + b;

        if (fullness > max_fullness) {
            max_fullness = fullness;
        }
    }

    printf("%d", max_fullness);

    return 0;
}