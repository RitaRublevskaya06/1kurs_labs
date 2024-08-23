#include <iostream>
#include <string>

using namespace std;

struct Discipline {
    string name;
    unsigned int course;
    unsigned int semesters;
    unsigned int lecturesPerSemester;
};

bool operator>(Discipline d1, Discipline d2) {
    if (d1.lecturesPerSemester > d2.lecturesPerSemester)
        return true;
    else
        return false;
}

bool operator<(Discipline d1, Discipline d2) {
    if (d1.lecturesPerSemester < d2.lecturesPerSemester)
        return true;
    else
        return false;
}

int main() {
    setlocale(LC_ALL, "Rus");
    Discipline disc1 = { "��������������� ������������ �����������", 1, 2, 32 };
    Discipline disc2 = { "��������������� ������������ �����������", 2, 3, 36 };

    if (disc1 > disc2)
        cout << "������" << endl;
    else
        cout << "����" << endl;

    if (disc1 < disc2)
        cout << "������" << endl;
    else
        cout << "����" << endl;

    return 0;
}
