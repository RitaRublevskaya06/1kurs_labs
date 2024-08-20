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
        cout << student.fullName << " - Все экзамены сданы на 4 или 5." << endl;
    }
    else {
        cout << student.fullName << " - Не все экзамены сданы на 4 или 5." << endl;
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
    cout << "Введите количество студентов: ";
    cin >> numStudents;

    ExamResult* students = new ExamResult[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Введите ФИО студента " << i + 1 << ": ";
        cin.ignore();
        getline(cin, students[i].fullName);

        cout << "Введите количество экзаменов для студента " << i + 1 << ": ";
        cin >> students[i].numExams;

        students[i].grades = new int[students[i].numExams];

        cout << "Введите оценки для студента " << i + 1 << ":" << endl;
        for (int j = 0; j < students[i].numExams; ++j) {
            cout << "Оценка за экзамен " << j + 1 << ": ";
            cin >> students[i].grades[j];
        }
        cout << endl;
    }

    cout << endl;

    // Обработка каждого студента
    for (int i = 0; i < numStudents; ++i) {
        processStudent(students[i]);
    }

    // Вычисление успеваемости
    float performance = calculatePerformance(students, numStudents);
    cout << "\nОбщая успеваемость студентов: " << performance << "%" << endl;

    // Освобождение памяти
    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].grades;
    }

    delete[] students;

    return 0;
}
