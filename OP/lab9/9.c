#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Выводит элементы массива
int printArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

// Выводит индекс числа в массиве
int findElement(int a[], size_t n, int value) {
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            return i;
        }
    }

    return -1;
}

// Сортирует массив по возрастанию модулей
void selectionAbsSort(int *a, const int n) {
    for (int i = 0; i < n - 1; i++) {
        int i_selected = i;

        for (int j = i + 1; j < n; j++) {
            if (abs(a[j]) < abs(a[i_selected])) {
                i_selected = j;
            }
        }

        int temp = a[i];
        a[i] = a[i_selected];
        a[i_selected] = temp;
    }
}

// Проверяет, возможно ли из элементов массива составить геометрическую прогрессию
bool checkIsGeometricProgressionPossible(int array[], const int size) {
    selectionAbsSort(array, size);

    if (abs(array[0]) == abs(array[1]) || findElement(array, size, 0) != -1) {
        return false;
    }

    int q = array[1] / array[0];

    for (int i = 1; i < size - 1; i++) {
        if ((array[i + 1]*1.0) / (array[i]*1.0) != q) {
            return false;
        }
    }

    return true;
}

int main() {
    int a1[3] = {4, 1, 2};
    int n1 = 3;
    if (checkIsGeometricProgressionPossible(a1, n1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a2[5] = {-1, -4, -16, 2, 8};
    int n2 = 5;
    if (checkIsGeometricProgressionPossible(a2, n2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a3[3] = {1, 2, 5};
    int n3 = 3;
    if (checkIsGeometricProgressionPossible(a3, n3)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a4[2] = {1, 1};
    int n4 = 2;
    if (checkIsGeometricProgressionPossible(a4, n4)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a5[2] = {0, 1};
    int n5 = 2;
    if (checkIsGeometricProgressionPossible(a5, n5)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a6[3] = {1, 3, 0};
    int n6 = 3;
    if (checkIsGeometricProgressionPossible(a6, n6)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a7[5] = {1, 2, -4, -8, -16};
    int n7 = 5;
    if (checkIsGeometricProgressionPossible(a7, n7)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a8[5] = {1, 1, 1, 1, -1};
    int n8 = 5;
    if (checkIsGeometricProgressionPossible(a8, n8)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a9[3] = {0, 0, 0};
    int n9 = 3;
    if (checkIsGeometricProgressionPossible(a9, n9)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a10[7] = {1, 2, 4, 4, 4, 4, 8};
    int n10 = 7;
    if (checkIsGeometricProgressionPossible(a10, n10)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    int a11[3] = {1, -1, 1};
    int n11 = 3;
    if (checkIsGeometricProgressionPossible(a11, n11)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}