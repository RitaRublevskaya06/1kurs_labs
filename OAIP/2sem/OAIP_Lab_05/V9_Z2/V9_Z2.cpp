#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Структура с информацией об ученике
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

// Функция для ввода информации об ученике
void inputStudentInfo(Student& student) {
    cout << "Введите ФИО ученика: ";
    cin.ignore();
    getline(cin, student.info.fullName);

    cout << "Введите класс ученика (цифра+буква): ";
    cin >> student.info.grade;
    cout << "Введите предметы ученика: ";
    cin.ignore();
    getline(cin, student.info.subjects);

    cout << "Введите оценки ученика: ";
    getline(cin, student.info.marks);

    cout << "Введите средний балл ученика: ";
    cin >> student.info.averageGrade;
}

// Функция для вывода информации об ученике
void displayStudentInfo(const Student& student) {
    cout << "ФИО ученика: " << student.info.fullName << endl;
    cout << "Класс: " << student.info.grade << endl;
    cout << "Предметы: " << student.info.subjects << endl;
    cout << "Оценки: " << student.info.marks << endl;
    cout << "Средний балл: " << student.info.averageGrade << endl;
}

// Функция для записи информации в файл
void writeStudentToFile(const Student& student, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "ФИО ученика: " << student.info.fullName << endl;
        file << "Класс: " << student.info.grade << endl;
        file << "Предметы: " << student.info.subjects << endl;
        file << "Оценки: " << student.info.marks << endl;
        file << "Средний балл: " << student.info.averageGrade << endl;
        file << "-----------------------------" << endl;
        file.close();
        cout << "Информация об ученике записана в файл." << endl;
    }
    else {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}

// Функция для чтения информации из файла
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
        cout << "Ошибка открытия файла для чтения." << endl;
    }
}

// Функция для поиска ученика по фамилии
void searchStudentByFullName(const string& fullName, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(fullName) != string::npos) {
                cout << "Найден ученик с ФИО: " << fullName << endl;
                // Выводим всю информацию об ученике из файла
                cout << line << endl;
                // Можно добавить дополнительную логику по выводу всей информации об ученике
                return;
            }
        }
        cout << "Ученик с ФИО " << fullName << " не найден." << endl;
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    const string filename = "students.txt";
    Student students[3];

    cout << "Введите информацию о 3 учениках" << endl << endl;

    for (int i = 0; i < 3; i++) {
        inputStudentInfo(students[i]);
        writeStudentToFile(students[i], filename);
        cout << endl;
    }

    cout << "Информация об учениках:" << endl;
    readStudentsFromFile(filename);

    string searchFullName;
    cout << "Введите ФИО ученика для поиска: ";
    cin.ignore(); // Очистка буфера ввода перед getline
    getline(cin, searchFullName);
    searchStudentByFullName(searchFullName, filename);

    return 0;
}