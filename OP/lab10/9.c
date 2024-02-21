#include <stdio.h>

// Вводит значения в массив
int inputArray(int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        a[i] = element;
    }

    return *a;
}

// Определяет максимальное количество прочитанных книг
int books(int *a, int n, int t) {
    int time = 0;
    int start_index = 0;

    for (int i = 0; i < n; i++) {
        time += a[i];

        if (time > t) {
            time -= a[start_index];
            start_index++;
        }
    }

    return n - start_index;
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    int a[n];
    inputArray(a, n);

    printf("%d", books(a, n, t));
}