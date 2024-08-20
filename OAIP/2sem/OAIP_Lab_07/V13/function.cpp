#include "header.h"

void push(int x, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    
	e->data = x;             
	e->next = myStk->head;   
	myStk->head = e;         
}
int pop(Stack* myStk)   //�������� �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               
	}
	else
	{
		Stack* e = myStk->head;   
		int a = myStk->head->data;   
		myStk->head = myStk->head->next; 
		delete e;                       
		return a;                        
	}
}
void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void InFile(Stack* myStk)
{
	ofstream B("File.txt", ios::app);
	if (B.fail())
	{
		cout << "\n ������ �������� ����� ��� ������";
		exit(1);
	}
	Stack* e = myStk->head;    
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{

		a = e->data;          
		B << a << " ";
		e = e->next;
	}
	cout << endl;

	B.close();
}
void OutFile(Stack* myStk) {
	ifstream A("File.txt", ios::in);
	char str[40];
	while (!A.eof())
	{
		A.getline(str, 40, '\n');
		cout << str << " ";
	}
	cout << endl;

	A.close();
}
void clear(Stack* myStk) {
	myStk->head = NULL;
}
int fun1(Stack* myStk)  // ������� ���������� ������������� ��������� ����� 
{
	Stack* e, * k;
	e = myStk->head;
	int count = 0; 
	int a, b;
	cout << "������������� ��������: ";
	while (e != NULL) {
		a = e->data;
		k = e->next;
		while (k != NULL) {
			b = k->data;
			if (a == b) {
				cout << a << " ";
				count++;
				break;
			}
			k = k->next;
		}
		e = e->next;
	}
	cout << endl;
	cout << "����� ������������� ���������: " << count << endl;
	return 0;
}
