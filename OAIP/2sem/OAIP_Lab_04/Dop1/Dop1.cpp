#include <iostream>
#include <string>
#include <windows.h> 

using namespace std;

struct ExamResult {
    int studentNumber;
    string fullName;
    int numExams;
    int* grades;
};

void processStudent(ExamResult student) {
    bool allPassed = true;

    for (int i = 0; i < student.numExams; ++i) {
        if (student.grades[i] < 4) {
            allPassed = false;
            break;
        }
    }

    if (allPassed) {
        cout << student.fullName << " - ��� �������� ����� �� 4 ��� 5." << endl;
    }
    else {
        cout << student.fullName << " - �� ��� �������� ����� �� 4 ��� 5." << endl;
    }
}

float calculatePerformance(ExamResult* students, int numStudents) {
    int passCount = 0;

    for (int i = 0; i < numStudents; ++i) {
        bool allPassed = true;

        for (int j = 0; j < students[i].numExams; ++j) {
            if (students[i].grades[j] < 4) {
                allPassed = false;
                break;
            }
        }

        if (allPassed) {
            passCount++;
        }
    }

    return (static_cast<float>(passCount) / numStudents) * 100;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int numStudents;
    cout << "������� ���������� ���������: ";
    cin >> numStudents;

    ExamResult* students = new ExamResult[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "������� ��� �������� " << i + 1 << ": ";
        cin.ignore();
        getline(cin, students[i].fullName);

        cout << "������� ���������� ��������� ��� �������� " << i + 1 << ": ";
        cin >> students[i].numExams;

        students[i].grades = new int[students[i].numExams];

        cout << "������� ������ ��� �������� " << i + 1 << ":" << endl;
        for (int j = 0; j < students[i].numExams; ++j) {
            cout << "������ �� ������� " << j + 1 << ": ";
            cin >> students[i].grades[j];
        }
        cout << endl;
    }

    cout << endl;

    // ��������� ������� ��������
    for (int i = 0; i < numStudents; ++i) {
        processStudent(students[i]);
    }

    // ���������� ������������
    float performance = calculatePerformance(students, numStudents);
    cout << "\n����� ������������ ���������: " << performance << "%" << endl;

    // ������������ ������
    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].grades;
    }

    delete[] students;

    return 0;
}
