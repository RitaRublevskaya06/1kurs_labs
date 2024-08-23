#include "stdafx.h"


std::string monthName(int month) {
    std::string names[] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };
    return names[month - 1];
}

std::string findProgrammersDay(int year, int eventDayOfYear) {
    std::string event;

    if (eventDayOfYear == 1) {
        return " - ����� ���";
    }
    else if (eventDayOfYear == 7) {
        return " - ���������";
    }
    else if (eventDayOfYear == 45) {
        return " - ���� ������� ���������";
    }
    else if (isLeapYear(year) && eventDayOfYear == 256) {
        return " - ���� ������������";
    }
    else if (!isLeapYear(year) && eventDayOfYear == 256) {
        return " - ���� ������������ ";
    }
    else {
        return " - ������ ���������� ����� �� ������������� �������.";
    }
}

std::string monthName_2(int month) {
    std::string names[] = { "������", "�������", "�����", "������", "���", "����", "����", "�������", "��������", "��������", "������", "�������" };
    return names[month - 1];
}

void eventDateInYear(int dayOfYear, int year, int& eventDay, int& eventMonth) {
    if (dayOfYear < 1 || dayOfYear >(isLeapYear(year) ? 366 : 365)) {
        // ������������ ���������� ����� ��� � ����
        eventDay = -1;
        eventMonth = -1;
    }
    else {
        dateFromDayOfYear(dayOfYear, year, eventDay, eventMonth);
    }
}

void dateFromDayOfYear(int dayOfYear, int year, int& day, int& month) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    int i = 0;
    while (dayOfYear > daysInMonth[i]) {
        dayOfYear -= daysInMonth[i];
        i++;
    }
    day = dayOfYear;
    month = i + 1;
}
