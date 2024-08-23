#include "stdafx.h"

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