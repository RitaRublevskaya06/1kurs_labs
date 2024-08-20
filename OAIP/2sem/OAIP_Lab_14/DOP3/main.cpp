#include <iostream>
#include <fstream>
#include <list>

using namespace std;

// ��������� ���� ������
struct Node {
    int key;
    int count;
    Node* next;
};

// ��������� ���-�������
struct HashTable {
    list<Node*>* table;
    int size;

    // ���-�������
    int hashFunction(int key) {
        return key % size;
    }

    // ������� ���� � ������ �������
    void insert(int key) {
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
    Node* search(int key) {
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
    void incrementCount(int key) {
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
    // ���� ������� ���-�������
    int size;
    cout << "������� ����������� ���-�������: ";
    cin >> size;

    // �������� ���-�������
    HashTable ht;
    ht.size = size;
    ht.table = new list<Node*>[size];

    // ���������� ����� �� �����
    string filename;
    cout << "������� ��� ���������� �����: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "���� �� ����� ���� ������!" << endl;
        return 1;
    }

    int number;
    while (infile >> number) {
        ht.insert(number);
    }
    infile.close();

    // ������ ���-�������
    cout << "���-������� �� ����� �����:" << endl;
    ht.print();

    // ���� ������ ����� ��� ������
    int searchNumber;
    cout << "������� ����� ����� ��� ������: ";
    cin >> searchNumber;

    // ����� ������ ����� � ���-�������
    Node* node = ht.search(searchNumber);
    if (node != NULL) {
        cout << "����� " << searchNumber << " �������, ���������� ���������: " << node->count << endl;
    }
    else {
        cout << "����� " << searchNumber << " �� �������." << endl;
    }

    return 0;
}
