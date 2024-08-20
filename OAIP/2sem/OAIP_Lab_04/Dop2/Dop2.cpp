#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct TRAIN
{
	int train;
	char destination[20];
	int departure_hours, departure_minutes;
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	TRAIN mass[8], buf;
	cout << "������� ���������� � 8-� �������" << endl << endl;
	for (int i = 0; i < 8; i++) {
		cout << "������� ����� ������: ";
		cin >> mass[i].train;
		cout << "������� ����� ����������: ";
		cin >> mass[i].destination;
		cout << "������� ����� ���������� (����): ";
		cin >> mass[i].departure_hours;
		cout << "������� ����� ����������� (�������): ";
		cin >> mass[i].departure_minutes;
		cout << endl;
	}
	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			if (mass[i].destination[0] < mass[j].destination[0]) {
				buf = mass[j];
				mass[j] = mass[i];
				mass[i] = buf;
				i--;
			}
		}
	}
	cout << "���������� �� �������� �� ������� ����������: ";
	for (int i = 0; i < 8; i++) cout << mass[i].destination << ' ';
	cout << endl;
	int hours, minutes;
	cout << "������� ����: ";
	cin >> hours;
	cout << "������� ������: ";
	cin >> minutes;
	cout << endl;
	cout << "���������� � �������, ������ ����� ��������� �������: " << endl << endl;
	int flag = 0;
	for (int i = 0; i < 8; i++) {
		if (mass[i].departure_hours > hours || (mass[i].departure_hours == hours && mass[i].departure_minutes > minutes)) {
			cout << "����� ������: " << mass[i].train << endl;
			cout << "����� ����������: " << mass[i].destination << endl;
			cout << "����� ����������: " << mass[i].departure_hours << ':' << mass[i].departure_minutes << endl;
			cout << endl;
			flag = 1;
		}
	}
	if (flag == 0) cout << "����� ������� ���";
}
