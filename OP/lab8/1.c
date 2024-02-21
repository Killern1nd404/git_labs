#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int inputArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    return *a;
}

int printArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int findElement(int a[], size_t n, int value) {
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            return i;
        }
    }

    return -1;
}

int fineNegativeElement(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            return i;
        }
    }

    return -1;
}

int isEven(const int number) {
    return number % 2 == 0;
}

int isNegative(const int number) {
    return number < 0;
}

bool isPrime(const int number) {
    if (number <= 1) {
        return false;
    }
    if (number == 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int findElementWithPredicate(int a[], size_t n, int(*predicate) (int)) {
    for (int i = 0; i < n; i++) {
        if (predicate(a[i])) {
            return i;
        }
    }

    return -1;
}

int findLastEvenElement(int a[], size_t n) {
    for (int i = n - 1; i >= 0; i--) {
        if (isEven(a[i])) {
            return i;
        }
    }

    return -1;
}

int findLastElementWithPredicate(int a[], size_t n, int(*predicate) (int)) {
    for (int i = n - 1; i >= 0; i--) {
        if (predicate(a[i])) {
            return i;
        }
    }

    return -1;
}

int countNegativeElements(int a[], size_t n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            result++;
        }
    }

    return result;
}

int countElementsWithPredicate(int a[], size_t n, int(*predicate) (int)) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (predicate(a[i])) {
            result++;
        }
    }

    return result;
}

void reverseArray(int *a, size_t n) {
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void sort(int *a, size_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;

            }
        }
    }
}

void selectionSort(int *a, const size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t i_selected = i;

        for (size_t j = i + 1; j < n; j++) {
            if (a[j] < a[i_selected]) {
                i_selected = j;
            }
        }

        int temp = a[i];
        a[i] = a[i_selected];
        a[i_selected] = temp;
    }
}

void cycleArrayShift(int *a, int n, int k) {
    if (n != k) {
        int min_needed_shift = n > k ? k : k % n;
        int first_elements_copy[min_needed_shift];

        for (int j = 0; j < n - min_needed_shift; j++) {
            if (j < min_needed_shift) {
                first_elements_copy[j] = a[j];
            }

            a[j] = a[j + min_needed_shift];
        }

        for (int i = 0; i < min_needed_shift; i++) {
            a[n - i - 1] = first_elements_copy[min_needed_shift - i - 1];
        }
    }
}

int getABS(int number) {
    return number < 0 ? -(number) : number;
}

int getSquare(int number) {
    return number*number;
}

void forEach(int *a, size_t n, int(*operand) (int)) {
    for (int i = 0; i < n; i++) {
        a[i] = operand(a[i]);
    }
}

bool isPositive(int number) {
    return number > 0 ? true : false;
}

bool any(int a[], size_t n, bool(*predicate) (int)) {
    for (int i = 0; i < n; i++) {
        if (predicate(a[i])) {
            return true;
        }
    }

    return false;
}

bool all(int a[], size_t n, bool(*predicate) (int)) {
    for (int i = 0; i < n; i++) {
        if (!predicate(a[i])) {
            return false;
        }
    }

    return true;
}

void arraySplit(const int a[], const size_t n, bool(*predicate) (int), int *b, int*c) {
    int b_index = 0;
    int c_index = 0;

    for (int i = 0; i < n; i++) {
        if (predicate(a[i])) {
            b[b_index] = a[i];
            b_index++;
        } else {
            c[c_index] = a[i];
            c_index++;
        }
    }
}

void insertElement(int *a, int *n, int element, int index) {
    if (index < 0 || index > *n) {
        return;
    }

    for (int i = *n; i > index; i--) {
        a[i] = a[i - 1];
    }

    a[index] = element;
    (*n)++;
}

void appendElement(int *a, int *n, int value) {
    a[*n] = value;
    (*n)++;
}

void removeElement(int *a, const size_t n, const size_t index) {
    a[index] = 0;
}

void removeElementSaveOrder(int *a, int *n, const size_t index) {
    for (size_t i = index; i < *n; i++) {
        a[i] = a[i + 1];
    }

    (*n)--;
}

void removeOddElements(int *a, int *n) {
    int next_even_element_index = 0;

    for (int i = 0; i < *n; i++) {
        if (a[i] % 2 == 0) {
            a[next_even_element_index] = a[i];
            next_even_element_index++;
        }
    }

    *n = next_even_element_index;
}

bool isArrayPalindrome(int a[], size_t n) {//12
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if (a[i] != a[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n = 1;
    int a[1] = {1};
    if (isArrayPalindrome(a, n)) {
        printf("*");
    } else {
        printf("-");
    }
}