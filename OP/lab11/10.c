#include <stdio.h>

void printMiddleOfNearbyElements(int element) {
    int next_element;
    scanf("%d", &next_element);

    if (next_element >= 0) {
        printf("%f\n", (float)(element + next_element) / 2);

        printMiddleOfNearbyElements(next_element);
    } else {
        return;
    }
}

int main() {
    int first_element;
    scanf("%d", &first_element);

    if (first_element > 0) {
        printMiddleOfNearbyElements(first_element);
    }
}