#include "header.h"

int main()
{
	Number* begin = NULL, * end, * t;
	t = new Number;
	int p, size;
	setlocale(LC_ALL, "Rus");
	int choice;
	cout << "� ������� ����� ���������� ������ ������������� ��������" << endl;
	cout << "������� ������ �������: ";
	cin >> size;
	cout << "������� ������ ������������� �������: ";
	cin >> p;
	while (p >= 0)
	{
		cout << "�������� ��������, ��������� �������: ";
		cin >> p;
	}
	t->info = p;        
	t->next = NULL;
	begin = end = t;
	cout << "1 - ���� ��������� �������" << endl;
	cout << "2 - ����� ������� � ���������� �� ���������" << endl;
	cout << "3 - ������� �������" << endl;
	cout << "4 - ����� ������������ � ������������ ��������� �������" << endl;
	cout << "5 - �����" << endl << endl;

	for (;;)
	{
		cout << "�������� �������: ";
		cin >> choice;
		switch (choice)
		{
		case 1: create(&begin, &end, p, size);  
			break;
		case 2: view(begin, size);  
			break;
		case 3: Del(&begin, &t); 
			break;
		case 4: t = minElem(begin);
			cout << "����������� ������� ������� - " << t->info;
			t = maxElem(begin);
			cout << ", ������������ ������� ������� - " << maxElem(begin)->info << endl;
			break;
		case 5: return 0;
			break;
		}
	}
}