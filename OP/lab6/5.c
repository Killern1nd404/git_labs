#include <stdio.h>
#include <math.h>
#include <windows.h>

void solveX2(int a, int b, int c) {
    int discriminant = pow(b, 2) - 4*a*c;

    if (discriminant < 0) {
        printf("Корней нет");
    } else {
        double discriminant_sqrt = sqrt(discriminant);
        double x1 = (-b - discriminant_sqrt) / (2*a);

        if (discriminant > 0) {
            double x2 = (-b + discriminant_sqrt) / (2*a);

            printf("%lf %lf", x1, x2);
        } else {
            printf("%lf", x1);
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    solveX2(a, b, c);
}