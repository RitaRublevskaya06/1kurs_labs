#include <iostream>
using namespace std;

void handleNumber() {
    char symbol;

    cout << "¬ведите число от 0 до 9:" << endl;
    cin >> symbol;

    if (symbol >= 0x30 && symbol <= 0x39) {
        cout << "в Windows-1251: " << hex << static_cast<int>(symbol) << endl;
    }
    else {
        cout << "ќшибка!" << endl;
    }
}