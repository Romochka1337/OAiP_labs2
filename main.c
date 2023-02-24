#include "functions.h"
#include "interface.h"

int main() {
    int carArrSize = 0;
    Car *carArr = parseHTML(&carArrSize);
    mainMenu(carArr, carArrSize);
    return 0;
}











