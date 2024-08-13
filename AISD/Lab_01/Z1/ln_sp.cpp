#include <iostream>
#include <chrono>

long long fibonacciLin(int n) {
	if (n <= 1)
		return n;
	long long fib = 1, prev = 0;
	for (int i = 2; i <= n; i++) {
		long long tmp = fib;
		fib += prev;
		prev = tmp;
	}
	return fib;
}

int main() {
    setlocale(LC_CTYPE, "RU");
    int userNumber;
    std::cout << "Введите число N: ";
    std::cin >> userNumber;

    auto start = std::chrono::high_resolution_clock::now();
    long long result = fibonacciLin(userNumber);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "N-ое число Фибоначчи: " << result << std::endl;
    std::cout << "Расчетное время циклом " << elapsed_seconds.count() << " секунд." << std::endl;

    return 0;
}