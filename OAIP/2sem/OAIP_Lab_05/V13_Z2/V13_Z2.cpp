#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
union Buf
{
	char name[20], capital[20];
	float population, square;
	char president_surname[10];
};
struct Country
{
	char name[20], capital[20];
	float population, square;
	char president_surname[10];
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	Country mass[20];
	Buf buf;
	const char* file = "Country.bin";
	int i = 0, beg;
	char str[20];
	cout << "������� ���������� � 3 �������" << endl << endl;
	for (i = 0; i < 3; i++) {
		fstream in_out(file, ios::binary | ios::in | ios::out | ios::trunc);
		in_out.seekp(0);
		cout << "������� ������������ ������: ";
		beg = in_out.tellg();
		cin >> buf.name;
		in_out.write((char*)&buf.name, sizeof buf.name);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].name, sizeof mass[i].name);
		cout << "������� �������: ";
		beg = in_out.tellg();
		cin >> buf.capital;
		in_out.write((char*)&buf.capital, sizeof buf.capital);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].capital, sizeof mass[i].capital);
		cout << "������� ����������� ��������� (� ���������): ";
		beg = in_out.tellg();
		cin >> buf.population;
		in_out.write((char*)&buf.population, sizeof buf.population);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].population, sizeof mass[i].population);
		cout << "������� ������� (� ��������� �����������): ";
		beg = in_out.tellg();
		cin >> buf.square;
		in_out.write((char*)&buf.square, sizeof buf.square);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].square, sizeof mass[i].square);
		cout << "������� ������� ����������: ";
		beg = in_out.tellg();
		cin >> buf.president_surname;
		in_out.write((char*)&buf.president_surname, sizeof buf.president_surname);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].president_surname, sizeof mass[i].president_surname);
		in_out.close();
		cout << endl << endl;
	}
	cout << "����� ���������� � �������� ������" << endl;
	cout << "������� �������� ������: ";
	cin >> str;
	cout << "���������� � ������ ������:" << endl;
	for (i = 0; i < 3; i++) {
		if (strcmp(mass[i].name, str) == 0) {
			cout << "�������: " << mass[i].capital << endl;
			cout << "����������� ��������� (� ��������): " << mass[i].population << endl;
			cout << "������� (� ���������� ������): " << mass[i].square << endl;
			cout << "������� ����������: " << mass[i].president_surname << endl;
		}
		if (strcmp(mass[i].name, str) != 0 && i == 2) cout << "���������� � ������ ������ ���";
	}
}
