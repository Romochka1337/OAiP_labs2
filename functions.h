#include "model.h"
String *getInfo(char *doc, String *strArr , int *len, char *firstDelimiter, char *secondDelimiter);
Car *parseHTML(int *len);
char *readFile();
void showArr(Car *carArr, int carArrSize);
void *deleteFromArray(Car *carArr, int *carArrSize);
void singleSortYear(Car *arr, int arrSize);
void singleSortPrice(Car *arr, int arrSize);
void singleSortModel( Car *arr, int arrSize);
void singleSortColor( Car *arr, int arrSize);
void sortingMenu( Car *carArr, int carArrSize);
void doubleSortYearPrice( Car *arr, int arrSize);
void doubleSortColorYear( Car *arr, int arrSize);
void doubleSortYearModel( Car *arr, int arrSize);
Car *createCarObject(Car *carArr, int *arrSize);