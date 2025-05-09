#include <iostream>
#include <cmath>
#include "windows.h"
using namespace std;

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int array_size = 20;
    double a[array_size];

    cout << "Введіть " << array_size << " дійсних чисел для масиву a:" << endl;
    for (int i = 0; i < array_size; i++) {
        cin >> a[i];
    }

    cout << "Створений масив a:" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int low = 0;
    int high = array_size - 1;

    while (low < high) {
        while (low < high && floor(a[low]) <= 1) {
            low++;
        }
        while (low < high && floor(a[high]) > 1) {
            high--;
        }
        if (low < high) {
            swap(a[low], a[high]);
            low++;
            high--;
        }
    }

    cout << "Масив a після перетворення:" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < array_size - 1; i++) {
        for (int j = 0; j < array_size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    cout << "Відсортований масив a:" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}