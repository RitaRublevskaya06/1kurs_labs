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
    cout << "Введите паспортные данные: ";
    cin >> client.passportData;
    cout << "Введите дату приезда (день месяц год): " << client.arrivalDate.day << client.arrivalDate.month << client.arrivalDate.year;
    cout << "Введите дату отъезда (день месяц год): " << client.departureDate.day << client.departureDate.month << client.departureDate.year;
    cout << "Введите номер комнаты: " << client.roomNumber;
    int type;
    cout << "Выберите тип размещения (0 - люкс, 1 - одноместный, 2 - двухместный, 3 - трехместный, 4 - апартаменты): ";
    cin >> type;
    client.accommodationType = static_cast<AccommodationType>(type);
}

void displayClientInfo(const Client& client) {
    cout << "Паспортные данные: " << client.passportData << endl;
    cout << "Дата приезда: " << client.arrivalDate.day << "." << client.arrivalDate.month << "." << client.arrivalDate.year << endl;
    cout << "Дата отъезда: " << client.departureDate.day << "." << client.departureDate.month << "." << client.departureDate.year << endl;
    cout << "Номер комнаты: " << client.roomNumber << endl;
    cout << "Тип размещения: ";
    switch (client.accommodationType) {
    case LUXURY:
        cout << "Люкс";
        break;
    case SINGLE:
        cout << "Одноместный";
        break;
    case DOUBLE:
        cout << "Двухместный";
        break;
    case TRIPLE:
        cout << "Трехместный";
        break;
    case APARTMENTS:
        cout << "Апартаменты";
        break;
    default:
        cout << "Неизвестный тип";
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
        cout << "Клиенты не найдены по указанной дате приезда." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    const int MAX_CLIENTS = 20;
    Client clients[MAX_CLIENTS];

    cout << "Добро пожаловать в базу данных клиентов гостиницы!" << endl;

    int a;

    do {
        cout << "\\nЧто вы хотите выполнить?" << endl;
        cout << "1. Запись клиента" << endl;
        cout << "2. Поиск клиента по дате приезда" << endl;
        cout << "3. Удаление клиента" << endl;
        cout << "0. Выход" << endl;

        cout << "\\nВведите номер операции: ";
        cin >> a;
        
        switch (a) {
        case 1:
            if (i < MAX_CLIENTS) {
                inputClientInfo(clients[i]);
                i++;
            }
            else {
                cout << "База данных заполнена. Невозможно добавить нового клиента." << endl;
            }
            break;

        case 2:
            Date searchDate;
            cout << "Введите дату приезда для поиска (день месяц год): " << searchDate.day << searchDate.month << searchDate.year;
            searchClientByArrivalDate(searchDate, clients, i);
            break;

        case 3:
            // Реализация удаления клиента
            break;

        case 0:
            break;

        default:
            cout << "Неверный номер операции. Повторите попытку." << endl;
            break;
        }
    } while (a != 0);

    cout << "До свидания!" << endl;

    return 0;
}