#include <stdio.h>

int main() {
    int n, h;
    scanf("%d %d", &n, &h);

    int road_width = 0;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a > h) {
            road_width++;
        }
        road_width++;
    }

    printf("%d", road_width);

    return 0;
}