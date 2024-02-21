#include <stdio.h>
#define BITS_IN_BYTE 8

int shiftBits(int x) {
    int result = 0;
    int shift = 0;

    while (x) {
        int bytes = 0;

        for (int i = 0; i < BITS_IN_BYTE; ++i) {
            bytes <<= 1;
            bytes |= x & 1;
            x >>= 1;
        }

        result |= bytes << shift;
        shift += BITS_IN_BYTE;
    }

    return result;
}


int main() {
    int x;
    scanf("%d", &x);

    printf("%lld", shiftBits(x));
}
