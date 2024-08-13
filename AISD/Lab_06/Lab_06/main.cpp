#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <windows.h>

using namespace std;

struct Contact {
    int phoneNumber;
    string fullName;
};

class HashTable {
public:
    HashTable(int size) {
        table.resize(size);
    }

    void addContact(Contact contact) {
        int index = hashFunction(contact.phoneNumber);
        table[index].push_back(contact);
    }

    vector<Contact> getContacts(int phoneNumber) {
        int index = hashFunction(phoneNumber);
        return table[index];
    }

    void printTable() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() > 0) {
                cout << "Номер телефона " << i << ":\n";
                for (int j = 0; j < table[i].size(); j++) {
                    cout << "\t" << table[i][j].phoneNumber << " - " << table[i][j].fullName << endl;
                }
            }
        }
    }
    void removeContact(int phoneNumber) {
        int index = hashFunction(phoneNumber);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].phoneNumber == phoneNumber) {
                table[index].erase(table[index].begin() + i);
                cout << "Контакт с номером телефона " << phoneNumber << " успешно удален" << endl;
                return;
            }
        }
        cout << "Контакт с номером телефона " << phoneNumber << " не найден" << endl;
    }

private:
    vector<vector<Contact>> table;
    const int hash = 32767;
    int hashFunction(int phoneNumber) {
        return phoneNumber % table.size();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    HashTable table(16);

    int choice = 0;
    while (choice != 4) {
        cout << "Меню:\n";
        cout << "1. Добавить новый контакт\n";
        cout << "2. Поиск контактов по номеру телефона\n";
        cout << "3. Вывести таблицу\n";
        cout << "4. Удаление контакта\n";
        cout << "5. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int phoneNumber;
            string fullName;
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            cout << "Введите полное имя: ";
            cin >> fullName;
            table.addContact({ phoneNumber, fullName });
            break;
        }
        case 2: {
            int phoneNumber;
            cout << "Введите номер телефона для поиска: ";
            cin >> phoneNumber;
            vector<Contact> contacts = table.getContacts(phoneNumber);
            if (contacts.size() == 0) {
                cout << "Контакты для номера телефона " << phoneNumber << " не найдены" << endl;
            }
            else {
                cout << "Контакты для номера телефона " << phoneNumber << ":\n";
                for (int i = 0; i < contacts.size(); i++) {
                    cout << "\t" << contacts[i].phoneNumber << " - " << contacts[i].fullName << endl;
                }
            }
            break;
        }
        case 3:
            table.printTable();
            break;
        case 4:
            int phoneNumber;
            cout << "Введите номер телефона для удаления: ";
            cin >> phoneNumber;
            table.removeContact(phoneNumber);
            break;
        case 5: {
            cout << "Выход...\n";
            break;
        }
        default:
            cout << "Неверный выбор\n";
        }

        cout << endl;
    }

    return 0;
}
