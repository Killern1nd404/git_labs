#include <stdio.h>

int main() {
    long int n, k;
    scanf("%ld %ld", &n, &k);

    long int max_pleasure;

    long int f, t;
    scanf("%ld %ld", &f, &t);

    if (t <= k) {
        max_pleasure = f;
    } else {
        max_pleasure = f - (t - k);
    }

    for (int i = 1; i < n; i++) {
        scanf("%ld %ld", &f, &t);

        if (t <= k) {
            max_pleasure = (f > max_pleasure) ? f : max_pleasure;
        } else {
            max_pleasure = ((f - (t - k)) > max_pleasure) ? (f - (t - k)) : max_pleasure;
        }
    }

    printf("%ld", max_pleasure);

    return 0;
}