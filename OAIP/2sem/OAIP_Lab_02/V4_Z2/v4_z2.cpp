#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* fileF;
    errno_t F1 = fopen_s(&fileF, "f.txt", "r");
    if (fileF == NULL) {
        perror("Не удалось открыть файл f.txt\n");
        return 1;
    }
    int threshold;
    printf("Введите пороговое значение: ");
    scanf_s("%d", &threshold);

    FILE* fileG;
    errno_t G1 = fopen_s(&fileG, "g.txt", "w");
    if (fileG == NULL) {
        perror("Не удалось открыть файл g.txt\n");
        fclose(fileF);
        return 1;
    }

    int number;
    while (fscanf_s(fileF, "%d", &number) == 1) {
        if (number > threshold) {
            fprintf(fileG, "%d\t", number);
        }
    }

    fclose(fileF);
    fclose(fileG);

    return 0;
}