#include <iostream>
using namespace std;

void handleRussianAlphabet() {
    unsigned char code, code1;
    int x;

    cout << "������� ����� �������� �������� � �������� ���������:" << endl;
    cin >> code;

    if (code >= 0xE0 && code <= 0xFF) {
        cout << "������� ����� �������� �������� � ��������� ���������:" << endl;
        cin >> code1;

        if (code1 >= 0xC0 && code1 <= 0xDF) {
            x = code - code1;
            cout << "������� � ����������������� ������� ��������� �����: " << hex << x << endl;
        }
        else {
            cout << "������!" << endl;
        }
    }
    else {
        cout << "������!" << endl;
    }
}