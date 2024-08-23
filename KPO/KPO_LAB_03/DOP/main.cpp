#include<iostream>
using namespace std;

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int days1 = day1;
    for (int i = 0; i < month1 - 1; i++) {
        days1 += daysInMonth[i];
    }
    days1 += year1 * 365;

    int days2 = day2;
    for (int i = 0; i < month2 - 1; i++) {
        days2 += daysInMonth[i];
    }
    days2 += year2 * 365;

    return abs(days2 - days1);
}

int hoursBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int daysDiff = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    int hoursDiff = daysDiff * 24;

    return hoursDiff;
}

int main() {
    setlocale(LC_CTYPE, "RU");
    int day1, month1, year1, day2, month2, year2;
    cout << "Введите первую дату (ДД ММ ГГГГ):  ";
    cin >> day1 >> month1 >> year1;
    cout << "Введите вторую дату (ДД ММ ГГГГ):  ";
    cin >> day2 >> month2 >> year2;

    int daysDiff = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    int hoursDiff = hoursBetweenDates(day1, month1, year1, day2, month2, year2);

    cout << "Разница в днях: " << daysDiff << endl;
    cout << "Разница в часах: " << hoursDiff << endl;

    return 0;
}