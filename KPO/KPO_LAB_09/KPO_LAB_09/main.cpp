#include "Varparm.h"
#include <iostream>
#include <cfloat>

using namespace Varparm;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Функция ivarparm: " << endl;
	cout << "1 параметр: " << ivarparm(1, 0) << endl;
	cout << "2 параметра: " << ivarparm(2, 4, 5) << endl;
	cout << "3 параметра: " << ivarparm(3, 2, 2, 3) << endl;
	cout << "7 параметров: " << ivarparm(7, 6, 1, 2, 3, 4, 5, 6);

	cout << "\n\nФункция svarparm: " << endl;
	cout << "1 параметр: " << svarparm(1, 0) << endl;
	cout << "2 параметра: " << svarparm(2, 1, 2) << endl;
	cout << "3 параметра: " << svarparm(3, 2, 2, 3) << endl;
	cout << "7 параметров: " << svarparm(7, 6, 1, 2, 3, 4, 5, 6);

	cout << "\n\nФункция fvarparm: " << endl;
	cout << "1 параметр: " << fvarparm(FLT_MAX) << endl;
	cout << "2 параметра: " << fvarparm(1.45, FLT_MAX) << endl;
	cout << "3 параметра: " << fvarparm(3.55, 2.48, FLT_MAX) << endl;
	cout << "7 параметров: " << fvarparm(7, 2.15, 3.48, 4.47, 5.47, 6.69, FLT_MAX);

	cout << "\n\nФункция dvarparm: " << endl;
	cout << "1 параметр: " << dvarparm(DBL_MAX) << endl;
	cout << "2 параметра: " << dvarparm(2.14, DBL_MAX) << endl;
	cout << "3 параметра: " << dvarparm(3.41, 2.36, DBL_MAX) << endl;
	cout << "7 параметров: " << dvarparm(7.25, 2.25, 3.36, 4.47, 5.36, 6.87, DBL_MAX) << endl;


	system("pause");
	return 0;
}
