#include <iostream>

int main() {
    setlocale(LC_CTYPE, "RU");
    int N;
    std::cout << "Введите количество участников: ";
    std::cin >> N;

    int* results = new int[N];
    int count_prize_winners = 0;

    for (int i = 0; i < N; i++) {
        std::cout << "Введите результат участника " << i + 1 << ": ";
        std::cin >> results[i];
    }

    for (int i = 0; i < N; i++) {
        if (results[i] >= 60) {
            count_prize_winners++;
        }
    }

    std::cout << "Количество призеров: " << count_prize_winners << std::endl;

    delete[] results;

    return 0;
}
