#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "windows.h"

using namespace std;

class HexCounter {
private:
    int value;
    int minVal;
    int maxVal;

    string toHex(int n) const {
        string hexString = "";
        while (n > 0) {
            int remainder = n % 16;
            char hexDigit;
            if (remainder < 10) {
                hexDigit = remainder + '0';
            } else {
                hexDigit = remainder - 10 + 'A';
            }
            hexString = hexDigit + hexString;
            n /= 16;
        }
        return hexString.empty() ? "0" : hexString;
    }

    int fromHex(const string& hexStr) const {
        int decimalValue = 0;
        int power = 1;
        for (int i = hexStr.length() - 1; i >= 0; i--) {
            char hexDigit = toupper(hexStr[i]);
            int digitValue;
            if (hexDigit >= '0' && hexDigit <= '9') {
                digitValue = hexDigit - '0';
            } else if (hexDigit >= 'A' && hexDigit <= 'F') {
                digitValue = hexDigit - 'A' + 10;
            } else {
                return -1;
            }
            decimalValue += digitValue * power;
            power *= 16;
        }
        return decimalValue;
    }

public:
    HexCounter(int min = 0, int max = 255) : value(min), minVal(min), maxVal(max) {
        if (min > max) {
            swap(minVal, maxVal);
            value = minVal;
        }
    }

    HexCounter(int start, int min, int max) : minVal(min), maxVal(max) {
        if (min > max) {
            swap(minVal, maxVal);
        }
        value = (start >= minVal && start <= maxVal) ? start : minVal;
    }

    void increment() {
        if (value < maxVal) {
            value++;
        }
    }

    void decrement() {
        if (value > minVal) {
            value--;
        }
    }

    string getValueHex() const {
        return toHex(value);
    }

    int getValueDec() const {
        return value;
    }
};

class FlexibleHexCounter : public HexCounter {
public:
    FlexibleHexCounter(int min = 0, int max = 255) : HexCounter(min, max) {}

    FlexibleHexCounter(int start, int min, int max) : HexCounter(start, min, max) {}

    void incrementBy(int step) {
        if (step > 0 && (getValueDec() + step <= getMaxVal())) {
            setValueDec(getValueDec() + step);
        }
    }

    void decrementBy(int step) {
        if (step > 0 && (getValueDec() - step >= getMinVal())) {
            setValueDec(getValueDec() - step);
        }
    }

private:
    void setValueDec(int newValue) {
        if (newValue >= getMinVal() && newValue <= getMaxVal()) {
            value = newValue;
        }
    }

    int getMinVal() const {
        return minVal;
    }

    int getMaxVal() const {
        return maxVal;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Демонстрація класу HexCounter
    cout << "Демонстрація класу HexCounter:" << endl;
    HexCounter counter1; // Лічильник за замовчуванням (0-255)
    cout << "Лічильник 1 (початкове значення): 0x" << counter1.getValueHex() << " (dec: " << counter1.getValueDec() << ")" << endl;
    counter1.increment();
    cout << "Лічильник 1 (після збільшення): 0x" << counter1.getValueHex() << " (dec: " << counter1.getValueDec() << ")" << endl;
    counter1.increment();
    cout << "Лічильник 1 (після збільшення): 0x" << counter1.getValueHex() << " (dec: " << counter1.getValueDec() << ")" << endl;
    counter1.decrement();
    cout << "Лічильник 1 (після зменшення): 0x" << counter1.getValueHex() << " (dec: " << counter1.getValueDec() << ")" << endl;

    HexCounter counter2(10, 5, 15); // Лічильник з довільним початковим значенням та діапазоном
    cout << "Лічильник 2 (початкове значення): 0x" << counter2.getValueHex() << " (dec: " << counter2.getValueDec() << ")" << endl;
    counter2.decrement();
    cout << "Лічильник 2 (після зменшення): 0x" << counter2.getValueHex() << " (dec: " << counter2.getValueDec() << ")" << endl;
    counter2.increment();
    counter2.increment();
    counter2.increment();
    cout << "Лічильник 2 (після збільшення тричі): 0x" << counter2.getValueHex() << " (dec: " << counter2.getValueDec() << ")" << endl;

    HexCounter counter3(300, 0, 255); // Початкове значення поза діапазоном
    cout << "Лічильник 3 (початкове значення поза діапазоном): 0x" << counter3.getValueHex() << " (dec: " << counter3.getValueDec() << ")" << endl;

    cout << endl;


    cout << "Демонстрація дочірнього класу FlexibleHexCounter:" << endl;
    FlexibleHexCounter flexCounter1; // Лічильник за замовчуванням (0-255)
    cout << "Гнучкий лічильник 1 (початкове значення): 0x" << flexCounter1.getValueHex() << " (dec: " << flexCounter1.getValueDec() << ")" << endl;
    flexCounter1.incrementBy(5);
    cout << "Гнучкий лічильник 1 (після збільшення на 5): 0x" << flexCounter1.getValueHex() << " (dec: " << flexCounter1.getValueDec() << ")" << endl;
    flexCounter1.decrementBy(2);
    cout << "Гнучкий лічильник 1 (після зменшення на 2): 0x" << flexCounter1.getValueHex() << " (dec: " << flexCounter1.getValueDec() << ")" << endl;

    FlexibleHexCounter flexCounter2(50, 20, 100);
    cout << "Гнучкий лічильник 2 (початкове значення): 0x" << flexCounter2.getValueHex() << " (dec: " << flexCounter2.getValueDec() << ")" << endl;
    flexCounter2.incrementBy(20);
    cout << "Гнучкий лічильник 2 (після збільшення на 20): 0x" << flexCounter2.getValueHex() << " (dec: " << flexCounter2.getValueDec() << ")" << endl;
    flexCounter2.decrementBy(60);
    cout << "Гнучкий лічильник 2 (після зменшення на 60): 0x" << flexCounter2.getValueHex() << " (dec: " << flexCounter2.getValueDec() << ")" << endl;
    flexCounter2.decrementBy(1); // Спроба вийти за нижню межу
    cout << "Гнучкий лічильник 2 (спроба зменшення за межу): 0x" << flexCounter2.getValueHex() << " (dec: " << flexCounter2.getValueDec() << ")" << endl;

    return 0;
}