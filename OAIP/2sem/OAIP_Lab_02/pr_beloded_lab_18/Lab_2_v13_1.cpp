#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* fileA, * fileB;
    int num;
    int count[1000] = { 0 }; // Максимальное значение числа в fileA

    // Открываем файл fileA для чтения
    errno_t A = fopen_s(&fileA, "fileA.txt", "r");
    if (fileA == NULL) {
        printf("Не удалось открыть файл fileA.txt\n");
        return 1;
    }

    // Считываем числа из fileA и считаем их количество
    while (fscanf_s(fileA, "%d", &num) != EOF) {
        count[num]++;
    }

    // Закрываем файл fileA
    if (fclose(fileA) != 0) {
        printf("Ошибка при закрытии файла fileA.txt\n");
        return 1;
    }

    // Открываем файл fileB для записи
    errno_t B = fopen_s(&fileB, "fileB.txt", "w");
    if (fileB == NULL) {
        printf("Не удалось открыть файл fileB.txt.n");
        return 1;
    }

    // Повторное открытие файла fileA для чтения
    errno_t A1 = fopen_s(&fileA, "fileA.txt", "r");
    if (fileA == NULL) {
        printf("Не удалось повторно открыть файл fileA.txt\n");
        return 1;
    }

    // Записываем в fileB числа, которые встречаются в fileA более двух раз
    while (fscanf_s(fileA, "%d", &num) != EOF) {
        if (count[num] > 2) {
            fprintf(fileB, "%d\t", num);
        }
    }
    // Закрываем файл fileA
    if (fclose(fileA) != 0) {
        printf("Ошибка при закрытии файла fileA.txt\n");
        return 1;
    } 
    // Закрываем файл fileB
    if (fclose(fileB) != 0) {
        printf("Ошибка при закрытии файла fileB.txt\n");
        return 1;
    }

    // Открываем файл fileB для чтения и выводим его содержимое на экран
    errno_t B1 = fopen_s(&fileB, "fileB.txt", "r");
    if (fileB == NULL) {
        printf("Не удалось открыть файл fileB.txt\n");
        return 1;
    }

    printf("Содержимое файла fileB:\n");
    while (fscanf_s(fileB, "%d", &num) != EOF) {
        printf("%d\t", num);
    }

    // Закрываем файл fileB
    if (fclose(fileB) != 0) {
        printf("Ошибка при закрытии файла fileB.txt\n");
        return 1;
    }

    return 0;
}