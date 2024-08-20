#include "Hash.h"
#include <iostream>
#include <random>

int UniversalHashFunction(int key, int size) { // Функция универсального хеширования
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, size - 1);

	int a = dis(gen);
	int b = dis(gen);

	return ((a * key + b) % size);
}
//Хеш-функция по методу двойного хеширования
int Next_hash(int hash, int size, int p)
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//Создание объекта типа Object
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//Инициализация объекта типа Object
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//Вставка элемента в хеш-таблицу
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = UniversalHashFunction(t, size);
			i != size && !b;  j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}
//Поиск элемента в хеш-таблице по его ключу
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = UniversalHashFunction(key, size); data[j] != NULL && i != size && !b; j = UniversalHashFunction(key, size))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//Получение указателя на элемент в хеш-таблице по его ключу
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//Удаление элемента из хеш-таблицы по его ключу
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//Удаление элемента из хеш-таблицы по его значению
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//Обход хеш-таблицы и выполнение указанной функции для каждого элемента
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}
