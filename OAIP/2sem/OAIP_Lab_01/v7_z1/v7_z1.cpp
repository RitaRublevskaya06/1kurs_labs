#include <iostream>
#include <cmath>

// x^3 + 2x Ц 4   (0, 2),            x^2 Ц 1 ()


// ‘ункци€ дл€ уравнени€ f(x) = x^3 + 2x Ц 4
double f1(double x) {
    return pow(x, 3) + 2 * x - 4;
}

// ‘ункци€ дл€ уравнени€ f(x) = x^2 Ц 1
double f2(double x) {
    return pow(x, 2) - 1;
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
    double a1 = 0, b1 = 2, a2 = -1, b2 = 1, e = 0.001, root1, root2;
    setlocale(LC_CTYPE, "RU");

    // ¬вод исходных данных
    std::cout << "ѕервое уравнение Ч f1(x) = x^3 + 2x Ц 4." << std::endl;

    // –ешение первого уравнени€
    root1 = dichotomyMethod(f1, a1, b1);

    // ¬вод новых границ дл€ второго уравнени€
    std::cout << "¬торое уравнение Ч f2(x) = x^2 Ц 1." << std::endl;

    // –ешение второго уравнени€
    root2 = dichotomyMethod(f2, a2, b2);

    // ¬ывод корней
    std::cout << " орень уравнени€ f1: " << root1 << std::endl;
    std::cout << " орень уравнени€ f2: " << root2 << std::endl;

    return 0;
}