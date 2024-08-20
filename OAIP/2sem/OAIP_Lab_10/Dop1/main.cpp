#include <iostream>
#include <fstream>

void generateNumbers(int A, int currentDigit, int* numberArray, std::ofstream& file) {
    if (currentDigit == A) {
        for (int i = 0; i < A; i++) {
            file << numberArray[i];
        }
        file << std::endl;
        return;
    }

    for (int i = 0; i <= A; i++) {
        numberArray[currentDigit] = i;
        generateNumbers(A, currentDigit + 1, numberArray, file);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int A;
    std::cout << "������� ����� A: ";
    std::cin >> A;

    while (A <= 0) {
        std::cout << "�������� ��������, ��������� �������: ";
        std::cin >> A;
    }

    std::ofstream outputFile("numbers.txt");
    if (!outputFile.is_open()) {
        std::cerr << "������ �������� �����!" << std::endl;
        return 1;
    }

    int* numberArray = new int[A];
    generateNumbers(A, 0, numberArray, outputFile);

    delete[] numberArray;
    outputFile.close();

    std::cout << "����� ������� �������� � ���� numbers.txt" << std::endl;

    return 0;
}

