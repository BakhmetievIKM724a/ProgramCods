#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 0, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 0},
        {16, 17, 18, 19, 20}
    };

    vector<int> counts;
    for (const auto& row : matrix) {
        bool hasZero = false;
        for (int num : row) {
            if (num == 0) {
                hasZero = true;
                break;
            }
        }

        if (hasZero) {
            int count = 0;
            for (int num : row) {
                if (num % 5 == 0) {
                    count++;
                }
            }
            counts.push_back(count);
        } else {
            counts.push_back(0);
        }
    }

    cout << "Кількість елементів, кратних 5, в рядках:" << endl;
    for (int count : counts) {
        cout << count << " ";
    }
    cout << endl;

    vector<double> averages;
    for (const auto& row : matrix) {
        double sum = accumulate(row.begin(), row.end(), 0.0);
        averages.push_back(sum / row.size());
    }

    cout << "Середні арифметичні елементів рядків:" << endl;
    for (double avg : averages) {
        cout << avg << " ";
    }
    cout << endl;

    return 0;
}