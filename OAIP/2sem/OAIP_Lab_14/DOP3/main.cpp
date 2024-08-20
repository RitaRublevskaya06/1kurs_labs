#include <iostream>
#include <fstream>
#include <list>

using namespace std;

// Структура узла списка
struct Node {
    int key;
    int count;
    Node* next;
};

// Структура хеш-таблицы
struct HashTable {
    list<Node*>* table;
    int size;

    // Хеш-функция
    int hashFunction(int key) {
        return key % size;
    }

    // Вставка узла в список цепочек
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->key = key;
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
    Node* search(int key) {
        int index = hashFunction(key);
        Node* curr = table[index].front();

        while (curr != NULL) {
            if (curr->key == key) {
                return curr;
            }
            curr = curr->next;
        }

        // Узел не найден
        return NULL;
    }

    // Увеличение счетчика элемента
    void incrementCount(int key) {
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
                cout << "(" << curr->key << ", " << curr->count << ") ";
            }
            cout << endl;
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

    // Считывание чисел из файла
    string filename;
    cout << "Введите имя текстового файла: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Файл не может быть открыт!" << endl;
        return 1;
    }

    int number;
    while (infile >> number) {
        ht.insert(number);
    }
    infile.close();

    // Печать хеш-таблицы
    cout << "Хеш-таблица из чисел файла:" << endl;
    ht.print();

    // Ввод целого числа для поиска
    int searchNumber;
    cout << "Введите целое число для поиска: ";
    cin >> searchNumber;

    // Поиск целого числа в хеш-таблице
    Node* node = ht.search(searchNumber);
    if (node != NULL) {
        cout << "Число " << searchNumber << " найдено, количество вхождений: " << node->count << endl;
    }
    else {
        cout << "Число " << searchNumber << " не найдено." << endl;
    }

    return 0;
}
