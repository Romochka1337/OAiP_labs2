#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "interface.h"

void mainMenu(Car *carArr, int carArrSize){
    int choice;
    printf("\n1 - Вывести массив на экран");
    printf("\n2 - Создать экземпляр структуры");
    printf("\n3 - Удалить экземпляр структуры");
    printf("\n4 - Выполнить сортировки массива");
    printf("\n5 - Завершить программу");
    printf("\nВыберите действие: ");
    scanf("%d", &choice);
    rewind(stdin);

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
            clearMemory(carArr);
            break;
        default:
            printf("\nНеверный аргумент");
            printf("\n-------------------------------------------------------------------\n\n");
            mainMenu(carArr, carArrSize);
            break;
    }
}

void sortingMenu(Car *carArr, int carArrSize){
    int parameter1;
    printf("\n1 - по одному полю, 2 - по двум полям: ");
    printf("\nВыберите вариант сортировки: ");
    scanf("%d", &parameter1);
    rewind(stdin);
    switch (parameter1) {
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
    int parameter2;
    printf("\n1 - по цене");
    printf("\n2 - по году выпуска");
    printf("\n3 - по цвету");
    printf("\n4 - по названию");
    printf("\nВыберите параметр для сортировки: ");
    scanf("%d", &parameter2);
    rewind(stdin);
    switch(parameter2) {
        case 1:
            singleSortPrice(carArr, carArrSize);
            break;
        case 2:
            singleSortYear(carArr, carArrSize);
            break;
        case 3:
            singleSortColor(carArr, carArrSize);
            break;
        case 4:
            singleSortModel(carArr, carArrSize);
            break;
        default:
            break;
    }
}

void choseDoubleParameter(Car *carArr, int carArrSize){
    int parameter2;
    printf("\n1 - по цвету и году");
    printf("\n2 - по году и цене");
    printf("\n3 - по году и названию");
    printf("\nВыберите параметр для сортировки: ");
    scanf("%d", &parameter2);
    rewind(stdin);
    switch(parameter2) {
        case 1:
            doubleSortColorYear(carArr, carArrSize);
            break;
        case 2:
            doubleSortYearPrice(carArr, carArrSize);
            break;
        case 3:
            doubleSortYearModel(carArr, carArrSize);
            break;
        default:
            break;
    }
}

void clearMemory(Car *carArr){
    free(carArr);
}