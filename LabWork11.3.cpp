#include <iostream>
#include <cstdlib>
using namespace std;
#include "windows.h"

int main() {
    int n;
    cout << "Введіть розмір масивів: ";
    cin >> n;

    int *p = new int[n];
    int *q = new int[n];

    for (int i = 0; i < n; i++) {
        p[i] = rand() % 11 - 5;
        q[i] = rand() % 11 - 5;
    }

    cout << "Масив p: ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    cout << "Масив q: ";
    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;

    int countP = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            countP++;
        }
    }

    int countQ = 0;
    for (int i = 0; i < n; i++) {
        if (q[i] == 0) {
            countQ++;
        }
    }

    cout << "Кількість нульових елементів у масиві p: " << countP << endl;
    cout << "Кількість нульових елементів у масиві q: " << countQ << endl;

    if (countP > countQ) {
        cout << "У масиві p більше нульових елементів." << endl;
    } else if (countQ > countP) {
        cout << "У масиві q більше нульових елементів." << endl;
    } else {
        cout << "Кількість нульових елементів у масивах p і q однакова." << endl;
    }

    delete[] p;
    delete[] q;

    return 0;
}