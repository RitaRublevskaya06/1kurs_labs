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
    cout << "Введите ФИО: ";
    cin.ignore();
    getline(cin, newCitizen.fullName);
    cout << "Введите день рождения: ";
    cin >> newCitizen.birthDate.day;
    cout << "Введите месяц рождения: ";
    cin >> newCitizen.birthDate.month;
    cout << "Введите год рождения: ";
    cin >> newCitizen.birthDate.year;
    cout << "Введите адрес: ";
    cin.ignore();
    getline(cin, newCitizen.address);
    cout << "Введите пол (0 - мужской, 1 - женский): ";
    int genderInput;
    cin >> genderInput;
    newCitizen.gender = static_cast<Gender>(genderInput);

    citizens[count++] = newCitizen;
    cout << endl;
}

void displayCitizens(const Citizen* citizens, int count) {
    cout << "Список граждан:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << "ФИО: " << citizens[i].fullName << endl;
        cout << "Дата рождения: " << citizens[i].birthDate.day << "." << citizens[i].birthDate.month << "." << citizens[i].birthDate.year << endl;
        cout << "Адрес: " << citizens[i].address << endl;
        cout << "Пол: " << (citizens[i].gender == Male ? "мужской" : "женский") << endl;
        cout << endl;
    }
}

void searchByYear(const Citizen* citizens, int count, int year) {
    cout << "Граждане, родившиеся в " << year << " году:" << endl;
    for (int i = 0; i < count; ++i) {
        if (citizens[i].birthDate.year == year) {
            cout << "ФИО: " << citizens[i].fullName << endl;
            cout << "Дата рождения: " << citizens[i].birthDate.day << "." << citizens[i].birthDate.month << "." << citizens[i].birthDate.year << endl;
            cout << "Адрес: " << citizens[i].address << endl;
            cout << "Пол: " << (citizens[i].gender == Male ? "мужской" : "женский") << endl;
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
            cout << "Гражданин " << fullName << " удален из базы данных." << endl;
            return;
        }
    }

    cout << "Гражданин " << fullName << " не найден в базе данных." << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Citizen citizens[20];
    int count = 0;
    cout << "Добро пожаловать в базу данных граждан!" << endl << endl;;
    cout << "Что вы хотите выполнить?" << endl;
    cout << "1. Добавить гражданина" << endl;
    cout << "2. Вывести всех граждан" << endl;
    cout << "3. Поиск граждан по году рождения" << endl;
    cout << "4. Удалить гражданина" << endl;
    cout << "0. Выход" << endl << endl;
    int a;
    int year;

    do {
        cout << "Введите номер операции: ";
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
            cout << "Введите год рождения для поиска: ";
            cin >> year;
            searchByYear(citizens, count, year);
            break;}
        case 4: {
            string fullNameToDelete;
            cout << "Введите ФИО гражданина для удаления: ";
            cin.ignore();
            getline(cin, fullNameToDelete);
            deleteCitizen(citizens, count, fullNameToDelete);
            break;}
        case 0:
            break;
        default:
            cout << "Неверный выбор. Повторите попытку." << endl;
        }

    } while (a != 0);

    cout << "До свидания!" << endl;

    return 0;
}