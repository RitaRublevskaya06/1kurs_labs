#include <iostream>
#include <cmath>

// x^3 + x � 2 (),                 sin(x) + 0,3 ()

// ������� ��� ��������� f(x) = x^3 + x � 2
double f1(double x) {
    return  pow(x, 3) + x - 2;
}

// ������� ��� ��������� f(x) = sin(x) + 0,3 
double f2(double x) {
    return sin(x) + 0.3;
}

// ������� ��� ������ ���������
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

    // ���� �������� ������
    std::cout << "������ ��������� � f1(x) = x^3 + x � 2." << std::endl;

    // ������� ������� ���������
    root1 = dichotomyMethod(f1, a1, b1);

    // ���� ����� ������ ��� ������� ���������
    std::cout << "������ ��������� � f2(x) = sin(x) + 0,3." << std::endl;

    // ������� ������� ���������
    root2 = dichotomyMethod(f2, a2, b2);

    // ����� ������
    std::cout << "������ ��������� f1: " << root1 << std::endl;
    std::cout << "������ ��������� f2: " << root2 << std::endl;

    return 0;
}