#include <iostream>

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

bool isValidDate(int day, int month, int year) {
    if (year < 0) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }
    return true;
}

int dayOfYear(int day, int month, int year) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dayCount = day;
    for (int i = 0; i < month - 1; i++) {
        dayCount += daysInMonth[i];
    }
    if (isLeapYear(year) && month > 2) {
        dayCount += 1;
    }
    return dayCount;
}

int daysUntilBirthday(int day, int month, int year, int currentDay, int currentMonth) {
    int birthdayDay = dayOfYear(day, month, year);
    int currentDayOfYear = dayOfYear(currentDay, currentMonth, year);
    if (birthdayDay >= currentDayOfYear) {
        return birthdayDay - currentDayOfYear;
    }
    else {
        return 365 - (currentDayOfYear - birthdayDay);
    }
}

int main() {
    setlocale(LC_CTYPE, "RU");
    int birthDay = 18, birthMonth = 2, birthYear = 2006;
    int day, month, year;
    std::cout << "������� ���� ������ �������� (�� �� ����): " << birthDay << " " << birthMonth << " " << birthYear << std::endl;

    if (!isValidDate(birthDay, birthMonth, birthYear)) {
        std::cout << "������� �������� ����." << std::endl;
        return 1;
    }

    std::cout << "������� ���� (�� �� ����):  ";
    std::cin >> day >> month >> year;

    if (!isValidDate(day, month, year)) {
        std::cout << "������� �������� ����." << std::endl;
        return 1;
    }

    if (isLeapYear(year)) {
        std::cout << year << " - ��� ���������� ���." << std::endl;
    }
    else {
        std::cout << year << " - ��� �� ���������� ���." << std::endl;
    }

    std::cout << "���������� ����� ���������� ��� � ����: " << dayOfYear(day, month, year) << std::endl;

    int currentDay, currentMonth, currentYear;
    std::cout << "������� ������� ���� (�� �� ����): ";
    std::cin >> currentDay >> currentMonth >> currentYear;

    if (!isValidDate(currentDay, currentMonth, currentYear)) {
        std::cout << "������� �������� ����." << std::endl;
        return 1;
    }

    std::cout << "��� �� ���������� ��� ��������: " << daysUntilBirthday(birthDay, birthMonth, birthYear, currentDay, currentMonth) << std::endl;

    return 0;
}