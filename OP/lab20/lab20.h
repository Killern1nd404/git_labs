#ifndef UNTITLED_LAB20_H
#define UNTITLED_LAB20_H

#include <stdio.h>
#include "C:\Users\andre\CLionProjects\Project\libs\data_structures\matrix\matrix.h"

int** task_1(int n, int query[][4], size_t size);

void test_task_1();

int count_living_neighboring_cells(int m, int n, int board[m][n], int i, int j);

void task_2(int m, int n, int board[m][n]);

void test_task_2();

void test_lab20();

#endif //UNTITLED_LAB20_H