#include "Lists.h"
#include <iostream>
struct AAA        //элемент таблицы
{
	int key;
	char* mas;
};
namespace listx
{
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		if (head == NULL)
			head = new Element(NULL, data, head);
		else
			head = (head->prev = new Element(NULL, data, head));
		return rc;
	}
	//Поиск элемента в списке по ключу
	Element* Object::search(void* data)
	{
		Element* rc = head;
		while ((rc != NULL) && ((((AAA*)rc->data)->key) != ((AAA*)data)->key))
			rc = rc->next;
		return rc;
	}
	//Удаление элемента из списка по указателю
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
		}
		std::cout << "Группа удалена" << std::endl;
		return rc;
	}
	//Удаление элемента из списка по значению
	bool Object::deleteByData(void* data)
	{
		return deleteByElement(search(data));
	}
	//Получение последнего элемента списка
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), * rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}

	Object create()
	{
		return *(new Object());
	};
	//Создание объекта списка
	void Object::scan()
	{
		listx::Element* e = this->getFirst();
		while (e != NULL)
		{
			std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
			e = e->getNext();
		};
	}
}
