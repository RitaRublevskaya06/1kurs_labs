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
    cout << "| Название санатория  | Место расположения | Лечебный профиль | Количество путевок |" << endl;
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
                cout << "Результаты поиска для лечебного профиля: " << profile << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "| Название санатория  | Место расположения | Лечебный профиль | Количество путевок |" << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
                found = true;
            }
            displaySanatorium(sanatoriums[i]);
        }
    }

    if (!found) {
        cout << "Санатории с лечебным профилем '" << profile << "' не найдены." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    const int MAX_SANATORIUMS = 5;
    Sanatorium sanatoriums[MAX_SANATORIUMS] = {
        {"Санаторий Журавушка", "Минская область   ", "Профилактика", 10},
        {"Санаторий Ченки    ", "Гомельская область", "Неврология", 5},
        {"Санаторий Буг      ", "Брестская область ", "Ортопедия", 8},
        {"Санаторий Ислочь   ", "Минская область   ", "Кардиология", 7},
        {"Санаторий Солнечный", "Крым              ", "Детская терапия", 3}
    };

    int choice;
    string searchProfile;

    do {
        cout << "Меню:" << endl;
        cout << "1. Вывести информацию о санаториях" << endl;
        cout << "2. Поиск санатория по лечебному профилю" << endl;
        cout << "3. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayTable(sanatoriums, MAX_SANATORIUMS);
            break;
        case 2:
            cout << "Введите лечебный профиль для поиска: ";
            cin.ignore();
            getline(cin, searchProfile);
            searchSanatorium(sanatoriums, MAX_SANATORIUMS, searchProfile);
            break;
        case 3:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 3);

    return 0;
}