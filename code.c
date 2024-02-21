#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct unordered_array_set {
    int *data ; // элементы множества
    size_t size ; // количество элементов в множестве
    size_t capacity ; // максимальное количество элементов в множестве
} unordered_array_set ;

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int*)realloc(a->data, sizeof(int)*a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    unordered_array_set result = {malloc(sizeof(int) * capacity), 0, capacity};

    return result;
}

size_t linearSearch_ ( const int *a , const size_t n , int x ) {
    for ( size_t i = 0; i < n ; i ++)
        if ( a [ i ] == x )
            return i ;
    return n ;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
    return linearSearch_(set.data, set.size, value);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(*set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        set->data[set->size++] = value;
    }
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set result = unordered_array_set_create(size);

    for (size_t i = 0; i < size; i++) {
        unordered_array_set_insert(&result, a[i]);
    }

    unordered_array_set_shrinkToFit(&result);

    return result;
}

void inputArray_ (int * const a , const size_t n ) {
    for ( size_t i = 0; i < n ; i ++)
        scanf ("%d", & a [ i ]) ;
}

void outputArray_ ( const int * const a , const size_t n ) {
    for ( size_t i = 0; i < n ; i ++)
        printf ("%d ", a [ i ]) ;
    printf ("\n") ;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    size_t size = set1.size < set2.size ? set1.size : set2.size;
    unordered_array_set result = unordered_array_set_create(size);

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) != set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }

    unordered_array_set_shrinkToFit(&result);

    return result;
}

void unordered_array_set_print(unordered_array_set set) {
    outputArray_(set.data, set.size);
}

void lab13_12() {
    int t;
    scanf("%d", &t);

    unordered_array_set set = unordered_array_set_create(21);

    for (size_t i = 0; i < 21; i++) {
        set.data[i] = 0;
    }

    for (size_t i = 0; i < t; i++) {
        long long int x;
        scanf("%lld", &x);

        (set.data[x + 10])++;
    }

    long long int result = 0;

    for (size_t i = 0; i < 10; i++) {
        result += set.data[i] * set.data[20 - i];
    }

    result += (set.data[10] * (set.data[10] - 1)) / 2;

    printf("%lld", result);
}

int main() {
    lab13_12();

    return 0;
}