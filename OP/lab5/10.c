#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int summand_number = n / 2;

    printf("%d\n", summand_number);

    for (int i = 1; i < summand_number; i++) {
        printf("2 ");
    }

    if (n % 2 == 0) {
        printf("2");
    } else {
        printf("3");
    }

    return 0;
}