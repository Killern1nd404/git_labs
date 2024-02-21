#include <stdio.h>

int getProgressionMember(int element, int q, int n) {
    if (n > 1) {
        getProgressionMember(element*q, q, n - 1);
    } else {
        return element;
    }
}

int main() {
    printf("%d", getProgressionMember(1, 2, 1));
}