#include <iostream>
#include <windows.h>
using namespace std;
enum Faculty {
	LF = 1, LID, FTOV, FHTiT, FPiM, IEF, FIT
};
struct Date
{
	unsigned short day : 5;       // 5 ����� - 32
	unsigned short month : 4;    // 4 ���� - 16  
	unsigned short year : 11;   // 11 ��� - 2048
};

struct Student
{
	char surname[20], name[20], patronymic[20];
	Date date;
	char spec[10];
	int group;
	int faculty;
	float ave_mark;
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	Student mass[20];
	cout << "����� ���������� � ���� ������ ���������!" << endl << endl;
	cout << "��� �� ������ ���������?" << endl;
	cout << "1. - ������ ������ ��������" << endl;
	cout << "2. - ����� �������� �� �������� �����" << endl;
	cout << "3. - �������� ��������" << endl;
	cout << "0. - �����" << endl << endl;
	int a, kol = 4, flag = 0, i = 0;
	float mark;
	char buf[20];
	do {
		cout << "������� ����� ��������: ";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1: int z;
			char str[5];
			cout << "�������: ";
			cin >> mass[i].surname;
			cout << "���: ";
			cin >> mass[i].name;
			cout << "��������: ";
			cin >> mass[i].patronymic;
			cout << "���� ����������: ";
			cin >> z;
			mass[i].date.day = z;
			cout << "����� ����������: ";
			cin >> z;
			mass[i].date.month = z;
			cout << "��� ����������: ";
			cin >> z;
			mass[i].date.year = z;
			cout << "�������������: ";
			cin >> mass[i].spec;
			cout << "������: ";
			cin >> mass[i].group;
			cout << "���������: ";
			cin >> str;
			if (strcmp(str, "��") == 0) mass[i].faculty = LF;
			if (strcmp(str, "���") == 0) mass[i].faculty = LID;
			if (strcmp(str, "����") == 0) mass[i].faculty = FTOV;
			if (strcmp(str, "�����") == 0) mass[i].faculty = FHTiT;
			if (strcmp(str, "����") == 0) mass[i].faculty = FPiM;
			if (strcmp(str, "���") == 0) mass[i].faculty = IEF;
			if (strcmp(str, "���") == 0) mass[i].faculty = FIT;
			cout << "������� ����: ";
			cin >> mass[i].ave_mark;
			cout << endl;
			i++;
			break;
		case 2: cout << "����������: �� - 1, ��� - 2, ���� - 3, ����� - 4, ���� - 5, ��� - 6, ��� - 7" << endl;
			cout << "������� ������� ����: ";
			cin >> mark;
			cout << "���������� � ��������� ��������: " << endl;
			for (int j = 0; j < i + 1; j++) {
				if (mark == mass[j].ave_mark) {
					cout << "�������: " << mass[j].surname << endl;
					cout << "���: " << mass[j].name << endl;
					cout << "��������: " << mass[j].patronymic << endl;
					cout << "���� ����������: " << mass[j].date.day << endl;
					cout << "����� ����������: " << mass[j].date.month << endl;
					cout << "��� ����������: " << mass[j].date.year << endl;
					cout << "�������������: " << mass[j].spec << endl;
					cout << "������: " << mass[j].group << endl;
					cout << "���������: " << mass[j].faculty;
				}
			}
			cout << endl << endl;
			break;
		case 3: cout << "������� ���������: ";
			for (int j = 0; j < i; j++)
				cout << mass[j].surname << ' ';
			cout << endl;
			cout << "������� ������� ��������, �������� ����� �������: ";
			cin >> buf;
			for (int j = 0; j < i + 1; j++) {
				if (strcmp(buf, mass[j].surname) == 0) {
					for (int k = j; k < i; k++) {
						mass[k] = mass[k + 1];
					}
					j--;
					i--;
				}
			}
			cout << "���������� � �������� �������� �������" << endl << endl;
			break;
		default: if (a != 0)
			cout << "�������� ����� ��������, ��������� �������." << endl << endl; break;
		}
	} while (a != 0);
	cout << "�� ��������!" << endl;
}
