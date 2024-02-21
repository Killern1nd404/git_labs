#include <stdio.h>
#include <stdlib.h>

// Проверяет равенство чисел
int compare_ints(const void* a, const void* b) {
    long long int arg1 = *(const int*)a;
    long long int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

// Производит ввод элементов в массив
int inputArray(long long int a[], size_t n) {
    for (int i = 0; i < n; i++) {
        long long int element;
        scanf("%lld", &element);

        a[i] = element;
    }

    return *a;
}

// Вычисляет сумму элементов массива
long long int getArraySum(const long long int *array, const int size) {
    long long int result = 0;

    for (int i = 0; i < size; i++) {
        result += array[i];
    }

    return result;
}

// Вычисляет минимальное количество монет для победы над драконом
long long int countMinMoneyToWin(long long int *heroes_power, const int n, const long long int dragon_power, const long long int dragon_protection, const int m) {
    long long int heroes_power_sum = getArraySum(heroes_power, n);

    if (heroes_power[0] >= dragon_protection) {
        long long int need_money = dragon_power - (heroes_power_sum - heroes_power[0]);

        return need_money > 0 ? need_money : 0;
    } else {
        int left = 1;
        int right = n - 1;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (heroes_power[middle] >= dragon_protection && heroes_power[middle - 1] < dragon_protection) {
                long long int need_money_to_attack = dragon_protection - heroes_power[middle - 1];
                long long int need_money_to_defence = dragon_power - (heroes_power_sum - heroes_power[middle]);
                long long int need_money_to_defence_2 = dragon_power - (heroes_power_sum - heroes_power[middle - 1]) >= 0 ? dragon_power - (heroes_power_sum - heroes_power[middle - 1]) : 0;
                long long int need_money_to_defence_and_attack = need_money_to_attack + need_money_to_defence_2;
                long long int need_money = need_money_to_defence_and_attack < need_money_to_defence ? need_money_to_defence_and_attack : need_money_to_defence;

                return need_money > 0 ? need_money : 0;
            } else if (heroes_power[middle] < dragon_protection) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        long long int need_money_to_attack = dragon_protection - heroes_power[n - 1];
        long long int need_money_to_defence = dragon_power - (heroes_power_sum - heroes_power[n - 1]) >= 0 ? dragon_power - (heroes_power_sum - heroes_power[n - 1]) : 0;
        long long int need_money = need_money_to_defence + need_money_to_attack;

        return need_money > 0 ? need_money : 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    long long int heroes_power[n];
    inputArray(heroes_power, n);
    qsort(heroes_power, n, sizeof(long long int), compare_ints);

    int m;
    scanf("%d", &m);

    long long int dragons_power[m];
    long long int dragons_protection[m];

    for (int i = 0; i < m; i++) {
        long long int x, y;
        scanf("%lld %lld", &x, &y);

        dragons_protection[i] = x;
        dragons_power[i] = y;

        printf("%lld\n", countMinMoneyToWin(heroes_power, n, y, x, m));
    }
}