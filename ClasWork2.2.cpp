#include <iostream>
#include <string>
#include "windows.h"

class Vehicle {
protected:
    double speed;
    double enginePower;

public:
    // Конструктор за замовчуванням
    Vehicle(double spd = 0.0, double power = 0.0) : speed(spd), enginePower(power) {
        if (spd < 0 || power < 0) {
            speed = enginePower = 0.0;
            std::cerr << "Помилка: швидкість та потужність не можуть бути від'ємними. Встановлено значення 0." << std::endl;
        }
    }

    double getSpeed() const { return speed; }
    double getEnginePower() const { return enginePower; }

    void setSpeed(double spd) {
        if (spd >= 0) {
            speed = spd;
        } else {
            std::cerr << "Помилка: швидкість не може бути від'ємною." << std::endl;
        }
    }

    void setEnginePower(double power) {
        if (power >= 0) {
            enginePower = power;
        } else {
            std::cerr << "Помилка: потужність не може бути від'ємною." << std::endl;
        }
    }

    virtual void displayInfo() const {
        std::cout << "Транспортний засіб: швидкість - " << speed << " км/год, потужність - " << enginePower << " кВт";
    }

    virtual void performAction() const {
        std::cout << "Транспортний засіб рухається." << std::endl;
    }
};

class Car : public Vehicle {
private:
    int passengerCapacity; // Кількість пасажирів

public:
    Car(double spd, double power, int capacity) : Vehicle(spd, power), passengerCapacity(capacity) {
        if (capacity < 1) {
            passengerCapacity = 1;
            std::cerr << "Помилка: кількість пасажирів не може бути меншою за 1. Встановлено значення 1." << std::endl;
        }
    }
    int getPassengerCapacity() const { return passengerCapacity; }
    void setPassengerCapacity(int capacity) {
        if (capacity >= 1) {
            passengerCapacity = capacity;
        } else {
            std::cerr << "Помилка: кількість пасажирів не може бути меншою за 1." << std::endl;
        }
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << ", тип - Легковий автомобіль, місткість - " << passengerCapacity << " пасажирів." << std::endl;
    }

    void performAction() const override {
        std::cout << "Легковий автомобіль перевозить пасажирів." << std::endl;
    }
};

class Truck : public Vehicle {
private:
    double maxLoadCapacity;

public:
    Truck(double spd, double power, double capacity) : Vehicle(spd, power), maxLoadCapacity(capacity) {
        if (capacity < 0) {
            maxLoadCapacity = 0;
            std::cerr << "Помилка: вантажопідйомність не може бути від'ємною. Встановлено значення 0." << std::endl;
        }
    }

    double getMaxLoadCapacity() const { return maxLoadCapacity; }

    void setMaxLoadCapacity(double capacity) {
        if (capacity >= 0) {
            maxLoadCapacity = capacity;
        } else {
            std::cerr << "Помилка: вантажопідйомність не може бути від'ємною." << std::endl;
        }
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << ", тип - Вантажівка, максимальна вантажопідйомність - " << maxLoadCapacity << " тонн." << std::endl;
    }

    void performAction() const override {
        std::cout << "Вантажівка перевозить вантаж." << std::endl;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(double spd, double power, bool sidecar) : Vehicle(spd, power), hasSidecar(sidecar) {}
    bool hasSidecarAttached() const { return hasSidecar; }
    void setHasSidecar(bool sidecar) {
        hasSidecar = sidecar;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << ", тип - Мотоцикл, з боковим причепом - " << (hasSidecar ? "Так" : "Ні") << "." << std::endl;
    }

    void performAction() const override {
        std::cout << "Мотоцикл швидко рухається." << std::endl;
    }

    void wheelie() const {
        std::cout << "Мотоцикл робить 'віллі'!" << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Car myCar(180.0, 150.0, 5);
    Truck myTruck(120.0, 400.0, 10.0);
    Motorcycle myMotorcycle(220.0, 180.0, false);
    Vehicle genericVehicle(50.0, 30.0);

    std::cout << "Інформація про легковий автомобіль:" << std::endl;
    myCar.displayInfo();
    myCar.performAction();
    std::cout << "Місткість: " << myCar.getPassengerCapacity() << " пасажирів." << std::endl;
    std::cout << std::endl;

    std::cout << "Інформація про вантажівку:" << std::endl;
    myTruck.displayInfo();
    myTruck.performAction();
    std::cout << "Максимальна вантажопідйомність: " << myTruck.getMaxLoadCapacity() << " тонн." << std::endl;
    std::cout << std::endl;

    std::cout << "Інформація про мотоцикл:" << std::endl;
    myMotorcycle.displayInfo();
    myMotorcycle.performAction();
    if (myMotorcycle.hasSidecarAttached()) {
        std::cout << "З боковим причепом." << std::endl;
    } else {
        std::cout << "Без бокового причепа." << std::endl;
        myMotorcycle.wheelie();
    }
    std::cout << std::endl;

    std::cout << "Інформація про транспортний засіб:" << std::endl;
    genericVehicle.displayInfo();
    genericVehicle.performAction();
    std::cout << std::endl;

    Vehicle* vehicles[] = {&myCar, &myTruck, &myMotorcycle, &genericVehicle};
    std::cout << "Інформація про всі транспортні засоби (через покажчики на базовий клас):" << std::endl;
    for (const Vehicle* vehicle : vehicles) {
        vehicle->displayInfo();
        vehicle->performAction();
        std::cout << "---" << std::endl;
    }

    return 0;
}