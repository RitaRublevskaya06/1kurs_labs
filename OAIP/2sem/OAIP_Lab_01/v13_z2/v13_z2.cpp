#include <iostream>
#include <cmath>
#include <cstdarg> 

int sum(int n, ...) {
    using namespace std;
    va_list args;
    va_start(args, n);

    int** A, sum = 0, i, j, st = static_cast<int>(sqrt(n));
    A = new int* [st];

    for (i = 0; i < st; i++) {
        A[i] = new int[st];
    }

    cout << "Матрица:" << endl;
    for (i = 0; i < st; i++) {
        for (j = 0; j < st; j++) {
            A[i][j] = va_arg(args, int);
            cout << A[i][j] << ' ';
            if (A[i][j] < 10)
                cout << " ";
            if (j == st - 1)
                cout << endl;
        }
    }

    for (i = 1; i < st; i++) {
        for (j = 0; j <= i - 1; j++) {
            sum += A[i][j];
        }
    }

    for (i = 0; i < st; i++) {
        delete[] A[i];
    }
    delete[] A;

    va_end(args);
    return sum;
}

int main() {
    using namespace std;
    setlocale(LC_CTYPE, "RU");

    cout << "Сумма элементов, которые расположены ниже главной диагонали - " << sum(9, 1, 6, 13, 15, 4, 21, 24, 3, 29) << endl;
    cout << "Сумма элементов, которые расположены ниже главной диагонали - " << sum(16, 5, 6, 12, 17, 1, 8, 11, 7, 9, 20, 2, 22, 14, 25, 16, 18) << endl;

    return 0;
}