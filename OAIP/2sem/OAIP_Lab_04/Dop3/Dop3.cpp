#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Sanatorium {
    string name;
    string location;
    string profile;
    int quantity;
};

void displaySanatorium(const Sanatorium& sanatorium) {
    cout << "| " << sanatorium.name << " | " << sanatorium.location << " | " << sanatorium.profile << " | " << sanatorium.quantity << " |" << endl;
}

void displayTable(const Sanatorium sanatoriums[], int count) {
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "| �������� ���������  | ����� ������������ | �������� ������� | ���������� ������� |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        displaySanatorium(sanatoriums[i]);
    }

    cout << "-----------------------------------------------------------------" << endl;
}

void searchSanatorium(const Sanatorium sanatoriums[], int count, const string& profile) {
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (sanatoriums[i].profile == profile) {
            if (!found) {
                cout << "���������� ������ ��� ��������� �������: " << profile << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "| �������� ���������  | ����� ������������ | �������� ������� | ���������� ������� |" << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
                found = true;
            }
            displaySanatorium(sanatoriums[i]);
        }
    }

    if (!found) {
        cout << "��������� � �������� �������� '" << profile << "' �� �������." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    const int MAX_SANATORIUMS = 5;
    Sanatorium sanatoriums[MAX_SANATORIUMS] = {
        {"��������� ���������", "������� �������   ", "������������", 10},
        {"��������� �����    ", "���������� �������", "����������", 5},
        {"��������� ���      ", "��������� ������� ", "���������", 8},
        {"��������� ������   ", "������� �������   ", "�����������", 7},
        {"��������� ���������", "����              ", "������� �������", 3}
    };

    int choice;
    string searchProfile;

    do {
        cout << "����:" << endl;
        cout << "1. ������� ���������� � ����������" << endl;
        cout << "2. ����� ��������� �� ��������� �������" << endl;
        cout << "3. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayTable(sanatoriums, MAX_SANATORIUMS);
            break;
        case 2:
            cout << "������� �������� ������� ��� ������: ";
            cin.ignore();
            getline(cin, searchProfile);
            searchSanatorium(sanatoriums, MAX_SANATORIUMS, searchProfile);
            break;
        case 3:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "������������ �����. ���������� �����." << endl;
        }
    } while (choice != 3);

    return 0;
}