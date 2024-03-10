#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix *m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix *m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix *m, int i1, int i2);

void swapColumns(matrix *m, int j1, int j2);

int getSum(int *a, int n);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, int));

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, int));

bool isSquareMatrix(matrix *m);

bool areTwoMatricesEqual(matrix *m1, matrix *m2);

bool isEMatrix(matrix *m);

bool isSymmetricMatrix(matrix *m);

void transposeSquareMatrix(matrix *m);

void transposeMatrix(matrix *m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

void test_swap_rows();

void test_swap_columns();

void test_is_square_matrix_true();

void test_is_square_matrix_false();

void test_is_e_matrix_true();

void test_is_e_matrix_false();

void test_is_symmetric_matrix_true();

void test_is_symmetric_matrix_false();

void test_transpose_square_matrix();

void test_transpose_matrix();

void test_get_min_value_pos();

void test_get_max_value_pos();

void test_matrix();

void swap_rows_with_min_and_max_elements(matrix *m);

void test_swap_rows_with_min_and_max_elements_1();

void test_swap_rows_with_min_and_max_elements_2();

void test_swap_rows_with_min_and_max_elements();

int getMax(int *a, int n);

void sortRowsByMinElement(matrix *m);

void test_sortRowsByMinElement_1();

void test_sortRowsByMinElement_2();

void test_sortRowsByMinElement();

#endif //UNTITLED_MATRIX_H