#include <stdio.h>
#include "1.c"
#include <float.h>

typedef struct line_t {
    double a;
    double b;
    double c;
} Line;

// Вводит значения в структуру Line
void inputLine(Line *line) {
    scanf("%lf %lf %lf", &line->a, &line->b, &line->c);
}

// Возвращает линию по двум точкам
Line getLineByPoints(Point p1, Point p2) {
    double a = (p1.y - p2.y);
    double b = (p2.x - p1.x);
    double c = (p1.x * p2.y + p2.x * p1.y);
    Line result = {a, b, c};

    return result;
}

// Возвращает линию по координатам двух точек
Line getLineByCoords(double x1, double y1, double x2, double y2) {
    double a = (y1 - y2);
    double b = (x2 - x1);
    double c = (x1*y2 + x2*y1);
    Line result = {a, b, c};

    return result;
}

// Выводит уравнение прямой
void outputLineEquation(Line line) {
    printf("%+.2lfx%+.2lfy%+.2lf = 0", line.a, line.b, line.c);
}

// Проверяет параллельность прямых
int isParallel(Line line1, Line line2) {
    return (line1.a*line2.b - line1.b*line2.a) < DBL_EPSILON;
}

// Проверяет перпендикулярность прямых
int isPerpendicular(Line line1, Line line2) {
    return (line1.a*line2.b + line1.b*line2.a) < DBL_EPSILON;
}

// Проверяет наличие параллельных в массиве прямых
int hasParallelLines(Line *lines, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (isParallel(lines[i], lines[j])) {
                return 1;
            }
        }
    }

    return 0;
}

// Ищет точку пересечения линий
void printIntersectionPoint(const Line l1, const Line l2) {
    if ((l1.a - l2.a) < DBL_EPSILON && (l1.b - l2.b) < DBL_EPSILON && (l1.c - l2.c) < DBL_EPSILON) {
        printf("Линии совпадают.\n");
    } else if (isParallel(l1, l2)) {
        printf("Линии параллельны.\n");
    } else {
        double x = (l1.c*l2.b - l2.c*l1.b) / (l1.b*l2.a - l2.b*l1.a);
        double y = (l2.c*l1.a - l1.c*l2.a) / (l1.b*l2.a - l2.b*l1.a);

        printf("%lf %lf\n", x, y);
    }
}

int main() {
    Line a = {1, 2.5, 5};

    outputLineEquation(a);
}