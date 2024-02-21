#include <stdio.h>

int countMaxSequenceLength(int x) {
    int current_length = 0;
    int max_length = 0;

    while (x) {
        if (x & 1) {
            current_length++;
        }
        else {
            if (current_length > max_length) {
                max_length = current_length;
            }

            current_length = 0;
        }

        x >>= 1;
    }

    max_length = current_length > max_length ?  current_length : max_length;

    return max_length;
}

int main() {
    int x;
    scanf("%ld", &x);


    printf("%d\n", countMaxSequenceLength(x));
}