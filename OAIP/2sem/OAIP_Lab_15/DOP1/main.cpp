#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для заполнения массива случайными числами
void fillArray(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Функция для печати массива
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция сортировки пузырьком
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция сортировки вставками
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция сортировки выбором
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Функция сортировки слиянием
void mergeSort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;

    // Разделение массива на две части
    int* left = new int[mid];
    int* right = new int[size - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Сортировка левой и правой частей
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Слияние отсортированных частей
    int i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < mid) {
        arr[k++] = left[i++];
    }
    while (j < size - mid) {
        arr[k++] = right[j++];
    }

    // Удаление временных массивов
    delete[] left;
    delete[] right;
}

// Функция сортировки подсчетом
void countingSort(int* arr, int size) {
    // Найти максимальный элемент
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Создать массив счетчиков
    int* count = new int[maxElement + 1];
    for (int i = 0; i <= maxElement; i++) {
        count[i] = 0;
    }

    // Подсчитать количество вхождений каждого элемента
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Найти положение каждого элемента в отсортированном массиве
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Удалить массив счетчиков
    delete[] count;
}

int main() {
    // Размер массива
    int size = 10;

    // Создание массива
    int* arr = new int[size];

    // Заполнение массива случайными числами
    fillArray(arr, size);

    // Печать исходного массива
    cout << "Исходный массив: ";
    printArray(arr, size);

    // Сортировка массива с помощью пузырьковой сортировки
    bubbleSort(arr, size);
    cout << "Отсортированный массив пузырьковой сортировкой: ";
    printArray(arr, size);

    // Сортировка массива с помощью сортировки вставками
    fillArray(arr, size);
    insertionSort(arr, size);
    cout << "Отсортированный массив сортировкой вставками: ";
    printArray(arr, size);

    // Сортировка массива с помощью сортировки выбором
    fillArray(arr, size);
    selectionSort(arr, size);
    cout << "Отсортированный массив сортировкой выбором: ";
    printArray(arr, size);

    // Сортировка массива с помощью сортировки слиянием
    fillArray(arr, size);
    mergeSort(arr, size);
    cout << "Отсортированный массив сортировкой слиянием: ";
    printArray(arr, size);

    // Сортировка массива с помощью сортировки подсчетом
    fillArray(arr, size);
    countingSort(arr, size);
    cout << "Отсортированный массив сортировкой подсчетом: ";
    printArray(arr, size);

    // Удаление массива
    delete[] arr;

    return 0;
}