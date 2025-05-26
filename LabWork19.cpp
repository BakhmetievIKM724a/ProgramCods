#include <iostream>
#include <string>

template <typename T>
void printArray(T* arr, int size) {
    if (arr == NULL || size <= 0) {
        std::cout << "Массив пуст или некорректен." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void insertionSort(T* arr, int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    int intArray[] = {12, 11, 13, 5, 6};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Исходный целочисленный массив: ";
    printArray(intArray, intArraySize);

    insertionSort(intArray, intArraySize);

    std::cout << "Отсортированный целочисленный массив: ";
    printArray(intArray, intArraySize);

    std::cout << std::endl;

    double doubleArray[] = {3.14, 1.618, 2.718, 0.5};
    int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Исходный массив чисел с плавающей запятой: ";
    printArray(doubleArray, doubleArraySize);

    insertionSort(doubleArray, doubleArraySize);

    std::cout << "Отсортированный массив чисел с плавающей запятой: ";
    printArray(doubleArray, doubleArraySize);

    std::cout << std::endl;

    std::string stringArray[] = {"banana", "apple", "cherry", "date"};
    int stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Исходный строковый массив: ";
    printArray(stringArray, stringArraySize);

    insertionSort(stringArray, stringArraySize);

    std::cout << "Отсортированный строковый массив: ";
    printArray(stringArray, stringArraySize);

    return 0;
}