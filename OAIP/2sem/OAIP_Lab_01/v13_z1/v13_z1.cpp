#include <iostream>
#include <cmath>

// Функция для уравнения f(x) = 5x - 1 + x^3
double f1(double x) {
    return 5 * x - 1 + pow(x, 3);
}

// Функция для уравнения f(x) = x^2 + 1/x
double f2(double x) {
    return pow(x, 2) + 1 / x;
}

// Функция для метода дихотомии
double dichotomyMethod(double (*f)(double), double a, double b) {
    double x, e = 0.001;
    while ((b - a) >= e) {
        x = (a + b) / 2;
        if (f(x) == 0.0)
            break;
        else if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
    }
    return x;
}

int main() {
    double a1 = 0, b1 = 1, a2 = -2, b2 = 1, e = 0.001, root1, root2;
    setlocale(LC_CTYPE, "RU");

    std::cout << "Первое уравнение — f1(x) = 5x - 1 + x^3." << std::endl;

    root1 = dichotomyMethod(f1, a1, b1);

    std::cout << "Второе уравнение — f2(x) = x^2 + 1/x." << std::endl;

    root2 = dichotomyMethod(f2, a2, b2);

    std::cout << "Корень уравнения f1: " << root1 << std::endl;
    std::cout << "Корень уравнения f2: " << root2 << std::endl;

    return 0;
}