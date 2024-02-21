#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int points;
    scanf("%d", &points);

    int amazing_performances = 0;
    int max_points = points;
    int min_points = points;

    for (int i = 1; i < n; i++) {
        scanf("%d", &points);

        if (points > max_points) {
            amazing_performances++;
            max_points = points;
        } else if (points < min_points) {
            amazing_performances++;
            min_points = points;
        }
    }

    printf("%d", amazing_performances);

    return 0;
}