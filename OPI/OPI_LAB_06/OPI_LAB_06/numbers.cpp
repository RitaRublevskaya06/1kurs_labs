#include <iostream>
using namespace std;

void handleNumber() {
    char symbol;

    cout << "������� ����� �� 0 �� 9:" << endl;
    cin >> symbol;

    if (symbol >= 0x30 && symbol <= 0x39) {
        cout << "� Windows-1251: " << hex << static_cast<int>(symbol) << endl;
    }
    else {
        cout << "������!" << endl;
    }
}