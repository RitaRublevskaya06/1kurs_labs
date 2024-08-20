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
	cout << "Введите информацию о 8-и поездах" << endl << endl;
	for (int i = 0; i < 8; i++) {
		cout << "Введите номер поезда: ";
		cin >> mass[i].train;
		cout << "Введите пункт назначения: ";
		cin >> mass[i].destination;
		cout << "Введите время оправления (часы): ";
		cin >> mass[i].departure_hours;
		cout << "Введите время отправления (миинуты): ";
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
	cout << "Сортировка по алфавиту по пунктам назначения: ";
	for (int i = 0; i < 8; i++) cout << mass[i].destination << ' ';
	cout << endl;
	int hours, minutes;
	cout << "Введите часы: ";
	cin >> hours;
	cout << "Введите минуты: ";
	cin >> minutes;
	cout << endl;
	cout << "Информация о поездах, идущих позже заданного времени: " << endl << endl;
	int flag = 0;
	for (int i = 0; i < 8; i++) {
		if (mass[i].departure_hours > hours || (mass[i].departure_hours == hours && mass[i].departure_minutes > minutes)) {
			cout << "Номер поезда: " << mass[i].train << endl;
			cout << "Пункт назначения: " << mass[i].destination << endl;
			cout << "Время оправления: " << mass[i].departure_hours << ':' << mass[i].departure_minutes << endl;
			cout << endl;
			flag = 1;
		}
	}
	if (flag == 0) cout << "Таких поездов нет";
}
