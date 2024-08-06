#include <iostream>
#include <windows.h>

using namespace std;

char main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    unsigned char code, code1, symbol;
    int x, k = 0;
    while (k != 4) {
        puts("Выберете число: (1 - буква латинского алфавита, 2 - буква русского алфавита, 3 - цифра, 4 - выход)");
        cin >> k;
        switch (k)
        {
        case 1:
        {
            cout << "Введите букву латинского алфавита в строчном написании:" << endl;
            cin >> code;
            if (code >= 0x61 && code <= 0x7A) {
                cout << "Введите букву латинского алфавита в прописном написании:" << endl;
                cin >> code1;
                if (code1 >= 0x41 && code1 <= 0x5A) {
                    x = code - code1;
                    cout << "Разница значений кодов в ASCII в шестнадцатеричной системе счисления равна: " << hex << x << endl;
                }
                else {
                    cout << "Ошибка!" << endl;
                }
            }
            else {
                cout << "Ошибка!" << endl;
            }
            break;
        }
        case 2: {
            cout << "Введите букву русского алфавита в строчном написании:" << endl;
            cin >> code;
            if (code >= 0xE0 && code <= 0xFF) {
                cout << "Введите букву русского алфавита в прописном написании:" << endl;
                cin >> code1;
                if (code1 >= 0xC0 && code1 <= 0xDF) {
                    x = code - code1;
                    cout << "Разница значений кодов в Windows-1251 в шестнадцатеричной системе счисления равна: " << hex << x << endl;
                }
                else {
                    cout << "Ошибка!" << endl;
                }
            }
            else {
                cout << "Ошибка!" << endl;
            }
            break;
        }
        case 3: {
            cout << "Введите число от 0 до 9 : " << endl;
            cin >> symbol;
            if (symbol >= 0x30 && symbol <= 0x90) {
                cout << "Код символа в Windows-1251: " << hex << static_cast<int>(symbol) << endl;
                break;
            }
            else {
                cout << "Ошибка!" << endl;
            }
            break;
        }
        case 4:
            break;

        default: puts("Ошибка!"); break;
        }
    }
    return 0;
}