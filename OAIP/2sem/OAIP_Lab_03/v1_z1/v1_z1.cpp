#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    ifstream read("FILE1.txt");
    ofstream write("FILE2.txt");

    string line;
    int count = 0;

    while (getline(read, line))
    {
        count++;
        if (count % 2 == 0)
        {
            write << line << endl;
        }
    }

    read.close();
    write.close();

    // Подсчет размера файлов
    HANDLE hFile1 = CreateFile(L"FILE1.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE hFile2 = CreateFile(L"FILE2.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile1 != INVALID_HANDLE_VALUE && hFile2 != INVALID_HANDLE_VALUE)
    {
        DWORD size1 = GetFileSize(hFile1, NULL);
        DWORD size2 = GetFileSize(hFile2, NULL);

        cout << "Размер FILE1: " << size1 << " байт" << endl;
        cout << "Размер FILE2: " << size2 << " байт" << endl;

        CloseHandle(hFile1);
        CloseHandle(hFile2);
    }
    else
    {
        cout << "Ошибка при получении размера файлов" << endl;
    }

    return 0;
}