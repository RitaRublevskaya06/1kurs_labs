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
        cout << "�������� �����: (1 - ����� ���������� ��������, 2 - ����� �������� ��������, 3 - �����, 4 - �����)" << endl;
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
            cout << "������!" << endl;
            break;
        }
    }

    return 0;
}