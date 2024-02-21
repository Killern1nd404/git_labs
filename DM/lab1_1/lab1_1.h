#ifndef UNTITLED_LAB1_1_H
#define UNTITLED_LAB1_1_H

#include <stdio.h>
#include <stdbool.h>

void set_print(int *set, size_t size);

void set_input(int *set, size_t size);

bool is_element_in_unordered_set(int *set, size_t set_size, int value);

bool unordered_set_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size);

bool unordered_set_strict_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size);

void unordered_set_unification(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void unordered_set_intersection(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void unordered_set_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void unordered_set_symmetrical_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void unordered_set_complement(int *set_a, size_t a_size, int *set_universe, size_t universe_size, int *set_c, size_t *c_size);

void check_unordered_set_operations();

bool is_element_in_ordered_set(int *set, size_t set_size, int value);

bool is_set_ordered(int *set, size_t size);

bool ordered_set_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size);

bool ordered_set_strict_enabling(int *set_a, size_t a_size, int *set_b, size_t b_size);

void ordered_set_unification(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void ordered_set_intersection(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void ordered_set_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void ordered_set_symmetrical_difference(int *set_a, size_t a_size, int *set_b, size_t b_size, int *set_c, size_t *c_size);

void ordered_set_complement(int *set_a, size_t a_size, int *set_universe, size_t universe_size, int *set_c, size_t *c_size);

void check_ordered_set_operations();

bool boolean_set_enabling(bool *set_a, bool *set_b, size_t size);

bool boolean_set_strict_enabling(bool *set_a, bool *set_b, size_t size);

void boolean_set_unification(bool *set_a, bool *set_b, bool *set_c, size_t size);

void boolean_set_intersection(bool *set_a, bool *set_b, bool *set_c, size_t size);

void boolean_set_difference(bool *set_a, bool *set_b, bool *set_c, size_t size);

void boolean_set_symmetrical_difference(bool *set_a, bool *set_b, bool *set_c, size_t size);

void boolean_set_complement(bool *set_a, bool *set_c, size_t size);

void boolean_set_print(bool *set, size_t size);

void check_boolean_set_operations();

void calculate_task_1();

void calculate_task_2();

#endif //UNTITLED_LAB1_1_H