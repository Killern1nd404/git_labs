#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "OP/lab13/lab13.h"
#include "DM/lab1_1/lab1_1.h"
#include "libs/data_structures//matrix/matrix.h"

int main() {
    matrix m = createMatrixFromArray((int[]) {2, 4, 3,
                                              5, 9, 6,
                                              7, 8, 1},3, 3);
    freeMemMatrix(&m);

    return 0;
}