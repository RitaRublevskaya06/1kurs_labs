#include <iostream>
#include "weekends.h"

void printWeekend(int dayNumber) {
    switch (dayNumber) {
    case 6:
        std::cout << "Суббота" << std::endl;
        break;
    case 7:
        std::cout << "Воскресенье" << std::endl;
        break;
    default:
        std::cout << "Ошибка: неправильный порядковый номер дня недели." << std::endl;
    }
}