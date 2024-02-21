#include <stdio.h>

int power(int a, int n) {
    int x = a;
    int result = 1;

    while (n > 0) {
        if (n & 1) {
            result *= x;
        }
        n >>= 1;
        x *= x;
    }

    return result;
}

int countDigits(int number) {
    int result = 0;

    while (number > 0) {
        result++;
        number /= 10;
    }

    return result;
}

int isPalindrome(int number) {
    int is_palindrome = 1;
    int digits = power(10, countDigits(number));

    for (int i = 1; (i <= (countDigits(number) / 2)) && is_palindrome; i++) {
        if (((number % power(10, i)) / power(10, i - 1)) != (number / (digits / power(10, i))) % 10) {
            is_palindrome = 0;
        }
    }

    return is_palindrome;
}

int countAllPalindromes(int number) {
    int result = 0;
    for (int i = 1; i <= number; i++) {
        if (isPalindrome(i)) {
            result++;
        }
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", countAllPalindromes(n));
}