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

// Превращает секунды в полное время
Day convertSecondsInFullTime(int time) {
    int hours = time / 3600;
    int minutes = (time % 3600) / 60;
    int seconds = (time % 3600) % 60;
    Day result = {hours, minutes, seconds};

    return result;
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

// Выводит время между элементами массива
void printTimeBetweenTimes(Day *days, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        int time1 = getTimeInSeconds(days[i]);
        int time2 = getTimeInSeconds(days[i + 1]);
        Day time = convertSecondsInFullTime(time2 - time1);
        outputDay(time);
    }
}

int main() {
    Day days[3] = {{23, 54, 34},
                   {0, 34, 23},
                   {15, 43, 24}};
    int n = 3;

    sortTimes(days, n);
    printTimeBetweenTimes(days, n);
}