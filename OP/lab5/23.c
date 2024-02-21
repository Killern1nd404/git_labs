#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int lessons = 0;
    int windows = 0;
    int is_lessons_start = 0;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a == 1) {
            lessons++;

            if (windows == 1 && is_lessons_start == 1) {
                lessons++;
            }

            if (is_lessons_start == 0) {
                is_lessons_start = 1;
            }

            windows = 0;
        } else {
            windows++;
        }
    }

    printf("%d", lessons);

    return 0;
}