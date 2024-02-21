#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int solved_tasks_number = 0;

    for (int i = 0; i < n; i++) {
        int opinion_p, opinion_v, opinion_t;
        scanf("%d %d %d", &opinion_p, &opinion_v, &opinion_t);

        if ((opinion_p + opinion_t + opinion_v) >= 2) {
            solved_tasks_number++;
        }
    }

    printf("%d", solved_tasks_number);

    return 0;
}