#include "stdafx.h"

int main() {

    setlocale(LC_CTYPE, "RU");
    int birthDay = 18, birthMonth = 02, birthYear = 2006;

    int day, month, year;
    std::cout << "Введите дату вашего рождения (ДД ММ ГГГГ): " << birthDay << " " << birthMonth << " " << birthYear << std::endl;

    int currentDay, currentMonth, currentYear;
    std::cout << "Введите текущую дату (ДД ММ ГГГГ): ";
    std::cin >> currentDay >> currentMonth >> currentYear;

    if (!isValidDate(currentDay, currentMonth, currentYear)) {
        std::cout << "Введена неверная дата." << std::endl;
        return 1;
    }

    std::cout << "Дни до следующего дня рождения: " << daysUntilBirthday(birthDay, birthMonth, birthYear, currentDay, currentMonth) << std::endl;


    std::cout << "Введите дату (ДД ММ ГГГГ):  ";
    std::cin >> day >> month >> year;

    if (!isValidDate(day, month, year)) {
        std::cout << "Введена неверная дата." << std::endl;
        return 1;
    }
    std::cout << "Название месяца: " << monthName(month) << std::endl;

    if (isLeapYear(year)) {
        std::cout << year << " - это високосный год." << std::endl;
    }
    else {
        std::cout << year << " - это не високосный год." << std::endl;
    }

    std::cout << "Порядковый номер введенного дня в году: " << dayOfYear(day, month, year) << std::endl;

    int eventDayOfYear;
    std::cout << "Введите порядковый номер дня в году: ";
    std::cin >> eventDayOfYear;

    int eventDay, eventMonth;
    eventDateInYear(eventDayOfYear, year, eventDay, eventMonth);
    if (eventDay == -1) {
        std::cout << "Некорректный порядковый номер события в году." << std::endl;
    }
    else {
        std::cout << "Праздник: " << eventDay << " " << monthName_2(eventMonth) << " " << year << findProgrammersDay(year, eventDayOfYear) << std::endl;
    }

    return 0;
}