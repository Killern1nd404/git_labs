#include <stdio.h>
#include <ctype.h>

void reverseTextExceptDigits() {
    int symbol = getchar();

    if (symbol == '\n') {
        return;
    } else {
        reverseTextExceptDigits();

        if (!isdigit(symbol)) {
            printf("%c", symbol);
        }
    }
}

int main() {
    reverseTextExceptDigits();
}