#include <stdio.h>

// Выводит все элементы массива
void printArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Производит линейный поиск элемента в массиве
int linearSearch(const int array[], const size_t size, const int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

// Выполняет сортировку массива методом выбора
void selectionSort(int *array, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t i_selected = i;

        for (size_t j = i + 1; j < size; j++) {
            if (array[j] < array[i_selected]) {
                i_selected = j;
            }
        }

        int temp = array[i];
        array[i] = array[i_selected];
        array[i_selected] = temp;
    }
}

// Выполняет сортировку массива после числа x
void SortArrayBetweenX(int array[], const size_t size, const int value) {
    int index = linearSearch(array, size, value);
    if (index != -1) {
        selectionSort(array + index + 1, size - index);
    }
}

int main() {
    int a1[5] = {16, 8, 4, 2, 1};
    int n1 = 5;
    int x1 = 4;
    int a2[5] = {16, 8, 4, 2, 1};
    int n2 = 5;
    int x2 = 16;
    int a3[5] = {16, 8, 4, 2, 1};
    int n3 = 5;
    int x3 = 1;
    int a4[5] = {16, 8, 4, 2, 1};
    int n4 = 5;
    int x4 = 3;

    SortArrayBetweenX(a1, n1, x1);
    SortArrayBetweenX(a2, n2, x2);
    SortArrayBetweenX(a3, n3, x3);
    SortArrayBetweenX(a4, n4, x4);
    printArray(a1, n1);
    printf("\n");
    printArray(a2, n2);
    printf("\n");
    printArray(a3, n3);
    printf("\n");
    printArray(a4, n4);

    return 0;
}