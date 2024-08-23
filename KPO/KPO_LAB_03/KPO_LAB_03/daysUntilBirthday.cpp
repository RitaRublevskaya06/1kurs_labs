#include "stdafx.h"

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