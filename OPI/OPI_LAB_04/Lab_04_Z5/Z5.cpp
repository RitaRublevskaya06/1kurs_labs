#include <iostream>

int main() {
    setlocale(LC_CTYPE, "Russian");
    int dayNumber;
    std::cout << "������� ���������� ����� ��� ������: ";
    std::cin >> dayNumber;

    switch (dayNumber) {
    case 1:
        std::cout << "�����������" << std::endl;
        break;
    case 2:
        std::cout << "�������" << std::endl;
        break;
    case 3:
        std::cout << "�����" << std::endl;
        break;
    case 4:
        std::cout << "�������" << std::endl;
        break;
    case 5:
        std::cout << "�������" << std::endl;
        break;
    case 6:
        std::cout << "�������" << std::endl;
        break;
    case 7:
        std::cout << "�����������" << std::endl;
        break;
    default:
        std::cout << "������: ������������ ���������� ����� ��� ������." << std::endl;
    }

    return 0;
}
