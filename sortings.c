#include "model.h"
#include "string.h"

void singleSort(Car *carArr, int arrSize, int param){
    int i, j;
    Car temp;
    for (i = 1; i < arrSize; i++)
    {
        temp = carArr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if(param == 1){
                if (carArr[j].price < temp.price)
                    break;
                carArr[j + 1] = carArr[j];
                carArr[j] = temp;
            }else if(param == 2){
                if (carArr[j].year < temp.year)
                    break;
                carArr[j + 1] = carArr[j];
                carArr[j] = temp;
            }else if(param == 3){
                if (carArr[j].color < temp.color)
                    break;
                carArr[j + 1] = carArr[j];
                carArr[j] = temp;
            }else {
                if (strcmp(temp.model, carArr[j].model)>0)
                    break;
                carArr[j + 1] = carArr[j];
                carArr[j] = temp;
            }
        }
    }
}

void doubleSort(Car *carArr, int arrSize, int firstParam, int secondParam){
    singleSort(carArr, arrSize, firstParam);
    for (int i = 0; i < arrSize - 1; i++){
        for (int j = (arrSize - 1); j > i; j--){
            if((firstParam == 3) && (secondParam == 2)){
                if ((carArr[i].color==carArr[j].color)&&(carArr[j - 1].year > carArr[j].year)){
                    Car temp = carArr[j - 1];
                    carArr[j - 1] = carArr[j];
                    carArr[j] = temp;
                }
            } else if((firstParam == 2) && (secondParam == 1)){
                if ((carArr[i].year==carArr[j].year)&&(carArr[j - 1].price > carArr[j].price)){
                    Car temp = carArr[j - 1];
                    carArr[j - 1] = carArr[j];
                    carArr[j] = temp;
                }
            } else if((firstParam == 2) && (secondParam == 4)){
                if ((carArr[i].color==carArr[j].color)&&(strcmp(carArr[i].model,carArr[j].model)>0)){
                    Car temp = carArr[j - 1];
                    carArr[j - 1] = carArr[j];
                    carArr[j] = temp;
                }
            }
        }
    }
}