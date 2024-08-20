#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

enum Gender {
    Male,
    Female
};

struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Citizen {
    string fullName;
    Date birthDate;
    string address;
    Gender gender;
};

void addCitizen(Citizen* citizens, int& count) {
    Citizen newCitizen;
    cout << "������� ���: ";
    cin.ignore();
    getline(cin, newCitizen.fullName);
    cout << "������� ���� ��������: ";
    cin >> newCitizen.birthDate.day;
    cout << "������� ����� ��������: ";
    cin >> newCitizen.birthDate.month;
    cout << "������� ��� ��������: ";
    cin >> newCitizen.birthDate.year;
    cout << "������� �����: ";
    cin.ignore();
    getline(cin, newCitizen.address);
    cout << "������� ��� (0 - �������, 1 - �������): ";
    int genderInput;
    cin >> genderInput;
    newCitizen.gender = static_cast<Gender>(genderInput);

    citizens[count++] = newCitizen;
    cout << endl;
}

void displayCitizens(const Citizen* citizens, int count) {
    cout << "������ �������:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << "���: " << citizens[i].fullName << endl;
        cout << "���� ��������: " << citizens[i].birthDate.day << "." << citizens[i].birthDate.month << "." << citizens[i].birthDate.year << endl;
        cout << "�����: " << citizens[i].address << endl;
        cout << "���: " << (citizens[i].gender == Male ? "�������" : "�������") << endl;
        cout << endl;
    }
}

void searchByYear(const Citizen* citizens, int count, int year) {
    cout << "��������, ���������� � " << year << " ����:" << endl;
    for (int i = 0; i < count; ++i) {
        if (citizens[i].birthDate.year == year) {
            cout << "���: " << citizens[i].fullName << endl;
            cout << "���� ��������: " << citizens[i].birthDate.day << "." << citizens[i].birthDate.month << "." << citizens[i].birthDate.year << endl;
            cout << "�����: " << citizens[i].address << endl;
            cout << "���: " << (citizens[i].gender == Male ? "�������" : "�������") << endl;
            cout << endl;
        }
    }
}

void deleteCitizen(Citizen* citizens, int& count, const string& fullName) {
    for (int i = 0; i < count; ++i) {
        if (citizens[i].fullName == fullName) {
            for (int j = i; j < count - 1; ++j) {
                citizens[j] = citizens[j + 1];
            }
            count--;
            cout << "��������� " << fullName << " ������ �� ���� ������." << endl;
            return;
        }
    }

    cout << "��������� " << fullName << " �� ������ � ���� ������." << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Citizen citizens[20];
    int count = 0;
    cout << "����� ���������� � ���� ������ �������!" << endl << endl;;
    cout << "��� �� ������ ���������?" << endl;
    cout << "1. �������� ����������" << endl;
    cout << "2. ������� ���� �������" << endl;
    cout << "3. ����� ������� �� ���� ��������" << endl;
    cout << "4. ������� ����������" << endl;
    cout << "0. �����" << endl << endl;
    int a;
    int year;

    do {
        cout << "������� ����� ��������: ";
        cin >> a;
        cout << endl;
        switch (a) {
        case 1: {
            addCitizen(citizens, count);
            break; }
        case 2: {
            displayCitizens(citizens, count);
            break;}
        case 3: {
            cout << "������� ��� �������� ��� ������: ";
            cin >> year;
            searchByYear(citizens, count, year);
            break;}
        case 4: {
            string fullNameToDelete;
            cout << "������� ��� ���������� ��� ��������: ";
            cin.ignore();
            getline(cin, fullNameToDelete);
            deleteCitizen(citizens, count, fullNameToDelete);
            break;}
        case 0:
            break;
        default:
            cout << "�������� �����. ��������� �������." << endl;
        }

    } while (a != 0);

    cout << "�� ��������!" << endl;

    return 0;
}