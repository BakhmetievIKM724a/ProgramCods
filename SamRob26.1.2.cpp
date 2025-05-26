#include <iostream>
#include <string>

template <typename T>
T findMax(T val1, T val2) {
    return (val1 > val2) ? val1 : val2;
}

int main() {

    int int1 = 15;
    int int2 = 7;
    std::cout << "Максимум из " << int1 << " и " << int2 << ": " << findMax(int1, int2) << std::endl; // 15

    int int3 = 20;
    int int4 = 30;
    std::cout << "Максимум из " << int3 << " и " << int4 << ": " << findMax(int3, int4) << std::endl; // 30

    std::cout << std::endl;

    double double1 = 3.14;
    double double2 = 2.71;
    std::cout << "Максимум из " << double1 << " и " << double2 << ": " << findMax(double1, double2) << std::endl; // 3.14

    double double3 = 10.5;
    double double4 = 10.51;
    std::cout << "Максимум из " << double3 << " и " << double4 << ": " << findMax(double3, double4) << std::endl; // 10.51

    std::cout << std::endl;

    char char1 = 'X';
    char char2 = 'A';
    std::cout << "Максимум из '" << char1 << "' и '" << char2 << "': " << findMax(char1, char2) << std::endl; // X

    std::cout << std::endl;

    std::string str1 = "apple";
    std::string str2 = "banana";
    std::cout << "Максимум из \"" << str1 << "\" и \"" << str2 << "\": " << findMax(str1, str2) << std::endl; // banana

    std::string str3 = "zebra";
    std::string str4 = "cat";
    std::cout << "Максимум из \"" << str3 << "\" и \"" << str4 << "\": " << findMax(str3, str4) << std::endl; // zebra

    return 0;
}