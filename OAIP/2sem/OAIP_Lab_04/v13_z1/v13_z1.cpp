#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct Time
{
	int hours, minutes;
};
struct Terminal
{
	int train;
	char destination[20], days[20];
	Time departure_time, arrival_time;
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	const char* file = "TERMINAL.bin";
	Terminal mass[20], buf;
	mass[0] = { 150, "Полоцк", "пн, пт", 14, 25, 18, 14 };
	mass[1] = { 814, "Брест", "вт, ср, сб", 17, 12, 21, 58 };
	mass[2] = { 236, "Санкт-Петербург", "пн, чт", 23, 36, 10, 21 };
	mass[3] = { 672, "Орша", "ср, пт, вс", 06, 30, 10, 47 };
	cout << "Добро пожаловать в базу данный вокзала!" << endl << endl;;
	cout << "Что вы хотите выполнить?" << endl;
	cout << "1. - Поиск поезда, идущего до определенного пункта назначения" << endl;
	cout << "2. - Вывод информации о заданном поезде" << endl;
	cout << "3. - Создание нового поезда" << endl;
	cout << "4. - Удаление существующего поезда" << endl;
	cout << "0. - Выход" << endl << endl;
	int a, kol = 4, flag = 0, number;
	char town[20];
	fstream in_out(file, ios::binary | ios::in | ios::out | ios::trunc);
	do {
		cout << "Введите номер операции: ";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1: cout << "Введите пункт назначения: ";
			cin >> town;
			cout << "Номера поездов, идущих до пункта назначения " << town << ": ";
			for (int i = 0; i < kol; i++) {
				flag = 0;
				for (int j = 0; j < strlen(town); j++) {
					if (town[j] != mass[i].destination[j]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0)
					cout << mass[i].train << ' ';
			}
			cout << endl << endl;
			break;
		case 2: cout << "Номера поездов: ";
			for (int i = 0; i < kol; i++)
				cout << mass[i].train << ' ';
			cout << endl;
			cout << "Введите номер поезда для получения информации о нем: ";
			cin >> number;
			cout << endl;
			for (int i = 0; i < kol; i++) {
				if (mass[i].train == number) {
					cout << "Пункт назначения: " << mass[i].destination << endl;
					cout << "Дни следования: " << mass[i].days << endl;
					cout << "Время отправления: " << mass[i].departure_time.hours << ":" << mass[i].departure_time.minutes << endl;
					cout << "Время прибытия: " << mass[i].arrival_time.hours << ":" << mass[i].arrival_time.minutes << endl;
					break;
				}
				if (i == kol - 1 && mass[i].train != number) cout << "Ошибка: такого пезда не существует" << endl;
			}
			cout << endl;
			break;
		case 3: cout << "Введите номер поезда: ";
			cin >> buf.train;
			cout << "Введите пункт назначения: ";
			cin >> buf.destination;
			cout << "Введите дни: ";
			cin >> buf.days;
			cout << "Введите время отправления (часы): ";
			cin >> buf.departure_time.hours;
			cout << "Введите время отправления (минуты): ";
			cin >> buf.departure_time.minutes;
			cout << "Введите время прибытия (часы): ";
			cin >> buf.arrival_time.hours;
			cout << "Введите время прибытия (минуты): ";
			cin >> buf.arrival_time.minutes;
			in_out.write((char*)&buf, sizeof Terminal);
			in_out.seekg(0);
			in_out.read((char*)&mass[kol], sizeof Terminal);
			kol++;
			cout << "Информация о поезде добавлена" << endl << endl;
			break;
		case 4: cout << "Номера поездов: ";
			for (int i = 0; i < kol; i++)
				cout << mass[i].train << ' ';
			cout << endl;
			cout << "Введите номер поезда, который нужно удалить: ";
			cin >> number;

			for (int i = 0; i < kol; i++) {
				if (mass[i].train == number) {
					for (i; i < kol; i++) {
						if (i == kol - 1) break;
						else {
							buf = mass[i + 1];
							mass[i] = buf;
						}
					}
					kol--;
				}
			}
			cout << "Информация о заданном поезде удалена" << endl << endl;
			break;
		default: if (a != 0)
			cout << "Неверный номер операции, повторите попытку." << endl << endl; break;
		}
	} while (a != 0);
	cout << "До свидания!" << endl;
	in_out.close();
}