#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* fileA;
    errno_t A1 = fopen_s(&fileA, "fileA.txt", "r");
    if (fileA == NULL) {
        perror("�� ������� ������� ���� fileA.txt\n");
        return 1;
    }

    FILE* fileB;
    errno_t B1 = fopen_s(&fileB, "fileB.txt", "w");
    if (fileB == NULL) {
        perror("�� ������� ������� ���� fileB.txt\n");
        fclose(fileA);
        return 1;
    }

    int num;
    while (fscanf_s(fileA, "%d", &num) == 1) { // ������ ����� �� fileA
        if (num > 0) { // ���������, ��� ����� �������������
            fprintf(fileB, "%d\t", num); // ���������� ������������� ����� � fileB
        }
    }

    fclose(fileA);
    fclose(fileB);

    // ����� ����������� ������
    errno_t A2 = fopen_s(&fileA, "fileA.txt", "r");
    errno_t B2 = fopen_s(&fileB, "fileB.txt", "r");

    if (fileA == NULL || fileB == NULL) {
        printf("������ ��� �������� ������ fileA.txt ��� fileB.txt\n");
        return 1;
    }

    int number;

    printf("���������� ����� fileA.txt:\n");
    while (fscanf_s(fileA, "%d", &number) == 1) {
        printf("%d\t", number);
    }

    printf("\n");

    printf("���������� ����� fileB.txt (������ ������������� �����):\n");
    while (fscanf_s(fileB, "%d", &number) == 1) {
        printf("%d\t", number);
    }

    fclose(fileA);
    fclose(fileB);

    return 0;
}