#include <iostream>
#include <cmath>
#include "windows.h"
#include <limits>
using namespace std;

void fillPowerOfTwoArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = pow(2, i);
    }
}

int interpolationSearch(const int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            return (arr[low] == target) ? low : -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        if (pos < low || pos > high) {
            return -1;
        }

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int array_size = 25;
    int powerOfTwoArray[array_size];

    fillPowerOfTwoArray(powerOfTwoArray, array_size);

    cout << "Масив ступенів двійки на " << array_size << " елементів:" << endl;
    for (int i = 0; i < array_size; ++i) {
        cout << powerOfTwoArray[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Введіть число для пошуку: ";
    cin >> target;

    int index = interpolationSearch(powerOfTwoArray, array_size, target);

    if (index != -1) {
        cout << "Число " << target << " знайдено за індексом: " << index << endl;
    } else {
        cout << "Число " << target << " не знайдено в масиві." << endl;
    }

    return 0;
}