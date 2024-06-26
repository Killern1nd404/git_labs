#include "lab20.h"
#include <stdio.h>
#include "C:\Users\andre\CLionProjects\Project\libs\data_structures\matrix\matrix.h"
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "C:\Users\andre\CLionProjects\Project\libs\data_structures\string\string_.h"
#include "C:\Users\andre\CLionProjects\Project\libs\data_structures\files\files.h"

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

void get_median(int filter, int matrix[filter][filter], int i, int j) {
    int neighboring_elements[8];

    neighboring_elements[0] = matrix[i - 1][j];
    neighboring_elements[1] = matrix[i - 1][j + 1];
    neighboring_elements[2] = matrix[i][j + 1];
    neighboring_elements[3] = matrix[i + 1][j + 1];
    neighboring_elements[4] = matrix[i + 1][j];
    neighboring_elements[5] = matrix[i + 1][j - 1];
    neighboring_elements[6] = matrix[i][j - 1];
    neighboring_elements[7] = matrix[i - 1][j - 1];

    for (int i_ = 0; i_ < 8; i_++) {
        for (int j_ = 0; j_ < i_; j_++) {
            if (neighboring_elements[i_] < neighboring_elements[j_]) {
                int temp = neighboring_elements[i_];
                neighboring_elements[i_] = neighboring_elements[j_];
                neighboring_elements[j_] = temp;
            }
        }
    }

    matrix[i][j] = neighboring_elements[4];
}

void task_3(int filter, int matrix[filter][filter]) {
    if (filter % 2 == 0) {
        perror("The window size should be be an odd number.");
        return;
    }

    for (int i = 1; i < filter - 1; i++) {
        for (int j = 1; j < filter - 1; j++) {
            get_median(filter, matrix, i, j);
        }
    }
}

void test_task_3() {
    int matrix_1[3][3] = {{10, 20, 30}, {25, 35, 45}, {15, 25, 35}};
    int filter_1 = 3;
    task_3(filter_1, matrix_1);
    int true_data_1[3][3] = {{10, 20, 30}, {25, 25, 45}, {15, 25, 35}};
    for (int i = 0; i < filter_1; i++) {
        for (int j = 0; j < filter_1; j++) {
            assert(matrix_1[i][j] == true_data_1[i][j]);
        }
    }

    int matrix_2[5][5] = {{15, 10, 15, 20, 30}, {45, 10, 35, 20, 40}, {35, 25, 10, 45, 15}, {30, 15, 50, 10, 5}, {15, 20, 40, 35, 10}};
    int filter_2 = 5;
    task_3(filter_2, matrix_2);
    int true_data_2[5][5] = {{15, 10, 15, 20, 30}, {45, 25, 20, 20, 40}, {35, 30, 25, 20, 15}, {30, 30, 30, 25, 5}, {15,20, 40, 35, 10}};
    for (int i = 0; i < filter_2; i++) {
        for (int j = 0; j < filter_2; j++) {
            assert(matrix_2[i][j] == true_data_2[i][j]);
        }
    }
}

void task_4(char **cpdomains, int size) {
    int domains_number = 0;

    for (int i = 0; i < size; i++) {
        size_t len = strlen(cpdomains[i]);
        char *string = cpdomains[i];
        for (char *s = string; s != string + len; s++) {
            if (*s == '.') {
                domains_number++;
            }
        }
        domains_number++;
    }

    domain domains[domains_number];
    int domains_size = 0;

    for (int i = 0; i < size; i++) {
        int visits = atoi(cpdomains[i]);
        size_t len = strlen(cpdomains[i]);
        char *string = cpdomains[i];
        for (char *s = string + len; s != string; s--) {
            if (*s == '.' || *s == ' ') {
                bool is_new_domain = true;
                for (int j = 0; j < domains_size && is_new_domain; j++) {
                    if (strcmp(s + 1, domains[j].name) == 0) {
                        domains[j].visits_number += visits;
                        is_new_domain = false;
                    }
                }
                if (is_new_domain) {
                    domains[domains_size].visits_number = visits;
                    domains[domains_size].name = s + 1;
                    domains_size++;
                }
            }
        }
    }

    for (int i = 0; i < domains_size; i++) {
        printf("%d %s\n", domains[i].visits_number, domains[i].name);
    }
}

void test_task_4() {
    char *cpdomains_1[] = {"9001 discuss.codeforces.com"};
    int size_1 = 1;
    task_4(cpdomains_1, size_1);
    printf("\n");
    char *cpdomains_2[] = {"900 google.mail.com",
                           "50 yahoo.com",
                           "1 intel.mail.com",
                           "5 wiki.org"};
    int size_2 = 4;
    task_4(cpdomains_2, size_2);
}

void fill_matrix(matrix m, matrix *new_matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m.values[i][j] == 1) {
                if (i != 0) {
                    new_matrix->values[i][j] = new_matrix->values[i - 1][j] + 1;
                } else {
                    new_matrix->values[i][j] = 1;
                }
            } else {
                new_matrix->values[i][j] = 0;
            }
        }
    }
}

int task_5(matrix m, int rows, int cols) {
    matrix new_matrix = getMemMatrix(rows, cols);
    fill_matrix(m, &new_matrix, rows, cols);
    int result = 0;

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = i + 1; k < cols + 1; k++) {
                int min = new_matrix.values[j][i];

                for (int g = i; g < k; g++) {
                    if (new_matrix.values[j][g] < min)
                        min = new_matrix.values[j][g];
                }

                result += min;
            }
        }
    }

    return result;
}

void test_task_5() {
    matrix matrix_1 = createMatrixFromArray((int[]) {
                                              1, 0, 1,
                                              1, 1, 0,
                                              1, 1, 0},
                                      3, 3);
    int result_1 = task_5(matrix_1, 3, 3);
    assert(result_1 == 13);

    matrix matrix_2 = createMatrixFromArray((int[]) {
                                              1, 1, 1, 0,
                                              0, 0, 1, 1,
                                              1, 0, 0, 0},
                                      3, 4);
    int result_2 = task_5(matrix_2, 3, 4);
    assert(result_2 == 11);
}


void task_6(char *string, int len, char *result, int *result_len) {
    char buffer[10];
    int buffer_len = 0;
    int new_result_len = 0;
    char num = '1';

    for (int i = 0; i < len; i++) {
        buffer[buffer_len++] = num++;
        if (string[i] == 'I') {
            while (buffer_len > 0) {
                result[new_result_len++] = buffer[--buffer_len];
            }
        }
    }

    buffer[buffer_len++] = num;

    while (buffer_len > 0) {
        result[new_result_len++] = buffer[--buffer_len];
    }

    result[new_result_len] = '\0';

    *result_len = new_result_len;
}

void test_task_6() {
    char patter[10] = "IIIDIDDD";
    int pattern_length = 8;
    char true_data[10] = "123549876";
    char result[10];
    int result_length;
    task_6(patter, pattern_length, result, &result_length);
    assert(strcmp(result, true_data) == 0);
}

void task_8(char *s, int *indices, char *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = s[indices[i]];
    }

    result[size] = '\0';
}

void test_task_8() {
    char s_1[4] = "abc";
    int indices_1[3] = {0, 1, 2};
    char *result_1[4];
    char true_data_1[4] = "abc";
    task_8(s_1, indices_1, result_1, 3);
    assert(strcmp(result_1, true_data_1) == 0);

    char s_2[5] = "abap";
    int indices_2[4] = {0, 3, 2, 1};
    char *result_2[5];
    char true_data_2[5] = "apab";
    task_8(s_2, indices_2, result_2, 4);
    assert(strcmp(result_2, true_data_2) == 0);
}

void fill_file(int *numbers, int size, char *file_name) {
    FILE *file;
    file = fopen(file_name, "w");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", numbers[i]);
    }

    fclose(file);
}

void task_9(int *numbers, int size, int n, char *file_name_1, char *file_name_2) {
    FILE *write_file = fopen(file_name_2, "w");
    FILE *read_file = fopen(file_name_1, "r");
    int number;

    while (fscanf(read_file, "%d", &number) != EOF) {
        if (number < n) {
            fprintf(write_file, "%d ", number);
        }
    }

    fclose(write_file);
    fclose(read_file);
}

void test_task_9(int argc, char **argv) {
    int numbers[10] = {1, 4, 3, 5, 2, 4, 10, 4, 0, -1};
    int size = 10;
    int n = atoi(argv[1]);
    char *file_name_1 = argv[2];
    char *file_name_2 = argv[3];

    fill_file(numbers, size, file_name_1);
    task_9(numbers, size, n, file_name_1, file_name_2);

    char *true_data[1] = {"1 4 3 2 4 4 0 -1 "};
    assert(assert_file(file_name_2, true_data));
    printf("correct");
}

static bool is_pressed = false;

void handler() {
    is_pressed = true;
}

void task_10(char *file_name, int n) {
    FILE *file = fopen(file_name, "r");
    char string[100];
    int index = 0;

    while (!feof(file)) {
        if (index % n == 0 && index != 0) {
            printf("Press ctrl+c to continue.\n");
            signal(SIGINT, handler);

            while (!is_pressed) {
                sleep(1);
            }
        }

        fgets(string, 100, file);
        printf("%s", string);
        index++;
        is_pressed = false;
    }

    fclose(file);
}

void fill_file_2(char **strings, int size, char *file_name) {
    FILE *file;
    file = fopen(file_name, "w");
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            fprintf(file, "%s\n", strings[i]);
        } else {
            fprintf(file, "%s", strings[i]);
        }
    }

    fclose(file);
}

void test_task_10(int argc, char **argv) {
    char *strings[] = {"string 1", "string 2", "string 3", "string 4", "string 5", "string 6"};
    char *file_name = argv[1];
    int n = atoi(argv[2]);
    fill_file_2(strings, 6, file_name);
    task_10(file_name, n);
}

int get_max_element_index(int *nums, int begin_index, int end_index) {
    int max_number = nums[begin_index];
    int max_number_index = begin_index;

    for (int i = begin_index + 1; i <= end_index; i++) {
        if (nums[i] > max_number) {
            max_number = nums[i];
            max_number_index = i;
        }
    }

    return max_number_index;
}

void get_new_node(int *nums, int size, prefix pref) {
    int max_element_index = get_max_element_index(nums, pref.begin_index, pref.end_index);
    printf("%d, ", nums[max_element_index]);

    if (pref.size > 1) {
        prefix left_prefix;
        left_prefix.size = max_element_index - pref.begin_index;
        if (left_prefix.size > 0) {
            left_prefix.begin_index = pref.begin_index;
            left_prefix.end_index = pref.begin_index + left_prefix.size - 1;
        }

        prefix right_prefix;
        right_prefix.size = pref.end_index - max_element_index;
        if (right_prefix.size > 0) {
            right_prefix.end_index = pref.end_index;
            right_prefix.begin_index = right_prefix.end_index - right_prefix.size + 1;
        }

        if (left_prefix.size > 0 && right_prefix.size > 0) {
            get_new_node(nums, size, left_prefix);
            get_new_node(nums, size, right_prefix);
        } else if (right_prefix.size > 0) {
            printf("null, ");
            get_new_node(nums, size, right_prefix);
        } else {
            get_new_node(nums, size, left_prefix);
            printf("null, ");
        }
    }
}

void task_7(int *nums, int size) {
    if (size == 0) {
        printf("{}\n");
        return;
    }

    printf("{");

    int max_element_index = get_max_element_index(nums, 0, size - 1);
    printf("%d, ", nums[max_element_index]);

    if (size > 1) {
        prefix left_prefix;
        left_prefix.size = max_element_index;
        if (left_prefix.size > 0) {
            left_prefix.begin_index = 0;
            left_prefix.end_index = max_element_index - 1;
        }

        prefix right_prefix;
        right_prefix.size = size - max_element_index - 1;
        if (right_prefix.size > 0) {
            right_prefix.begin_index = max_element_index + 1;
            right_prefix.end_index = size - 1;
        }

        if (left_prefix.size > 0 && right_prefix.size > 0) {
            get_new_node(nums, size, left_prefix);
            get_new_node(nums, size, right_prefix);
        } else if (right_prefix.size > 0) {
            printf("null, ");
            get_new_node(nums, size, right_prefix);
        } else {
            get_new_node(nums, size, left_prefix);
            printf("null, ");
        }
    }
    printf("\b\b}\n");
}

void test_task_7() {
    int nums_1[6] = {3, 2, 1, 6, 0, 5};
    int size_1 = 6;
    task_7(nums_1, size_1);

    int nums_2[3] = {3, 2, 1};
    int size_2 = 3;
    task_7(nums_2, size_2);

    int nums_3[5] = {5, 3, 2, 4, 1};
    int size_3 = 5;
    task_7(nums_3, size_3);

    int nums_4[5] = {2, 3, 1, 4, 5};
    int size_4 = 5;
    task_7(nums_4, size_4);
}

bool is_prefix(char *string, char *prefix) {
    bool result = true;
    char buffer_string = *string;
    char buffer_prefix = *prefix;

    while ((*string != '\0' || *prefix != '\0') && result) {
        if (*prefix == '\0') {
            return result;
        } else if (*string == '\0') {
            result = false;
        } else {
            if (*prefix != *string) {
                result = false;
            }
            prefix++;
            string++;
        }
    }

    return result;
}

void task_11() {
    int n, q;
    scanf("%d %d", &n, &q);
    char dictionary[n][MAX_STRING_SIZE];

    for (int i = 0; i < n; i++) {
        scanf("%s", dictionary[i]);
    }

    for (int i = 0; i < q; i++) {
        int k;
        char p[MAX_STRING_SIZE];
        scanf("%d %s", &k, p);

        int index = 1;
        bool is_word_founded = false;

        for (int j = 0; j < n && !is_word_founded; j++) {
            if (is_prefix(dictionary[j], p)) {
                if (index == k) {
                    printf("%d\n", j + 1);
                    is_word_founded = true;
                } else {
                    index++;
                }
            }
        }

        if (!is_word_founded) {
            printf("-1\n");
        }
    }
}

void test_task_11() {
    task_11();
}

void test_lab20() {
    //test_task_1();
    //test_task_2();
    //test_task_3();
    //test_task_4();
    //test_task_5();
    //test_task_6();
    //test_task_8();
    //test_task_7();
    test_task_11();
}