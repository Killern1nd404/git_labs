#include <stdio.h>
#include <math.h>

typedef struct fraction_t {
    int numerator;
    int denumerator;
} Fraction;

// Вводит значения в структуру Fraction
void inputFraction(Fraction *fraction) {
    scanf("%d / %d", &fraction->numerator, &fraction->denumerator);
}

// Вводит значения в массив структур Fraction
void inputFractions(Fraction *fractions, size_t size) {
    for (size_t i = 0; i < size; i++) {
        inputFraction(&fractions[i]);
    }
}

// Выводит значения структуры Fraction
void outputFraction(Fraction fraction) {
    printf("%d/%d\n", fraction.numerator, fraction.denumerator);
}

// Выводит значения массива структур Fraction
void outputFractions(Fraction *fractions, size_t size) {
    for (size_t i = 0; i < size; i++) {
        outputFraction(fractions[i]);
    }
}

// Находит наибольший общий делитель
int gcd(int a, int b) {
    int min_number = a < b ? a : b;

    for (int i = min_number; i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}

// Находит наименьшее общее кратное
int lcm(int a, int b) {
    return (a*b) / gcd(a, b);
}

// Сокращает дродь
void simpleFraction(Fraction *fraction) {
    int n = gcd(abs(fraction->denumerator), abs(fraction->numerator));
    fraction->denumerator /= n;
    fraction->numerator /= n;
}

// Умножает дроби
Fraction mulFraction(Fraction fraction1, Fraction fraction2) {
    int numerator = fraction1.numerator*fraction2.numerator;
    int denumerator = fraction1.denumerator*fraction2.denumerator;
    Fraction result = {numerator, denumerator};
    simpleFraction(&result);

    return result;
}

// Делит дроби
Fraction divFraction(Fraction fraction1, Fraction fraction2) {
    int numerator = fraction1.numerator*fraction2.denumerator;
    int denumerator = fraction1.denumerator*fraction2.numerator;
    Fraction result = {numerator, denumerator};
    simpleFraction(&result);

    return result;
}

// Складывает дроби
Fraction addFraction(Fraction fraction1, Fraction fraction2) {
    int denumerator = lcm(fraction1.denumerator, fraction2.denumerator);
    int numerator = fraction1.numerator*(denumerator/fraction1.denumerator) + fraction2.numerator*(denumerator/fraction2.denumerator);
    Fraction result = {numerator, denumerator};
    simpleFraction(&result);

    return result;
}

// Вычитает дроби
Fraction subFraction(Fraction fraction1, Fraction fraction2) {
    int denumerator = lcm(fraction1.denumerator, fraction2.denumerator);
    int numerator = fraction1.numerator*(denumerator/fraction1.denumerator) - fraction2.numerator*(denumerator/fraction2.denumerator);
    Fraction result = {numerator, denumerator};
    simpleFraction(&result);

    return result;
}

// Суммирует все дроби в массиве
Fraction sumFractions(Fraction *fractions, size_t size) {
    Fraction sum = fractions[0];

    for (size_t i = 1; i < size; i++) {
        sum = addFraction(sum, fractions[i]);
    }

    return sum;
}

int main() {
    Fraction fractions[3] = {{1, 4}, {1, 4}, {3, 4}};
    //Fraction fraction2 = {1, 3};
    outputFraction(sumFractions(fractions, 3));
}