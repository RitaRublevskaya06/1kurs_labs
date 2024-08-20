#include "header.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Node* front = nullptr;
    Node* rear = nullptr;
    int size, choice, value;

    std::cout << "Введите размер очереди: ";
    std::cin >> size;

    std::cout << "1 - Ввод элементов очереди" << std::endl;
    std::cout << "2 - Вывод очереди и количества ее элементов" << std::endl;
    std::cout << "3 - Очистка очереди" << std::endl;
    std::cout << "4 - Удалить первый отрицательный элемент" << std::endl;
    std::cout << "5 - Выход" << std::endl << std::endl;

    for (;;) {
        std::cout << "Выберите команду: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления в очередь: ";
            std::cin >> value;
            enqueue(&front, &rear, value);
            break;

        case 2:
            std::cout << "Очередь: ";
            display(front);
            std::cout << "Количество элементов в очереди: " << size_1(front) << std::endl;
            break;

        case 3:
            clearQueue(&front);
            std::cout << "Очередь очищена." << std::endl;
            break;

        case 4:
            removeFirstNegativeAnywhere(&front);
            std::cout << "Первый отрицательный элемент удален из очереди." << std::endl;
            break;

        case 5:
            clearQueue(&front);
            return 0;

        default:
            std::cout << "Неверная команда. Попробуйте снова." << std::endl;
            break;
        }
    }

    return 0;
}
