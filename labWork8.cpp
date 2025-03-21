#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> numbers(20);
    std::cout << "Введіть 20 дійсних чисел:" << std::endl;
    for (int i = 0; i < 20; ++i) {
        std::cin >> numbers[i];
    }
    double maxElement = numbers[0];
    double minElement = numbers[0];
    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 1; i < 20; ++i) {
        if (numbers[i] > maxElement) {
            maxElement = numbers[i];
            maxIndex = i;
        }
        if (numbers[i] < minElement) {
            minElement = numbers[i];
            minIndex = i;
        }
    }
    std::swap(numbers[maxIndex], numbers[minIndex]);
    std::cout << "Масив після заміни:" << std::endl;
    for (int i = 0; i < 20; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}