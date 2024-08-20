#include <iostream>
#include <fstream>
#include <cstring> // ��� ������������� ������� ������
#include <cctype> // ��� ������ � ���������

using namespace std;

void writeFile(const char* str) {
    ofstream write("File.txt");
    if (write.is_open()) {
        write << str << endl;
        write.close();
    }
    else {
        cout << "������ �������� ����� ��� ������" << endl;
    }
}

void readFile() {
    ifstream read("File.txt");
    if (read.is_open()) {
        read.seekg(0, ios_base::end);
        int sz = read.tellg();
        read.seekg(0);

        char* new_str = new char[sz];
        read.getline(new_str, sz);

        char number[100]; // ������������ ����� �����
        int i = 0;
        bool is_number = false;

        while (new_str[i] != '\0') {
            if (isdigit(new_str[i])) {
                is_number = true;
                number[i] = new_str[i];
            }
            else {
                if (is_number) {
                    number[i] = '\0';
                    cout << "������� ����� �����: " << number << endl;
                    is_number = false;
                }
            }
            i++;
        }

        delete[] new_str;
        read.close();
    }
    else {
        cout << "������ �������� ����� ��� ������" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    char str[100]; // ������������ ����� �������� ������

    cout << "������� ������, ��������� �� ����, ����, �������, �����, ������ + � -:" << endl;
    cin.getline(str, 100);

    writeFile(str);
    readFile();

    return 0;
}
