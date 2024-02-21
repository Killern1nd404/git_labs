#include <stdio.h>

// Выводит все элементы массива
int printArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Возвращает сумму чётных цифр числа
int getEvenDigitsSum(int number) {
    int sum = 0;

    while (number) {
        if ((number % 10) % 2 == 0) {
            sum += number % 10;
        }

        number /= 10;
    }

    return sum;
}

// Заменяет элемент массива на результат операнда
void forEach(int *a, size_t n, int(*operand) (int)) {
    for (int i = 0; i < n; i++) {
        a[i] = operand(a[i]);
    }
}

// Возвращает сумму элементов массива
int getElementsSum(const int array[], const int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += array[i];
    }

    return result;
}

int main() {
    int a[6] = {1, 23, 33, 54, 22, 2};
    int n = 6;

    forEach(a, n, getEvenDigitsSum);

    printf("%d", getElementsSum(a, n));
}