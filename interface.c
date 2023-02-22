#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "interface.h"
#include "sortings.h"

void mainMenu(Car *carArr, int carArrSize){
    int choice;
    printf("\n1 - Вывести массив на экран");
    printf("\n2 - Создать экземпляр структуры");
    printf("\n3 - Удалить экземпляр структуры");
    printf("\n4 - Выполнить сортировки массива");
    printf("\n5 - Завершить программу");
    printf("\nВыберите действие: ");
    while (!scanf("%d", &choice) || choice > 5 || choice <= 0 || getchar() != '\n') {
        printf("\nНеверный аргумент. Попробуйте снова: ");
        rewind(stdin);
    }
    switch(choice) {
        case 1:
            printf("\n-------------------------------------------------------------------\n");
            showArr(carArr, carArrSize);
            printf("\n\n-------------------------------------------------------------------\n\n");
            mainMenu(carArr, carArrSize);
            break;
        case 2:
            carArr = createCarObject(carArr, &carArrSize);
            printf("\nАвтомобиль добавлен.");
            printf("\n\n-------------------------------------------------------------------\n\n");
            mainMenu(carArr, carArrSize);
            break;
        case 3:
            deleteFromArray(carArr, &carArrSize);
            printf("\n\n-------------------------------------------------------------------\n\n");
            mainMenu(carArr, carArrSize);
            break;
        case 4:
            sortingMenu(carArr, carArrSize);
            printf("\nМассив отсортирован.");
            printf("\n-------------------------------------------------------------------\n\n");
            mainMenu(carArr, carArrSize);
            break;
        case 5:
            clearCarMemory(carArr, carArrSize);
            break;
        default:
            break;
    }
}

void sortingMenu(Car *carArr, int carArrSize){
    int param1;
    printf("\n1 - по одному полю, 2 - по двум полям: ");
    printf("\nВыберите вариант сортировки: ");
    while (!scanf("%d", &param1) || param1 > 2 || param1 <= 0 || getchar() != '\n') {
        printf("\nНеверный аргумент:");
        rewind(stdin);
    }
    switch (param1) {
        case 1:
            choseSingleParameter(carArr, carArrSize);
            break;
        case 2:
            choseDoubleParameter(carArr, carArrSize);
            break;
        default:
            break;
    }
}

void choseSingleParameter(Car *carArr, int carArrSize){
    int param;
    printf("\n1 - по цене");
    printf("\n2 - по году выпуска");
    printf("\n3 - по цвету");
    printf("\n4 - по названию");
    printf("\nВыберите параметр для сортировки: ");
    while (!scanf("%d", &param) || param > 2 || param <= 0 || getchar() != '\n') {
        printf("\nНеверный аргумент:");
        rewind(stdin);
    }
    switch(param) {
        case 1:
            singleSort(carArr,carArrSize, 1);
            break;
        case 2:
            singleSort(carArr,carArrSize, 2);
            break;
        case 3:
            singleSort(carArr,carArrSize, 3);
            break;
        case 4:
            singleSort(carArr,carArrSize, 4);
            break;
        default:
            break;
    }
}

void choseDoubleParameter(Car *carArr, int carArrSize){
    int param2;
    printf("\n1 - по цвету и году");
    printf("\n2 - по году и цене");
    printf("\n3 - по году и названию");
    printf("\nВыберите параметр для сортировки: ");
    while (!scanf("%d", &param2) || param2 > 3 || param2 <= 0 || getchar() != '\n') {
        printf("\nНеверный аргумент:");
        rewind(stdin);
    }
    switch(param2) {
        case 1:
            doubleSort(carArr, carArrSize, 3, 2);
            break;
        case 2:
            doubleSort(carArr, carArrSize, 2, 1);
            break;
        case 3:
            doubleSort(carArr, carArrSize, 2, 4);
            break;
        default:
            break;
    }
}

void clearCarMemory(Car *carArr, int carArrSize){
    for (int i = 0; i < carArrSize; i++) {
        free(carArr[i].model);
    }
    free(carArr);
}