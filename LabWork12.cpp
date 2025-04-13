#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

void reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {

        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Введіть ціле число n: ";
    cin >> n;

    vector<int> divisorsArray = findDivisors(n);

    cout << "Масив дільників числа " << n << ": ";
    for (int divisor : divisorsArray) {
        cout << divisor << " ";
    }
    cout << endl;

    reverseArray(divisorsArray);

    cout << "Масив дільників у зворотному порядку: ";
    for (int divisor : divisorsArray) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}