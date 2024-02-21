#include <assert.h>
#include <stdbool.h>
#include <malloc.h>
#include "array.h"
#include "ordered_array_set.h"

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int*)realloc(a->data, sizeof(int)*a->size);
        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create(size_t capacity) {
    ordered_array_set result = {malloc(sizeof(int) * capacity), 0, capacity};

    return result;
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set result = ordered_array_set_create(size);

    for (size_t i = 0; i < size; i++) {
        ordered_array_set_insert(&result, a[i]);
    }

    return result;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            return i;
        } else if (set->data[i] > value) {
            return set->size;
        }
    }

    return set->size;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }

    for (size_t i = 0; i < set1.size; i++) {
        if (set1.data[i] != set2.data[i]) {
            return false;
        }
    }

    return true;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    if (subset.size > set.size) {
        return false;
    }

    int coincidence = 0;
    size_t previous_index = 0;

    for (size_t i = 0; i < subset.size; i++) {
        for (size_t j = previous_index; j < set.size; j++) {
            if (subset.data[i] == set.data[j]) {
                previous_index = j;
                coincidence++;
                break;
            } else if (set.data[j] > subset.data[i]) {
                return false;
            }
        }
    }

    if (coincidence == subset.size) {
        return true;
    }  else {
        return false;
    }
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) == set->size) {
        ordered_array_set_isAbleAppend(set);
        set->data[set->size++] = value;
        qsort(set->data, set->size, sizeof(int), compare_ints);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) != set->size) {
        for (size_t i = 0; i < set->size; i++) {
            if (set->data[i] == value) {
                deleteByPosSaveOrder_(set->data, &set->size, i);
                break;
            }
        }
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size + set2.size);

    for (size_t i = 0; i < set1.size; i++) {
        ordered_array_set_insert(&result, set1.data[i]);
    }

    for (size_t i = 0; i < set2.size; i++) {
        if (ordered_array_set_in(&set1, set2.data[i]) == set1.size) {
            ordered_array_set_insert(&result, set2.data[i]);
        }
    }

    ordered_array_set_shrinkToFit(&result);

    return result;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    size_t size = set1.size < set2.size ? set1.size : set2.size;
    ordered_array_set result = ordered_array_set_create(size);

    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) != set2.size) {
            ordered_array_set_insert(&result, set1.data[i]);
        }
    }

    ordered_array_set_shrinkToFit(&result);

    return result;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size) {
            ordered_array_set_insert(&result, set1.data[i]);
        }
    }

    ordered_array_set_shrinkToFit(&result);

    return result;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set difference1 = ordered_array_set_difference(set1, set2);
    ordered_array_set difference2 = ordered_array_set_difference(set2, set1);
    ordered_array_set result = ordered_array_set_union(difference1, difference2);

    ordered_array_set_delete(&difference1);
    ordered_array_set_delete(&difference2);

    return result;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    ordered_array_set result = ordered_array_set_create(universumSet.size);

    for (size_t i = 0; i < universumSet.size; i++) {
        if (ordered_array_set_in(&set, universumSet.data[i]) == set.size) {
            ordered_array_set_insert(&result, universumSet.data[i]);
        }
    }

    ordered_array_set_shrinkToFit(&result);

    return result;
}

void ordered_array_set_print(ordered_array_set set) {
    outputArray_(set.data, set.size);
}

void ordered_array_set_delete(ordered_array_set *set) {
    free(set->data);
    set->size = 0;
    set->capacity = 0;
}

void test_ordered_array_set_union1 () {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2} , 2) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {2 , 3} , 2) ;
    ordered_array_set resSet = ordered_array_set_union ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {1 , 2 , 3} , 3) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_union2 () {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2, 3} , 3) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {} , 0) ;
    ordered_array_set resSet = ordered_array_set_union ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {1 , 2, 3} , 3) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
}

void test_ordered_array_set_in1() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1, 2, 3}, 3);
    size_t result = ordered_array_set_in(&set1, 2);

    assert(result == 1);

    ordered_array_set_delete(&set1);
}

void test_ordered_array_set_in2() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1, 2, 3}, 3);
    size_t result = ordered_array_set_in(&set1, 4);

    assert(result == 3);

    ordered_array_set_delete(&set1);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
}

void test_ordered_array_set_isSubset1() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int []) {1, 2, 3, 4}, 4);
    bool result = ordered_array_set_isSubset(set1, set2);

    assert(result);

    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1, 2, 7}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int []) {1, 2, 3, 4}, 4);
    bool result = ordered_array_set_isSubset(set1, set2);

    assert(!result);

    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
}

void test_ordered_array_set_insert() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1, 2, 7}, 3);
    set1.capacity++;
    ordered_array_set_insert(&set1, 4);
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {1 , 2, 4, 7} , 4) ;

    assert ( ordered_array_set_isEqual ( set1 , expectedSet ) ) ;

    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_deleteElement() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1, 2, 7}, 3);
    ordered_array_set_deleteElement(&set1, 7);
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {1 , 2} , 2) ;

    assert ( ordered_array_set_isEqual ( set1 , expectedSet ) ) ;

    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2} , 2) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {2 , 3} , 2) ;
    ordered_array_set resSet = ordered_array_set_intersection ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {2} , 1) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 4} , 2) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {2 , 3} , 2) ;
    ordered_array_set resSet = ordered_array_set_intersection ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {} , 0) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
}

void test_ordered_array_set_difference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2} , 2) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {2 , 3} , 2) ;
    ordered_array_set resSet = ordered_array_set_difference ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {1} , 1) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {2 , 3} , 2) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {2 , 3} , 2) ;
    ordered_array_set resSet = ordered_array_set_difference ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {} , 0) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
}

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2} , 2) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {2 , 3} , 2) ;
    ordered_array_set resSet = ordered_array_set_symmetricDifference ( set1 , set2 ) ;

    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {1, 3} , 2) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2} , 2) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {4 , 5} , 2) ;
    ordered_array_set resSet = ordered_array_set_symmetricDifference ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {1, 2, 4, 5} , 4) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
}

void test_ordered_array_set_complement1() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2, 4} , 3) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {1, 2 , 3, 4, 5} , 5) ;
    ordered_array_set resSet = ordered_array_set_complement ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {3, 5} , 2) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_complement2() {
    ordered_array_set set1 = ordered_array_set_create_from_array (( int []) {1 , 2, 3, 4, 5} , 5) ;
    ordered_array_set set2 = ordered_array_set_create_from_array (( int []) {1, 2, 3, 4, 5} , 5) ;
    ordered_array_set resSet = ordered_array_set_complement ( set1 , set2 ) ;
    ordered_array_set expectedSet = ordered_array_set_create_from_array (( int []) {} , 0) ;

    assert ( ordered_array_set_isEqual ( resSet , expectedSet ) ) ;

    ordered_array_set_delete ( &set1 ) ;
    ordered_array_set_delete ( &set2 ) ;
    ordered_array_set_delete ( &resSet ) ;
    ordered_array_set_delete ( &expectedSet ) ;
}

void test_ordered_array_set_complement() {
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
}

void test_ordered_array_set() {
    test_ordered_array_set_union();
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}