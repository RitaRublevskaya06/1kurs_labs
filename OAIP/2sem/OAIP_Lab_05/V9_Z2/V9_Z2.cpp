#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// ��������� � ����������� �� �������
struct StudentInfo {
    string fullName;
    string grade;
    string subjects;
    string marks;
    float averageGrade;
};

struct Student {
    StudentInfo info;
};

// ������� ��� ����� ���������� �� �������
void inputStudentInfo(Student& student) {
    cout << "������� ��� �������: ";
    cin.ignore();
    getline(cin, student.info.fullName);

    cout << "������� ����� ������� (�����+�����): ";
    cin >> student.info.grade;
    cout << "������� �������� �������: ";
    cin.ignore();
    getline(cin, student.info.subjects);

    cout << "������� ������ �������: ";
    getline(cin, student.info.marks);

    cout << "������� ������� ���� �������: ";
    cin >> student.info.averageGrade;
}

// ������� ��� ������ ���������� �� �������
void displayStudentInfo(const Student& student) {
    cout << "��� �������: " << student.info.fullName << endl;
    cout << "�����: " << student.info.grade << endl;
    cout << "��������: " << student.info.subjects << endl;
    cout << "������: " << student.info.marks << endl;
    cout << "������� ����: " << student.info.averageGrade << endl;
}

// ������� ��� ������ ���������� � ����
void writeStudentToFile(const Student& student, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "��� �������: " << student.info.fullName << endl;
        file << "�����: " << student.info.grade << endl;
        file << "��������: " << student.info.subjects << endl;
        file << "������: " << student.info.marks << endl;
        file << "������� ����: " << student.info.averageGrade << endl;
        file << "-----------------------------" << endl;
        file.close();
        cout << "���������� �� ������� �������� � ����." << endl;
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� ������ ���������� �� �����
void readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� ������ ������� �� �������
void searchStudentByFullName(const string& fullName, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(fullName) != string::npos) {
                cout << "������ ������ � ���: " << fullName << endl;
                // ������� ��� ���������� �� ������� �� �����
                cout << line << endl;
                // ����� �������� �������������� ������ �� ������ ���� ���������� �� �������
                return;
            }
        }
        cout << "������ � ��� " << fullName << " �� ������." << endl;
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    const string filename = "students.txt";
    Student students[3];

    cout << "������� ���������� � 3 ��������" << endl << endl;

    for (int i = 0; i < 3; i++) {
        inputStudentInfo(students[i]);
        writeStudentToFile(students[i], filename);
        cout << endl;
    }

    cout << "���������� �� ��������:" << endl;
    readStudentsFromFile(filename);

    string searchFullName;
    cout << "������� ��� ������� ��� ������: ";
    cin.ignore(); // ������� ������ ����� ����� getline
    getline(cin, searchFullName);
    searchStudentByFullName(searchFullName, filename);

    return 0;
}