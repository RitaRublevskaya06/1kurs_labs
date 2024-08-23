#pragma once

#include "stdafx.h"

bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
int dayOfYear(int day, int month, int year);
int daysUntilBirthday(int day, int month, int year, int currentDay, int currentMonth);
std::string findProgrammersDay(int year, int ordinalDay);
std::string monthName(int month);
std::string monthName_2(int month);
void dateFromDayOfYear(int dayOfYear, int year, int& day, int& month);
void eventDateInYear(int dayOfYear, int year, int& eventDay, int& eventMonth);