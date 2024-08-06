#include <iostream>
#include "weekdays.h"

void printWeekday(int dayNumber) {
    switch (dayNumber) {
    case 1:
        std::cout << "Понедельник" << std::endl;
        break;
    case 2:
        std::cout << "Вторник" << std::endl;
        break;
    case 3:
        std::cout << "Среда" << std::endl;
        break;
    case 4:
        std::cout << "Четверг" << std::endl;
        break;
    case 5:
        std::cout << "Пятница" << std::endl;
        break;
    default:
        std::cout << "Ошибка: неправильный порядковый номер дня недели." << std::endl;
    }
}