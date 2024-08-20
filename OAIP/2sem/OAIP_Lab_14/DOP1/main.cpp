#include <iostream>
#include <list>
#include <string>

using namespace std;

// Структура узла списка
struct Node {
    char key;
    int count;
    Node* next;
};

// Структура хеш-таблицы
struct HashTable {
    list<Node*>* table;
    int size;

    // Хеш-функция
    int hashFunction(char key) {
        return key % size;
    }

    // Вставка узла в список цепочек
    void insert(char key) {
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
    Node* search(char key) {
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
    void incrementCount(char key) {
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
    // Размер хеш-таблицы
    const int SIZE = 10;

    // Создание хеш-таблицы
    HashTable ht;
    ht.size = SIZE;
    ht.table = new list<Node*>[SIZE];

    // Ввод строки
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    // Построение хеш-таблицы
    for (char c : input) {
        ht.insert(c);
    }

    // Печать хеш-таблицы
    cout << "Хеш-таблица:" << endl;
    ht.print();

    // Ввод буквы для поиска
    char searchKey;
    cout << "Введите букву для поиска: ";
    cin >> searchKey;

    // Поиск буквы в хеш-таблице
    Node* node = ht.search(searchKey);
    if (node != NULL) {
        cout << "Буква '" << searchKey << "' найдена, количество вхождений: " << node->count << endl;
    }
    else {
        cout << "Буква '" << searchKey << "' не найдена." << endl;
    }

    return 0;
}
