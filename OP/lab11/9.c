#include <stdio.h>

int getProgressionFirstMember(int element, int b, int n) {
    if (n > 1) {
        getProgressionFirstMember(element-b, b, n - 1);
    } else {
        return element;
    }
}

int main() {
    printf("%d", getProgressionFirstMember(12, 3, 4));
}