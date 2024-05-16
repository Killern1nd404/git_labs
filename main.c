/*#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "OP/lab13/lab13.h"
#include "DM/lab1_1/lab1_1.h"
#include "libs/data_structures//matrix/matrix.h"
#include "libs/data_structures/string/string_.h"
#include "DM/lab1_3/lab1_3.h"
#include "DM/lab1_4/lab1_4.h"*/
#include "libs/data_structures/files/files.h"
#include "DM/lab2_1/lab2_1.h"
#include "C:\Users\andre\CLionProjects\Project\OP\lab20\lab20.h"
#include <time.h>

/*int main(int argc, char **argv) {
    //test_lab20();
    //lab2_1_8();
    //test_task_9(argc, argv);
    test_task_10(argc, argv);

    return 0;
}*/

int main() {
    //lab2_1_13();
    test_lab20();
    return 0;
}

/*int main () {
    clock_t start_clock, end_clock;
    int size = 30;

    double diff;
    for (int i = 1; i < 31; i++) {
        set = bitset_create(i);
        // Замер времени выполнения алгоритма порождения подмножеств
        start_clock = clock();
        get_subsets(set, 0);
        end_clock = clock();
        // Разница между началом и концом замеров времени
        // (деление на макрос CLK_TCK преобразует время в тиках в время в секундах)
        diff = difftime(end_clock, start_clock) / CLK_TCK;
        printf("Time for creating all subsets of set with power %d: %.3f\n", i, diff);
    }
}*/
