#include "header.h"

void create(Number** begin, Number** end, int p, int size) //Формирование элементов очереди
{
    for (int i = 1; i < size; i++) //Создание очереди
    {
        cout << "Введите число:  ";
        cin >> p;
        if (p >= 0) {
            i--;
        }
        else {
            Number* t = new Number;
            t->next = NULL;
            if (*begin == NULL)
                *begin = *end = t;
            else
            {
                t->info = p;
                (*end)->next = t;
                *end = t;
            }
        }
    }
}
void view(Number* begin, int size) //Вывод элементов очереди 
{
    if (begin == NULL)
        cout << "Очередь пуста" << endl;
    else {
        Number* t = begin;
        while (t != NULL)
        {
            cout << t->info << ' ';
            t = t->next;
        }
        cout << endl << "Количество элементов: " << size << endl;
    }
}
void Del(Number** begin, Number** p) //Очистка очереди
{
    Number* t;
    t = new Number;
    while (*begin != NULL)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
    begin = NULL;
    cout << "Очередь очищена!" << endl;
}
Number* minElem(Number* begin) //Определение минимального элемента
{
    Number* t = begin, * mn = 0;
    int min;
    if (t == NULL)
    {
        cout << "Очередь пуста!\n"; return 0;
    }
    else
    {
        min = t->info;
        while (t != NULL)
        {
            if (t->info <= min)
            {
                min = t->info;
                mn = t;
            }
            t = t->next;
        }
    }
    return mn;
}
Number* maxElem(Number* begin) //Определение максимального элемента
{
    Number* t = begin, * mx = 0;
    int max;
    if (t == NULL)
    {
        cout << "Очередь пуста!\n"; return 0;
    }
    else
    {
        max = t->info;
        while (t != NULL)
        {
            if (t->info >= max)
            {
                max = t->info;
                mx = t;
            }
            t = t->next;
        }
    }
    return mx;
}