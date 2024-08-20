#include <iostream> //Подключение стандартной библиотеки
#include <stdio.h>
#include <stdlib.h>

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
    int isEven = 0;

    while (fgets(buffer, sizeof(buffer), fileF1)) {
        if (isEven) {
            fprintf(fileF2, "%s", buffer);
        }
        isEven = !isEven;
    }

    fclose(fileF1);
    fclose(fileF2);

    // Вывод содержимого файлов
    errno_t F1_1 = fopen_s(&fileF1, "F1.txt", "r");
    errno_t F2_1 = fopen_s(&fileF2, "F2.txt", "r");

    if (fileF1 == NULL || fileF2 == NULL) {
        printf("Ошибка при открытии файлов F1.txt или F2.txt\n");
        return 1;
    }

    printf("Содержимое файла F1.txt:\n");
    while (fgets(buffer, sizeof(buffer), fileF1)) {
        printf("%s", buffer);
    }

    printf("\n");

    printf("Содержимое файла F2.txt (чётные строки из F1):\n");
    while (fgets(buffer, sizeof(buffer), fileF2)) {
        printf("%s", buffer);
    }

    fclose(fileF1);
    fclose(fileF2);

    return 0;
}
