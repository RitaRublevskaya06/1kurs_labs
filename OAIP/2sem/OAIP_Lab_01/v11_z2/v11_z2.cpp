#include <iostream>
#include <cstdarg>

int find_min(int count, ...) {
    va_list args;
    va_start(args, count);

    int** matrix, min_val = INT_MAX, i, j, st = static_cast<int>(sqrt(count));
    matrix = new int* [st];

    for (i = 0; i < st; i++) {
        matrix[i] = new int[st];
    }

    for (i = 0; i < st; i++) {
        for (j = 0; j < st; j++) {
            matrix[i][j] = va_arg(args, int);
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
            }
        }
    }

    for (i = 0; i < st; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    va_end(args);
    return min_val;
}

int main() {
    using namespace std;
    setlocale(LC_CTYPE, "RU");

    int matrix1[2][2] = { {20, 6}, {10, 18} };
    int matrix2[3][3] = { {5, 12, 8}, {4, 19, 21}, {23, 17, 6} };
    int matrix3[4][4] = { {15, 12, 18, 20}, {5, 14, 9, 17}, {11, 7, 16, 19}, {24, 13, 10, 6} };

    int (*min_func)(int, ...);
    min_func = &find_min;

    cout << "Минимальное значение в матрице 1: " << min_func(4, matrix1[0][0], matrix1[0][1], matrix1[1][0], matrix1[1][1]) << endl;
    cout << "Минимальное значение в матрице 2: " << min_func(9, matrix2[0][0], matrix2[0][1], matrix2[0][2], matrix2[1][0], matrix2[1][1], matrix2[1][2], matrix2[2][0], matrix2[2][1], matrix2[2][2]) << endl;
    cout << "Минимальное значение в матрице 3: " << min_func(16, matrix3[0][0], matrix3[0][1], matrix3[0][2], matrix3[0][3], matrix3[1][0], matrix3[1][1], matrix3[1][2], matrix3[1][3], matrix3[2][0], matrix3[2][1], matrix3[2][2], matrix3[2][3], matrix3[3][0], matrix3[3][1], matrix3[3][2], matrix3[3][3]) << endl;

    return 0;
}