#include <stdio.h>
#include <float.h>
#include <math.h>

typedef struct point_t {
    double x;
    double y;
} Point;

typedef struct rect_t {
    Point center;
    double length;
    double height;
} Rect;

// Вводит значения структуры Rect
void inputRect(Rect *rect) {
    scanf("%lf %lf %lf %lf", &rect->center.x, &rect->center.y, &rect->length, &rect->height);
}

// Выводит значения структуры Rect
void outputRect(Rect rect) {
    printf("center=(%lf %lf) length=%lf height=%lf\n", rect.center.x, rect.center.y, rect.length, rect.height);
}

// Проверяет, является ли прямоугольник квадратом
int isSquare(Rect rect) {
    return fabs(rect.length - rect.height) < DBL_EPSILON;
}

// Проверяет, пересекаются ли прямоугольники
int isRectsIntersect(Rect rect1, Rect rect2) {
    double center_distance_x = fabs(rect1.center.x - rect2.center.x);
    double center_distance_y = fabs(rect1.center.y - rect2.center.y);
    double common_half_length = (rect1.length + rect2.length) / 2;
    double common_half_height = (rect1.height + rect2.height) / 2;

    if (center_distance_x > common_half_length || center_distance_y > common_half_height) {
        return 0;
    } else {
        return 1;
    }
}

// Находит площадь прямоугольника
double getRectSquare(Rect rect) {
    return rect.length * rect.height;
}

// Находит пересечение двух прямоугольников
Rect getIntersection(Rect rect1, Rect rect2) {
    double left_x = (rect1.center.x - rect1.length / 2) > (rect2.center.x - rect2.length / 2) ? (rect1.center.x - rect1.length / 2) : (rect2.center.x - rect2.length / 2);
    double right_x = (rect1.center.x + rect1.length / 2) < (rect2.center.x + rect2.length / 2) ? (rect1.center.x + rect1.length / 2) : (rect2.center.x + rect2.length / 2);
    double top_y = (rect1.center.y - rect1.height / 2) > (rect2.center.y - rect2.height / 2) ? (rect1.center.y - rect1.height / 2) : (rect2.center.y - rect2.height / 2);
    double bottom_y = (rect1.center.y + rect1.height / 2) < (rect2.center.y + rect2.height / 2) ? (rect1.center.y + rect1.height / 2) : (rect2.center.y + rect2.height / 2);

    Rect result = {{0, 0}, 0, 0};

    if (left_x < right_x && top_y < bottom_y) {
        result.center.x = (left_x + right_x) / 2;
        result.center.y = (top_y + bottom_y) / 2;
        result.length = right_x - left_x;
        result.height = bottom_y - top_y;
    }

    return result;
}

// Находит площадь пересечения 2 прямоугольников
double getTwoRectsIntersectionSquare(Rect rect1, Rect rect2) {
    Rect intersection = getIntersection(rect1, rect2);

    return intersection.length * intersection.height;
}

// Находит площадь пересечения нескольких прямоугольников
double getRectsIntersectionSquare(Rect *rects, const size_t size) {
    if (size == 0) {
        return 0;
    } else if (size > 1) {
        Rect intersection = getIntersection(rects[0], rects[1]);

        for (size_t i = 2; i < size; i++) {
            if (intersection.length == 0 && intersection.height == 0) {
                return 0;
            }

            intersection = getIntersection(intersection, rects[i]);
        }

        return intersection.length * intersection.height;
    } else {
        return rects[0].length * rects[0].height;
    }
}

int main() {
    Rect rect1 = {{2, 2}, 2, 2};
    Rect rect2 = {{2.5, 1.5}, 1, 1};
    Rect rect3 = {{3.5, 0.75}, 3, 1.5};
    Rect rects[3] = {rect1, rect2, rect3};
    size_t size = 3;

    printf("%lf\n", getRectsIntersectionSquare(rects, size));
}