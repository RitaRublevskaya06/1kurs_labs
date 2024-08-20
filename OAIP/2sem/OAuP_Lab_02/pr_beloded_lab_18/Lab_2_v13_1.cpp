#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* fileA, * fileB;
    int num;
    int count[1000] = { 0 }; // ������������ �������� ����� � fileA

    // ��������� ���� fileA ��� ������
    errno_t A = fopen_s(&fileA, "fileA.txt", "r");
    if (fileA == NULL) {
        printf("�� ������� ������� ���� fileA.txt\n");
        return 1;
    }

    // ��������� ����� �� fileA � ������� �� ����������
    while (fscanf_s(fileA, "%d", &num) != EOF) {
        count[num]++;
    }

    // ��������� ���� fileA
    if (fclose(fileA) != 0) {
        printf("������ ��� �������� ����� fileA.txt\n");
        return 1;
    }

    // ��������� ���� fileB ��� ������
    errno_t B = fopen_s(&fileB, "fileB.txt", "w");
    if (fileB == NULL) {
        printf("�� ������� ������� ���� fileB.txt.n");
        return 1;
    }

    // ��������� �������� ����� fileA ��� ������
    errno_t A1 = fopen_s(&fileA, "fileA.txt", "r");
    if (fileA == NULL) {
        printf("�� ������� �������� ������� ���� fileA.txt\n");
        return 1;
    }

    // ���������� � fileB �����, ������� ����������� � fileA ����� ���� ���
    while (fscanf_s(fileA, "%d", &num) != EOF) {
        if (count[num] > 2) {
            fprintf(fileB, "%d\t", num);
        }
    }
    // ��������� ���� fileA
    if (fclose(fileA) != 0) {
        printf("������ ��� �������� ����� fileA.txt\n");
        return 1;
    } 
    // ��������� ���� fileB
    if (fclose(fileB) != 0) {
        printf("������ ��� �������� ����� fileB.txt\n");
        return 1;
    }

    // ��������� ���� fileB ��� ������ � ������� ��� ���������� �� �����
    errno_t B1 = fopen_s(&fileB, "fileB.txt", "r");
    if (fileB == NULL) {
        printf("�� ������� ������� ���� fileB.txt\n");
        return 1;
    }

    printf("���������� ����� fileB:\n");
    while (fscanf_s(fileB, "%d", &num) != EOF) {
        printf("%d\t", num);
    }

    // ��������� ���� fileB
    if (fclose(fileB) != 0) {
        printf("������ ��� �������� ����� fileB.txt\n");
        return 1;
    }

    return 0;
}