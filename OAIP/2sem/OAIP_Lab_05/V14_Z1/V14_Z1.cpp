#include <iostream>
#include <windows.h>
using namespace std;

enum AccommodationType {
    LUXURY,
    SINGLE,
    DOUBLE,
    TRIPLE,
    APARTMENTS
};

struct Date {
    unsigned short day : 5;     // 5 bits - 0-31
    unsigned short month : 4;   // 4 bits - 0-15  
    unsigned short year : 11;   // 11 bits - 0-2047
};

struct Client {
    string passportData;
    Date arrivalDate;
    Date departureDate;
    int roomNumber;
    AccommodationType accommodationType;
};

void inputClientInfo(Client& client) {
    cout << "������� ���������� ������: ";
    cin >> client.passportData;
    cout << "������� ���� ������� (���� ����� ���): " << client.arrivalDate.day << client.arrivalDate.month << client.arrivalDate.year;
    cout << "������� ���� ������� (���� ����� ���): " << client.departureDate.day << client.departureDate.month << client.departureDate.year;
    cout << "������� ����� �������: " << client.roomNumber;
    int type;
    cout << "�������� ��� ���������� (0 - ����, 1 - �����������, 2 - �����������, 3 - �����������, 4 - �����������): ";
    cin >> type;
    client.accommodationType = static_cast<AccommodationType>(type);
}

void displayClientInfo(const Client& client) {
    cout << "���������� ������: " << client.passportData << endl;
    cout << "���� �������: " << client.arrivalDate.day << "." << client.arrivalDate.month << "." << client.arrivalDate.year << endl;
    cout << "���� �������: " << client.departureDate.day << "." << client.departureDate.month << "." << client.departureDate.year << endl;
    cout << "����� �������: " << client.roomNumber << endl;
    cout << "��� ����������: ";
    switch (client.accommodationType) {
    case LUXURY:
        cout << "����";
        break;
    case SINGLE:
        cout << "�����������";
        break;
    case DOUBLE:
        cout << "�����������";
        break;
    case TRIPLE:
        cout << "�����������";
        break;
    case APARTMENTS:
        cout << "�����������";
        break;
    default:
        cout << "����������� ���";
        break;
    }
    cout << endl;
}

void searchClientByArrivalDate(const Date& date, const Client* clients, int size) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (clients[i].arrivalDate.day == date.day && clients[i].arrivalDate.month == date.month && clients[i].arrivalDate.year == date.year) {
            displayClientInfo(clients[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "������� �� ������� �� ��������� ���� �������." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    const int MAX_CLIENTS = 20;
    Client clients[MAX_CLIENTS];

    cout << "����� ���������� � ���� ������ �������� ���������!" << endl;

    int a;

    do {
        cout << "\\n��� �� ������ ���������?" << endl;
        cout << "1. ������ �������" << endl;
        cout << "2. ����� ������� �� ���� �������" << endl;
        cout << "3. �������� �������" << endl;
        cout << "0. �����" << endl;

        cout << "\\n������� ����� ��������: ";
        cin >> a;
        
        switch (a) {
        case 1:
            if (i < MAX_CLIENTS) {
                inputClientInfo(clients[i]);
                i++;
            }
            else {
                cout << "���� ������ ���������. ���������� �������� ������ �������." << endl;
            }
            break;

        case 2:
            Date searchDate;
            cout << "������� ���� ������� ��� ������ (���� ����� ���): " << searchDate.day << searchDate.month << searchDate.year;
            searchClientByArrivalDate(searchDate, clients, i);
            break;

        case 3:
            // ���������� �������� �������
            break;

        case 0:
            break;

        default:
            cout << "�������� ����� ��������. ��������� �������." << endl;
            break;
        }
    } while (a != 0);

    cout << "�� ��������!" << endl;

    return 0;
}