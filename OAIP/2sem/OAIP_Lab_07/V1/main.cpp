#include "header.h"

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    Stack* myStk = new Stack;
    myStk->head = nullptr;

    Stack* positiveStack = new Stack;
    positiveStack->head = nullptr;

    Stack* negativeStack = new Stack;
    negativeStack->head = nullptr;

    std::cout << "�������� �����:" << std::endl;
    std::cout << "1 - ���������� �������� � ����" << std::endl;
    std::cout << "2 - �������� �������� �� �����" << std::endl;
    std::cout << "3 - ����� �����" << std::endl;
    std::cout << "4 - ���� ����� � ����" << std::endl;
    std::cout << "5 - ����� ����� �� �����" << std::endl;
    std::cout << "6 - ������� �����" << std::endl;
    std::cout << "7 - ���������� ������ �� ������������� � ������������� ���������" << std::endl;
    std::cout << "8 - �����" << std::endl << std::endl;

    for (;;) {
        std::cout << "�������� �������: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            int data;
            std::cout << "������� �������� ��� ���������� � ����: ";
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
            std::cout << "���� ������." << std::endl;
            break;
        case 7:
            splitStack(myStk, positiveStack, negativeStack);
            std::cout << "������������� ";
            display(positiveStack);
            std::cout << "������������� ";
            display(negativeStack);
            break;
        case 8:
            clear(myStk);
            clear(positiveStack);
            clear(negativeStack);
            delete myStk;
            delete positiveStack;
            delete negativeStack;
            exit(0);
        default:
            std::cout << "������������ �����. ��������� �������." << std::endl;
        }
    }

    return 0;
}