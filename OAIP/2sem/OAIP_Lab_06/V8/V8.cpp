#include <iostream>
#include <fstream>
using namespace std;
struct list
{
	int number;
	list* next;
};

void insert(list*&, int); //������� ���������� ��������, ���������� ����� ������ � ������, ������� ����������� 
int del(list*&, int);   //������� ��������, ���������� ����� ������ � ������, ������� ��������� 
void printList(list*);      //������� ������
void sum(list*);   // ������� �������� ����� ������������� ���������, ������� 2  
void to_file(list*& p);  //������� ������ � ����
void from_file(list*& p);  //������� ���������� �� �����

int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	int a;
	cout << "�������� �����:" << endl;
	cout << " 1 - ���� �����" << endl;
	cout << " 2 - �������� �����" << endl;
	cout << " 3 - ������� ����� ������������� ���������, ������� 2" << endl;
	cout << " 4 - ����� ������" << endl;
	cout << " 5 - ������ ������ � ����" << endl;
	cout << " 6 - ������ ������ �� �����" << endl;
	cout << " 7 - �����" << endl;
	cout << "�������� ��������: ";
	cin >> choice;
	while (choice != 7)
	{
		switch (choice)
		{
		case 1:  	cout << "������� ����� "; // �������� ����� � ������
			cin >> a;
			insert(first, a);
			break;
		case 2:   if (first != NULL) // ������� ����� �� ������
		{
			cout << "������� ��������� ����� ";
			cin >> a;
			if (del(first, a))
			{
				cout << "������� ����� " << a << endl;
			}
			else
				cout << "����� �� �������" << endl;
		}
			  else
			cout << "������ ����" << endl;
			break;
		case 3:   sum(first);	// ���������� �����	
			break;
		case 4: printList(first);
			break;
		case 5:    to_file(first);
			break;
		case 6:    from_file(first);
			break;
		default:  cout << "������������ �����" << endl;
			break;
		}
		cout << "�������� ��������: ";
		cin >> choice;
	}
	return 0;
}

void insert(list*& p, int a) //���������� ����� a � ������ 
{
	list* newP = new list;
	newP->number = a;
	newP->next = p;
	p = newP;
}

int del(list*& p, int a)  // �������� ����� a
{
	list* previous, * current, * temp;
	if (a == p->number)
	{
		temp = p;
		p = p->next;    // ����������� ���� 
		delete temp;      //���������� ������������� ���� 
		return a;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != a)
		{
			previous = current;
			current = current->next; // ������� � ���������� 
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

void printList(list* p)  //����� ������ 
{
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << p->number << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void sum(list* p)  // ������� ����� ������������� ���������, ������� 5
{
	int sm = 0;
	bool found = false;  // ����, ������������, ��� ��� ������ ���� �� ���� ���������� �������

	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number < 0 && p->number % 2 == 0)  // ������� �������� �� ������������� ��������, ������� 2
			{
				sm += p->number;
				found = true;
			}
			p = p->next;
		}

		if (!found)
			cout << "����� ��������� ���" << endl;
		else
			cout << "����� = " << sm << endl;
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
	cout << "������ ������� � ���� List.dat\n";
}

void from_file(list*& p)          //���������� �� �����
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
	cout << "\n������ ������ �� ����� List.dat\n";
}