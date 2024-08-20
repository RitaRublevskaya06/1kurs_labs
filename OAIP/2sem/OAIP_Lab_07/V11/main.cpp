#include "header.h"

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    Stack* myStk = new Stack;
    myStk->head = nullptr;

    std::cout << "Сделайте выбор:" << std::endl;
    std::cout << "1 - Добавление элемента в стек" << std::endl;
    std::cout << "2 - Удаление элемента из стека" << std::endl;
    std::cout << "3 - Вывод стека" << std::endl;
    std::cout << "4 - Ввод стека в файл" << std::endl;
    std::cout << "5 - Вывод стека из файла" << std::endl;
    std::cout << "6 - Очистка стека" << std::endl;
    std::cout << "7 - Подсчет количества элементов стека, кратных 3" << std::endl;
    std::cout << "8 - Удаление элементов, кратных 3" << std::endl;
    std::cout << "9 - Выход" << std::endl << std::endl;

    for (;;) {
        std::cout << "Выберите команду: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            int data;
            std::cout << "Введите значение для добавления в стек: ";
            std::cin >> data;
            push(myStk, data);
            break;
        case 2:
            pop(myStk);
            break;
        case 3:
            display(myStk);
            break;
        case 4:
            saveToFile(myStk, "stack_data.txt");
            break;
        case 5:
            readFromFile(myStk, "stack_data.txt");
            break;
        case 6:
            clear(myStk);
            std::cout << "Стек очищен." << std::endl;
            break;
        case 7:
            countMultiplesOfThree(myStk);
            break;
        case 8:
            deleteMultiplesOfThree(myStk);
            std::cout << "Элементы, кратные 3, удалены из стека." << std::endl;
            break;
        case 9:
            clear(myStk);
            delete myStk;
            exit(0);
        default:
            std::cout << "Некорректный выбор. Повторите попытку." << std::endl;
        }
    }

    return 0;
}
