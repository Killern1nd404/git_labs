#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n + 1];
    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        int c, t;
        scanf("%d %d", &c, &t);

        a[i] = c*t + a[i - 1];
    }

    int result = 1;

    for (int j = 0; j < m; j++) {
        int v;
        scanf("%d", &v);

        while (v > a[result]) {
            result++;
        }

        printf("%d\n", result);
    }
}