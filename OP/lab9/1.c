#include <stdio.h>
#include <stdbool.h>

// Выводит все элементы массива
int printArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Сортирует массив по убыванию
void sort(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (array[i] > array[j]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;

            }
        }
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

// Производит сортировку массива по убыванию если нет повторяющихся элементов, иначе не меняет массив
void tryDescendingSortArray(int *array, size_t size) {
    bool is_elements_unique = true;

    for (size_t i = 0; i < size && is_elements_unique; i++) {
        if (linearSearch(array + i + 1, size - i - 1, array[i]) != -1) {
            is_elements_unique = false;
        }
    }

    if (is_elements_unique) {
        sort(array, size);
    }
}

int main() {
    int a[4] = {4, 2, 3, 1};
    int n = 4;

    tryDescendingSortArray(a, n);
    printArray(a, n);
}