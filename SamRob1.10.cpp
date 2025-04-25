#include "windows.h"
#include <iostream>
#include <cmath>
using namespace std;

// 1. Функція, яка приймає два цілих числа і повертає їхню суму.
int sum(int a, int b) {
    return a + b;
}

// 2. Функція, яка обчислює факторіал заданого цілого числа і повертає результат.
long long factorial(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// 3. Функція, яка приймає рядок і повертає його довжину.
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 4. Функція для перевірки, чи є задане ціле число простим.
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 5. Функція, яка приймає масив цілих чисел і повертає суму всіх елементів.
int arraySum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// 6. Функція для перевертання рядка задом наперед.
void reverseString(char* str) {
    int start = 0;
    int end = stringLength(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 7. Функція, яка приймає масив і його розмір, а потім сортує масив за зростанням (бульбашкове сортування).
void sortArrayAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 8. Функція, яка приймає два масиви цілих чисел та повертає новий масив,
//    який містить елементи, що є спільними для обох масивів.
int* findCommonElements(const int arr1[], int size1, const int arr2[], int size2, int& commonSize) {
    int maxSize = (size1 < size2) ? size1 : size2;
    int* commonArr = new int[maxSize];
    commonSize = 0;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {
                bool found = false;
                for (int k = 0; k < commonSize; ++k) {
                    if (commonArr[k] == arr1[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    commonArr[commonSize++] = arr1[i];
                }
            }
        }
    }
    return commonArr;
}

// 9. Функція, яка приймає довжину сторін прямокутника та повертає його площу.
double rectangleArea(double length, double width) {
    double area = length * width;
    return area;
}