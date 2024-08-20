#include "header.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; 
	myStk->head = NULL;       	
	cout << "Сделайте выбор:" << endl;
	cout << "1 - Добавление элемента в стек" << endl;
	cout << "2 - Удаление элемента из стека" << endl;
	cout << "3 - Вывод стека" << endl;
	cout << "4 - Ввод стека в файл" << endl;
	cout << "5 - Вывод стека из файла" << endl;
	cout << "6 - Очистка стека" << endl;
	cout << "7 - Подсчет количества повторяющихся элементов стека" << endl;
	cout << "8 - Выход" << endl << endl;
	for (;;)
	{
		
		cout << "Выберите команду: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: ";
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice ;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: cout << "Весь стек записан в файл File.txt " << endl;
			InFile(myStk);
			break;
		case 5: cout << "Весь стек выведен из файла File.txt " << endl;
			OutFile(myStk);
			break;
		case 6: cout << "Стек очищен " << endl;
			clear(myStk);
			break;
		case 7: fun1(myStk);
			break;
		case 8: return 0;
			break;
		}
	}
}
