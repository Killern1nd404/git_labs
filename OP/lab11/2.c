#include <stdio.h>

void printOct(int number) {
    if (number > 0) {
        printOct(number / 8);

        printf("%d", number % 8);
    } else {
        return;
    }
}

int main() {
    printOct(1337);
}