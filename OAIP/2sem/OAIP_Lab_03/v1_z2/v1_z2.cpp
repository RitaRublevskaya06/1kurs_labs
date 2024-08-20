#include <iostream>
#include <fstream>

using namespace std;

void writeToFile(char str[40]) {
    ofstream write("File.txt");
    if (write.is_open()) {
        int i = 0;
        while (str[i] != '\0') {
            write << str[i];
            i++;
        }
        write.close();
    }
    else {
        cout << "Ошибка открытия файла для записи" << endl;
    }
}

void readFromFile() {
    char new_str[40];
    ifstream read("File.txt");
    if (read.is_open()) {
        read.getline(new_str, 40);
        cout << "Нечетные числа из строки: ";
        int i = 0;
        while (new_str[i] != '\0') {
            if (new_str[i] >= '0' && new_str[i] <= '9') {
                int num = new_str[i] - '0';
                if (num % 2 != 0) {
                    cout << num << " ";
                }
            }
            i++;
        }
        cout << endl;
        read.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    char str[40];

    cout << "Введите строку символов: ";
    cin.getline(str, 40);

    writeToFile(str);
    readFromFile();

    return 0;
}