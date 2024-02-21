#include <stdio.h>

int zipBits(int sh1, int sh2) {
    int result = 0;
    int shift = 0;

    while (sh1 || sh2) {
        result |= (sh2 & 1) << shift;
        result |= (sh1 & 1) << (shift + 1);
        shift += 2;
        sh1 >>= 1;
        sh2 >>= 1;
    }

    return result;
}


int main() {
    int sh1, sh2;
    scanf("%d %d", &sh1, &sh2);

    printf("%d", zipBits(sh1, sh2));
}