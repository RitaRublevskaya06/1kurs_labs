#include "Hash_Chain.h"
#include <iostream>
#include <ctime>
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = nullptr;
	}
};
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//Печать элемента списка
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//Главная функция программы 
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	clock_t t1, t2;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление группы" << endl;
		cout << "3 - удаление группы" << endl;
		cout << "4 - поиск группы" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 2: {	AAA* a = new AAA;
			char* str = new char[20];
			cout << "Введите номер группы" << endl;
			cin >> k;
			a->key = k;
			cout << "Введите кол-вот студентов" << endl;
			cin >> str;
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	AAA* b = new AAA;
			cout << "введите номер группы" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "введите номер группы" << endl;
			cin >> k;
			c->key = k;
			t1 = clock();
			if (H.search(c) == NULL)
				cout << "Группа не найдена" << endl;
			else
			{
				cout << "Первая найденная группа с данным номером" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			t2 = clock();
			cout << "Время выполнения поиска: " << t2 - t1 << " тактов времени" << endl;
			break;
		}
	}
	return 0;
}
