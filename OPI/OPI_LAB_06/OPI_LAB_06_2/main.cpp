#include <iostream>
#include <cstdlib>
#include <ctime>
#include "weekdays.h"
#include "weekends.h"

int main() {
    setlocale(LC_CTYPE, "Russian");
    int dayNumber;

    std::cout << "Введите порядковый номер дня недели (1-7): ";
    std::cin >> dayNumber;

    if (dayNumber >= 1 && dayNumber <= 5) {
        printWeekday(dayNumber);
    }
    else if (dayNumber >= 6 && dayNumber <= 7) {
        printWeekend(dayNumber);
    }
    else {
        std::cout << "Ошибка: неправильный порядковый номер дня недели." << std::endl;
    }

    return 0;
}