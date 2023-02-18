#include "functions.h"
#include "interface.h"

int main() {
    int len = 0;
    Car *carArr = parseHTML(&len);
    mainMenu(carArr, len);
    return 0;
}











