#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int levels_number = 0;
    int qubes_needed = 0;

    while (qubes_needed <= n) {
        levels_number++;
        qubes_needed += (levels_number*(levels_number + 1)) / 2;
    }

    printf("%d",levels_number-1);

    return 0;
}