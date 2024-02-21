#include <stdio.h>
#include "1.c"

typedef struct circle_t {
    Point center;
    double r;
} Circle;

// Вводит значения в структуру
void inputCircle(Circle *circle) {
    inputPoint(&circle->center);
    scanf("%lf", &circle->r);
}

// Вводит значения в массив структур Circle
void inputCircles(Circle *circles, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        inputCircle(&circles[i]);
    }
}

// Выводит значения структуры Circle
void outputCircle(Circle circle) {
    printf("center = (%.2lf, %.2lf), r = %.2lf\n", circle.center.x, circle.center.y, circle.r);
}

// Выводит значения структур Circle из массива
void outputCircles(Circle *circles, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        outputCircle(circles[i]);
    }
}

// Проверяет касание окружностей
int hasOneOuterIntersection(Circle c1, Circle c2) {
    if ((c1.center.x - c2.center.x) < DBL_EPSILON && (c1.center.y - c2.center.y) < DBL_EPSILON) {
        return 0;
    } else {
        double distance = getDistance(c1.center, c2.center);
        double r_sum = c1.r + c2.r;

        if (distance > r_sum) {
            return 0;
        } else {
            return 1;
        }
    }
}

// Проверяет, лежит ли одна окружность в другой
int isCircleInOther(const Circle circle1, const Circle circle2) {
    double d = getDistance(circle2.center, circle1.center);

    return d + circle1.r < circle2.r;
}

// Считает для окружности количество вложенных
int countCirclesInCircle(Circle *const circles, const size_t size, const Circle c) {
    int result = 0;

    for (int i = 0; i < size; i++)
        if (isCircleInOther(circles[i], c))
            result++;

    return result;
}

// Меняет окружности местами
void swapCircles(Circle *circle1, Circle *circle2) {
    Circle temp = *circle1;
    *circle1 = *circle2;
    *circle2 = temp;
}

int main() {
    int n;
    scanf("%d", &n);

    Circle circles[n];
    inputCircles(circles, n);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            int i_number = countCirclesInCircle(circles, n, circles[i]);
            int j_number = countCirclesInCircle(circles, n, circles[j]);

            if (i_number >= j_number) {
                if (i_number == j_number) {
                    if (circles[i].r > circles[j].r) {
                        swapCircles(&circles[j], &circles[i]);
                    }
                } else {
                    swapCircles(&circles[i], &circles[j]);
                }
            }
        }
    }

    outputCircles(circles, n);
}