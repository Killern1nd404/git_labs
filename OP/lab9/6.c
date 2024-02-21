#include <stdio.h>

// Выводит все элементы массива
void printArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Переворачивает массив
void reverseArray(int array[], const size_t size) {
    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
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

// Сортирует отрицательные числа по убыванию, а положительные по возрастанию
void sortPositiveAndNegativeElements(int array[], const size_t size) {
    selectionSort(array, size);
    int last_negative_index = -1;

    for (size_t i = 0; i < size && array[i] < 0; i++) {
        last_negative_index++;
    }

    if (last_negative_index != -1) {
        reverseArray(array, size - (size - last_negative_index) + 1);
    }
}

int main() {
    int a1[7] = {3, 2, 1, 1, -4, -5, -6};
    int n1 = 7;
    int a2[8] = {-3, -2, -1, 0, 1, 2, 3, 4};
    int n2 = 8;
    int a3[5] = {1, 2, 3, 4, 5};
    int n3 = 5;

    sortPositiveAndNegativeElements(a1, n1);
    sortPositiveAndNegativeElements(a2, n2);
    sortPositiveAndNegativeElements(a3, n3);

    printArray(a1, n1);
    printf("\n");
    printArray(a2, n2);
    printf("\n");
    printArray(a3, n3);
}