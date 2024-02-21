#ifndef UNTITLED_BITSET_H
#define UNTITLED_BITSET_H

# include <stdint.h>
# include <stdbool.h>

typedef struct bitset {
    uint32_t values; // множество
    uint32_t maxValue; // максимальный элемент универсума
} bitset ;

// возвращает пустое множество c универсумом 0, 1,..., maxValue
bitset bitset_create ( unsigned maxValue ) ;

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in ( bitset set , unsigned int value ) ;

// возвращает значение ’истина’, если множества set1 и set2 равны// иначе - ’ложь’
bool bitset_isEqual ( bitset set1 , bitset set2 ) ;

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitset_isSubset ( bitset subset , bitset set ) ;

// добавляет элемент value в множество set
void bitset_insert ( bitset * set , unsigned int value ) ;

// удаляет элемент value из множества set
void bitset_deleteElement ( bitset * set , unsigned int value ) ;

// возвращает объединение множеств set1 и set2
bitset bitset_union ( bitset set1 , bitset set2 ) ;

// возвращает пересечение множеств set1 и set2
bitset bitset_intersection ( bitset set1 , bitset set2 ) ;

// возвращает разность множеств set1 и set2
bitset bitset_difference ( bitset set1 , bitset set2 ) ;

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetricDifference ( bitset set1 , bitset set2 ) ;

// возвращает дополнение до универсума множества set
bitset bitset_complement ( bitset set ) ;

// вывод множества set
void bitset_print ( bitset set ) ;

void test_bitset_union1();

void test_bitset_union2();

void test_bitset_union();

void test_bitset_in1();

void test_bitset_in2();

void test_bitset_in();

void test_bitset_isSubset1();

void test_bitset_isSubset2();

void test_bitset_isSubset();

void test_bitset_deleteElement();

void test_bitset_intersection1();

void test_bitset_intersection2();

void test_bitset_intersection();

void test_bitset_difference1();

void test_bitset_difference2();

void test_bitset_difference();

void test_bitset_symmetricDifference1();

void test_bitset_symmetricDifference2();

void test_bitset_symmetricDifference();

void test_bitset_complement1();

void test_bitset_complement2();

void test_bitset_complement();

void test_bitset();

#endif //UNTITLED_BITSET_H
