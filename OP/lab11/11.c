#include <stdio.h>
#include <stdbool.h>

int isEven(int number) {
    return 1 - number % 2;
}

bool any(int *a, int n, int(*predicate) (int)) {
    if (n == 0) {
        return false;
    } else if (predicate(a[n - 1])) {
        return true;
    } else {
        any(a, n - 1, predicate);
    }
}

bool all(int *a, int n, int(*predicate) (int)) {
    if (n == 0) {
        return true;
    } else if (!predicate(a[n - 1])) {
        return false;
    } else {
        all(a, n - 1, predicate);
    }
}

int main() {
    int a[5] = {2, 4, 4, 8, 4};
    int n = 5;
    bool is = all(a, n, isEven);
    if (is) {
        printf("+");
    } else {
        printf("-");
    }
}