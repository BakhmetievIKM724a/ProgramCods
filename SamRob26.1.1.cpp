#include <iostream>
#include <string>

template <typename T>
bool areEqual(T val1, T val2) {
    return val1 == val2;
}

int main() {

    int int1 = 5;
    int int2 = 5;
    int int3 = 10;
    std::cout << "Сравнение целых чисел:" << std::endl;
    std::cout << int1 << " == " << int2 << "? " << (areEqual(int1, int2) ? "true" : "false") << std::endl; // true
    std::cout << int1 << " == " << int3 << "? " << (areEqual(int1, int3) ? "true" : "false") << std::endl; // false

    std::cout << std::endl;

    double double1 = 3.14;
    double double2 = 3.14;
    double double3 = 2.71;
    std::cout << "Сравнение чисел с плавающей запятой:" << std::endl;
    std::cout << double1 << " == " << double2 << "? " << (areEqual(double1, double2) ? "true" : "false") << std::endl; // true
    std::cout << double1 << " == " << double3 << "? " << (areEqual(double1, double3) ? "true" : "false") << std::endl; // false

    std::cout << std::endl;

    std::string str1 = "Hello";
    std::string str2 = "Hello";
    std::string str3 = "World";
    std::cout << "Сравнение строк:" << std::endl;
    std::cout << "\"" << str1 << "\" == \"" << str2 << "\"? " << (areEqual(str1, str2) ? "true" : "false") << std::endl; // true
    std::cout << "\"" << str1 << "\" == \"" << str3 << "\"? " << (areEqual(str1, str3) ? "true" : "false") << std::endl; // false

    std::cout << std::endl;

    char char1 = 'A';
    char char2 = 'A';
    char char3 = 'B';
    std::cout << "Сравнение символов:" << std::endl;
    std::cout << "'" << char1 << "' == '" << char2 << "'? " << (areEqual(char1, char2) ? "true" : "false") << std::endl; // true
    std::cout << "'" << char1 << "' == '" << char3 << "'? " << (areEqual(char1, char3) ? "true" : "false") << std::endl; // false

    return 0;
}