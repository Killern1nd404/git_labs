#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "OP/lab13/lab13.h"
#include "DM/lab1_1/lab1_1.h"
#include "libs/data_structures//matrix/matrix.h"

int main() {
    matrix m = getMemMatrix(3, 2);
    inputMatrix(&m);
    transposeMatrix(&m);
    outputMatrix(m);

    return 0;
}