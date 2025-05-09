#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;


struct WordInfo {
    string word;
    int pageNumbers[10];
    int pageCount;

    WordInfo() : pageCount(0) {
        for (int i = 0; i < 10; ++i) {
            pageNumbers[i] = 0;
        }
    }
};

void addPageNumber(WordInfo& wordInfo, int pageNumber) {
    bool found = false;
    for (int i = 0; i < wordInfo.pageCount; ++i) {
        if (wordInfo.pageNumbers[i] == pageNumber) {
            found = true;
            break;
        }
    }
    if (!found && wordInfo.pageCount < 10 && pageNumber >= 1 && pageNumber <= 10) {
        wordInfo.pageNumbers[wordInfo.pageCount++] = pageNumber;
    }
}

void printWordsMoreThanNPages(WordInfo arr[], int size, int n) {
    cout << "Слова, які зустрічаються більш ніж на " << n << " сторінках:" << endl;
    for (int i = 0; i < size; ++i) {
        if (arr[i].pageCount > n) {
            cout << arr[i].word << " (" << arr[i].pageCount << " сторінок)" << endl;
        }
    }
    cout << endl;
}
bool compareWords(const WordInfo& a, const WordInfo& b) {
    return a.word < b.word;
}

void printWordsAlphabeticalOrder(WordInfo arr[], int size) {
    sort(arr, arr + size, compareWords);
    cout << "Слова в алфавітному порядку:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i].word << endl;
    }
    cout << endl;
}

void printPagesForWord(WordInfo arr[], int size, const string& searchWord) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].word == searchWord) {
            cout << "Слово \"" << searchWord << "\" зустрічається на сторінках: ";
            for (int j = 0; j < arr[i].pageCount; ++j) {
                cout << arr[i].pageNumbers[j] << (j == arr[i].pageCount - 1 ? "" : ", ");
            }
            cout << endl;
            return;
        }
    }
    cout << "Слово \"" << searchWord << "\" не знайдено." << endl;
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int arraySize = 5;
    WordInfo words[arraySize];

    words[0].word = "яблуко";
    addPageNumber(words[0], 1);
    addPageNumber(words[0], 3);
    addPageNumber(words[0], 5);

    words[1].word = "банан";
    addPageNumber(words[1], 2);
    addPageNumber(words[1], 4);
    addPageNumber(words[1], 6);
    addPageNumber(words[1], 8);

    words[2].word = "вишня";
    addPageNumber(words[2], 1);
    addPageNumber(words[2], 7);

    words[3].word = "груша";
    addPageNumber(words[3], 3);
    addPageNumber(words[3], 5);
    addPageNumber(words[3], 9);
    addPageNumber(words[3], 10);

    words[4].word = "абрикос";
    addPageNumber(words[4], 2);

    // a) Виведення слів, які зустрічаються більш ніж на N сторінках
    int n;
    cout << "Введіть N (кількість сторінок): ";
    cin >> n;
    printWordsMoreThanNPages(words, arraySize, n);

    // б) Виведення слів в алфавітному порядку
    printWordsAlphabeticalOrder(words, arraySize);

    // в) Виведення номерів сторінок для заданого слова
    string searchWord;
    cout << "Введіть слово для пошуку сторінок: ";
    cin >> searchWord;
    printPagesForWord(words, arraySize, searchWord);

    return 0;
}