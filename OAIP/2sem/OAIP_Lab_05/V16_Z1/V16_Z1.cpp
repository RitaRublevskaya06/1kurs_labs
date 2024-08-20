#include <iostream>
#include <windows.h>

using namespace std;

// ������������ ��� ������ ��������
enum Exam {
    MATH,
    PHYSICS,
    CHEMISTRY,
    ENGLISH,
    COMPUTER_SCIENCE
};

// ��������� ��� ���� �������� � �������������� ������� �����
struct ExamDate {
    unsigned short day : 5;     // 5 ����� ��� ���
    unsigned short month : 4;   // 4 ���� ��� ������
    unsigned short year : 11;   // 11 ����� ��� ����
};

// ��������� � ����������� � �������������
struct Teacher {
    char lastName[50];
    Exam exam;
    ExamDate examDate;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Teacher teachers[20];
    int choice, totalTeachers = 0;

    cout << "����� ���������� � ���� ������ ��������������!" << endl << endl;

    do {
        cout << "��� �� ������ ���������?" << endl;
        cout << "1. �������� ������ �������������" << endl;
        cout << "2. ����� ������������� �� ���� ��������" << endl;
        cout << "3. ������� �������������" << endl;
        cout << "0. �����" << endl << endl;

        cout << "������� ����� ��������: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            if (totalTeachers < 20) {
                cout << "������� ������� �������������: ";
                cin >> teachers[totalTeachers].lastName;

                cout << "�������� ������� (0 - ����������, 1 - ������, 2 - �����, 3 - ����������, 4 - �����������): ";
                int examChoice;
                cin >> examChoice;
                teachers[totalTeachers].exam = static_cast<Exam>(examChoice);

                cout << "������� ���� �������� (���� ����� ���): ";
                cin >> teachers[totalTeachers].examDate.day >> teachers[totalTeachers].examDate.month >> teachers[totalTeachers].examDate.year;

                totalTeachers++;
                cout << "������������� ������� ��������!" << endl << endl;
            }
            else {
                cout << "���� ������ �������������� ���������. ����� �������������� �������� ������." << endl << endl;
            }
            break;
        }
        case 2: {
            if (totalTeachers > 0) {
                ExamDate searchDate;
                cout << "������� ���� �������� ��� ������ (���� ����� ���): ";
                cin >> searchDate.day >> searchDate.month >> searchDate.year;

                bool teacherFound = false;
                cout << "���������� ������:" << endl;
                for (int i = 0; i < totalTeachers; i++) {
                    if (teachers[i].examDate.day == searchDate.day && teachers[i].examDate.month == searchDate.month && teachers[i].examDate.year == searchDate.year) {
                        cout << "������� �������������: " << teachers[i].lastName << endl;
                        cout << "�������: ";
                        switch (teachers[i].exam) {
                        case MATH:
                            cout << "����������" << endl;
                            break;
                        case PHYSICS:
                            cout << "������" << endl;
                            break;
                        case CHEMISTRY:
                            cout << "�����" << endl;
                            break;
                        case ENGLISH:
                            cout << "����������" << endl;
                            break;
                        case COMPUTER_SCIENCE:
                            cout << "�����������" << endl;
                            break;
                        }
                        cout << "���� ��������: " << teachers[i].examDate.day << "." << teachers[i].examDate.month << "." << teachers[i].examDate.year << endl;
                        cout << "-------------------------" << endl;
                        teacherFound = true;
                    }
                }

                if (!teacherFound) {
                    cout << "�������������� � ��������� ����� �������� �� �������." << endl;
                }
            }
            else {
                cout << "���� ������ �������������� �����. ������� �������� ��������������." << endl;
            }
            break;
        }
        case 3: {
            if (totalTeachers > 0) {
                cout << "������� �������� ������������� �� �������������� � ������ ������ ���������." << endl;
                // ���� ���� ���� ��������� ��������� ����������� �������� ������������� �� ������� ��� ������� ��������.
            }
            else {
                cout << "� ��� ��� �������������� ��� ��������." << endl;
            }
            break;
        }
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� ����� ��������. ��������� ����." << endl;
        }
    } while (choice != 0);

    return 0;
}