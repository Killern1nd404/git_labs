#include <stdio.h>
#define HEX_MASK 15

int invertHex(int x) {
    int result = 0;

    while (x) {
        result <<= 4;
        result |= x & HEX_MASK;
        x >>= 4;
    }

    return result;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d", invertHex(x));
}