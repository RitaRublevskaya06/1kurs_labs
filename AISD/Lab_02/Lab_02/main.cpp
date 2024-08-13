#include <iostream>
#include <windows.h>

int max_steps_binary_search(int N) {
    return log2(N) + 1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int N, X;
    int low = 1, high, steps = 0;

    std::cout << "Введите число N: ";
    std::cin >> N;
    int max_steps = max_steps_binary_search(N);
    std::cout << "Максимальное количество шагов при бинарном поиске от числа " << N << ": " << max_steps << std::endl;
    high = N;

    while (true) {
        steps++;
        X = low + (high - low) / 2;
        std::cout << "Это " << X << "? (мало / много / угадал): ";
        std::string answer;
        std::cin >> answer;

        if (answer == "много") {
            high = X - 1;
        }
        else if (answer == "мало") {
            low = X + 1;
        }
        else if (answer == "угадал") {
            std::cout << "Количество шагов: " << steps << std::endl;
            std::cout << "Шаги бинарного поиска: ";
            int current = 1;
            while (current <= N) {
                int mid = current + (N - current) / 2;
                std::cout << " " << mid;
                if (mid == X) {
                    break;
                }
                else if (mid < X) {
                    current = mid + 1;
                }
                else {
                    N = mid - 1;
                }
            }
            break;
        }
        else {
            std::cout << "Неверный ввод. Пробовать снова." << std::endl;
        }
    }
    return 0;
}