#include <iostream>
#include <windows.h>

using namespace std;

// Перечисление для выбора экзамена
enum Exam {
    MATH,
    PHYSICS,
    CHEMISTRY,
    ENGLISH,
    COMPUTER_SCIENCE
};

// Структура для даты экзамена с использованием битовых полей
struct ExamDate {
    unsigned short day : 5;     // 5 битов для дня
    unsigned short month : 4;   // 4 бита для месяца
    unsigned short year : 11;   // 11 битов для года
};

// Структура с информацией о преподавателе
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

    cout << "Добро пожаловать в базу данных преподавателей!" << endl << endl;

    do {
        cout << "Что вы хотите выполнить?" << endl;
        cout << "1. Добавить нового преподавателя" << endl;
        cout << "2. Поиск преподавателя по дате экзамена" << endl;
        cout << "3. Удалить преподавателя" << endl;
        cout << "0. Выход" << endl << endl;

        cout << "Введите номер операции: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            if (totalTeachers < 20) {
                cout << "Введите фамилию преподавателя: ";
                cin >> teachers[totalTeachers].lastName;

                cout << "Выберите экзамен (0 - Математика, 1 - Физика, 2 - Химия, 3 - Английский, 4 - Информатика): ";
                int examChoice;
                cin >> examChoice;
                teachers[totalTeachers].exam = static_cast<Exam>(examChoice);

                cout << "Введите дату экзамена (День Месяц Год): ";
                cin >> teachers[totalTeachers].examDate.day >> teachers[totalTeachers].examDate.month >> teachers[totalTeachers].examDate.year;

                totalTeachers++;
                cout << "Преподаватель успешно добавлен!" << endl << endl;
            }
            else {
                cout << "База данных преподавателей заполнена. Новых преподавателей добавить нельзя." << endl << endl;
            }
            break;
        }
        case 2: {
            if (totalTeachers > 0) {
                ExamDate searchDate;
                cout << "Введите дату экзамена для поиска (День Месяц Год): ";
                cin >> searchDate.day >> searchDate.month >> searchDate.year;

                bool teacherFound = false;
                cout << "Результаты поиска:" << endl;
                for (int i = 0; i < totalTeachers; i++) {
                    if (teachers[i].examDate.day == searchDate.day && teachers[i].examDate.month == searchDate.month && teachers[i].examDate.year == searchDate.year) {
                        cout << "Фамилия преподавателя: " << teachers[i].lastName << endl;
                        cout << "Экзамен: ";
                        switch (teachers[i].exam) {
                        case MATH:
                            cout << "Математика" << endl;
                            break;
                        case PHYSICS:
                            cout << "Физика" << endl;
                            break;
                        case CHEMISTRY:
                            cout << "Химия" << endl;
                            break;
                        case ENGLISH:
                            cout << "Английский" << endl;
                            break;
                        case COMPUTER_SCIENCE:
                            cout << "Информатика" << endl;
                            break;
                        }
                        cout << "Дата экзамена: " << teachers[i].examDate.day << "." << teachers[i].examDate.month << "." << teachers[i].examDate.year << endl;
                        cout << "-------------------------" << endl;
                        teacherFound = true;
                    }
                }

                if (!teacherFound) {
                    cout << "Преподавателей с указанной датой экзамена не найдено." << endl;
                }
            }
            else {
                cout << "База данных преподавателей пуста. Сначала добавьте преподавателей." << endl;
            }
            break;
        }
        case 3: {
            if (totalTeachers > 0) {
                cout << "Функция удаления преподавателя не поддерживается в данной версии программы." << endl;
                // Этот блок кода требуется дополнить реализацией удаления преподавателя по фамилии или другому критерию.
            }
            else {
                cout << "У вас нет преподавателей для удаления." << endl;
            }
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный номер операции. Повторите ввод." << endl;
        }
    } while (choice != 0);

    return 0;
}