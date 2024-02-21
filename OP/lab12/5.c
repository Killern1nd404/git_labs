#include <stdio.h>

#define N_MARKS 5

typedef struct student_t {
    char surname[20];
    int marks[N_MARKS];
} Student;

// Выводит значения структуры Student
void outputStudent(Student student) {
    printf("%s %d %d %d %d %d\n", student.surname, student.marks[0], student.marks[1], student.marks[2], student.marks[3], student.marks[4]);
}

// Выводит значения массива структур Student
void outputStudents(Student *students, size_t size) {
    for (size_t i = 0; i < size; i++) {
        outputStudent(students[i]);
    }
}

// удаляет структуру Student из массива
void removeStudent(Student *students, int *size, const size_t index) {
    for (size_t i = index; i < *size; i++) {
        students[i] = students[i + 1];
    }

    (*size)--;
}

// Проверяет, хороший ли студент
int isGoodStudent(Student student) {
    for (size_t i = 0; i < N_MARKS; i++) {
        if (student.marks[i] < 3) {
            return 0;
        }
    }

    return 1;
}

// Удаляет плохих студентов из массива
void deleteBadStudents(Student *students, int *size) {
    for (size_t i = 0; i < *size; i++) {
        if (!isGoodStudent(students[i])) {
            removeStudent(students, size, i);
            i--;
        }
    }
}

int main() {
    Student students[3] = {{"F1", {2, 5, 5, 5, 5}},
                           {"F2", {5, 3, 5, 5, 5}},
                           {"F3", {2, 5, 5, 5 ,5}}};
    int n = 3;

    deleteBadStudents(students, &n);
    outputStudents(students, n);
}