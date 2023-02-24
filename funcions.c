#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "sortings.h"

char *readFile() {
    long length;

    FILE *file = fopen("../index.html", "r");
    if(file){
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        char *buffer = calloc(length, 1);

        fread(buffer, 1, length, file);
        fclose(file);
        return buffer;
    } else return NULL;

}

String *getInfo(const char *doc, String *strArr ,int *len,const char *firstDelimiter,const char *secondDelimiter) {
    unsigned long long diff;
    const char *pos = doc;
    const char *newPos;
    unsigned long long firstDelSize = strlen(firstDelimiter);
    char *tmpStr;
    do {
        pos = strstr(pos, firstDelimiter);
        newPos = strstr(pos, secondDelimiter);
        diff = strlen(pos) - strlen(newPos);
        tmpStr = malloc(sizeof(char) * diff);
        for (unsigned long long i = firstDelSize; i < diff; i++) {
            char *tmpChar = malloc(sizeof(char));
            tmpChar[0] = pos[i];
            strcat(tmpStr, tmpChar);
            free(tmpChar);
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

Car *parseHTML(int *carArrSize) {
    char *doc = readFile();

    String *strArr = calloc(*carArrSize, sizeof(String));
    const char *firstDelimiter = "<a class=\"tov_info\"><strong>";
    const char *secondDelimiter = "</strong>";
    strArr = getInfo(doc, strArr, carArrSize, firstDelimiter, secondDelimiter);
    Car *carArr = calloc(*carArrSize, sizeof(Car));
    for (int i = 0; i < *carArrSize; i++) {
        Car obj;
        unsigned long long diff;
        const char *pos=strArr[i].str;
        const char *newPos= strstr(pos, "(");
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
        } else if (strstr(strArr[i].str, "RED") != NULL){
            color = 3;
        } else{
            color = 4;
        }
        obj.model = model;
        obj.year = atoi(year) ;
        obj.color = color;
        carArr[i] = obj;
    }
    const char *firstPriceDel = "<div class=\"tov_price\">";
    const char *secondPriceDel = " р.";
    int priceCounter=0;
    String *priceArr = calloc(*carArrSize, sizeof(String));
    priceArr = getInfo(doc, priceArr, &priceCounter, firstPriceDel, secondPriceDel);
    for (int i = 0; i < *carArrSize; i++) {
        carArr[i].price = atof(priceArr[i].str);
    }
    clearStrMemory(strArr, doc, priceArr, *carArrSize);
    return carArr;
}
int strLength(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i + 1;
}
Car *createCarObject(Car *carArr, int *carArrSize){
    char *model = (char*)calloc(1024, sizeof(char));
    int chooseColor;
    int year;
    float price;
    printf("\nВведите название автомобиля: ");
    do
    {
        fgets(model, 1024, stdin);
        rewind(stdin);
    } while (strLength(model) < 1 && getchar() != '\0');
    char *mas = (char*)realloc(model, (strLength(model) + 1) * sizeof(char));
    if (mas != NULL)
        model = mas;
    rewind(stdin);

    printf("Введите цену: ");
    while (!scanf("%f", &price) || price <= 0 || getchar() != '\n') {
        printf("\nНеверный аргумент:");
        rewind(stdin);
    }
    printf("Введите год: ");
    while (!scanf("%d", &year) || year <= 0 || getchar() != '\n') {
        printf("\nНеверный аргумент:");
        rewind(stdin);
    }
    printf("\n1 - BLACK");
    printf("\n2 - BLUE");
    printf("\n3 - GRAY");
    printf("\n4 - RED: ");
    printf("\n5 - WHITE ");
    printf("\nВыберите цвет: ");
    while (!scanf("%d", &chooseColor) || chooseColor <= 0 || chooseColor > 5 || getchar() != '\n') {
        printf("\nНеверный аргумент:");
        rewind(stdin);
    }
    chooseColor--;
    Car carObject = {year,price,  model, chooseColor};
    carArr = (Car*)realloc(carArr, sizeof(Car) * ((*carArrSize) + 1));
    carArr[(*carArrSize)] = carObject;
    (*carArrSize)++;
    return carArr;
}
void showArr(Car *carArr, int carArrSize){

    for (int i = 0; i < carArrSize; i++) {
        int j=0;
        printf("\n[id]:%2d,  model: ", i);
        while(carArr[i].model[j] != '\n' && carArr[i].model[j] != '\0'){
            printf("%c", carArr[i].model[j]);
            j++;
        }

        printf(",   price: %5.1f,   year: %d", carArr[i].price, carArr[i].year);
        switch (carArr[i].color) {
            case 0:
                printf(",   color: BLACK");
                break;
            case 1:
                printf(",   color: BLUE");
                break;
            case 2:
                printf(",   color: GRAY");
                break;
            case 3:
                printf(",   color: RED");
                break;
            case 4:
                printf(",   color: WHITE");
                break;
            default:
                break;
        }
    }
}

Car *deleteFromArray(Car *carArr, int *carArrSize){
    int deleteId;
    printf("\nВведите id автомобиля, который вы хотите удалить: ");
    while (!scanf("%d", &deleteId) || deleteId >= *carArrSize || deleteId < 0 || getchar() != '\n') {
        printf("\nНеверный аргумент. Попробуйте снова: ");
        rewind(stdin);
    }
    if ( deleteId >= 0 || deleteId < *carArrSize) {
        free(carArr[deleteId].model);
        for (int i = deleteId+2; i < (*carArrSize); i++) {
            carArr[i-2] = carArr[i-1];
        }
        (*carArrSize)--;
        carArr = realloc(carArr, *carArrSize * sizeof(Car));
        printf("\nАвтомобиль удалён.");
    }else{
        printf("\nНеверный id");
    }
    return carArr;
}
void clearStrMemory(String *strArr, char *doc, String *priceArr, int size){
    for (int i = 0; i < size; i++) {
        free(strArr[i].str);
    }
    for (int i = 0; i < size; i++) {
        free(priceArr[i].str);
    }
    free(doc);
    free(strArr);
    free(priceArr);
}




















