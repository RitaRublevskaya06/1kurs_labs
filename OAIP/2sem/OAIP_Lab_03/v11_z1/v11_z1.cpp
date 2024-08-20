#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool containsOnlyOneWord(const string& line) {
    int wordCount = 0;
    for (char c : line) {
        if (isalpha(c)) {
            wordCount++;
        }
        else if (wordCount > 0) {
            return false;
        }
    }
    return wordCount > 0;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    ifstream read("FILE1.txt");
    ofstream write("FILE2.txt");

    if (read.is_open() && write.is_open()) {
        string line;
        int characterCount = 0;
        int wordCount = 0;

        while (getline(read, line)) {
            if (containsOnlyOneWord(line)) {
                write << line << endl;
                characterCount += line.size();
                wordCount++;
            }
        }

        read.close();
        write.close();

        cout << "Количество символов в FILE2: " << characterCount << endl;
        cout << "Количество слов в FILE2: " << wordCount << endl;
    }
    else {
        cout << "Ошибка открытия файлов" << endl;
    }

    return 0;
}
