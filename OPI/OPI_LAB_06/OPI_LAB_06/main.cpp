#include <iostream>
#include "latin_alp.h"
#include "russian_alp.h"
#include "numbers.h"
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    unsigned char symbol;
    int k = 0;

    while (k != 4) {
        cout << "Выберите число: (1 - буква латинского алфавита, 2 - буква русского алфавита, 3 - цифра, 4 - выход)" << endl;
        cin >> k;

        switch (k) {
        case 1:
            handleLatinAlphabet();
            break;
        case 2:
            handleRussianAlphabet();
            break;
        case 3:
            handleNumber();
            break;
        case 4:
            break;
        default:
            cout << "Ошибка!" << endl;
            break;
        }
    }

    return 0;
}