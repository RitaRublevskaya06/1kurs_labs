#pragma once

#include <iostream>
#include <fstream>
using namespace std;

struct Stack
{
	int data;             
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
void InFile(Stack* myStk);
void OutFile(Stack* myStk);
void clear(Stack* myStk);
int fun1(Stack* myStk);

