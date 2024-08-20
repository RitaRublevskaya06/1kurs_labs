#include <iostream>
#include <fstream>
#include <list>

using namespace std;

// Структура узла списка
struct Node {
    string word;
    int count;
    Node* next;
};

// Структура хеш-таблицы
struct HashTable {
    list<Node*>* table;
    int size;

    // Хеш-функция
    int hashFunction(string key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue += (int)c;
        }
        return hashValue % size;
    }

    // Вставка узла в список цепочек
    void insert(string key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->word = key;
        newNode->count = 1;
        newNode->next = NULL;

        // Если список цепочек пуст, добавить узел
        if (table[index].empty()) {
            table[index].push_back(newNode);
        }
        // Иначе, перебрать список и вставить узел в конец
        else {
            Node* curr = table[index].back();
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Поиск узла в списке цепочек
    Node* search(string key) {
        int index = hashFunction(key);
        Node* curr = table[index].front();

        while (curr != NULL) {
            if (curr->word == key) {
                return curr;
            }
            curr = curr->next;
        }

        // Узел не найден
        return NULL;
    }

    // Увеличение счетчика элемента
    void incrementCount(string key) {
        Node* node = search(key);
        if (node != NULL) {
            node->count++;
        }
    }

    // Печать хеш-таблицы
    void print() {
        for (int i = 0; i < size; i++) {
            cout << "Индекс " << i << ": ";
            for (Node* curr : table[i]) {
                cout << "(" << curr->word << ", " << curr->count << ") ";
            }
            cout << endl;
        }
    }

    // Удаление всех слов, начинающихся с указанной буквы
    void deleteByPrefix(char prefix) {
        for (int i = 0; i < size; i++) {
            Node* curr = table[i].front();
            Node* prev = NULL;

            while (curr != NULL) {
                if (curr->word[0] == prefix) {
                    // Удалить узел
                    if (prev == NULL) {
                        table[i].pop_front();
                    }
                    else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    curr = prev->next;
                }
                else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }
};

int main() {
    // Ввод размера хеш-таблицы
    int size;
    cout << "Введите размерность хеш-таблицы: ";
    cin >> size;

    // Создание хеш-таблицы
    HashTable ht;
    ht.size = size;
    ht.table = new list<Node*>[size];

    // Считывание слов из файла
    string filename;
    cout << "Введите имя текстового файла: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Файл не может быть открыт!" << endl;
        return 1;
    }

    string word;
    while (infile >> word) {
        ht.insert(word);
    }
    infile.close();

    // Печать хеш-таблицы
    cout << "Хеш-таблица из слов файла:" << endl;
    ht.print();

    // Ввод слова для поиска
    string searchWord;
    cout << "Введите слово для поиска: ";
    cin >> searchWord;

    // Поиск слова в хеш-таблице
    Node* node = ht.search(searchWord);
    if (node != NULL) {
        cout << "Слово '" << searchWord << "' найдено, количество вхождений: " << node->count << endl;
    }
    else {
        cout << "Слово '" << searchWord << "' не найдено." << endl;
    }

    // Удаление всех слов, начинающихся с указанной буквы
    char prefix;
    cout << "Введите букву, с которой начинаются слова для удаления: ";
    cin >> prefix;

    ht.deleteByPrefix(prefix);

    // Печать обновленной хеш-таблицы
    cout << "Хеш-таблица после удаления слов, начинающихся с '" << prefix << "':" << endl;
    ht.print();

    return 0;
}