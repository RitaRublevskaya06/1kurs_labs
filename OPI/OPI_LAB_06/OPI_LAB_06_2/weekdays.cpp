#include <iostream>
#include "weekdays.h"

void printWeekday(int dayNumber) {
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
    default:
        std::cout << "������: ������������ ���������� ����� ��� ������." << std::endl;
    }
}