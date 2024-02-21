#include <stdio.h>

// Выводит все элементы массива
void printArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Выполняет сортировку массива методом выбора
void selectionSort(int *array, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int i_selected = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[i_selected]) {
                i_selected = j;
            }
        }

        int temp = array[i];
        array[i] = array[i_selected];
        array[i_selected] = temp;
    }
}

// Удаляет неуникальные элементы из массива
void saveUniqueElements(int array[], int *size) {
    selectionSort(array, *size);
    int saving_index = 0;

    for (size_t i = 0; i < *size; i++) {
        if (array[i - 1] != array[i] && array[i] != array[i + 1]) {
            array[saving_index] = array[i];
            saving_index++;
        }
    }

    (*size) -= *size - saving_index;
}

int main() {
    int a1[5] = {1, 2, 4, 1, 2};
    int n1 = 5;
    saveUniqueElements(a1, &n1);
    printArray(a1, n1);
    printf("\n");

    int a2[5] = {1, 2, 3, 4, 5};
    int n2 = 5;
    saveUniqueElements(a2, &n2);
    printArray(a2, n2);
    printf("\n");

    int a3[5] = {1, 1, 1, 1, 1};
    int n3 = 5;
    saveUniqueElements(a3, &n3);
    printArray(a3, n3);
}