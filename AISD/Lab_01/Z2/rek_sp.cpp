#include<iostream>
#include<chrono>

long long fibonacciRec(int n) {
    if (n <= 1)
        return n;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

int main() {
    setlocale(LC_CTYPE, "RU");
    int userNumber;
    std::cout << "Введите число N: ";
    std::cin >> userNumber;

    auto start = std::chrono::high_resolution_clock::now();
    long long result = fibonacciRec(userNumber);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "N-ое число Фибоначчи: " << result << std::endl;
    std::cout << "Расчетное время рекурсией: " << elapsed_seconds.count() << " секунд." << std::endl;

    return 0;
}