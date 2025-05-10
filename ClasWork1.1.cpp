#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

class Student {
private:
    string name;
    int age;
    double averageGrade;

public:
    Student() : name("Невідомо"), age(0), averageGrade(0.0) {}

    Student(string studentName, int studentAge, double studentAverageGrade)
        : name(studentName), age(studentAge), averageGrade(studentAverageGrade) {}


    void setName(string studentName) {
        name = studentName;
    }

    void setAge(int studentAge) {
        if (studentAge >= 0) {
            age = studentAge;
        } else {
            cout << "Помилка: вік не може бути від'ємним." << endl;
        }
    }

    void setAverageGrade(double studentAverageGrade) {
        if (studentAverageGrade >= 0.0 && studentAverageGrade <= 100.0) {
            averageGrade = studentAverageGrade;
        } else {
            cout << "Помилка: середній бал повинен бути в діапазоні від 0.0 до 100.0." << endl;
        }
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getAverageGrade() const {
        return averageGrade;
    }


    void displayInfo() const {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << " років" << endl;
        cout << "Середній бал: " << averageGrade << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student student1;
    Student student2("Іван Петренко", 20, 85.5);
    Student student3("Марія Сидоренко", 19, 92.0);

    cout << "Інформація про студента 1:" << endl;
    student1.displayInfo();
    cout << endl;

    cout << "Інформація про студента 2:" << endl;
    student2.displayInfo();
    cout << endl;

    cout << "Інформація про студента 3:" << endl;
    student3.displayInfo();
    cout << endl;

    student1.setName("Ольга Іванова");
    student1.setAge(21);
    student1.setAverageGrade(78.9);

    cout << "Оновлена інформація про студента 1:" << endl;
    student1.displayInfo();
    cout << endl;

    cout << "Ім'я студента 2: " << student2.getName() << endl;
    cout << "Вік студента 2: " << student2.getAge() << endl;
    cout << "Середній бал студента 2: " << student2.getAverageGrade() << endl;

    return 0;
}