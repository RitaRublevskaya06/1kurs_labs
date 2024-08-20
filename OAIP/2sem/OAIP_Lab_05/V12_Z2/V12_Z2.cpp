//union

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// ��������� � ����������� � �������� ������
struct ContactInfo {
    string fullName;
    string birthDate;
    string address;
    string phoneNumber;
    string workplace;
    string position;
};

struct Contact {
    ContactInfo info;
};

// ������� ��� ����� ���������� � ��������
void inputContactInfo(Contact& contact) {
    cout << "������� ���: ";
    cin.ignore();
    getline(cin, contact.info.fullName);

    cout << "������� ���� ��������: ";
    getline(cin, contact.info.birthDate);

    cout << "������� �����: ";
    getline(cin, contact.info.address);

    cout << "������� ����� ��������: ";
    getline(cin, contact.info.phoneNumber);

    cout << "������� ����� ������ ��� �����: ";
    getline(cin, contact.info.workplace);

    cout << "������� ���������: ";
    getline(cin, contact.info.position);
}

// ������� ��� ������ ���������� � ��������
void displayContactInfo(const Contact& contact) {
    cout << "���: " << contact.info.fullName << endl;
    cout << "���� ��������: " << contact.info.birthDate << endl;
    cout << "�����: " << contact.info.address << endl;
    cout << "����� ��������: " << contact.info.phoneNumber << endl;
    cout << "����� ������ ��� �����: " << contact.info.workplace << endl;
    cout << "���������: " << contact.info.position << endl;
}

// ������� ��� ������ ���������� � ����
void writeContactToFile(const Contact& contact, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "���: " << contact.info.fullName << endl;
        file << "���� ��������: " << contact.info.birthDate << endl;
        file << "�����: " << contact.info.address << endl;
        file << "����� ��������: " << contact.info.phoneNumber << endl;
        file << "����� ������ ��� �����: " << contact.info.workplace << endl;
        file << "���������: " << contact.info.position << endl;
        file << "-----------------------------" << endl;
        file.close();
        cout << "���������� � �������� �������� � ����." << endl;
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� ������ ���������� �� �����
void readContactsFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� ������ �������� �� �������
void searchContactByLastName(const string& lastName, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t found = line.find(lastName);
            if (found != string::npos) {
                cout << "������ ������� � ��������: " << lastName << endl;
                cout << line << endl;
                return;
            }
        }
        cout << "������� � �������� " << lastName << " �� ������." << endl;
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    const string filename = "contacts.txt";
    Contact contacts[3];

    cout << "������� ���������� � ���������" << endl << endl;

    for (int i = 0; i < 3; i++) {
        inputContactInfo(contacts[i]);
        writeContactToFile(contacts[i], filename);
        cout << endl;
    }

    cout << "���������� � ���� ���������:" << endl;
    readContactsFromFile(filename);

    string searchLastName;
    cout << "������� ������� ��� ������ ��������: ";
    cin.ignore(); // ������� ������ ����� ����� getline
    getline(cin, searchLastName);
    searchContactByLastName(searchLastName, filename);

    return 0;
}