#include "model.h"
String *getInfo(const char *doc, String *strArr , int *len,const char *firstDelimiter,const char *secondDelimiter);
void clearStrMemory(String *strArr, char *doc, String *priceArr, int len);
Car *parseHTML(int *len);
char *readFile();
int strLength(const char *str);
void showArr(Car *carArr, int carArrSize);
Car *deleteFromArray(Car *carArr, int *carArrSize);
void sortingMenu( Car *carArr, int carArrSize);
Car *createCarObject(Car *carArr, int *arrSize);