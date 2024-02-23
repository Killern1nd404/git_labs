#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "OP/lab13/lab13.h"
#include "DM/lab1_1/lab1_1.h"

int main() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    int* result = atVector(&v, 1);

    vectorVoid v_void = {result, v.size, v.capacity, sizeof(int)};

    return 0;
}