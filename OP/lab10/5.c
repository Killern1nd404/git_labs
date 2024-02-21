#include <stdio.h>

#define EPS 1e-6

// Считает количество кусков
int countPieces(const int *a, const size_t n, const double length) {
    int counter = 0;

    for (size_t i = 0; i < n; i++) {
        counter += a[i] / length;
    }

    return counter;
}

// Производит поиск длины кусков верёвки
double binarySearchRopeLength(const int *a, const size_t n, const int k) {
    double left = 0;
    double right = 1e7;

    while (right - left > EPS) {
        double middle = (right + left) / 2;

        if (countPieces(a, n, middle) >= k) {
            left = middle;
        } else {
            right = middle;
        }
    }

    return left;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int array[n];

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        array[i] = a;
    }

    printf("%lf", binarySearchRopeLength(array, n, k));
}