#include <iostream>
using namespace std;

void handleRussianAlphabet() {
    unsigned char code, code1;
    int x;

    cout << "Введите букву русского алфавита в строчном написании:" << endl;
    cin >> code;

    if (code >= 0xE0 && code <= 0xFF) {
        cout << "Введите букву русского алфавита в прописном написании:" << endl;
        cin >> code1;

        if (code1 >= 0xC0 && code1 <= 0xDF) {
            x = code - code1;
            cout << "Разница в шестнадцатеричной системе счисления равна: " << hex << x << endl;
        }
        else {
            cout << "Ошибка!" << endl;
        }
    }
    else {
        cout << "Ошибка!" << endl;
    }
}