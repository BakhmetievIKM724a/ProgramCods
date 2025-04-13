#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

struct Student {
    char lastName[50];
    char faculty[50];
    char group[10];
    int absences;
};

const int MAX_STUDENTS = 100; // Максимальна кількість студентів
Student students[MAX_STUDENTS];
int studentCount = 0;

// Функція для введення інформації про студента
void enterStudentInfo() {
    if (studentCount < MAX_STUDENTS) {
        Student newStudent;
        cout << "Введіть прізвище студента: ";
        cin >> newStudent.lastName;
        cout << "Введіть факультет: ";
        cin >> newStudent.faculty;
        cout << "Введіть групу: ";
        cin >> newStudent.group;
        cout << "Введіть кількість пропусків: ";
        cin >> newStudent.absences;
        students[studentCount++] = newStudent;
        cout << "Інформацію про студента додано.\n";
    } else {
        cout << "Досягнуто максимальної кількості студентів.\n";
    }
}

// Функція для виведення повного списку студентів
void displayAllStudents() {
    if (studentCount == 0) {
        cout << "Список студентів порожній.\n";
        return;
    }
    cout << "\nПовний список студентів:\n";
    for (int i = 0; i < studentCount; ++i) {
        cout << "Прізвище: " << students[i].lastName
             << ", Факультет: " << students[i].faculty
             << ", Група: " << students[i].group
             << ", Пропуски: " << students[i].absences << "\n";
    }
}

// Функція для знаходження студента з найбільшою кількістю пропусків
void findStudentWithMostAbsences() {
    if (studentCount == 0) {
        cout << "Список студентів порожній.\n";
        return;
    }

    int maxAbsences = -1; // Ініціалізуємо від'ємним значенням
    int studentWithMaxAbsencesIndex = -1;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].absences > maxAbsences) {
            maxAbsences = students[i].absences;
            studentWithMaxAbsencesIndex = i;
        }
    }

    if (studentWithMaxAbsencesIndex != -1) {
        cout << "\nСтудент з найбільшою кількістю пропусків:\n";
        cout << "Прізвище: " << students[studentWithMaxAbsencesIndex].lastName
             << ", Факультет: " << students[studentWithMaxAbsencesIndex].faculty
             << ", Група: " << students[studentWithMaxAbsencesIndex].group
             << ", Пропуски: " << students[studentWithMaxAbsencesIndex].absences << "\n";
    } else {
        cout << "Не вдалося знайти студента (можливо, список порожній).\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Ввести інформацію про студента\n";
        cout << "2. Вивести повний список студентів\n";
        cout << "3. Вивести дані про студента з найбільшою кількістю пропусків\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера після введення числа

        switch (choice) {
            case 1:
                enterStudentInfo();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                findStudentWithMostAbsences();
                break;
            case 0:
                cout << "Програма завершена.\n";
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}