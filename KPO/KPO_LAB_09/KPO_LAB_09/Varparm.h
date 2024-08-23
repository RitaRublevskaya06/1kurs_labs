#pragma once

#include <iostream>

namespace Varparm {
	int ivarparm(int count, int first, ...);
	int svarparm(short count, int first, ...);
	double fvarparm(float first, ...);
	double dvarparm(double first, ...);
}