#include <iostream>
#include <string>
#include <cmath>
#include "windows.h"

class Figure {
protected:
    std::string color;

public:
    Figure(const std::string& figColor = "не визначено") : color(figColor) {}

    std::string getColor() const {
        return color;
    }

    void setColor(const std::string& newColor) {
        color = newColor;
    }

    virtual double calculateArea() const {
        return 0.0;
    }

    virtual void displayInfo() const {
        std::cout << "Фігура: колір - " << color;
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r, const std::string& color = "не визначено") : Figure(color), radius(r) {
        if (r < 0) {
            radius = 0;
            std::cerr << "Помилка: радіус кола не може бути від'ємним. Встановлено значення 0." << std::endl;
        }
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            std::cerr << "Помилка: радіус кола не може бути від'ємним." << std::endl;
        }
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    void displayInfo() const override {
        Figure::displayInfo();
        std::cout << ", радіус - " << radius << ", площа - " << calculateArea() << std::endl;
    }
};

class Rectangle : public Figure {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h, const std::string& color = "не визначено") : Figure(color), width(w), height(h) {
        if (w < 0 || h < 0) {
            width = height = 0;
            std::cerr << "Помилка: ширина та висота прямокутника не можуть бути від'ємними. Встановлено значення 0." << std::endl;
        }
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void setWidth(double w) {
        if (w >= 0) {
            width = w;
        } else {
            std::cerr << "Помилка: ширина прямокутника не може бути від'ємною." << std::endl;
        }
    }

    void setHeight(double h) {
        if (h >= 0) {
            height = h;
        } else {
            std::cerr << "Помилка: висота прямокутника не може бути від'ємною." << std::endl;
        }
    }

    double calculateArea() const override {
        return width * height;
    }
    void displayInfo() const override {
        Figure::displayInfo();
        std::cout << ", ширина - " << width << ", висота - " << height << ", площа - " << calculateArea() << std::endl;
    }
};

class Triangle : public Figure {
private:
    double base;
    double height;

public:
    Triangle(double b, double h, const std::string& color = "не визначено") : Figure(color), base(b), height(h) {
        if (b < 0 || h < 0) {
            base = height = 0;
            std::cerr << "Помилка: основа та висота трикутника не можуть бути від'ємними. Встановлено значення 0." << std::endl;
        }
    }
    double getBase() const {
        return base;
    }

    double getHeight() const {
        return height;
    }

    void setBase(double b) {
        if (b >= 0) {
            base = b;
        } else {
            std::cerr << "Помилка: основа трикутника не може бути від'ємною." << std::endl;
        }
    }

    void setHeight(double h) {
        if (h >= 0) {
            height = h;
        } else {
            std::cerr << "Помилка: висота трикутника не може бути від'ємною." << std::endl;
        }
    }

    double calculateArea() const override {
        return 0.5 * base * height;
    }

    void displayInfo() const override {
        Figure::displayInfo();
        std::cout << ", основа - " << base << ", висота - " << height << ", площа - " << calculateArea() << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Circle circle(5.0, "червоний");
    Rectangle rectangle(4.0, 6.0, "синій");
    Triangle triangle(7.0, 3.0, "зелений");
    Figure genericFigure("жовтий");

    std::cout << "Інформація про коло:" << std::endl;
    circle.displayInfo();
    std::cout << "Площа кола: " << circle.calculateArea() << std::endl;
    std::cout << "Колір кола: " << circle.getColor() << std::endl;
    std::cout << std::endl;

    std::cout << "Інформація про прямокутник:" << std::endl;
    rectangle.displayInfo();
    std::cout << "Площа прямокутника: " << rectangle.calculateArea() << std::endl;
    std::cout << "Колір прямокутника: " << rectangle.getColor() << std::endl;
    std::cout << std::endl;

    std::cout << "Інформація про трикутник:" << std::endl;
    triangle.displayInfo();
    std::cout << "Площа трикутника: " << triangle.calculateArea() << std::endl;
    std::cout << "Колір трикутника: " << triangle.getColor() << std::endl;
    std::cout << std::endl;

    std::cout << "Інформація про фігуру:" << std::endl;
    genericFigure.displayInfo();
    std::cout << "Площа фігури: " << genericFigure.calculateArea() << std::endl;
    std::cout << "Колір фігури: " << genericFigure.getColor() << std::endl;
    std::cout << std::endl;

    Figure* shapes[] = {&circle, &rectangle, &triangle, &genericFigure};
    std::cout << "Інформація про всі фігури (через покажчики на базовий клас):" << std::endl;
    for (const Figure* shape : shapes) {
        shape->displayInfo();
        std::cout << "Площа: " << shape->calculateArea() << std::endl;
        std::cout << "Колір: " << shape->getColor() << std::endl;
        std::cout << "---" << std::endl;
    }

    return 0;
}