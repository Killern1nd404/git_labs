#include <stdio.h>

void selectionSort(int *a, int n) {
    if (n == 1) {
        return;
    } else {
        int i = n - 1;
        int i_selected = i;

        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[i_selected]) {
                i_selected = j;
            }
        }

        int temp = a[i];
        a[i] = a[i_selected];
        a[i_selected] = temp;

        selectionSort(a, n - 1);
    }
}

int main() {
    int a[5] = {1, 4, 0, 2, -2};
    int n = 5;

    selectionSort(a, n);
}