#include <stdio.h>
#include <math.h>

// Возвращает треугольное число
int getTriangleNumber(const int number) {
    return ((number + 1)*number) / 2;
}

// Проверяет является ли число треугольным
int isTriangle(const int x) {
    int left = 1;
    int right = (int)sqrt(x)*2 + 1;
    while ((right - left) > 1) {
        int middle = (left + right) / 2;
        if (x - getTriangleNumber(middle) < 0)
            right = middle;
        else
            left = middle;
    }

    return getTriangleNumber(left) == x;
}

//Проверяет является ли число модным
int isFashion(const int x) {
    for (int i = 1; i < (int)sqrt(x)*2; i++)
        if (isTriangle(x - getTriangleNumber(i)))
            return 1;

    return 0;
}

int main() {
    int x;
    scanf("%d", &x);

    if (isFashion(x)) {
        printf("YES");
    } else {
        printf("NO");
    }
}