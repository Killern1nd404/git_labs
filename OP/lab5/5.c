#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int suitable_rooms_number = 0;

    for (int i = 0; i < n; i++) {
        int p, q;
        scanf("%d %d", &p, &q);

        if (q - p >= 2) {
            suitable_rooms_number++;
        }
    }

    printf("%d", suitable_rooms_number);

    return 0;
}