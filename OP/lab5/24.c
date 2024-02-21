#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int max_odd_sum;
    int positive_numbers_sum = 0;
    int max_negative_odd_number = 0;
    int min_positive_odd_number = 0;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a > 0) {
            positive_numbers_sum += a;
            if ((a < min_positive_odd_number || min_positive_odd_number == 0) && a % 2 != 0) {
                min_positive_odd_number = a;
            }
        } else if ((a > max_negative_odd_number || max_negative_odd_number == 0) && a % 2 != 0) {
            max_negative_odd_number = a;
        }
    }

    if (positive_numbers_sum % 2 != 0) {
        max_odd_sum = positive_numbers_sum;
    } else {
        if ((min_positive_odd_number < max_negative_odd_number*-1 && min_positive_odd_number != 0) || max_negative_odd_number == 0) {
            max_odd_sum = positive_numbers_sum - min_positive_odd_number;
        } else {
            max_odd_sum = positive_numbers_sum - max_negative_odd_number*-1;
        }
    }

    printf("%d", max_odd_sum);

    return 0;
}