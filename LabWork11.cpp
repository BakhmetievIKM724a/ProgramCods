#include <iostream>

int main() {
    double a, b;
    double *ptrA, *ptrB;

    std::cout << "Введіть значення змінної a: ";
    std::cin >> a;
    std::cout << "Введіть значення змінної b: ";
    std::cin >> b;

    ptrA = &a;
    ptrB = &b;

    std::cout << "Початкові значення:\n";
    std::cout << "a = " << a << ", адреса: " << ptrA << "\n";
    std::cout << "b = " << b << ", адреса: " << ptrB << "\n";

    double temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    std::cout << "\nЗначення після обміну:\n";
    std::cout << "a = " << a << ", адреса: " << ptrA << "\n";
    std::cout << "b = " << b << ", адреса: " << ptrB << "\n";

    return 0;
}