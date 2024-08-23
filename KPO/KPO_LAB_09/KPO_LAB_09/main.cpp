#include "Varparm.h"
#include <iostream>
#include <cfloat>

using namespace Varparm;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ivarparm: " << endl;
	cout << "1 ��������: " << ivarparm(1, 0) << endl;
	cout << "2 ���������: " << ivarparm(2, 4, 5) << endl;
	cout << "3 ���������: " << ivarparm(3, 2, 2, 3) << endl;
	cout << "7 ����������: " << ivarparm(7, 6, 1, 2, 3, 4, 5, 6);

	cout << "\n\n������� svarparm: " << endl;
	cout << "1 ��������: " << svarparm(1, 0) << endl;
	cout << "2 ���������: " << svarparm(2, 1, 2) << endl;
	cout << "3 ���������: " << svarparm(3, 2, 2, 3) << endl;
	cout << "7 ����������: " << svarparm(7, 6, 1, 2, 3, 4, 5, 6);

	cout << "\n\n������� fvarparm: " << endl;
	cout << "1 ��������: " << fvarparm(FLT_MAX) << endl;
	cout << "2 ���������: " << fvarparm(1.45, FLT_MAX) << endl;
	cout << "3 ���������: " << fvarparm(3.55, 2.48, FLT_MAX) << endl;
	cout << "7 ����������: " << fvarparm(7, 2.15, 3.48, 4.47, 5.47, 6.69, FLT_MAX);

	cout << "\n\n������� dvarparm: " << endl;
	cout << "1 ��������: " << dvarparm(DBL_MAX) << endl;
	cout << "2 ���������: " << dvarparm(2.14, DBL_MAX) << endl;
	cout << "3 ���������: " << dvarparm(3.41, 2.36, DBL_MAX) << endl;
	cout << "7 ����������: " << dvarparm(7.25, 2.25, 3.36, 4.47, 5.36, 6.87, DBL_MAX) << endl;


	system("pause");
	return 0;
}
