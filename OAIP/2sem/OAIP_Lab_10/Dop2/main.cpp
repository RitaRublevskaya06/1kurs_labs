#include <iostream>

const int MAX_COUNTRIES = 10; // Максимальное количество стран

void splitCountries(int adjacencyMatrix[MAX_COUNTRIES][MAX_COUNTRIES], int n, int countryGroup[], int currentCountry, int group) {
    countryGroup[currentCountry] = group;

    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[currentCountry][i] == 1 && countryGroup[i] == -1) {
            splitCountries(adjacencyMatrix, n, countryGroup, i, 1 - group); // Переключение между группами 0 и 1
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите количество стран: ";
    std::cin >> n;

    int adjacencyMatrix[MAX_COUNTRIES][MAX_COUNTRIES];
    int countryGroup[MAX_COUNTRIES];

    std::cout << "Введите матрицу смежности для " << n << " стран:" << std::endl;
    for (int i = 0; i < n; i++) {
        countryGroup[i] = -1; // Инициализация группы стран
        for (int j = 0; j < n; j++) {
            std::cin >> adjacencyMatrix[i][j];
        }
    }

    splitCountries(adjacencyMatrix, n, countryGroup, 0, 0); // Начинаем с первой страны и группы 0

    // Вывод результатов
    std::cout << "Группы стран:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Страна " << i + 1 << ": Группа " << countryGroup[i] << std::endl;
    }

    return 0;
}


/*
ИЛИ
#include <iostream>
#include <vector>

int** createAdjacencyMatrix(int n) {
    int** adjacencyMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjacencyMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            std::cout << "Введите значение A[" << i << ", " << j << "]: ";
            std::cin >> adjacencyMatrix[i][j];
        }
    }
    return adjacencyMatrix;
}

void deleteAdjacencyMatrix(int** adjacencyMatrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}

bool isEdgeBetweenGroups(int* group1, int* group2, int** adjacencyMatrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (group1[i] && group2[j] && adjacencyMatrix[i][j]) {
                return true;
            }
        }
    }
    return false;
}

void splitCountries(int n, int* group1, int* group2, int** adjacencyMatrix, int currentCountry, int& minEdgeCount) {
    if (currentCountry == n) {
        if (!isEdgeBetweenGroups(group1, group2, adjacencyMatrix, n)) {
            int edgeCount = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (group1[i] && group2[j] && adjacencyMatrix[i][j]) {
                        edgeCount++;
                    }
                }
            }
            if (edgeCount < minEdgeCount) {
                minEdgeCount = edgeCount;
            }
        }
        return;
    }

    group1[currentCountry] = 1;
    splitCountries(n, group1, group2, adjacencyMatrix, currentCountry + 1, minEdgeCount);

    group1[currentCountry] = 0;
    group2[currentCountry] = 1;
    splitCountries(n, group1, group2, adjacencyMatrix, currentCountry + 1, minEdgeCount);

    group2[currentCountry] = 0;
}

int main() {
    int n;
    std::cout << "Введите количество стран: ";
    std::cin >> n;

    int** adjacencyMatrix = createAdjacencyMatrix(n);

    int* group1 = new int[n];
    int* group2 = new int[n];
    int minEdgeCount = n * n; // Initialize with a large value

    splitCountries(n, group1, group2, adjacencyMatrix, 0, minEdgeCount);

    std::cout << "Минимальное количество пар смежных стран из противоположных групп: " << minEdgeCount << std::endl;

    delete[] group1;
    delete[] group2;
    deleteAdjacencyMatrix(adjacencyMatrix, n);

    return 0;
}


*/