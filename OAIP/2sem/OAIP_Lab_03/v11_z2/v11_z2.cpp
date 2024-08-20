#include <iostream>
#include <fstream>
#include <cstring> // ��� ������ �� ��������
#include <string> // ��� ������������� C++ �����
#include <sstream> // ��� ������ �� ��������� �������

using namespace std;

void writeToFile(const char* str1, const char* str2) {
    ofstream write("File.txt");
    if (write.is_open()) {
        write << str1 << endl;
        write << str2 << endl;
        write.close();
    }
    else {
        cerr << "������ �������� ����� ��� ������" << endl;
    }
}

void readFromFile() {
    ifstream read("File.txt");
    if (read.is_open()) {
        string str1, str2;
        getline(read, str1);
        getline(read, str2);

        string shortestWord;
        string longestWord;

        stringstream ss1(str1);
        stringstream ss2(str2);

        string word;
        int shortestLength = 100, longestLength = 0;

        while (ss1 >> word) {
            if (word.length() < shortestLength) {
                shortestLength = word.length();
                shortestWord = word;
            }
        }

        while (ss2 >> word) {
            if (word.length() > longestLength) {
                longestLength = word.length();
                longestWord = word;
            }
        }

        cout << "����� �������� ����� � ������ ������: " << shortestWord << endl;
        cout << "����� ������� ����� �� ������ ������: " << longestWord << endl;

        read.close();
    }
    else {
        cerr << "������ �������� ����� ��� ������" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    char str1[100], str2[100];

    cout << "������� ������ ������: ";
    cin.getline(str1, 100);

    cout << "������� ������ ������: ";
    cin.getline(str2, 100);

    writeToFile(str1, str2);
    readFromFile();

    return 0;
}