#include <iostream>
#include <stdlib.h>

int main() {
    int* dynamicArray = NULL;
    int capacity = 0;
    int size = 0;

    for (int i = 0; i < 5; ++i) {
        int newValue = (i + 1) * 10;

        if (size == capacity) {

            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* newArray = (int*)realloc(dynamicArray, capacity * sizeof(int));
            if (newArray == NULL) {
                std::cerr << "Ошибка: не удалось выделить память!" << std::endl;
                return 1;
            }
            dynamicArray = newArray;
        }

        dynamicArray[size] = newValue;
        size++;
    }

    int newValue1 = 60;
    if (size == capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        int* newArray = (int*)realloc(dynamicArray, capacity * sizeof(int));
        if (newArray == NULL) {
            std::cerr << "Ошибка: не удалось выделить память!" << std::endl;
            return 1;
        }
        dynamicArray = newArray;
    }
    dynamicArray[size] = newValue1;
    size++;

    int newValue2 = 70;
    if (size == capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        int* newArray = (int*)realloc(dynamicArray, capacity * sizeof(int));
        if (newArray == NULL) {
            std::cerr << "Ошибка: не удалось выделить память!" << std::endl;
            return 1;
        }
        dynamicArray = newArray;
    }
    dynamicArray[size] = newValue2;
    size++;

    std::cout << "Элементы вектора (динамического массива):" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Элемент " << i << ": " << dynamicArray[i] << std::endl;
    }

    free(dynamicArray);
    dynamicArray = NULL;

    return 0;
}