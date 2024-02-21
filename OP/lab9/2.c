#include <stdio.h>

// Выводит все элементы массива
void printArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Возвращает индекс первого вхождения в массив максимального числа
int findFirstMaxIndex(const int array[], const size_t size) {
    int max_element = array[0];
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] > max_element) {
            max_element = array[i];
            index = i;
        }
    }

    return index;
}

// Возвращает индекс последнего вхождения в массив минимального числа
int findLastMinIndex(const int array[], const size_t size) {
    int min_element = array[size - 1];
    int index = size - 1;

    for (int i = size - 2; i >= 0; i--) {
        if (array[i] < min_element) {
            min_element = array[i];
            index = i;
        }
    }

    return index;
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

// Выполняет сортировку определённой части массива
void selectionSortOfPart(int *array, int begin_index, int end_index) {
    selectionSort(array + begin_index + 1, begin_index + end_index - 1);
}

// Выполняет сортировку массива между первым вхождение максимального числа и последним вхождением минимального числа
void sortBetweenMinAndMax(int *array, const size_t size) {
    int min_index = findLastMinIndex(array, size);
    int max_index = findFirstMaxIndex(array, size);
    int begin_index = min_index < max_index ? min_index : max_index;
    int end_index = (min_index + max_index) - begin_index;

    selectionSortOfPart(array, begin_index, end_index);
}

int main() {
    int a[8] = {10, 5, 4, 4, 7, 8, 10, 10};
    int n = 8;

    sortBetweenMinAndMax(a, n);
    printArray(a, n);

    return 0;
}