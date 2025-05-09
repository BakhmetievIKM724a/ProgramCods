#include <iostream>
#include <cmath>

using namespace std;

double calculateNthTerm(int n) {
    if (n == 1) {
        return 20;
    } else if (n == 2) {
        return 10;
    } else if (n == 3) {
        return 5;
    } else if (n > 3) {
        return 5.0 / pow(2, n - 3);
    } else {
        cerr << "Некоректний індекс n. Індекс повинен бути більшим або рівним 1." << endl;
        return NAN;
    }
}

int main() {
    int n;

    cout << "Введіть номер члена ряду (n >= 1): ";
    cin >> n;

    double nthTerm = calculateNthTerm(n);

    if (!isnan(nthTerm)) {
        cout << n << "-й член ряду: " << nthTerm << endl;
    }

    return 0;
}