#include "stdafx.h"

int main() {
    setlocale(LC_CTYPE, "RU");
    int birthDay = 18, birthMonth = 2, birthYear = 2006;
    int day, month, year;
    std::cout << "Введите дату вашего рождения (ДД ММ ГГГГ): " << birthDay << " " << birthMonth << " " << birthYear << std::endl;

    if (!isValidDate(birthDay, birthMonth, birthYear)) {
        std::cout << "Введена неверная дата." << std::endl;
        return 1;
    }

    std::cout << "Введите дату (ДД ММ ГГГГ):  ";
    std::cin >> day >> month >> year;

    if (!isValidDate(day, month, year)) {
        std::cout << "Введена неверная дата." << std::endl;
        return 1;
    }

    if (isLeapYear(year)) {
        std::cout << year << " - это високосный год." << std::endl;
    }
    else {
        std::cout << year << " - это не високосный год." << std::endl;
    }

    std::cout << "Порядковый номер введенного дня в году: " << dayOfYear(day, month, year) << std::endl;

    int currentDay, currentMonth, currentYear;
    std::cout << "Введите текущую дату (ДД ММ ГГГГ): ";
    std::cin >> currentDay >> currentMonth >> currentYear;

    if (!isValidDate(currentDay, currentMonth, currentYear)) {
        std::cout << "Введена неверная дата." << std::endl;
        return 1;
    }

    std::cout << "Дни до следующего дня рождения: " << daysUntilBirthday(birthDay, birthMonth, birthYear, currentDay, currentMonth) << std::endl;

    return 0;
}