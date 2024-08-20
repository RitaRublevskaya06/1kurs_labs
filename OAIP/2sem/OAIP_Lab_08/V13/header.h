#pragma once

#include<iostream> 
using namespace std;
struct Number
{
    int info;
    Number* next;
};

void create(Number** begin, Number** end, int p, int size); //формирование элементов очереди
void view(Number* begin, int size); //функция вывода элементов очереди 
void Del(Number** begin, Number** p); //функция удаления до минимального элемента 
Number* minElem(Number* begin); //функция определения минимального элемента 
Number* maxElem(Number* begin); //функция определения максимального элемента