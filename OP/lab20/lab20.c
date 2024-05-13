#include "lab20.h"
#include <stdio.h>
#include "C:\Users\andre\CLionProjects\Project\libs\data_structures\matrix\matrix.h"
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
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







/*int search_domain(domain *results, int size, char *s) {
    for (int i = 0; i < size; i++) {
        if (strcmp(results[i].name, s) == 0) {
            return i;
        }
    }

    return size;
}

bool search_number(int *array, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (number == array[i])
            return true;
    }

    return false;
}

void handle_dot_pointer(domain *array, int i, char *dot_pointer, domain *results, int *results_size) {
    strcpy(array[i].name, dot_pointer + 1);
    int pos = search_domain(results, *results_size, array[i].name);
    if (pos == *results_size) {
        results[*results_size] = array[i];
        *results_size += 1;
    } else {
        results[pos].visits_number += array[i].visits_number;
    }
}

void output_domains(domain *results, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %s\n", results[i].visits_number, results[i].name);
    }
}

void task_4(domain *array, int size) {
    int closes_indexes[size];
    int closes_counter = 0;
    domain results[100];
    int results_size = 0;

    for (int i = 0; i < size; i++)
        results[results_size++] = array[i];

    while (closes_counter != size) {
        for (int i = 0; i < size; i++) {
            if (!search_number(closes_indexes, closes_counter, i)) {
                char *dot_pointer;
                dot_pointer = strchr(array[i].name, '.');

                if (dot_pointer != NULL)
                    handle_dot_pointer(array, i, dot_pointer, results, &results_size);
                else
                    closes_indexes[closes_counter++] = i;
            }
        }
    }

    output_domains(results, results_size);
}

void test_task_4() {
    char *cpdomains = "9001 discuss.codeforces.com";
    domain d;
    d.visits_number = 9001;
    domain r[1] = {d};
    d.name = "discuss.codeforces.com";
    task_4(r, 1);
}*/

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

/*int searchMaxIdx(const int array[], int start, int end) {
    if (start > end) {
        return end + 1;
    } else {
        int max_num_idx = start;
        for (int ind = start + 1; ind <= end; ind++) {
            if (array[ind] > array[max_num_idx])
                max_num_idx = ind;
        }

        return max_num_idx;
    }
}

root_node *create_root_node(int number) {
    root_node *result = (root_node *) malloc(sizeof(root_node));
    result->max_value = number;
    result->left_prefix = NULL;
    result->right_prefix = NULL;

    return result;
}

root_node *insert(root_node *node, int number, bool is_left) {
    root_node *result = create_root_node(number);
    if (is_left) {
        node->left_prefix = result;
    } else {
        node->right_prefix = result;
    }

    return result;
}


void create_root_nodes(root_node *node, int *nums, int start, int end, bool is_left) {
    /*int max_number = nums[0];
    int index = 0;

    for (int i = 1; i <= end; i++) {
        if (nums[i] > max_number) {
            max_number = nums[i];
            index = i;
        }
    }*/

    /*int max_number_index = searchMaxIdx(nums, start, end);

    if (max_number_index == end + 1) {
        if (is_left) {
            node->left_prefix = NULL;
        } else {
            node->right_prefix = NULL;
        }

        printf("null ");
        return;
    }

    printf("%d ", nums[max_number_index]);
    root_node *new_node = insert(node, nums[max_number_index], is_left);
    create_root_nodes(new_node, nums, start, max_number_index - 1, true);
    create_root_nodes(new_node, nums, max_number_index + 1, end, false);
}

void task_7(int *nums, int size) {
    if (size == 0) {
        return;
    }

    /*int max_number = nums[0];
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (nums[i] > max_number) {
            max_number = nums[i];
            index = i;
        }
    }*/

    /*int max_number_index = searchMaxIdx(nums, 0, size - 1);

    root_node *new_node = create_root_node(nums[max_number_index]);
    printf("%d ", nums[max_number_index]);

    create_root_nodes(new_node, nums, 0, max_number_index - 1, true);
    create_root_nodes(new_node, nums, max_number_index + 1, size - 1, false);

    printf("\n");
}

void test_task_7() {
    int nums[6] = {3, 2, 1, 6, 0, 5};
    task_7(nums, 6);
}*/

void test_lab20() {
    //test_task_1();
    //test_task_2();
    //test_task_3();
    //test_task_4();
    //test_task_5();
    //test_task_6();
    //test_task_8();
    //test_task_7();
}