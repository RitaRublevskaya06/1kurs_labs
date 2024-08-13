#include <iostream>
#include <ctime>
#include <cstdlib>

void shuffleArray(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

int main() {
    setlocale(LC_CTYPE, "RU");
    srand(static_cast<unsigned int>(time(0)));

    int N;
    std::cout << "Введите количество товаров: ";
    std::cin >> N;

    int* prices = new int[N];
    for (int i = 0; i < N; i++) {
        prices[i] = rand() % 100 + 1;
    }

    shuffleArray(prices, N);

    int total_check_sum = 0;
    for (int i = N - 1; i >= 0; i -= 2) {
        total_check_sum += prices[i];
    }

    std::cout << "Порядок пробивания на кассе: ";
    for (int i = N - 1; i >= 0; i--) {
        std::cout << prices[i] << " ";
    }
    std::cout << "\nМаксимальная сумма чека: " << total_check_sum << std::endl;

    delete[] prices;

    return 0;
}