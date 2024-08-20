#include "Hash.h"
#include <iostream>
// Универсальная хеш-функция
int UniversalHash(int key, int size, int a, int b, int p) {
    return ((a * key + b) % p) % size;
}

// Создание объекта типа Object
Object create(int size, int(*getkey)(void*)) {
    return *(new Object(size, getkey));
}

// Инициализация объекта типа Object
Object::Object(int size, int(*getkey)(void*)) {
    N = 0;
    this->size = size;
    this->getKey = getkey;
    this->data = new void* [size];
    for (int i = 0; i < size; ++i)
        data[i] = NULL;

    // Генерация случайных коэффициентов для универсальной хеш-функции
    a = rand() % (size - 1) + 1;
    b = rand() % (size - 1) + 1;
    p = size * 2 + 1;
}

// Вставка элемента в хеш-таблицу
bool Object::insert(void* d) {
    bool b = false;
    if (N != size) {
        for (int i = 0, t = getKey(d), j = UniversalHash(t, size, a, b, p); i != size && !b; j = (j + 1) % size, ++i) {
            if (data[j] == NULL || data[j] == DEL) {
                data[j] = d;
                N++;
                b = true;
            }
        }
    }
    return b;
}

// Поиск элемента в хеш-таблице по его ключу
int Object::searchInd(int key) {
    int t = -1;
    bool b = false;
    if (N != 0) {
        for (int i = 0, j = UniversalHash(key, size, a, b, p); data[j] != NULL && i != size && !b; j = (j + 1) % size, ++i) {
            if (data[j] != DEL) {
                if (getKey(data[j]) == key) {
                    t = j;
                    b = true;
                }
            }
        }
    }
    return t;
}
