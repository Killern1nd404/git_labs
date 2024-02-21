#include <stdio.h>
#include <math.h>

double getDistance(int x1, int y1, int x2, int y2) {
    int delta_x = x2 - x1;
    int delta_y = y2 - y1;

    return sqrt(pow(delta_x, 2) + pow(delta_y, 2));
}

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    printf("%lf", getDistance(x1, y1, x2, y2));
}