#include "stdafx.h"

int main() {

    setlocale(LC_CTYPE, "RU");
    int birthDay = 18, birthMonth = 02, birthYear = 2006;

    int day, month, year;
    std::cout << "������� ���� ������ �������� (�� �� ����): " << birthDay << " " << birthMonth << " " << birthYear << std::endl;

    int currentDay, currentMonth, currentYear;
    std::cout << "������� ������� ���� (�� �� ����): ";
    std::cin >> currentDay >> currentMonth >> currentYear;

    if (!isValidDate(currentDay, currentMonth, currentYear)) {
        std::cout << "������� �������� ����." << std::endl;
        return 1;
    }

    std::cout << "��� �� ���������� ��� ��������: " << daysUntilBirthday(birthDay, birthMonth, birthYear, currentDay, currentMonth) << std::endl;


    std::cout << "������� ���� (�� �� ����):  ";
    std::cin >> day >> month >> year;

    if (!isValidDate(day, month, year)) {
        std::cout << "������� �������� ����." << std::endl;
        return 1;
    }
    std::cout << "�������� ������: " << monthName(month) << std::endl;

    if (isLeapYear(year)) {
        std::cout << year << " - ��� ���������� ���." << std::endl;
    }
    else {
        std::cout << year << " - ��� �� ���������� ���." << std::endl;
    }

    std::cout << "���������� ����� ���������� ��� � ����: " << dayOfYear(day, month, year) << std::endl;

    int eventDayOfYear;
    std::cout << "������� ���������� ����� ��� � ����: ";
    std::cin >> eventDayOfYear;

    int eventDay, eventMonth;
    eventDateInYear(eventDayOfYear, year, eventDay, eventMonth);
    if (eventDay == -1) {
        std::cout << "������������ ���������� ����� ������� � ����." << std::endl;
    }
    else {
        std::cout << "��������: " << eventDay << " " << monthName_2(eventMonth) << " " << year << findProgrammersDay(year, eventDayOfYear) << std::endl;
    }

    return 0;
}