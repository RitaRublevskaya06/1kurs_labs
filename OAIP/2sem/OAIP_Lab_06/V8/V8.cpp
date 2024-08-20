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
void sum(list*);   // функция подсчета суммы отрицательных элементов, кратных 2  
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
	cout << " 3 - Подсчет суммы отрицательных элементов, кратных 2" << endl;
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
		case 1:  	cout << "Введите число "; // добавить число в список
			cin >> a;
			insert(first, a);
			break;
		case 2:   if (first != NULL) // удалить число из списка
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
		case 3:   sum(first);	// вычисление суммы	
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

void insert(list*& p, int a) //Добавление числа a в список 
{
	list* newP = new list;
	newP->number = a;
	newP->next = p;
	p = newP;
}

int del(list*& p, int a)  // Удаление числа a
{
	list* previous, * current, * temp;
	if (a == p->number)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел 
		return a;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != a)
		{
			previous = current;
			current = current->next; // перейти к следующему 
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

void printList(list* p)  //Вывод списка 
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

void sum(list* p)  // Подсчет суммы отрицательных элементов, кратных 5
{
	int sm = 0;
	bool found = false;  // Флаг, показывающий, что был найден хотя бы один подходящий элемент

	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number < 0 && p->number % 2 == 0)  // Условие изменено на отрицательные элементы, кратные 2
			{
				sm += p->number;
				found = true;
			}
			p = p->next;
		}

		if (!found)
			cout << "Таких элементов нет" << endl;
		else
			cout << "Сумма = " << sm << endl;
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

void from_file(list*& p)          //Считывание из файла
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