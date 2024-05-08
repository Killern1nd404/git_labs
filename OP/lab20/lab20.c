#include "lab20.h"
#include <stdio.h>
#include "C:\Users\andre\CLionProjects\Project\libs\data_structures\matrix\matrix.h"
#include <assert.h>

int** task_1(int n, int query[][4], size_t size) {
    matrix result = getMemMatrix(n, n);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            result.values[i][j] = 0;
        }
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t row = query[i][0]; row <= query[i][2] && row < n; row++) {
            for (size_t col = query[i][1]; col <= query[i][3] && col < n; col++) {
                result.values[row][col]++;
            }
        }
    }

    return result.values;
}

void test_task_1() {
    int query[2][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    int n = 3;
    int **result = task_1(n, query, 2);
    int true_data[3][3] = {{1, 1, 0}, {1, 2, 1}, {0, 1, 1}};

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            assert(true_data[i][j] == result[i][j]);
        }
    }

    int query_2[1][4] = {{0, 0, 5, 5}};
    int n_2 = 3;
    int **result_2 = task_1(n_2, query_2, 1);
    int true_data_2[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

    for (size_t i = 0; i < n_2; i++) {
        for (size_t j = 0; j < n_2; j++) {
            assert(true_data_2[i][j] == result_2[i][j]);
        }
    }
}

int count_living_neighboring_cells(int m, int n, int board[n][m], int i, int j) {
    int result = 0;

    if (i != 0) {
        result += board[i - 1][j];
        if (j != 0) {
            result += board[i - 1][j - 1];
        }
        if (j != m - 1) {
            result += board[i - 1][j + 1];
        }
    }

    if (i != n - 1) {
        result += board[i + 1][j];
        if (j != 0) {
            result += board[i + 1][j - 1];
        }
        if (j != m - 1) {
            result += board[i + 1][j + 1];
        }
    }

    if (j != 0) {
        result += board[i][j - 1];
    }

    if (j != m - 1) {
        result += board[i][j + 1];
    }

    return result;
}

void task_2(int m, int n, int board[n][m]) {
    int result[m][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int living_cells = count_living_neighboring_cells(m, n, board, i, j);

            if (board[i][j]) {
                if (living_cells < 2) {
                    result[i][j] = 0;
                } else if (living_cells == 2 || living_cells == 3) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = 0;
                }
            } else {
                if (living_cells == 3) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = result[i][j];
        }
    }
}

void test_task_2() {
    int board[4][3] = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    int m = 3;
    int n = 4;
    task_2(m, n, board);
    int true_data[4][3] = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            assert(true_data[i][j] == board[i][j]);
        }
    }
}

void test_lab20() {
    //test_task_1();
    test_task_2();
}