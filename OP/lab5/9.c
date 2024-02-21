#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int free_officers = 0;
    int unsolved_crimes = 0;

    for (int i = 0; i < n; i++) {
        int event;
        scanf("%d", &event);

        if (event == -1) {
            if (free_officers == 0) {
                unsolved_crimes++;
            } else {
                free_officers--;
            }
        } else {
            free_officers += event;
        }
    }

    printf("%d", unsolved_crimes);

    return 0;
}