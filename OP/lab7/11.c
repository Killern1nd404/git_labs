#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int min_packages = 0;

    while (n) {
        n >>= 1;
        min_packages++;
    }

    printf("%d", min_packages);

    return 0;
}