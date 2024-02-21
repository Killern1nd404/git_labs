#include <stdio.h>

// Производит линейный поиск элемента в массиве
int linearSearch(const int array[], const size_t size, const int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

// Находит ближайший к числу элемент массива сверху
int getElementMoreThenNumber(const int array[], const int size, const int number) {
    int result = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] > number && (array[i] < result || result == -1)) {
            result = array[i];
        }
    }

    return result;
}

// Находит ближайший к числу элемент массива снизу
int getElementLessThenNumber(const int array[], const int size, const int number) {
    int result = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] < number && (array[i] > result || result == -1)) {
            result = array[i];
        }
    }

    return result;
}

int main() {
    int a1[5] = {1, 3, 6, 2, 5};
    int n1 = 5;
    int x1 = 6;
    int x_in_a1 = linearSearch(a1, n1, x1);
    if (x_in_a1 != -1) {
        printf("x - element in array\n");
    } else {
        int less_number1 = getElementLessThenNumber(a1, n1, x1);
        int more_number1 = getElementMoreThenNumber(a1, n1, x1);

        if (less_number1 == -1) {
            printf("-inf %d\n", more_number1);
        } else if (more_number1 == -1) {
            printf("%d inf\n", less_number1);
        } else {
            printf("%d %d\n", less_number1, more_number1);
        }
    }

    int a2[5] = {1, 3, 6, 2, 5};
    int n2 = 5;
    int x2 = 4;
    int x_in_a2 = linearSearch(a2, n2, x2);
    if (x_in_a2 != -1) {
        printf("x - element in array\n");
    } else {
        int less_number2 = getElementLessThenNumber(a2, n2, x2);
        int more_number2 = getElementMoreThenNumber(a2, n2, x2);

        if (less_number2 == -1) {
            printf("-inf %d\n", more_number2);
        } else if (more_number2 == -1) {
            printf("%d inf\n", less_number2);
        } else {
            printf("%d %d\n", less_number2, more_number2);
        }
    }

    int a3[5] = {1, 3, 6, 2, 5};
    int n3 = 5;
    int x3 = 0;
    int x_in_a3 = linearSearch(a3, n3, x3);
    if (x_in_a3 != -1) {
        printf("x - element in array\n");
    } else {
        int less_number3 = getElementLessThenNumber(a3, n3, x3);
        int more_number3 = getElementMoreThenNumber(a3, n3, x3);

        if (less_number3 == -1) {
            printf("-inf %d\n", more_number3);
        } else if (more_number3 == -1) {
            printf("%d inf\n", less_number3);
        } else {
            printf("%d %d\n", less_number3, more_number3);
        }
    }

    int a4[5] = {1, 3, 6, 2, 5};
    int n4 = 5;
    int x4 = 7;
    int x_in_a4 = linearSearch(a4, n4, x4);
    if (x_in_a4 != -1) {
        printf("x - element in array\n");
    } else {
        int less_number4 = getElementLessThenNumber(a4, n4, x4);
        int more_number4 = getElementMoreThenNumber(a4, n4, x4);

        if (less_number4 == -1) {
            printf("-inf %d\n", more_number4);
        } else if (more_number4 == -1) {
            printf("%d inf\n", less_number4);
        } else {
            printf("%d %d\n", less_number4, more_number4);
        }
    }

    int a5[5] = {1, 1, 5, 5, 5};
    int n5 = 5;
    int x5 = 3;
    int x_in_a5 = linearSearch(a5, n5, x5);
    if (x_in_a5 != -1) {
        printf("x - element in array\n");
    } else {
        int less_number5 = getElementLessThenNumber(a5, n5, x5);
        int more_number5 = getElementMoreThenNumber(a5, n5, x5);

        if (less_number5 == -1) {
            printf("-inf %d\n", more_number5);
        } else if (more_number5 == -1) {
            printf("%d inf\n", less_number5);
        } else {
            printf("%d %d\n", less_number5, more_number5);
        }
    }
}