#include <stdio.h>
#include <string.h>
#include <search.h>
#include "C:\Users\andre\CLionProjects\Project\libs\algorithms\array\array.h"
#include "C:\Users\andre\CLionProjects\Project\libs\algorithms\array\unordered_array_set.h"
#include "C:\Users\andre\CLionProjects\Project\libs\algorithms\array\ordered_array_set.h"
#include "lab13.h"

void lab13_1() {
    int n;
    scanf("%d", &n);

    unordered_array_set suitable_routes = unordered_array_set_create(0);

    for (int i = 0; i < n; i++) {
        int r;
        scanf("%d", &r);

        int routes[r];
        inputArray_(routes, r);

        if (!suitable_routes.capacity) {
            suitable_routes = unordered_array_set_create_from_array(routes, r);
        } else
            suitable_routes = unordered_array_set_intersection(suitable_routes, unordered_array_set_create_from_array(routes, r));
    }

    unordered_array_set_print(suitable_routes);
}

void lab13_2() {
    int n;
    scanf("%d", &n);

    unordered_array_set series = unordered_array_set_create(n);

    for (int i = 1; i <= n; i++) {
        series.data[i - 1] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);

        series.data[a - 1] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (series.data[i]) {
            printf("%d", i + 1);
            break;
        }
    }
}

void lab13_3() {
    int n;
    scanf("%d", &n);

    for (size_t i = 0; i < n; i++) {
        char string[1000];
        scanf("%s", string);
        size_t string_len = strlen(string);

        unordered_array_set symbols = unordered_array_set_create(26);

        for (size_t i = 0; i < 26; i++) {
            symbols.data[i] = 0;
        }

        bool is_palindrome = true;

        for (size_t i = 0; i < string_len; i++) {
            (symbols.data[string[i] - 97])++;

            if (string[0] != string[i] && is_palindrome) {
                is_palindrome = false;
            }
        }

        if (is_palindrome) {
            printf("-1\n");
        } else {
            for (size_t i = 0; i < 26; i++) {
                for (size_t j = 0; j < symbols.data[i]; j++) {
                    printf("%c", i + 97);
                }
            }
            printf("\n");
        }
    }
}

void lab13_4() {
    unordered_array_set symbols = unordered_array_set_create(26);
    symbols.size = 26;

    for (size_t i = 0; i < 26; i++) {
        symbols.data[i] = 0;
    }

    int t;
    scanf("%d", &t);

    for (size_t i = 0; i < t; i++) {
        char name[20];
        scanf("%s", name);
        (symbols.data[name[0] - 97])++;
    }

    int x = 0;

    for (size_t i = 0; i < 26; i++) {
        int symbol_number = symbols.data[i];

        if (symbol_number > 2) {
            int first_class = symbol_number / 2;
            int second_class = symbol_number - first_class;

            x += ((first_class * (first_class - 1)) / 2) + ((second_class * (second_class - 1)) / 2);
        }
    }

    printf("%d", x);
}

void lab13_5() {
    unordered_array_set colors = unordered_array_set_create(26);
    colors.size = 26;

    for (size_t i = 0; i < 26; i++) {
        colors.data[i] = 0;
    }

    int n, k;
    scanf("%d %d", &n, &k);

    char name[n];
    scanf("%s", name);

    for (size_t i = 0; i < n; i++) {
        (colors.data[name[i] - 97])++;
    }

    bool is_can_not_offend_friend = true;

    for (int i = 0; i < 26 && is_can_not_offend_friend; i++) {
        if (colors.data[i] > k) {
            is_can_not_offend_friend = false;
        }
    }

    if (is_can_not_offend_friend) {
        printf("YES");
    } else {
        printf("NO");
    }
}

void lab13_6() {
    unordered_array_set colors = unordered_array_set_create(26);

    for (size_t i = 0; i < 26; i++) {
        colors.data[i] = 0;
    }

    int n;
    scanf("%d", &n);

    char name[n];
    scanf("%s", name);

    for (size_t i = 0; i < n; i++) {
        (colors.data[name[i] - 97])++;
    }

    bool is_have_not_solo_color = false;

    for (size_t i = 0; i < 26 && !is_have_not_solo_color; i++) {
        if (colors.data[i] >= 2) {
            is_have_not_solo_color = true;
        }
    }

    if (is_have_not_solo_color || n == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
}

void lab13_7() {
    bool presence_of_steps[26];

    for (size_t i = 0; i < 26; i++) {
        presence_of_steps[i] = false;
    }

    int n, k;
    scanf("%d %d", &n, &k);

    char steps_in_warehouse[n];
    scanf("%s", steps_in_warehouse);

    for (size_t i = 0; i < n; i++) {
        presence_of_steps[steps_in_warehouse[i] - 97] = true;
    }

    int previous_step_index = -2;
    int steps_assembled = 0;
    int weight = 0;

    for (int i = 0; i < 26 && steps_assembled < k; i++) {
        if (presence_of_steps[i] && i - previous_step_index >= 2) {
            steps_assembled++;
            weight += i + 1;
            previous_step_index = i;
        }
    }

    if (steps_assembled < k) {
        printf("-1");
    } else {
        printf("%d", weight);
    }
}

void lab13_8() { // сделать полное решение на форсах
    unordered_array_set bars = unordered_array_set_create(1000);

    for (size_t i = 0; i < 26; i++) {
        bars.data[i] = 0;
    }

    int n;
    scanf("%d", &n);

    for (size_t i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);

        bars.data[size - 1]++;
    }

    int towers_number = 0;
    int max_size = 0;

    for (size_t i = 0; i < 1000; i++) {
        if (bars.data[i]) {
            towers_number++;

            if (bars.data[i] > max_size) {
                max_size = bars.data[i];
            }
        }
    }

    printf("%d %d", max_size, towers_number);
}

int go_next(unordered_array_set set, unordered_array_set holes, int x) {
    if (holes.data[x]) {
        return x;
    }

    holes.data[x] = 1;
    int next = go_next(set, holes, set.data[x]);

    return next;
}

void lab13_9() {
    int n;
    scanf("%d", &n);

    unordered_array_set set = unordered_array_set_create(n + 1);
    unordered_array_set holes = unordered_array_set_create(n + 1);

    for (size_t i = 1; i <= n; i++) {
        holes.data[i] = 0;
        scanf("%d", &set.data[i]);
    }

    for (int i = 1; i <= n; i++) {
        int x = go_next(set, holes, i);

        printf("%d ", x);

        for (int j = 1; j <= n; j++) {
            holes.data[j] = 0;
        }
    }
}

void lab13_10() {
    int n;
    scanf("%d", &n);

    unordered_array_set symbols = unordered_array_set_create(26);

    for (size_t i = 0; i < 26; i++) {
        symbols.data[i] = 0;
    }

    char string[n];
    scanf("%s", string);

    for (size_t i = 0; i < n; i++) {
        size_t index = string[i] - 97;
        (symbols.data[index])++;
    }

    int result = 0;

    for (size_t i = 0; i < 26; i++) {
        if (symbols.data[i] > 1) {
            result += symbols.data[i] - 1;
        }
    }

    if (n > 26) {
        printf("-1");
    } else {
        printf("%d", result);
    }
}

int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

void lab13_11() {
    int n;
    scanf("%d", &n);

    char code_1[n];
    char code_2[n];
    scanf("%s", code_1);
    scanf("%s", code_2);

    unordered_array_set set_1 = unordered_array_set_create(n);
    unordered_array_set set_2 = unordered_array_set_create(n);

    for (size_t i = 0; i < n; i++) {
        set_1.data[i] = code_1[i];
        set_2.data[i] = code_2[i];
    }

    qsort(set_1.data, n, sizeof(int), compare);
    qsort(set_2.data, n, sizeof(int), compare);

    int result_1 = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (set_1.data[i] <= set_2.data[result_1])
            result_1--;
    }

    int result_2 = 0;
    for (size_t i = 0; i < n; i++) {
        if (set_2.data[i] > set_1.data[result_2])
            result_2++;
    }

    printf("%d\n%d", result_1 + 1, result_2);
}

void lab13_12() {
    int t;
    scanf("%d", &t);

    unordered_array_set set = unordered_array_set_create(21);

    for (size_t i = 0; i < 21; i++) {
        set.data[i] = 0;
    }

    for (size_t i = 0; i < t; i++) {
        long long int x;
        scanf("%lld", &x);

        (set.data[x + 10])++;
    }

    long long int result = 0;

    for (size_t i = 0; i < 10; i++) {
        result += set.data[i] * set.data[20 - i];
    }

    result += (set.data[10] * (set.data[10] - 1)) / 2;

    printf("%lld", result);
}