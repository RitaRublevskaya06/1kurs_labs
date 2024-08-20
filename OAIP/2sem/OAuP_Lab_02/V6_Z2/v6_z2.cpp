#include <iostream> //����������� ����������� ����������
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* fileF1;
    errno_t F1 = fopen_s(&fileF1, "F1.txt", "r");
    if (fileF1 == NULL) {
        perror("�� ������� ������� ���� F1.txt\n");
        return 1;
    }

    FILE* fileF2;
    errno_t F2 = fopen_s(&fileF2, "F2.txt", "w");
    if (fileF2 == NULL) {
        perror("�� ������� ������� ���� F2.txt\n");
        fclose(fileF1);
        return 1;
    }

    char buffer[1000];
    int isEven = 0;

    while (fgets(buffer, sizeof(buffer), fileF1)) {
        if (isEven) {
            fprintf(fileF2, "%s", buffer);
        }
        isEven = !isEven;
    }

    fclose(fileF1);
    fclose(fileF2);

    // ����� ����������� ������
    errno_t F1_1 = fopen_s(&fileF1, "F1.txt", "r");
    errno_t F2_1 = fopen_s(&fileF2, "F2.txt", "r");

    if (fileF1 == NULL || fileF2 == NULL) {
        printf("������ ��� �������� ������ F1.txt ��� F2.txt\n");
        return 1;
    }

    printf("���������� ����� F1.txt:\n");
    while (fgets(buffer, sizeof(buffer), fileF1)) {
        printf("%s", buffer);
    }

    printf("\n");

    printf("���������� ����� F2.txt (������ ������ �� F1):\n");
    while (fgets(buffer, sizeof(buffer), fileF2)) {
        printf("%s", buffer);
    }

    fclose(fileF1);
    fclose(fileF2);

    return 0;
}
