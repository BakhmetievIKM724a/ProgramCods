#include <iostream>

int main() {
    int *ptr1;
    int *ptr2;

    ptr1 = new int;
    ptr2 = new int;

    if (ptr1 == nullptr || ptr2 == nullptr) {
        std::cerr << "Помилка виділення динамічної пам'яті!" << std::endl;
        return 1;
    }
    *ptr1 = 10;
    *ptr2 = 25;

    std::cout << "Значення до обміну:" << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << std::endl;
    std::cout << "*ptr2 = " << *ptr2 << std::endl;

    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    std::cout << "\nЗначення після обміну:" << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << std::endl;
    std::cout << "*ptr2 = " << *ptr2 << std::endl;

    delete ptr1;
    delete ptr2;
    ptr1 = nullptr;
    ptr2 = nullptr;

    return 0;
}