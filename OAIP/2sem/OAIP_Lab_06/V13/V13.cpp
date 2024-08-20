#include <iostream>
#include <fstream>
using namespace std;
struct list
{
	int number;
	list* next;
};

void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
int del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
void printList(list*);      //функция вывода
void sum(list*);  //функция подсчета суммы отрицательных двухзначных элементов  
void to_file(list*& p);  //функция записи в файл
void from_file(list*& p);  //функция считывание из файла

int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	int a;
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - Подсчет суммы отрицательных двухзначных элементов" << endl;
	cout << " 4 - Вывод списка" << endl;
	cout << " 5 - Запись списка в файл" << endl;
	cout << " 6 - Чтение списка из файла" << endl;
	cout << " 7 - Выход" << endl;
	cout << "Выберете действие: ";
	cin >> choice;
	while (choice != 7)
	{
		switch (choice)
		{
		case 1:  	cout << "Введите число ";
			cin >> a;
			insert(first, a);
			break;
		case 2:   if (first != NULL) 
		{
			cout << "Введите удаляемое число ";
			cin >> a;
			if (del(first, a))
			{
				cout << "Удалено число " << a << endl;
			}
			else
				cout << "Число не найдено" << endl;
		}
			  else
			cout << "Список пуст" << endl;
			break;
		case 3:   sum(first);	
			break;
		case 4: printList(first);
			break;
		case 5:    to_file(first);
			break;
		case 6:    from_file(first);
			break;
		default:  cout << "Неправильный выбор" << endl;
			break;
		}
		cout << "Выберете действие: ";
		cin >> choice;
	}
	return 0;
}

void insert(list*& p, int a)  
{
	list* newP = new list;
	newP->number = a;
	newP->next = p;
	p = newP;
}

int del(list*& p, int a)  
{
	list* previous, * current, * temp;
	if (a == p->number)
	{
		temp = p;
		p = p->next;    
		delete temp;      
		return a;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != a)
		{
			previous = current;
			current = current->next; 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return a;
		}
	}
}

void printList(list* p)  
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << p->number << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void sum(list* p)  
{
	int sm = 0;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number < 0 && p->number > -100)
				sm = sm + (p->number);
			p = p->next;
		}
		if (sm == 0) cout << "Таких элементов нет" << endl;
		else cout << "Сумма = " << sm << endl;
	}
}

void to_file(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("List.dat");
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл List.dat\n";
}

void from_file(list*& p)          
{
	list buf, * first = nullptr;
	ifstream frm("List.dat");
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.number);
		cout << buf.number << " ";
		frm.read((char*)&buf, sizeof(list));
	}
	cout << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла List.dat\n";
}