#include <stdio.h>

int swapPairBites(int n) {
    int shift = 0;
    int res = 0;
    int low_bit = n & 1;
    int high_bit = (n & 2) >> 1;
    n >>= 2;

    while (n) {
        res |= high_bit << shift;
        res |= low_bit << (shift + 1);
        low_bit = n & 1;
        high_bit = (n & 2) >> 1;
        shift += 2;
        n >>= 2;
    }

    res |= low_bit << (shift + (high_bit != 0));

    if (high_bit)
        res |= high_bit << shift;

    return res;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d", swapPairBites(x));
}