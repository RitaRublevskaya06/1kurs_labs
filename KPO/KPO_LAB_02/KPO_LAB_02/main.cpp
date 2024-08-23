#include <iostream>
#include <iomanip>

#define n 13;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int x, y, z;
	double S;
	x = 9 + n;
	y = 10 + n;
	z = 11 + n;
	S = 1.0 + n;

	// Задание 4
	bool TRUE = true, FALSE = false;

	// Задание 5
	char lat = 'u';

	// Задание 6
	char rus = 'у';

	// Задание 7
	wchar_t wlat = 'R';

	// Задание 8
	wchar_t wrus = 'Р';

	// Задание 9
	short a = x, a1 = -x;

	cout << "X16 = " << hex << a << endl;
	cout << "-X16 = " << hex << a1 << endl;

	// Задание 10
	short smax = SHRT_MAX;
	short smin = SHRT_MIN;

	// Задание 11
	unsigned short usmax = USHRT_MAX;
	unsigned short usmin = 0;


	// Задание 12
	int t = y, t1 = -y;
	cout << "Y16 = " << hex << t << endl;
	cout << "-Y16 = " << hex << t1 << endl;

	// Задание 13
	int imax = INT_MAX;
	int imin = INT_MIN;

	// Задание 14
	unsigned int ismax = UINT_MAX;
	unsigned int ismin = 0;

	// Задание 15
	int b = z, b1 = -z;
	cout << "imax = " << hex << imax << endl;
	cout << "imax = " << hex << imin << endl;
	cout << "Z16 = " << hex << b << endl;
	cout << "-Z16 = " << hex << b1 << endl;

	// Задание 16
	long lmax = LONG_MAX;
	long lmin = LONG_MIN;

	// Задание 17
	unsigned long lsmax = ULONG_MAX;
	unsigned long lsmin = 0;

	// Задание 18
	float ch = S, ch1 = -S;

	cout << "S16 = " << hex << setprecision(3) << ch << endl;
	cout << "-S16 = " << hex << ch1 << endl;

	double pd1 = 10.124;

	// Задание 19
	float var1 = INFINITY;
	float var2 = -INFINITY;
	float var3 = NAN;

	cout << var1 << " " << var2 << " " << var3 << endl;

	// Задание 20
	char* pch = &rus;
	wchar_t* pwch = &wlat;
	short* ps = &a;
	int* pi = &b;
	float* pf = &ch;
	double* pd = &pd1;
	pch += 3;
	pwch += 3;
	ps += 3;
	pi += 3;
	pf += 3;
	pd += 3;

	return 0;
}
