#include <iostream>
#include "windows.h"

const int MATRIX_SIZE = 8;

class Matrix {
private:
    int data[MATRIX_SIZE];

public:

    Matrix() {
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            data[i] = 0;
        }
    }

    Matrix(int arr[MATRIX_SIZE]) {
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            data[i] = arr[i];
        }
    }

    void print() const {
        std::cout << "[";
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            std::cout << data[i];
            if (i < MATRIX_SIZE - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    Matrix operator==(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            if (this->data[i] == other.data[i]) {
                result.data[i] = 1;
            } else {
                result.data[i] = 0;
            }
        }
        return result;
    }

    bool areEqual(const Matrix& other) const {
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            if (this->data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr1[MATRIX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[MATRIX_SIZE] = {8, 7, 6, 5, 4, 3, 2, 1};

    Matrix matrix1(arr1);
    Matrix matrix2(arr2);

    std::cout << "Матриця 1: ";
    matrix1.print();
    std::cout << "Матриця 2: ";
    matrix2.print();
    std::cout << std::endl;

    std::cout << "Результат додавання (Матриця 1 + Матриця 2):" << std::endl;
    Matrix sum_matrix = matrix1 + matrix2;
    sum_matrix.print();
    std::cout << std::endl;

    std::cout << "Результат віднімання (Матриця 1 - Матриця 2):" << std::endl;
    Matrix diff_matrix = matrix1 - matrix2;
    diff_matrix.print();
    std::cout << std::endl;

    std::cout << "Результат порівняння (Матриця 1 == Матриця 2) (елемент за елементом):" << std::endl;
    std::cout << "(1 якщо елементи рівні, 0 якщо ні)" << std::endl;
    Matrix comparison_result = matrix1 == matrix2;
    comparison_result.print();
    std::cout << std::endl;

    int arr3[MATRIX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    Matrix matrix3(arr3);
    std::cout << "Матриця 3: ";
    matrix3.print();
    std::cout << "Результат порівняння (Матриця 1 == Матриця 3) (елемент за елементом):" << std::endl;
    Matrix comparison_result2 = matrix1 == matrix3;
    comparison_result2.print();
    std::cout << std::endl;

    std::cout << "Порівняння Матриця 1 і Матриця 2 як цілих об'єктів (через areEqual()): ";
    if (matrix1.areEqual(matrix2)) {
        std::cout << "Матриці рівні." << std::endl;
    } else {
        std::cout << "Матриці не рівні." << std::endl;
    }

    std::cout << "Порівняння Матриця 1 і Матриця 3 як цілих об'єктів (через areEqual()): ";
    if (matrix1.areEqual(matrix3)) {
        std::cout << "Матриці рівні." << std::endl;
    } else {
        std::cout << "Матриці не рівні." << std::endl;
    }

    return 0;
}