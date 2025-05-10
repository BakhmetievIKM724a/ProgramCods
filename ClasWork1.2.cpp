#include <iostream>
#include <cmath>
#include "windows.h"
#include <algorithm>
using namespace std;

class Triangle {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle() : sideA(0.0), sideB(0.0), sideC(0.0) {}

    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
        if (!isValidTriangle()) {
            sideA = sideB = sideC = 0.0;
            cout << "Помилка: неможливо створити трикутник з заданими сторонами." << endl;
        }
    }

    void setSides(double a, double b, double c) {
        sideA = a;
        sideB = b;
        sideC = c;
        if (!isValidTriangle()) {
            sideA = sideB = sideC = 0.0;
            cout << "Помилка: неможливо встановити такі сторони для трикутника." << endl;
        }
    }

    double getSideA() const { return sideA; }
    double getSideB() const { return sideB; }
    double getSideC() const { return sideC; }

    bool isValidTriangle() const {
        return (sideA > 0 && sideB > 0 && sideC > 0 &&
                sideA + sideB > sideC &&
                sideA + sideC > sideB &&
                sideB + sideC > sideA);
    }

    double calculatePerimeter() const {
        if (isValidTriangle()) {
            return sideA + sideB + sideC;
        } else {
            cout << "Помилка: неможливо обчислити периметр недійсного трикутника." << endl;
            return 0.0;
        }
    }

    double calculateArea() const {
        if (isValidTriangle()) {
            double s = calculatePerimeter() / 2.0;
            return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
        } else {
            cout << "Помилка: неможливо обчислити площу недійсного трикутника." << endl;
            return 0.0;
        }
    }

    bool isRightAngled() const {
        if (isValidTriangle()) {
            double a2 = pow(sideA, 2);
            double b2 = pow(sideB, 2);
            double c2 = pow(sideC, 2);

            return (abs(a2 + b2 - c2) < 1e-9 ||
                    abs(a2 + c2 - b2) < 1e-9 ||
                    abs(b2 + c2 - a2) < 1e-9);
        } else {
            cout << "Помилка: неможливо перевірити, чи є недійсний трикутник прямокутним." << endl;
            return false;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle1(3.0, 4.0, 5.0);
    Triangle triangle2(2.0, 3.0, 4.0);
    Triangle triangle3(5.0, 12.0, 13.0);
    Triangle invalidTriangle(1.0, 2.0, 5.0);

    cout << "Інформація про трикутник 1 (3, 4, 5):" << endl;
    cout << "Периметр: " << triangle1.calculatePerimeter() << endl;
    cout << "Площа: " << triangle1.calculateArea() << endl;
    cout << "Прямокутний: " << (triangle1.isRightAngled() ? "Так" : "Ні") << endl;
    cout << endl;

    cout << "Інформація про трикутник 2 (2, 3, 4):" << endl;
    cout << "Периметр: " << triangle2.calculatePerimeter() << endl;
    cout << "Площа: " << triangle2.calculateArea() << endl;
    cout << "Прямокутний: " << (triangle2.isRightAngled() ? "Так" : "Ні") << endl;
    cout << endl;

    cout << "Інформація про трикутник 3 (5, 12, 13):" << endl;
    cout << "Периметр: " << triangle3.calculatePerimeter() << endl;
    cout << "Площа: " << triangle3.calculateArea() << endl;
    cout << "Прямокутний: " << (triangle3.isRightAngled() ? "Так" : "Ні") << endl;
    cout << endl;

    cout << "Інформація про недійсний трикутник (1, 2, 5):" << endl;
    cout << "Периметр: " << invalidTriangle.calculatePerimeter() << endl;
    cout << "Площа: " << invalidTriangle.calculateArea() << endl;
    cout << "Прямокутний: " << (invalidTriangle.isRightAngled() ? "Так" : "Ні") << endl;
    cout << endl;

    triangle2.setSides(6.0, 8.0, 10.0);
    cout << "Оновлена інформація про трикутник 2 (6, 8, 10):" << endl;
    cout << "Периметр: " << triangle2.calculatePerimeter() << endl;
    cout << "Площа: " << triangle2.calculateArea() << endl;
    cout << "Прямокутний: " << (triangle2.isRightAngled() ? "Так" : "Ні") << endl;

    return 0;
}