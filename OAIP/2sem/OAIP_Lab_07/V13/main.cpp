#include "header.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; 
	myStk->head = NULL;       	
	cout << "�������� �����:" << endl;
	cout << "1 - ���������� �������� � ����" << endl;
	cout << "2 - �������� �������� �� �����" << endl;
	cout << "3 - ����� �����" << endl;
	cout << "4 - ���� ����� � ����" << endl;
	cout << "5 - ����� ����� �� �����" << endl;
	cout << "6 - ������� �����" << endl;
	cout << "7 - ������� ���������� ������������� ��������� �����" << endl;
	cout << "8 - �����" << endl << endl;
	for (;;)
	{
		
		cout << "�������� �������: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������: ";
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "����������� �������: " << choice ;
			break;
		case 3: cout << "���� ����: " << endl;
			show(myStk);
			break;
		case 4: cout << "���� ���� ������� � ���� File.txt " << endl;
			InFile(myStk);
			break;
		case 5: cout << "���� ���� ������� �� ����� File.txt " << endl;
			OutFile(myStk);
			break;
		case 6: cout << "���� ������ " << endl;
			clear(myStk);
			break;
		case 7: fun1(myStk);
			break;
		case 8: return 0;
			break;
		}
	}
}
