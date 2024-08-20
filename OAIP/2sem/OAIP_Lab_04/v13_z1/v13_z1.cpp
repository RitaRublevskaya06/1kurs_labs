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
	mass[0] = { 150, "������", "��, ��", 14, 25, 18, 14 };
	mass[1] = { 814, "�����", "��, ��, ��", 17, 12, 21, 58 };
	mass[2] = { 236, "�����-���������", "��, ��", 23, 36, 10, 21 };
	mass[3] = { 672, "����", "��, ��, ��", 06, 30, 10, 47 };
	cout << "����� ���������� � ���� ������ �������!" << endl << endl;;
	cout << "��� �� ������ ���������?" << endl;
	cout << "1. - ����� ������, ������� �� ������������� ������ ����������" << endl;
	cout << "2. - ����� ���������� � �������� ������" << endl;
	cout << "3. - �������� ������ ������" << endl;
	cout << "4. - �������� ������������� ������" << endl;
	cout << "0. - �����" << endl << endl;
	int a, kol = 4, flag = 0, number;
	char town[20];
	fstream in_out(file, ios::binary | ios::in | ios::out | ios::trunc);
	do {
		cout << "������� ����� ��������: ";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1: cout << "������� ����� ����������: ";
			cin >> town;
			cout << "������ �������, ������ �� ������ ���������� " << town << ": ";
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
		case 2: cout << "������ �������: ";
			for (int i = 0; i < kol; i++)
				cout << mass[i].train << ' ';
			cout << endl;
			cout << "������� ����� ������ ��� ��������� ���������� � ���: ";
			cin >> number;
			cout << endl;
			for (int i = 0; i < kol; i++) {
				if (mass[i].train == number) {
					cout << "����� ����������: " << mass[i].destination << endl;
					cout << "��� ����������: " << mass[i].days << endl;
					cout << "����� �����������: " << mass[i].departure_time.hours << ":" << mass[i].departure_time.minutes << endl;
					cout << "����� ��������: " << mass[i].arrival_time.hours << ":" << mass[i].arrival_time.minutes << endl;
					break;
				}
				if (i == kol - 1 && mass[i].train != number) cout << "������: ������ ����� �� ����������" << endl;
			}
			cout << endl;
			break;
		case 3: cout << "������� ����� ������: ";
			cin >> buf.train;
			cout << "������� ����� ����������: ";
			cin >> buf.destination;
			cout << "������� ���: ";
			cin >> buf.days;
			cout << "������� ����� ����������� (����): ";
			cin >> buf.departure_time.hours;
			cout << "������� ����� ����������� (������): ";
			cin >> buf.departure_time.minutes;
			cout << "������� ����� �������� (����): ";
			cin >> buf.arrival_time.hours;
			cout << "������� ����� �������� (������): ";
			cin >> buf.arrival_time.minutes;
			in_out.write((char*)&buf, sizeof Terminal);
			in_out.seekg(0);
			in_out.read((char*)&mass[kol], sizeof Terminal);
			kol++;
			cout << "���������� � ������ ���������" << endl << endl;
			break;
		case 4: cout << "������ �������: ";
			for (int i = 0; i < kol; i++)
				cout << mass[i].train << ' ';
			cout << endl;
			cout << "������� ����� ������, ������� ����� �������: ";
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
			cout << "���������� � �������� ������ �������" << endl << endl;
			break;
		default: if (a != 0)
			cout << "�������� ����� ��������, ��������� �������." << endl << endl; break;
		}
	} while (a != 0);
	cout << "�� ��������!" << endl;
	in_out.close();
}