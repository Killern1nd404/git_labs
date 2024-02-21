#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// Выводит все элементы массива
void printArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Выполняет сортировку массива методом выбора
void selectionSort(int *array, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t i_selected = i;

        for (size_t j = i + 1; j < size; j++) {
            if (array[j] > array[i_selected]) {
                i_selected = j;
            }
        }

        int temp = array[i];
        array[i] = array[i_selected];
        array[i_selected] = temp;
    }
}

// Добавляет в массив c элементы, упорядочные по убыванию, из массива a, которых нет в массиве b
void getArrayOfElementsNonInArrayB(int array_a[], const size_t size_a, int array_b[], const size_t size_b, int array_c[]) {
    selectionSort(array_a, size_a);
    selectionSort(array_b, size_b);
    int index_c = 0;

    for (size_t i = 0; i < size_a; i++) {
        bool is_element_in_b = false;

        for (size_t j = 0; j < size_b && !is_element_in_b; j++) {
            if (array_b[j] == array_a[i]) {
                is_element_in_b = true;
            }
        }

        if (!is_element_in_b) {
            array_c[index_c] = array_a[i];
            index_c++;
        }
    }
}

//void checkProgram()

int main() {
    int a1[3] = {1, 2, 4};
    int na1 = 3;
    int b1[1] = {4};
    int nb1 = 1;
    int c1[3] = {0, 0, 0};
    int true_c1[3] = {2, 1, 0};

    int a2[4] = {1, 2, 2, 4};
    int na2 = 4;
    int b2[2] = {1, 4};
    int nb2 = 2;
    int c2[4] = {0, 0, 0, 0};
    int true_c2[4] = {2, 2, 0, 0};

    int a3[4] = {1, 2, 2, 4};
    int na3 = 4;
    int b3[1] = {3};
    int nb3 = 1;
    int c3[4] = {0, 0, 0, 0};
    int true_c3[4] = {4, 2, 2, 1};

    int a4[14] = {1, 3, 3, 4, 6, 8, 8, 9, 10, 12, 12, 13, 15, 15};
    int na4 = 14;
    int b4[10] = {0, 3, 5, 5, 8, 9, 9, 11, 14, 14};
    int nb4 = 10;
    int c4[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int true_c4[14] = {15, 15, 13, 12, 12, 10, 6, 4, 1, 0, 0, 0, 0, 0};

    getArrayOfElementsNonInArrayB(a1, na1, b1, nb1, c1);
    getArrayOfElementsNonInArrayB(a2, na2, b2, nb2, c2);
    getArrayOfElementsNonInArrayB(a3, na3, b3, nb3, c3);
    getArrayOfElementsNonInArrayB(a4, na4, b4, nb4, c4);
    for (int i = 0; i < na1; i++) {
        assert(c1[i] == true_c1[i]);
    }
    for (int i = 0; i < na2; i++) {
        assert(c2[i] == true_c2[i]);
    }
    for (int i = 0; i < na3; i++) {
        assert(c3[i] == true_c3[i]);
    }
    for (int i = 0; i < na4; i++) {
        assert(c4[i] == true_c4[i]);
    }

    printArray(c1, na1);
    printf("\n");
    printArray(c2, na2);
    printf("\n");
    printArray(c3, na3);
    printf("\n");
    printArray(c4, na4);

    return 0;
}