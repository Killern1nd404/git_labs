#include <stdio.h>
#include "lab1_1.h"
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>

void set_print(int *set, size_t size) {
    if (size == 0) {
        printf("{}\n");
    } else {
        printf("{");

        for (size_t i = 0; i < size; i++) {
            printf("%d, ", set[i]);
        }

        printf("\b\b}\n");
    }
}

void set_input(int *set, size_t size) {
    for (size_t i = 0; i < size; i++)
        scanf("%d", &set[i]);
}

bool is_element_in_unordered_set(int *set, size_t set_size, int value) {
    for (size_t i = 0; i < set_size; i++) {
        if (set[i] == value) {
            return true;
        }
    }

    return false;
}

bool unordered_set_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size) {
    if (a_size > b_size) {
        return false;
    } else {
        for (size_t i = 0; i < a_size; i++) {
            if (!is_element_in_unordered_set(set_b, b_size, set_a[i])) {
                return false;
            }
        }

        return true;
    }
}

bool unordered_set_strict_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size) {
    if (a_size == b_size) {
        return false;
    } else {
        return unordered_set_enabling(set_a, a_size, set_b, b_size);
    }
}

void unordered_set_unification(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    for (size_t i = 0; i < a_size; i++) {
        set_c[i] = set_a[i];
    }

    int elements_from_b = 0;

    for (int j = 0; j < b_size; j++) {
        if (!is_element_in_unordered_set(set_c, a_size, set_b[j])) {
            set_c[a_size + elements_from_b] = set_b[j];
            elements_from_b++;
        }
    }

    *c_size = a_size + elements_from_b;
}

void unordered_set_intersection(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    *c_size = 0;

    for (int i = 0; i < a_size; i++) {
        if (is_element_in_unordered_set(set_b, b_size, set_a[i])) {
            set_c[*c_size] = set_a[i];
            (*c_size)++;
        }
    }
}

void unordered_set_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    *c_size = 0;

    for (int i = 0; i < a_size; i++) {
        if (!is_element_in_unordered_set(set_b, b_size, set_a[i])) {
            set_c[*c_size] = set_a[i];
            (*c_size)++;
        }
    }
}

void unordered_set_symmetrical_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    *c_size = 0;

    for (int i = 0; i < a_size; i++) {
        if (!is_element_in_unordered_set(set_b, b_size, set_a[i])) {
            set_c[*c_size] = set_a[i];
            (*c_size)++;
        }
    }

    for (int i = 0; i < b_size; i++) {
        if (!is_element_in_unordered_set(set_a, a_size, set_b[i])) {
            set_c[*c_size] = set_b[i];
            (*c_size)++;
        }
    }
}

void unordered_set_complement(int *set_a, size_t a_size, int *set_universe, size_t universe_size, int *set_c, size_t *c_size) {
    unordered_set_difference(set_universe, universe_size, set_a, a_size, set_c, c_size);
}

void check_unordered_set_operations() {
    size_t universe_size = 10;
    int set_universe[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    size_t a_size;
    size_t b_size;

    printf("Input size of set A:\n");
    scanf("%lld", &a_size);
    int set_a[a_size];
    printf("Input elements of set A:\n");
    set_input(set_a, a_size);

    printf("Input size of set B:\n");
    scanf("%lld", &b_size);
    int set_b[b_size];
    printf("Input elements of set B:\n");
    set_input(set_b, b_size);

    printf("Unification: ");
    size_t c1_size = a_size + b_size;
    int set_c1[c1_size];
    unordered_set_unification(set_a, a_size, set_b, b_size, set_c1, &c1_size);
    set_print(set_c1, c1_size);

    printf("Intersection: ");
    size_t c2_size = a_size + b_size;
    int set_c2[c2_size];
    unordered_set_intersection(set_a, a_size, set_b, b_size, set_c2, &c2_size);
    set_print(set_c2, c2_size);

    printf("Difference: ");
    size_t c3_size = a_size + b_size;
    int set_c3[c3_size];
    unordered_set_difference(set_a, a_size, set_b, b_size, set_c3, &c3_size);
    set_print(set_c3, c3_size);

    printf("Symmetrical difference: ");
    size_t c4_size = a_size + b_size;
    int set_c4[c4_size];
    unordered_set_symmetrical_difference(set_a, a_size, set_b, b_size, set_c4, &c4_size);
    set_print(set_c4, c4_size);

    if (unordered_set_enabling(set_a, a_size, set_b, b_size)) {
        printf("Set A is included in set B\n");
    } else {
        printf("Set A is not included in set B\n");
    }

    if (unordered_set_strict_enabling(set_a, a_size, set_b, b_size)) {
        printf("Set A is strictly included in set B\n");
    } else {
        printf("Set A is not strictly included in set B\n");
    }

    printf("Set A complement: ");
    size_t c5_size = universe_size;
    int set_c5[c5_size];
    unordered_set_complement(set_a, a_size, set_universe, universe_size, set_c5, &c5_size);
    set_print(set_c5, c5_size);

    printf("Set B complement: ");
    size_t c6_size = universe_size;
    int set_c6[c6_size];
    unordered_set_complement(set_b, b_size, set_universe, universe_size, set_c6, &c6_size);
    set_print(set_c6, c6_size);
}

bool is_element_in_ordered_set(int *set, size_t set_size, int value) {
    for (size_t i = 0; i < set_size; i++) {
        if (set[i] == value) {
            return true;
        } else if ( set[i] > value) {
            return false;
        }
    }

    return false;
}

bool is_set_ordered(int *set, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        if (set[i] >= set[i + 1]) {
            return false;
        }
    }

    return true;
}

bool ordered_set_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size) {
    if (a_size > b_size) {
        return false;
    } else {
        for (size_t i = 0; i < a_size; i++) {
            if (!is_element_in_ordered_set(set_b, b_size, set_a[i])) {
                return false;
            }
        }

        return true;
    }
}

bool ordered_set_strict_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size) {
    if (a_size == b_size) {
        return false;
    } else {
        return unordered_set_enabling(set_a, a_size, set_b, b_size);
    }
}

void ordered_set_unification(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    size_t a_index = 0;
    size_t b_index = 0;
    *c_size = 0;

    while (a_index < a_size && b_index < b_size) {
        if (set_a[a_index] < set_b[b_index]) {
            set_c[(*c_size)++] = set_a[a_index++];
        } else if (set_a[a_index] == set_b[b_index]) {
            set_c[(*c_size)++] = set_a[a_index++];
            b_index++;
        } else {
            set_c[(*c_size)++] = set_b[b_index++];
        }
    }

    while (a_index < a_size) {
        set_c[(*c_size)++] = set_a[a_index++];
    }

    while (b_index < b_size) {
        set_c[(*c_size)++] = set_b[b_index++];
    }
}

void ordered_set_intersection(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    *c_size = 0;

    for (int i = 0; i < a_size; i++) {
        if (is_element_in_ordered_set(set_b, b_size, set_a[i])) {
            set_c[*c_size] = set_a[i];
            (*c_size)++;
        }
    }
}

void ordered_set_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    *c_size = 0;

    for (int i = 0; i < a_size; i++) {
        if (!is_element_in_ordered_set(set_b, b_size, set_a[i])) {
            set_c[*c_size] = set_a[i];
            (*c_size)++;
        }
    }
}

void ordered_set_symmetrical_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size) {
    size_t size1 = a_size;
    int set1[size1];
    size_t size2 = b_size;
    int set2[size2];

    ordered_set_difference(set_a, a_size, set_b, b_size, set1, &size1);
    ordered_set_difference(set_b, b_size, set_a, a_size, set2, &size2);

    ordered_set_unification(set1, size1, set2, size2, set_c, c_size);
}

void ordered_set_complement(int *set_a, size_t a_size, int *set_universe, size_t universe_size, int *set_c, size_t *c_size) {
    unordered_set_difference(set_universe, universe_size, set_a, a_size, set_c, c_size);
}

void check_ordered_set_operations() {
    size_t universe_size = 10;
    int set_universe[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    size_t a_size;
    size_t b_size;

    printf("Input size of set A:\n");
    scanf("%lld", &a_size);
    int set_a[a_size];
    printf("Input ordered elements of set A:\n");
    set_input(set_a, a_size);
    assert(is_set_ordered(set_a, a_size));

    printf("Input size of set B:\n");
    scanf("%lld", &b_size);
    int set_b[b_size];
    printf("Input ordered elements of set B:\n");
    set_input(set_b, b_size);
    assert(is_set_ordered(set_b, b_size));

    printf("Unification: ");
    size_t c1_size = a_size + b_size;
    int set_c1[c1_size];
    ordered_set_unification(set_a, a_size, set_b, b_size, set_c1, &c1_size);
    set_print(set_c1, c1_size);

    printf("Intersection: ");
    size_t c2_size = a_size + b_size;
    int set_c2[c2_size];
    ordered_set_intersection(set_a, a_size, set_b, b_size, set_c2, &c2_size);
    set_print(set_c2, c2_size);

    printf("Difference: ");
    size_t c3_size = a_size + b_size;
    int set_c3[c3_size];
    ordered_set_difference(set_a, a_size, set_b, b_size, set_c3, &c3_size);
    set_print(set_c3, c3_size);

    printf("Symmetrical difference: ");
    size_t c4_size = a_size + b_size;
    int set_c4[c4_size];
    ordered_set_symmetrical_difference(set_a, a_size, set_b, b_size, set_c4, &c4_size);
    set_print(set_c4, c4_size);

    if (ordered_set_enabling(set_a, a_size, set_b, b_size)) {
        printf("Set A is included in set B\n");
    } else {
        printf("Set A is not included in set B\n");
    }

    if (ordered_set_strict_enabling(set_a, a_size, set_b, b_size)) {
        printf("Set A is strictly included in set B\n");
    } else {
        printf("Set A is not strictly included in set B\n");
    }

    printf("Set A complement: ");
    size_t c5_size = universe_size;
    int set_c5[c5_size];
    ordered_set_complement(set_a, a_size, set_universe, universe_size, set_c5, &c5_size);
    set_print(set_c5, c5_size);

    printf("Set B complement: ");
    size_t c6_size = universe_size;
    int set_c6[c6_size];
    ordered_set_complement(set_b, b_size, set_universe, universe_size, set_c6, &c6_size);
    set_print(set_c6, c6_size);
}

bool boolean_set_enabling(bool *a_set, bool *b_set, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (a_set[i] && !b_set[i]) {
            return false;
        }
    }

    return true;
}

bool boolean_set_strict_enabling(bool *set_a, bool *set_b, size_t size) {
    bool is_b_more_than_a = false;

    for (size_t i = 0; i < size; i++) {
        if (set_a[i] && !set_b[i]) {
            return false;
        } else if (!set_a[i] && set_b[i]) {
            is_b_more_than_a = true;
        }
    }

    if (is_b_more_than_a) {
        return true;
    } else {
        return false;
    }
}

void boolean_set_unification(bool *set_a, bool *set_b, bool *set_c, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (set_a[i] || set_b[i]) {
            set_c[i] = true;
        } else {
            set_c[i] = false;
        }
    }
}

void boolean_set_intersection(bool *set_a, bool *set_b, bool *set_c, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (set_a[i] && set_b[i]) {
            set_c[i] = true;
        } else {
            set_c[i] = false;
        }
    }
}

void boolean_set_difference(bool *set_a, bool *set_b, bool *set_c, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (set_a[i] && !set_b[i]) {
            set_c[i] = true;
        } else {
            set_c[i] = false;
        }
    }
}

void boolean_set_symmetrical_difference(bool *set_a, bool *set_b, bool *set_c, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if ((set_a[i] && !set_b[i]) || (!set_a[i] && set_b[i])) {
            set_c[i] = true;
        } else {
            set_c[i] = false;
        }
    }
}

void boolean_set_complement(bool *set_a, bool *set_c, size_t size) {
    for (size_t i = 0; i < size; i++) {
        set_c[i] = !set_a[i];
    }
}

void boolean_set_print(bool *set, size_t size) {
    if (size == 0) {
        printf("{}\n");
    } else {
        printf("{");

        for (size_t i = 0; i < size; i++) {
            if (set[i]) {
                printf("true, ");
            } else {
                printf("false, ");
            }
        }

        printf("\b\b}\n");
    }
}

void check_boolean_set_operations() {
    size_t size = 10;

    bool set1_a[10] = {false, false, true, false, true, false, true, true, false, true};
    bool set1_b[10] = {false, false, true, false, true, false, true, true, false, true};
    bool set1_unification[10];
    bool set1_intersection[10];
    bool set1_difference[10];
    bool set1_symmetrical_difference[10];
    bool set1_complement_a[10];
    boolean_set_unification(set1_a, set1_b, set1_unification, size);
    boolean_set_intersection(set1_a, set1_b, set1_intersection, size);
    boolean_set_difference(set1_a, set1_b, set1_difference, size);
    boolean_set_symmetrical_difference(set1_a, set1_b, set1_symmetrical_difference, size);
    boolean_set_complement(set1_a, set1_complement_a, size);
    printf("Set A: ");
    boolean_set_print(set1_a, size);
    printf("Set B: ");
    boolean_set_print(set1_b, size);
    printf("Unification: ");
    boolean_set_print(set1_unification, size);
    printf("Intersection: ");
    boolean_set_print(set1_intersection, size);
    printf("Difference: ");
    boolean_set_print(set1_difference, size);
    printf("Symmetrical difference: ");
    boolean_set_print(set1_symmetrical_difference, size);
    printf("Complement A: ");
    boolean_set_print(set1_complement_a, size);
    if (boolean_set_enabling(set1_a, set1_b, size)) {
        printf("Set A is included in set B\n");
    } else {
        printf("Set A is not included in set B\n");
    }
    if (boolean_set_strict_enabling(set1_a, set1_b, size)) {
        printf("Set A is strictly included in set B\n");
    } else {
        printf("Set A is not strictly included in set B\n");
    }
    printf("\n");

    bool set2_a[10] = {false, false, true, false, true, false, true, true, false, true};
    bool set2_b[10] = {true, false, true, false, true, true, true, true, false, true};
    bool set2_unification[10];
    bool set2_intersection[10];
    bool set2_difference[10];
    bool set2_symmetrical_difference[10];
    bool set2_complement_a[10];
    boolean_set_unification(set2_a, set2_b, set2_unification, size);
    boolean_set_intersection(set2_a, set2_b, set2_intersection, size);
    boolean_set_difference(set2_a, set2_b, set2_difference, size);
    boolean_set_symmetrical_difference(set2_a, set2_b, set2_symmetrical_difference, size);
    boolean_set_complement(set2_a, set2_complement_a, size);
    printf("Set A: ");
    boolean_set_print(set2_a, size);
    printf("Set B: ");
    boolean_set_print(set2_b, size);
    printf("Unification: ");
    boolean_set_print(set2_unification, size);
    printf("Intersection: ");
    boolean_set_print(set2_intersection, size);
    printf("Difference: ");
    boolean_set_print(set2_difference, size);
    printf("Symmetrical difference: ");
    boolean_set_print(set2_symmetrical_difference, size);
    printf("Complement A: ");
    boolean_set_print(set2_complement_a, size);
    if (boolean_set_enabling(set2_a, set2_b, size)) {
        printf("Set A is included in set B\n");
    } else {
        printf("Set A is not included in set B\n");
    }
    if (boolean_set_strict_enabling(set2_a, set2_b, size)) {
        printf("Set A is strictly included in set B\n");
    } else {
        printf("Set A is not strictly included in set B\n");
    }
    printf("\n");

    bool set3_a[10] = {true, false, false, false, false, true, true, true, true, true};
    bool set3_b[10] = {false, true, true, false, true, false, true, true, false, true};
    bool set3_unification[10];
    bool set3_intersection[10];
    bool set3_difference[10];
    bool set3_symmetrical_difference[10];
    bool set3_complement_a[10];
    boolean_set_unification(set3_a, set3_b, set3_unification, size);
    boolean_set_intersection(set3_a, set3_b, set3_intersection, size);
    boolean_set_difference(set3_a, set3_b, set3_difference, size);
    boolean_set_symmetrical_difference(set3_a, set3_b, set3_symmetrical_difference, size);
    boolean_set_complement(set3_a, set3_complement_a, size);
    printf("Set A: ");
    boolean_set_print(set3_a, size);
    printf("Set B: ");
    boolean_set_print(set3_b, size);
    printf("Unification: ");
    boolean_set_print(set3_unification, size);
    printf("Intersection: ");
    boolean_set_print(set3_intersection, size);
    printf("Difference: ");
    boolean_set_print(set3_difference, size);
    printf("Symmetrical difference: ");
    boolean_set_print(set3_symmetrical_difference, size);
    printf("Complement A: ");
    boolean_set_print(set3_complement_a, size);
    if (boolean_set_enabling(set3_a, set3_b, size)) {
        printf("Set A is included in set B\n");
    } else {
        printf("Set A is not included in set B\n");
    }
    if (boolean_set_strict_enabling(set3_a, set3_b, size)) {
        printf("Set A is strictly included in set B\n");
    } else {
        printf("Set A is not strictly included in set B\n");
    }
}

void calculate_task_1() {
    int a[5] = {1, 2, 3, 4, 8};
    int b[3] = {2, 3, 8};
    int c[5] = {3, 4, 5, 6, 7};
    int u[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int _1[10];
    size_t _1_size = 10;
    unordered_set_intersection(a, 5, b, 3, _1, &_1_size);

    int _2[10];
    size_t _2_size = 10;
    unordered_set_difference(_1, _1_size, a, 5, _2, &_2_size);

    int _3[10];
    size_t _3_size = 10;
    unordered_set_unification(c, 5, b, 3, _3, &_3_size);

    int _4[10];
    size_t _4_size = 10;
    unordered_set_symmetrical_difference(_2, _2_size, _3, _3_size, _4, &_4_size);

    int _5[10];
    size_t _5_size = 10;
    unordered_set_difference(_4, _4_size, b, 3, _5, &_5_size);

    int _6[10];
    size_t _6_size = 10;
    unordered_set_symmetrical_difference(_5, _5_size, a, 5, _6, &_6_size);

    int _7[10];
    size_t _7_size = 10;
    unordered_set_complement(_6, _6_size, u, 10, _7, &_7_size);

    set_print(_7, _7_size);
}

void calculate_task_2() {
    int a[6] = {1, 2, 3, 4, 6, 7};
    int b[4] = {1, 3, 6, 7};
    int c[5] = {3, 4, 5, 6, 8};
    int u[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int _1[10];
    size_t _1_size = 10;
    unordered_set_intersection(b, 4, c, 5, _1, &_1_size);

    int _2[10];
    size_t _2_size = 10;
    unordered_set_difference(b, 4, _1, _1_size, _2, &_2_size);

    int _3[10];
    size_t _3_size = 10;
    unordered_set_difference(c, 5, a, 6, _3, &_3_size);

    int _4[10];
    size_t _4_size = 10;
    unordered_set_unification(_2, _2_size, _3, _3_size, _4, &_4_size);

    set_print(_4, _4_size);
}