#include <iostream>
#include "weekends.h"

void printWeekend(int dayNumber) {
    switch (dayNumber) {
    case 6:
        std::cout << "�������" << std::endl;
        break;
    case 7:
        std::cout << "�����������" << std::endl;
        break;
    default:
        std::cout << "������: ������������ ���������� ����� ��� ������." << std::endl;
    }
}