#include "stdafx.h"

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