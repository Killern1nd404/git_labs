#include <stdio.h>
#include <math.h>

// Определяет, через какой вход зайдёт Аллен
int getEnterNumber(int const *array, const size_t size) {
    int min = array[0];
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
            index = i;
        }
    }

    return index + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        array[i] = ceil((double)(a - i) / n);
    }

    printf( "%d", getEnterNumber( array, n ) );
}