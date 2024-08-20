#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ������� ��� ���������� ������� ���������� �������
void fillArray(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// ������� ��� ������ �������
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ������� ���������� ���������
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ������� ���������� ���������
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

// ������� ���������� �������
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

// ������� ���������� ��������
void mergeSort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;

    // ���������� ������� �� ��� �����
    int* left = new int[mid];
    int* right = new int[size - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // ���������� ����� � ������ ������
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // ������� ��������������� ������
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

    // �������� ��������� ��������
    delete[] left;
    delete[] right;
}

int main() {
    // ������ �������
    int size = 10;

    // �������� �������
    int* arr = new int[size];

    // ���������� ������� ���������� �������
    fillArray(arr, size);

    // ������ ��������� �������
    cout << "�������� ������: ";
    printArray(arr, size);

    // ���������� ������� � ������� ����������� ����������
    bubbleSort(arr, size);
    cout << "��������������� ������ ����������� �����������: ";
    printArray(arr, size);

    // ���������� ������� � ������� ���������� ���������
    fillArray(arr, size);
    insertionSort(arr, size);
    cout << "��������������� ������ ����������� ���������: ";
    printArray(arr, size);

    // ���������� ������� � ������� ���������� �������
    fillArray(arr, size);
    selectionSort(arr, size);
    cout << "��������������� ������ ����������� �������: ";
    printArray(arr, size);

    // ���������� ������� � ������� ���������� ��������
    fillArray(arr, size);
    mergeSort(arr, size);
    cout << "��������������� ������ ����������� ��������: ";
    printArray(arr, size);

    // �������� �������
    delete[] arr;

    return 0;
}
