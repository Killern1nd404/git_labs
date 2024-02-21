#include <stdio.h>

// Находит минимальное значение величины v
int nightWork(int n, int k) {
    int low = 0;
    int high = n;

    while (low < high) {
        int middle = (low + high) / 2;
        int v = middle;
        int sum = 0;

        while (v > 0) {
            sum += v;
            v /= k;
        }

        if (sum >= n) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    return low;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d", nightWork(n, k));
}