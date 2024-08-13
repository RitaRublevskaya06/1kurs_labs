#include <iostream>
#include <ctime>
#include<chrono>

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    setlocale(LC_CTYPE, "RU");
    int N;
    std::cout << "Введите размер массива:  ";
    std::cin >> N;

    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 1000;
    }

    std::cout << "Исходный массив A:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    int* B = new int[N];
    int* C = new int[N];
    int* D = new int[N];
    int* E = new int[N];

    for (int i = 0; i < N; i++) {
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
        E[i] = A[i];
    }
    std::cout << std::endl;


    auto start_B = std::chrono::high_resolution_clock::now();
    bubbleSort(B, N);
    auto end_B = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds_B = end_B - start_B;
    std::cout << "Отсортированный массив B методом пузырьковой сортировки:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << "\nВремя выполнения: " << elapsed_seconds_B.count() << " секунд" << std::endl;
    std::cout << std::endl;

    auto start_C = std::chrono::high_resolution_clock::now();
    insertionSort(C, N);
    auto end_C = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds_C = end_C - start_C;
    std::cout << "Отсортированный массив C методом сортировки вставками:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << "\nВремя выполнения: " << elapsed_seconds_C.count() << " секунд" << std::endl;
    std::cout << std::endl;

    auto start_D = std::chrono::high_resolution_clock::now();
    selectionSort(D, N);
    auto end_D = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds_D = end_D - start_D;
    std::cout << "Отсортированный массив D методом сортировки выбором:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << D[i] << " ";
    }
    std::cout << "\nВремя выполнения: " << elapsed_seconds_D.count() << " секунд" << std::endl;
    std::cout << std::endl;

    auto start_E = std::chrono::high_resolution_clock::now();
    quickSort(E, 0, N - 1);
    auto end_E = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds_E = end_E - start_E;
    std::cout << "Отсортированный массив E методом быстрой сортировки:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << E[i] << " ";
    }
    std::cout << "\nВремя выполнения: " << elapsed_seconds_E.count() << " секунд" << std::endl;
    std::cout << std::endl;

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;

    return 0;
}
