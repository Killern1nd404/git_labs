#include <stdio.h>

// Выполняет маскимальное число ходов b
int computerGame(int k, int n, int a, int b) {
    if (n >= (k + b - 1) / b) {
        return -1;
    } else {
        if ((k - 1) / a >= n) {
            return n;
        } else {
            return (k - n*b - 1) / (a - b);
        }
    }
}

int main() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int k, n, a, b;
        scanf("%d %d %d %d", &k, &n, &a, &b);

        printf("%d\n", computerGame(k, n, a, b));


    }
}