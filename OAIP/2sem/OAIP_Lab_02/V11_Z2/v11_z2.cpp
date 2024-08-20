#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* fileF1;
    errno_t F1 = fopen_s(&fileF1, "F1.txt", "r");
    if (fileF1 == NULL) {
        perror("Не удалось открыть файл F1.txt\n");
        return 1;
    }

    FILE* fileF2;
    errno_t F2 = fopen_s(&fileF2, "F2.txt", "w");
    if (fileF2 == NULL) {
        perror("Не удалось открыть файл F2.txt\n");
        fclose(fileF1);
        return 1;
    }

    char buffer[1000];
    int lineCounter = 1;

    while (fgets(buffer, sizeof(buffer), fileF1)) {
        // Проверяем, заканчивается ли строка символом 'a' или 'A'
        if (buffer[strlen(buffer) - 2] == 'a' || buffer[strlen(buffer) - 2] == 'A') {
            fprintf(fileF2, "%s",  buffer);
        }
    }

    fclose(fileF1);
    fclose(fileF2);

    // Вывод содержимого файлов
    errno_t F1_1 = fopen_s(&fileF1, "F1.txt", "r");
    errno_t F2_1 = fopen_s(&fileF2, "F2.txt", "r");

    char ch;

    printf("Содержимое файла F1.txt:\n");
    ch = fgetc(fileF1);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fileF1);
    }

    printf("\n");

    printf("Содержимое файла F2.txt (строки, заканчивающиеся на 'a' или 'A'):\n");
    ch = fgetc(fileF2);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fileF2);
    }

    fclose(fileF1);
    fclose(fileF2);

    return 0;
}