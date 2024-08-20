#include <iostream>
using namespace std;

int dnx(int n, int x)
{
	if (x == 1)
		return 1;
	if (n % x == 0 && x > 1)
		return dnx(n, x - 1) + 1;
	else
		return dnx(n, x - 1);
}

int dn(int n) {
	return dnx(n, n);
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите натуральное число: ";
	cin >> n;
	while (n < 1) {
		cout << "Ќеверное значение, повторите попытку: ";
		cin >> n;
	}
	cout << " оличество всех положительных делителей натурального числа " << n << ": " << dn(n) << endl;
}