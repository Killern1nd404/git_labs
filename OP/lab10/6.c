#include <stdio.h>

// Выполняет подсчёт времени для выполнения печати
int veryEasyTask(int n, int x, int y) {
    int time;

    if (n == 1) {
        time = x < y ? x : y;
    } else {
        int low = 0;
        int high = 2e9 + 10;

        while ((high - low) > 1) {
            int middle = (low + high) / 2;

            if ((middle / x) + (middle / y) < n - 1) {
                low = middle;
            }
            else {
                high = middle;
            }
        }

        time = x < y ? high + x : high + y;
    }

    return time;
}

int main() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    printf("%d", veryEasyTask(n, x, y));
}