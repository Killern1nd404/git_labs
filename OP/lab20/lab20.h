#ifndef UNTITLED_LAB20_H
#define UNTITLED_LAB20_H

#include <stdio.h>
#include "C:\Users\andre\CLionProjects\Project\libs\data_structures\matrix\matrix.h"

/*typedef struct domain {
    int visits_number;
    char *name;
} domain;*/

/*typedef struct root_node {
    int max_value;
    struct root_node *left_prefix;
    struct root_node *right_prefix;
} root_node;*/

int** task_1(int n, int query[][4], size_t size);

void test_task_1();

int count_living_neighboring_cells(int m, int n, int board[m][n], int i, int j);

void task_2(int m, int n, int board[m][n]);

void test_task_2();

void get_median(int filter, int matrix[filter][filter], int i, int j);

void task_3(int filter, int matrix[filter][filter]);

void test_task_3();

//void test_task_4();

void fill_matrix(matrix m, matrix *new_matrix, int rows, int cols);

int task_5(matrix m, int rows, int cols);

void test_task_5();

void task_6(char *string, int len, char *result, int *result_len);

void test_task_6();

void task_8(char *s, int *indices, char *result, int size);

void test_task_8();

void fill_file(int *numbers, int size, char *file_name);

void task_9(int *numbers, int size, int n, char *file_name_1, char *file_name_2);

void test_task_9(int argc, char **argv);

/*root_node *insert(root_node *node, int number, bool is_left);

root_node *create_root_node(int number);

void create_root_nodes(root_node *node, int *nums, int start, int end, bool is_left);

void task_7(int *nums, int size);

void test_task_7();*/

void test_lab20();

#endif //UNTITLED_LAB20_H