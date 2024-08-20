#include "header.h"

void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    
	e->data = x;             
	e->next = myStk->head;   
	myStk->head = e;         
}
int pop(Stack* myStk)   //Удаление элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
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
void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
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
		cout << "\n Ошибка открытия файла для записи";
		exit(1);
	}
	Stack* e = myStk->head;    
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
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
int fun1(Stack* myStk)  // Подсчет количества повторяющихся элементов стека 
{
	Stack* e, * k;
	e = myStk->head;
	int count = 0; 
	int a, b;
	cout << "Повторяющиеся элементы: ";
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
	cout << "Число повторяющихся элементов: " << count << endl;
	return 0;
}
