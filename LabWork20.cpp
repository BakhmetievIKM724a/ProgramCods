#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {

    std::vector<double> numbers(20);

    srand(time(NULL));

    std::cout << "Исходный вектор:" << std::endl;
    for (int i = 0; i < numbers.size(); ++i) {

        numbers[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
        std::cout << numbers[i] << " ";
        if ((i + 1) % 5 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    auto minIt = std::min_element(numbers.begin(), numbers.end());
    auto maxIt = std::max_element(numbers.begin(), numbers.end());

    if (minIt != numbers.end() && maxIt != numbers.end()) {
        std::swap(*minIt, *maxIt);
        std::cout << "Вектор после обмена минимального и максимального элементов:" << std::endl;
        for (int i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
            if ((i + 1) % 5 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "Вектор пуст, обмен невозможен." << std::endl;
    }

    double sumOfAbsAfterFirstZero = 0.0;
    bool foundFirstZero = false;
    int firstZeroIndex = -1;

    for (int i = 0; i < numbers.size(); ++i) {

        if (numbers[i] == 0.0) {
            firstZeroIndex = i;
            foundFirstZero = true;
            break;
        }
    }

    if (foundFirstZero) {
        for (int i = firstZeroIndex + 1; i < numbers.size(); ++i) {
            sumOfAbsAfterFirstZero += std::abs(numbers[i]);
        }
        std::cout << "Сумма модулей элементов после первого нуля: " << sumOfAbsAfterFirstZero << std::endl;
    } else {
        std::cout << "В векторе нет элементов, равных нулю. Сумма модулей не вычислялась." << std::endl;
    }

    return 0;
}