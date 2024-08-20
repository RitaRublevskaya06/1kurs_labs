#include <iostream>
#include <cmath>
#include <cstdarg>

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void find_primes(int num_intervals, ...) {
    va_list args;
    va_start(args, num_intervals);

    for (int i = 0; i < num_intervals; ++i) {
        int a = va_arg(args, int);
        int b = va_arg(args, int);
        std::cout << "Простые числа в интервале [" << a << ", " << b << "]: ";
        for (int j = a; j <= b; ++j) {
            if (is_prime(j)) {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
    }

    va_end(args);
}

int main() {
    using namespace std;
    setlocale(LC_CTYPE, "RU");

    find_primes(2, 1, 10, 20, 30);
    find_primes(3, 50, 70, 80, 100, 110, 120);

    return 0;
}