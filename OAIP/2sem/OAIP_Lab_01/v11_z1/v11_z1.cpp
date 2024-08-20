#include <iostream>
#include <cmath>

// e^x + 2x^2 Ц 3 ( 0,1 ),                 x^3 + 3 ( -2 , 0 )


// ‘ункци€ дл€ уравнени€ f(x) = e^x + 2x^2 Ц 3
double f1(double x) {
    return exp(x) + 2 * pow(x, 2) - 3;
}

// ‘ункци€ дл€ уравнени€ f(x) = x^3 + 3
double f2(double x) {
    return pow(x, 3) + 3;
}

// ‘ункци€ дл€ метода дихотомии
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
    double a1 = 0, b1 = 1, a2 = -2, b2 = 0, e = 0.001, root1, root2;
    setlocale(LC_CTYPE, "RU");

    // ¬вод исходных данных
    std::cout << "ѕервое уравнение Ч f1(x) = e^x + 2x^2 Ц 3." << std::endl;

    // –ешение первого уравнени€
    root1 = dichotomyMethod(f1, a1, b1);

    // ¬вод новых границ дл€ второго уравнени€
    std::cout << "¬торое уравнение Ч f2(x) = x^3 + 3." << std::endl;

    // –ешение второго уравнени€
    root2 = dichotomyMethod(f2, a2, b2);

    // ¬ывод корней
    std::cout << " орень уравнени€ f1: " << root1 << std::endl;
    std::cout << " орень уравнени€ f2: " << root2 << std::endl;

    return 0;
}