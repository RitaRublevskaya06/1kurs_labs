#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "");
    FILE* filefA;
    errno_t fA = fopen_s(&filefA, "fA.txt", "r");
    if (filefA == NULL) {
        perror("Не удалось открыть файл fA.txt\n");
        return 1;
    }

    int size = 0;
    float currentValue, closestValue, userValue;

    printf("Введите целое число: ");
    if (scanf_s("%f", &userValue) != 1) {
        printf("Ошибка ввода. Введите целое число.\n");
        return 1;
    }

    int position = 0, closestPosition;
    float smallestDifference = INFINITY;

    while (fscanf_s(filefA, "%F", &currentValue) == 1) {
        if (abs(userValue - currentValue) < smallestDifference) {
            closestValue = currentValue;
            smallestDifference = abs(userValue - currentValue);
            closestPosition = position;
        }
        position++;
    }
    fclose(filefA);

    printf("Наиболее близкое значение: %.2f\n", closestValue);
    printf("Порядковый номер: %d\n", closestPosition);

    return 0;
}