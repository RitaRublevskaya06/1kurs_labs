#pragma once

#include "stdafx.h"

bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
int dayOfYear(int day, int month, int year);
int daysUntilBirthday(int day, int month, int year, int currentDay, int currentMonth);