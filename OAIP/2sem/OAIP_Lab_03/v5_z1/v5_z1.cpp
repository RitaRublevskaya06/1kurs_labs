#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream read("FILE1.txt");
    ofstream write("FILE2.txt");

    if (read.is_open() && write.is_open()) {
        string line;
        int line_count = 0;
        while (getline(read, line)) {
            line_count++;
            if (line_count >= 4) {
                write << line << endl;
            }
        }

        read.close();
        write.close();

        ifstream read2("FILE2.txt");
        if (read2.is_open()) {
            string last_word;
            while (read2 >> last_word) {}
            cout << "Количество символов в последнем слове FILE2: " << last_word.size() << endl;
            read2.close();
        }
        else {
            cout << "Ошибка открытия файла FILE2 для чтения" << endl;
        }

    }
    else {
        cout << "Ошибка открытия файлов FILE1 или FILE2" << endl;
    }

    return 0;
}