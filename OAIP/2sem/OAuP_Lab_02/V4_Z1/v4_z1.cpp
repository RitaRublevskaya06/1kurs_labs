#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* fileA;
    errno_t A1 = fopen_s(&fileA, "fileA.txt", "r");
    if (fileA == NULL) {
        perror("Не удалось открыть файл fileA.txt\n");
        return 1;
    }

    FILE* fileB;
    errno_t B1 = fopen_s(&fileB, "fileB.txt", "w");
    if (fileB == NULL) {
        perror("Не удалось открыть файл fileB.txt\n");
        fclose(fileA);
        return 1;
    }

    int num;
    while (fscanf_s(fileA, "%d", &num) == 1) { // Читаем числа из fileA
        if (num > 0) { // Проверяем, что число положительное
            fprintf(fileB, "%d\t", num); // Записываем положительное число в fileB
        }
    }

    fclose(fileA);
    fclose(fileB);

    // Вывод содержимого файлов
    errno_t A2 = fopen_s(&fileA, "fileA.txt", "r");
    errno_t B2 = fopen_s(&fileB, "fileB.txt", "r");

    if (fileA == NULL || fileB == NULL) {
        printf("Ошибка при открытии файлов fileA.txt или fileB.txt\n");
        return 1;
    }

    int number;

    printf("Содержимое файла fileA.txt:\n");
    while (fscanf_s(fileA, "%d", &number) == 1) {
        printf("%d\t", number);
    }

    printf("\n");

    printf("Содержимое файла fileB.txt (только положительные числа):\n");
    while (fscanf_s(fileB, "%d", &number) == 1) {
        printf("%d\t", number);
    }

    fclose(fileA);
    fclose(fileB);

    return 0;
}