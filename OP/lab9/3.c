#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Проверяет, отсортирован ли массив по убыванию
bool checkDecreasingSort(const int array[], const size_t size) {
    int previous_element = array[0];

    for (size_t i = 1; i < size; i++) {
        if (array[i] > previous_element) {
            return false;
        }

        previous_element = array[i];
    }

    return true;
}

// Проверяет, отсортирован ли массив по возрастанию
bool checkIncreasingSort(const int array[], const size_t size) {
    int previous_element = array[0];

    for (size_t i = 1; i < size; i++) {
        if (array[i] < previous_element) {
            return false;

        }

        previous_element = array[i];
    }

    return true;
}

// Возвращает среднее геометрическое массива если он не отсортирован
double getMiddleGeometricOfUnsortedArray(const int array[], const size_t size) {
    if (!checkDecreasingSort(array, size) && !checkIncreasingSort(array, size)) {
        double multiplication = 1;
        double multipliers_number = 0;

        for (size_t i = 0; i < size; i++) {
            if (array[i] > 0) {
                multiplication *= array[i];
                multipliers_number++;
            }
        }

        if (multipliers_number == 0) {
            return 0;
        }

        return pow(multiplication, (1.0/multipliers_number));
    }

    return -1;
}

int main() {
    int a1[3] = {4, 1, 2};
    int n1 = 3;
    int a2[5] = {9, 1, 3, 3, 0};
    int n2 = 5;
    int a3[4] = {2, -1, -1, 0};
    int n3 = 4;
    int a4[3] = {-1, -2, -1};
    int n4 = 3;
    int a5[3] = {2, 4, 3};
    int n5 = 3;
    int a6[3] = {-1, -1, -1};
    int n6 = 3;
    int a7[3] = {1, 2, 4};
    int n7 = 3;
    int a8[3] = {4, 2, 2};
    int n8 = 3;

    printf("1. %lf\n", getMiddleGeometricOfUnsortedArray(a1, n1));
    printf("2. %lf\n", getMiddleGeometricOfUnsortedArray(a2, n2));
    printf("3. %lf\n", getMiddleGeometricOfUnsortedArray(a3, n3));
    printf("4. %lf\n", getMiddleGeometricOfUnsortedArray(a4, n4));
    printf("5. %lf\n", getMiddleGeometricOfUnsortedArray(a5, n5));
    printf("6. %lf\n", getMiddleGeometricOfUnsortedArray(a6, n6));
    printf("7. %lf\n", getMiddleGeometricOfUnsortedArray(a7, n7));
    printf("8. %lf", getMiddleGeometricOfUnsortedArray(a8, n8));

    return 0;
}