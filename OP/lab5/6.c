#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int suitable_participants_number = 0;

    for (int i = 0; i < n; i++) {
        int y;
        scanf("%d", &y);

        if (5 - y >= k) {
            suitable_participants_number++;
        }
    }

    int teams_max_number = suitable_participants_number / 3;

    printf("%d", teams_max_number);

    return 0;
}