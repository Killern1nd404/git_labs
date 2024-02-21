#include <stdio.h>
#include <stdbool.h>

bool isFib(int a, int b) {
    if (a == b == 1) {
        return true;
    } else if (a < 1 || b < 1) {
        return false;
    } else {
        isFib(b - a, a);
    }
}

int main() {
    bool is = isFib(1597, 2584);
    if (is) {
        printf("+");
    } else {
        printf("-");
    }
}