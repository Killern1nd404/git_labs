#include <stdio.h>

typedef struct day_t {
    int hours;
    int minutes;
    int seconds;
} Day;

// Выводит значения структуры Day
void outputDay(Day day) {
    printf("%02d:%02d:%02d\n", day.hours, day.minutes, day.seconds);
}

// Выводит значения массива структур Day
void outputDays(Day *days, size_t size) {
    for (size_t i = 0; i < size; i++) {
        outputDay(days[i]);
    }
}

// Возвращает время в секундах
int getTimeInSeconds(Day day) {
    return day.seconds + day.minutes*60 + day.hours*3600;
}

// Сортирует время
void sortTimes(Day *days, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        if (getTimeInSeconds(days[i]) > getTimeInSeconds(days[i + 1])) {
            Day temp = days[i];
            days[i] = days[i + 1];
            days[i + 1] = temp;
        }
    }
}

int main() {
    Day days[3] = {{23, 54, 34},
                   {0, 34, 23},
                   {15, 43, 24}};
    int n = 3;

    sortTimes(days, n);
    outputDays(days, n);
}