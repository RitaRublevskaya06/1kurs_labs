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
        puts("�������� �����: (1 - ����� ���������� ��������, 2 - ����� �������� ��������, 3 - �����, 4 - �����)");
        cin >> k;
        switch (k)
        {
        case 1:
        {
            cout << "������� ����� ���������� �������� � �������� ���������:" << endl;
            cin >> code;
            if (code >= 0x61 && code <= 0x7A) {
                cout << "������� ����� ���������� �������� � ��������� ���������:" << endl;
                cin >> code1;
                if (code1 >= 0x41 && code1 <= 0x5A) {
                    x = code - code1;
                    cout << "������� �������� ����� � ASCII � ����������������� ������� ��������� �����: " << hex << x << endl;
                }
                else {
                    cout << "������!" << endl;
                }
            }
            else {
                cout << "������!" << endl;
            }
            break;
        }
        case 2: {
            cout << "������� ����� �������� �������� � �������� ���������:" << endl;
            cin >> code;
            if (code >= 0xE0 && code <= 0xFF) {
                cout << "������� ����� �������� �������� � ��������� ���������:" << endl;
                cin >> code1;
                if (code1 >= 0xC0 && code1 <= 0xDF) {
                    x = code - code1;
                    cout << "������� �������� ����� � Windows-1251 � ����������������� ������� ��������� �����: " << hex << x << endl;
                }
                else {
                    cout << "������!" << endl;
                }
            }
            else {
                cout << "������!" << endl;
            }
            break;
        }
        case 3: {
            cout << "������� ����� �� 0 �� 9 : " << endl;
            cin >> symbol;
            if (symbol >= 0x30 && symbol <= 0x90) {
                cout << "��� ������� � Windows-1251: " << hex << static_cast<int>(symbol) << endl;
                break;
            }
            else {
                cout << "������!" << endl;
            }
            break;
        }
        case 4:
            break;

        default: puts("������!"); break;
        }
    }
    return 0;
}