#include <iostream>
#include <string>

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    // Конструктор
    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }

    ~TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (children[i] != NULL) {
                delete children[i];
            }
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:

    Trie() {
        root = new TrieNode();
    }


    ~Trie() {
        delete root;
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (size_t i = 0; i < word.length(); ++i) {
            char ch = word[i];
            int index = ch - 'a';

            if (index < 0 || index >= ALPHABET_SIZE) {
                std::cout << "Помилка: символ '" << ch << "' не підтримується алфавітом." << std::endl;
                return;
            }

            if (current->children[index] == NULL) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) const {
        TrieNode* current = root;
        for (size_t i = 0; i < word.length(); ++i) {
            char ch = word[i];
            int index = ch - 'a';

            if (index < 0 || index >= ALPHABET_SIZE) {
                return false;
            }

            if (current->children[index] == NULL) {
                return false;
            }
            current = current->children[index];
        }
        return current != NULL && current->isEndOfWord;
    }

    bool starts_with(const std::string& prefix) const {
        TrieNode* current = root;
        for (size_t i = 0; i < prefix.length(); ++i) {
            char ch = prefix[i];
            int index = ch - 'a';

            if (index < 0 || index >= ALPHABET_SIZE) {
                return false;
            }

            if (current->children[index] == NULL) {
                return false; // Шлях не існує
            }
            current = current->children[index];
        }
        return true;
    }
};

int main() {

    Trie trie;

    std::cout << "Вставляємо слова: " << std::endl;
    trie.insert("apple");
    std::cout << " - apple" << std::endl;
    trie.insert("apricot");
    std::cout << " - apricot" << std::endl;
    trie.insert("apply");
    std::cout << " - apply" << std::endl;
    trie.insert("banana");
    std::cout << " - banana" << std::endl;
    std::cout << std::endl;

    std::cout << "Тестуємо метод search():" << std::endl;
    std::cout << "Пошук 'apple': " << (trie.search("apple") ? "Знайдено" : "Не знайдено") << std::endl;
    std::cout << "Пошук 'app': " << (trie.search("app") ? "Знайдено" : "Не знайдено") << std::endl; // 'app' не є повним словом
    std::cout << "Пошук 'apricot': " << (trie.search("apricot") ? "Знайдено" : "Не знайдено") << std::endl;
    std::cout << "Пошук 'bandana': " << (trie.search("bandana") ? "Знайдено" : "Не знайдено") << std::endl;
    std::cout << "Пошук 'banana': " << (trie.search("banana") ? "Знайдено" : "Не знайдено") << std::endl;
    std::cout << std::endl;

    std::cout << "Тестуємо метод starts_with():" << std::endl;
    std::cout << "Починається з 'app': " << (trie.starts_with("app") ? "Так" : "Ні") << std::endl;
    std::cout << "Починається з 'appl': " << (trie.starts_with("appl") ? "Так" : "Ні") << std::endl;
    std::cout << "Починається з 'ban': " << (trie.starts_with("ban") ? "Так" : "Ні") << std::endl;
    std::cout << "Починається з 'grape': " << (trie.starts_with("grape") ? "Так" : "Ні") << std::endl;
    std::cout << std::endl;

    return 0;
}