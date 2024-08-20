#include <iostream>
#include <list>
#include <string>

using namespace std;

// ��������� ���� ������
struct Node {
    char key;
    int count;
    Node* next;
};

// ��������� ���-�������
struct HashTable {
    list<Node*>* table;
    int size;

    // ���-�������
    int hashFunction(char key) {
        return key % size;
    }

    // ������� ���� � ������ �������
    void insert(char key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->key = key;
        newNode->count = 1;
        newNode->next = NULL;

        // ���� ������ ������� ����, �������� ����
        if (table[index].empty()) {
            table[index].push_back(newNode);
        }
        // �����, ��������� ������ � �������� ���� � �����
        else {
            Node* curr = table[index].back();
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // ����� ���� � ������ �������
    Node* search(char key) {
        int index = hashFunction(key);
        Node* curr = table[index].front();

        while (curr != NULL) {
            if (curr->key == key) {
                return curr;
            }
            curr = curr->next;
        }

        // ���� �� ������
        return NULL;
    }

    // ���������� �������� ��������
    void incrementCount(char key) {
        Node* node = search(key);
        if (node != NULL) {
            node->count++;
        }
    }

    // ������ ���-�������
    void print() {
        for (int i = 0; i < size; i++) {
            cout << "������ " << i << ": ";
            for (Node* curr : table[i]) {
                cout << "(" << curr->key << ", " << curr->count << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // ������ ���-�������
    const int SIZE = 10;

    // �������� ���-�������
    HashTable ht;
    ht.size = SIZE;
    ht.table = new list<Node*>[SIZE];

    // ���� ������
    string input;
    cout << "������� ������: ";
    getline(cin, input);

    // ���������� ���-�������
    for (char c : input) {
        ht.insert(c);
    }

    // ������ ���-�������
    cout << "���-�������:" << endl;
    ht.print();

    // ���� ����� ��� ������
    char searchKey;
    cout << "������� ����� ��� ������: ";
    cin >> searchKey;

    // ����� ����� � ���-�������
    Node* node = ht.search(searchKey);
    if (node != NULL) {
        cout << "����� '" << searchKey << "' �������, ���������� ���������: " << node->count << endl;
    }
    else {
        cout << "����� '" << searchKey << "' �� �������." << endl;
    }

    return 0;
}
