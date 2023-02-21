#include "model.h"
String *getInfo(char *doc, String *strArr , int *len, char *firstDelimiter, char *secondDelimiter);
Car *parseHTML(int *len);
char *readFile();
void showArr(Car *carArr, int carArrSize);
Car *deleteFromArray(Car *carArr, int *carArrSize);
void sortingMenu( Car *carArr, int carArrSize);
Car *createCarObject(Car *carArr, int *arrSize);