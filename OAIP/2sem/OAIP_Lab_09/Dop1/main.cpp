#include "List.h"
#include <iostream>
using namespace std;


bool Object::Insert(void* data)           // ������� � ������
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(void* data)    // ����� �������� �������
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*))     // �����
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*), Element* e)
{
	f(e->Data);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // ������� �� ������
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(void* data)      // ������� �� ��������
{
	return Delete(Search(data));
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object());
}

struct Person
{
	char name[20];
	int age;
	Person* next;
};

void print(void* b)       //������� ������������ ��� ������ 
{
	Person* a = (Person*)b;
	cout << a->name << "  " << a->age << endl;
}
void Object::deleteList()
{
	while (Head != nullptr)
	{
		Element* temp = Head;
		Head = Head->Next;
		delete temp;
	}
}

int Object::countList()
{
	int count = 0;
	Element* current = Head;
	while (current != nullptr)
	{
		count++;
		current = current->Next;
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Person a1 = { "������", 20 };
	Person a2 = { "�������", 25 };
	Person a3 = { "��������", 47 };
	bool rc;
	Object L1 = Create();   // �������� ������ � ������ L1
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	L1.PrintList(print);
	Element* e = L1.Search(&a3);
	Person* aa = (Person*)e->Data;
	cout << "������ �������= " << aa->name << endl;
	rc = L1.Delete(&a2);
	if (rc == true) cout << "������ �������" << endl;
	cout << "������:" << endl;
	L1.PrintList(print);
	return 0;
}

