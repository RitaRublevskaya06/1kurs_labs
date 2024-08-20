#include "header.h"

int main()
{
	Number* begin = NULL, * end, * t;
	t = new Number;
	int p, size;
	setlocale(LC_ALL, "Rus");
	int choice;
	cout << "В очередь будут помещаться только отрицательные элементы" << endl;
	cout << "Введите размер очереди: ";
	cin >> size;
	cout << "Введите первый отрицательный элемент: ";
	cin >> p;
	while (p >= 0)
	{
		cout << "Неверное значение, повторите попытку: ";
		cin >> p;
	}
	t->info = p;        
	t->next = NULL;
	begin = end = t;
	cout << "1 - Ввод элементов очереди" << endl;
	cout << "2 - Вывод очереди и количества ее элементов" << endl;
	cout << "3 - Очистка очереди" << endl;
	cout << "4 - Вывод максиального и минимального элементов очереди" << endl;
	cout << "5 - Выход" << endl << endl;

	for (;;)
	{
		cout << "Выберите команду: ";
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
			cout << "Минимальный элемент очереди - " << t->info;
			t = maxElem(begin);
			cout << ", максимальный элемент очереди - " << maxElem(begin)->info << endl;
			break;
		case 5: return 0;
			break;
		}
	}
}