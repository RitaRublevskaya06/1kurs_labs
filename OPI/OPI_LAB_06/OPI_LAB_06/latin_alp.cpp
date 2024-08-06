#include <iostream>
using namespace std;

void handleLatinAlphabet() {
    unsigned char code, code1;
    int x;

    cout << "Введите букву латинского алфавита в строчном написании:" << endl;
    cin >> code;

    if (code >= 0x61 && code <= 0x7A) {
        cout << "Введите букву латинского алфавита в прописном написании:" << endl;
        cin >> code1;

        if (code1 >= 0x41 && code1 <= 0x5A) {
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