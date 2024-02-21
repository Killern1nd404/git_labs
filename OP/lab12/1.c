#include <stdio.h>
#include <float.h>
#include <math.h>
#include <malloc.h>

typedef struct point_t {
    double x;
    double y;
} Point;

// Вводит значения структуры
void inputPoint(Point *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

// Выводит значения структуры
void outputPoint(Point p) {
    printf("%.3lf %.3lf\n", p.x, p.y);
}


// Вводит значения в массив структур
void inputPoints(Point *points, const int size) {
    for (int i = 0; i < size; i++) {
        inputPoint(&points[i]);
    }
}

// Выводит значения массива структур
void outputPoints(Point *points, const int size) {
    for (int i = 0; i < size; i++) {
        outputPoint(points[i]);
    }
}

// Возвращает среднюю точку
Point getMiddlePoint(Point p1, Point p2) {
    Point middle_point = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};

    return middle_point;
}

// Проверяет равенство точек
int isEqualPoint(Point p1, Point p2) {
    return fabs(p1.x - p2.x) <= DBL_EPSILON && fabs(p1.y - p2.y) <= DBL_EPSILON;
}

// Проверяет, является ли точка средней
int isPointBetween(Point p1, Point p2, Point p3) {
    Point middle = getMiddlePoint(p1, p2);

    return isEqualPoint(middle, p3);
}

// Меняет значения координат точки
void swapCoordinates(Point *p) {
    double temp = p->x;
    p->x = p->y;
    p->y = temp;
}

// Меняет координаты точек
void swapPoints(Point *p1, Point *p2) {
    double temp_x = p1->x;
    double temp_y = p1->y;
    p1->x = p2->x;
    p1->y = p2->y;
    p2->x = temp_x;
    p2->y = temp_y;
}

// Находит расстояние между точками
double getDistance(Point p1, Point p2) {
    double distance_x = p1.x - p2.x;
    double distance_y = p1.y - p2.y;

    return sqrt(distance_x * distance_x + distance_y * distance_y);
}

int comparePointsM(const void *a, const void *b) {
    Point p1 = *(Point*)a;
    Point p2 = *(Point*)b;
    double distance_x = p1.x - p2.x;
    if (distance_x < DBL_EPSILON) {
        double distance_y = p1.y - p2.y;

        return distance_y;
    } else {
        return distance_x;
    }
}

int comparePointsN(const void *a, const void *b) {
    Point p1 = *(Point*)a;
    Point p2 = *(Point*)b;
    double dist1 = sqrt(p1.x * p1.x + p1.y * p1.y);
    double dist2 = sqrt(p2.x * p2.x + p2.y * p2.y);

    return dist1 - dist2;
}


/*int main() {
    int n = 3;
    Point *points = (Point*)malloc(n * sizeof(Point));
    free(points);
}*/