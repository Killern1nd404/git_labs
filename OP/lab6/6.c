#include <stdio.h>

int isDigit(int symbol) {
    return ('0' <= symbol && symbol <= '9') ? 1 : 0;
}

int main() {
    int symbol = getchar();

    printf("%d", isDigit(symbol));
}