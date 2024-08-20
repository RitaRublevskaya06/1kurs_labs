#include <iostream>
#include <cstdarg>
#include <bitset>

void decimalToBinary(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        std::cout << "Число " << num << " в двоичной системе: " << std::bitset<sizeof(int) * 2>(num) << std::endl;
    }
    va_end(args);
}

int main() {
    using namespace std;
    setlocale(LC_CTYPE, "RU");

    void (*decimalToBinaryPtr)(int, ...);
    decimalToBinaryPtr = decimalToBinary;

    decimalToBinaryPtr(3, 10, 20, 30);
    decimalToBinaryPtr(2, 5, 15);
    decimalToBinaryPtr(1, 255);

    return 0;
}