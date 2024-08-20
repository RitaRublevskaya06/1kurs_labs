#include <iostream>
#include <fstream>
#include <list>

using namespace std;

// ��������� ���� ������
struct Node {
    string word;
    int count;
    Node* next;
};

// ��������� ���-�������
struct HashTable {
    list<Node*>* table;
    int size;

    // ���-�������
    int hashFunction(string key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue += (int)c;
        }
        return hashValue % size;
    }

    // ������� ���� � ������ �������
    void insert(string key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->word = key;
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
    Node* search(string key) {
        int index = hashFunction(key);
        Node* curr = table[index].front();

        while (curr != NULL) {
            if (curr->word == key) {
                return curr;
            }
            curr = curr->next;
        }

        // ���� �� ������
        return NULL;
    }

    // ���������� �������� ��������
    void incrementCount(string key) {
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
                cout << "(" << curr->word << ", " << curr->count << ") ";
            }
            cout << endl;
        }
    }

    // �������� ���� ����, ������������ � ��������� �����
    void deleteByPrefix(char prefix) {
        for (int i = 0; i < size; i++) {
            Node* curr = table[i].front();
            Node* prev = NULL;

            while (curr != NULL) {
                if (curr->word[0] == prefix) {
                    // ������� ����
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
    // ���� ������� ���-�������
    int size;
    cout << "������� ����������� ���-�������: ";
    cin >> size;

    // �������� ���-�������
    HashTable ht;
    ht.size = size;
    ht.table = new list<Node*>[size];

    // ���������� ���� �� �����
    string filename;
    cout << "������� ��� ���������� �����: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "���� �� ����� ���� ������!" << endl;
        return 1;
    }

    string word;
    while (infile >> word) {
        ht.insert(word);
    }
    infile.close();

    // ������ ���-�������
    cout << "���-������� �� ���� �����:" << endl;
    ht.print();

    // ���� ����� ��� ������
    string searchWord;
    cout << "������� ����� ��� ������: ";
    cin >> searchWord;

    // ����� ����� � ���-�������
    Node* node = ht.search(searchWord);
    if (node != NULL) {
        cout << "����� '" << searchWord << "' �������, ���������� ���������: " << node->count << endl;
    }
    else {
        cout << "����� '" << searchWord << "' �� �������." << endl;
    }

    // �������� ���� ����, ������������ � ��������� �����
    char prefix;
    cout << "������� �����, � ������� ���������� ����� ��� ��������: ";
    cin >> prefix;

    ht.deleteByPrefix(prefix);

    // ������ ����������� ���-�������
    cout << "���-������� ����� �������� ����, ������������ � '" << prefix << "':" << endl;
    ht.print();

    return 0;
}