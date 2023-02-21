#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "sortings.h"


char *readFile() {
    long length;

    FILE *f = fopen("../index.html", "r");

    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = calloc(length, 1);

    fread(buffer, 1, length, f);
    fclose(f);

    return buffer;
}

String *getInfo(char *doc, String *strArr ,int *len, char *firstDelimiter, char *secondDelimiter) {
    int diff;
    char *pos = doc;
    char *newPos;
    int firstDelSize = strlen(firstDelimiter);
    char *tmpStr;
    do {
        pos = strstr(pos, firstDelimiter);
        newPos = strstr(pos, secondDelimiter);
        diff = strlen(pos) - strlen(newPos);
        tmpStr = malloc(sizeof(char) * diff);
        for (int i = firstDelSize; i < diff; i++) {
            char *tmpChar = malloc(0);
            tmpChar[0] = pos[i];
            strcat(tmpStr, tmpChar);
        }
        (*len)++;
        strArr = realloc(strArr, (*len) * sizeof(Car));
        pos = newPos;
        String obj;
        obj.str = tmpStr;
        strArr[(*len)-1]=obj;
    } while (strstr(pos, firstDelimiter) != NULL);

    return strArr;
}

Car *parseHTML(int *len) {
    char *doc = readFile();

    String *strArr = calloc(*len, sizeof(String));
    char *firstDelimiter = "<a class=\"tov_info\"><strong>";
    char *secondDelimiter = "</strong>";
    strArr = getInfo(doc, strArr, len, firstDelimiter, secondDelimiter);
    Car *carArr = calloc(*len, sizeof(Car));
    for (int i = 0; i < *len; i++) {
        Car obj;
        int diff;
        char *pos=strArr[i].str;

        char *newPos= strstr(pos, "(");
        diff = strlen(pos)- strlen(newPos);
        char *model= calloc(diff, sizeof(char));

        for (int j = 0; j < diff; j++) {
            model[j] = pos[j];
        }

        char *year = calloc(4, sizeof(char));
        for (int j = 1; j < 5; j++) {
            year[j-1] = newPos[j];
        }

        int color;
        if (strstr(strArr[i].str, "BLACK") != NULL){
            color = 0;
        } else if (strstr(strArr[i].str, "BLUE") != NULL){
            color = 1;
        } else if (strstr(strArr[i].str, "GRAY") != NULL){
            color= 2;
        } else if (strstr(strArr[i].str, "RAD") != NULL){
            color = 3;
        } else{
            color = 4;
        }

        obj.model = model;
        obj.year = atoi(year) ;
        obj.color = color;
        carArr[i] = obj;
    }

    char *firstPriceDel = "<div class=\"tov_price\">";
    char *secondPriceDel = " р.";
    int priceCounter=0;
    String *priceArr = calloc(*len, sizeof(String));
    priceArr = getInfo(doc, priceArr, &priceCounter, firstPriceDel, secondPriceDel);
    for (int i = 0; i < *len; i++) {
        carArr[i].price = atoi(priceArr[i].str);
    }
    free(strArr);
    free(doc);
    free(priceArr);
    return carArr;
}

Car *createCarObject(Car *carArr, int *arrSize){
    char *model = (char*)calloc(1024, sizeof(char));
    int chooseColor;
    int year;
    float price;
    printf("\nВведите название автомобиля: ");
    scanf("%s", model);
    rewind(stdin);
    printf("Введите цену: ");
    scanf("%f", &price);
    rewind(stdin);
    printf("Введите год создания: ");
    scanf("%d", &year);
    rewind(stdin);
    printf("\n1 - BLACK");
    printf("\n2 - BLUE");
    printf("\n3 - GRAY");
    printf("\n4 - RAD: ");
    printf("\n5 - WHITE ");
    printf("\nВыберите цвет: ");
    scanf("%d", &chooseColor);
    rewind(stdin);
    chooseColor--;
    Car carObject = {year,price,  model, chooseColor};
    carArr = (Car*)realloc(carArr, sizeof(Car) * ((*arrSize) + 1));
    carArr[(*arrSize)] = carObject;
    (*arrSize)++;
    return carArr;
}
void showArr(Car *carArr, int carArrSize){
    for (int i = 0; i < carArrSize; i++) {
        printf("\nid[%d]: model: %s, price: %5.1f, year: %d", i,  carArr[i].model, carArr[i].price, carArr[i].year);
        switch (carArr[i].color) {
            case 0:
                printf(", color: BLACK");
                break;
            case 1:
                printf(", color: BLUE");
                break;
            case 2:
                printf(", color: GRAY");
                break;
            case 3:
                printf(", color: RAD");
                break;
            case 4:
                printf(", color: WHITE");
                break;
            default:
                break;
        }
    }
}

void *deleteFromArray(Car *carArr, int *carArrSize){
    int deleteId;
    printf("\nВведите id автомобиля, который вы хотите удалить: ");
    scanf("%d", &deleteId);
    if ( deleteId < 0 || deleteId >= *carArrSize) {
        printf("\nНеверный id");
    }else{
        for (int i = deleteId+1; i < (*carArrSize) - 3; i++) {
            carArr[i] = carArr[i+1];
        }
        (*carArrSize)--;
        printf("\nАвтомобиль удалён.");
    }
    return NULL;
}




















