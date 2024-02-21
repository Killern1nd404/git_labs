#include <stdio.h>

int isPerfect(int a) {
    int sum = 0;
    for (int i = 1; i <= (a / 2); i++) {
        if (a % i == 0) {
            sum += i;
        }
    }

    return (sum == a) ? 1 : 0;
}

int printPerfectNumbers(int n) {
    for (int i = 2; i < n; i++) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printPerfectNumbers(n);

    return 0;
}