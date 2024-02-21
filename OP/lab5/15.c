#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long int superiority_a = 0;
    long int superiority_b = 0;

    for (int i = 0; i < n; i++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);

        if (t == 1) {
            superiority_a += x;
            superiority_a -= y;
        } else {
            superiority_b += x;
            superiority_b -= y;
        }
    }

    if (superiority_a >= 0) {
        printf("LIVE\n");
    } else {
        printf("DEAD\n");
    }

    if (superiority_b >= 0) {
        printf("LIVE");
    } else {
        printf("DEAD");
    }

    return 0;
}