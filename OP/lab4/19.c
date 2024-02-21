#include <stdio.h>
#include <float.h>
#include <math.h>
#include <windows.h>

int fcompare(float a, float b) {
    printf("%.20f %.20f\n", a, b);
    return fabs(a - b) < DBL_EPSILON;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    float number;
    scanf("%f", &number);

    if (number == 0) {
        printf("Последовательность пуста");
    } else {
        float previous_number;
        float difference;
        int numbers_amount = 1;
        int is_progression = 1;

        while (number != 0) {
            previous_number = number;

            scanf("%f", &number);

            if (numbers_amount == 1) {
                difference = number - previous_number;
            }

            if (number != 0) {
                is_progression = fcompare(difference, number - previous_number);
            }

            numbers_amount++;
        }

        if (!is_progression || numbers_amount <= 2) {
            printf("Последовательность не является прогрессией");
        } else {
            printf("Последовательность является прогрессией");
        }
    }

    return 0;
}