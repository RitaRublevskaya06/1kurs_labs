//union

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Структура с информацией в записной книжке
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

// Функция для ввода информации о контакте
void inputContactInfo(Contact& contact) {
    cout << "Введите ФИО: ";
    cin.ignore();
    getline(cin, contact.info.fullName);

    cout << "Введите дату рождения: ";
    getline(cin, contact.info.birthDate);

    cout << "Введите адрес: ";
    getline(cin, contact.info.address);

    cout << "Введите номер телефона: ";
    getline(cin, contact.info.phoneNumber);

    cout << "Введите место работы или учебы: ";
    getline(cin, contact.info.workplace);

    cout << "Введите должность: ";
    getline(cin, contact.info.position);
}

// Функция для вывода информации о контакте
void displayContactInfo(const Contact& contact) {
    cout << "ФИО: " << contact.info.fullName << endl;
    cout << "Дата рождения: " << contact.info.birthDate << endl;
    cout << "Адрес: " << contact.info.address << endl;
    cout << "Номер телефона: " << contact.info.phoneNumber << endl;
    cout << "Место работы или учебы: " << contact.info.workplace << endl;
    cout << "Должность: " << contact.info.position << endl;
}

// Функция для записи информации в файл
void writeContactToFile(const Contact& contact, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "ФИО: " << contact.info.fullName << endl;
        file << "Дата рождения: " << contact.info.birthDate << endl;
        file << "Адрес: " << contact.info.address << endl;
        file << "Номер телефона: " << contact.info.phoneNumber << endl;
        file << "Место работы или учебы: " << contact.info.workplace << endl;
        file << "Должность: " << contact.info.position << endl;
        file << "-----------------------------" << endl;
        file.close();
        cout << "Информация о контакте записана в файл." << endl;
    }
    else {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}

// Функция для чтения информации из файла
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
        cout << "Ошибка открытия файла для чтения." << endl;
    }
}

// Функция для поиска контакта по фамилии
void searchContactByLastName(const string& lastName, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t found = line.find(lastName);
            if (found != string::npos) {
                cout << "Найден контакт с фамилией: " << lastName << endl;
                cout << line << endl;
                return;
            }
        }
        cout << "Контакт с фамилией " << lastName << " не найден." << endl;
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    const string filename = "contacts.txt";
    Contact contacts[3];

    cout << "Введите информацию о контактах" << endl << endl;

    for (int i = 0; i < 3; i++) {
        inputContactInfo(contacts[i]);
        writeContactToFile(contacts[i], filename);
        cout << endl;
    }

    cout << "Информация о всех контактах:" << endl;
    readContactsFromFile(filename);

    string searchLastName;
    cout << "Введите фамилию для поиска контакта: ";
    cin.ignore(); // Очистка буфера ввода перед getline
    getline(cin, searchLastName);
    searchContactByLastName(searchLastName, filename);

    return 0;
}