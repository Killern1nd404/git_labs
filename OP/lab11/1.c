#include <stdio.h>
#include <ctype.h>

int countDigits(int digits) {
    int symbol = getchar();

    if (symbol == '\n') {
        return digits;
    } else if (isdigit(symbol)) {
        digits++;
    }

    countDigits(digits);
}

int main() {
    printf("%d", countDigits(0));
}
