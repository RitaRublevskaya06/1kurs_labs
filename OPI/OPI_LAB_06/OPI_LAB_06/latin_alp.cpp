#include <iostream>
using namespace std;

void handleLatinAlphabet() {
    unsigned char code, code1;
    int x;

    cout << "������� ����� ���������� �������� � �������� ���������:" << endl;
    cin >> code;

    if (code >= 0x61 && code <= 0x7A) {
        cout << "������� ����� ���������� �������� � ��������� ���������:" << endl;
        cin >> code1;

        if (code1 >= 0x41 && code1 <= 0x5A) {
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