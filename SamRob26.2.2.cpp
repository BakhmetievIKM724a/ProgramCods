#include <iostream>
#include <stdlib.h>

int main() {
    int* dynamicArray = NULL;
    int capacity = 0;
    int size = 0;

    int numElementsToAdd;

    std::cout << "Введите количество целых чисел, которые вы хотите добавить: ";
    if (!(std::cin >> numElementsToAdd) || numElementsToAdd < 0) {
        std::cerr << "Некорректный ввод. Пожалуйста, введите положительное целое число." << std::endl;
        return 1;
    }

    for (int i = 0; i < numElementsToAdd; ++i) {
        int newValue;
        std::cout << "Введите целое число #" << i + 1 << ": ";
        if (!(std::cin >> newValue)) {
            std::cerr << "Некорректный ввод. Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            --i;
            continue;
        }


        if (size == capacity) {

            capacity = (capacity == 0) ? 2 : capacity * 2;
            int* newArray = (int*)realloc(dynamicArray, capacity * sizeof(int));
            if (newArray == NULL) {
                std::cerr << "Ошибка: не удалось выделить память для нового элемента!" << std::endl;
                free(dynamicArray);
                return 1;
            }
            dynamicArray = newArray;
            std::cout << "Вместимость массива увеличена до: " << capacity << std::endl;
        }

        dynamicArray[size] = newValue;
        size++;
    }

    if (size > 0) {
        std::cout << "\nЭлементы в вашем векторе (динамическом массиве):" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << "Элемент " << i + 1 << ": " << dynamicArray[i] << std::endl;
        }
    } else {
        std::cout << "\nВектор пуст." << std::endl;
    }

    free(dynamicArray);
    dynamicArray = NULL;

    return 0;
}