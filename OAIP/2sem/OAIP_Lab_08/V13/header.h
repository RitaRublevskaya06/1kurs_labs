#pragma once

#include<iostream> 
using namespace std;
struct Number
{
    int info;
    Number* next;
};

void create(Number** begin, Number** end, int p, int size); //������������ ��������� �������
void view(Number* begin, int size); //������� ������ ��������� ������� 
void Del(Number** begin, Number** p); //������� �������� �� ������������ �������� 
Number* minElem(Number* begin); //������� ����������� ������������ �������� 
Number* maxElem(Number* begin); //������� ����������� ������������� ��������