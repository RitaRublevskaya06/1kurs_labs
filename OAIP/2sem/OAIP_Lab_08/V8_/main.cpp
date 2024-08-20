#include "header.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Node* front = nullptr;
    Node* rear = nullptr;
    int size, choice, value;

    std::cout << "������� ������ �������: ";
    std::cin >> size;

    std::cout << "1 - ���� ��������� �������" << std::endl;
    std::cout << "2 - ����� ������� � ���������� �� ���������" << std::endl;
    std::cout << "3 - ������� �������" << std::endl;
    std::cout << "4 - ������� ������ ������������� �������" << std::endl;
    std::cout << "5 - �����" << std::endl << std::endl;

    for (;;) {
        std::cout << "�������� �������: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "������� ������� ��� ���������� � �������: ";
            std::cin >> value;
            enqueue(&front, &rear, value);
            break;

        case 2:
            std::cout << "�������: ";
            display(front);
            std::cout << "���������� ��������� � �������: " << size_1(front) << std::endl;
            break;

        case 3:
            clearQueue(&front);
            std::cout << "������� �������." << std::endl;
            break;

        case 4:
            removeFirstNegativeAnywhere(&front);
            std::cout << "������ ������������� ������� ������ �� �������." << std::endl;
            break;

        case 5:
            clearQueue(&front);
            return 0;

        default:
            std::cout << "�������� �������. ���������� �����." << std::endl;
            break;
        }
    }

    return 0;
}
