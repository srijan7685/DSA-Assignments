#include "stdio.h"

int main(){
    int sourceArray[] = { 2,7,3,5,6,16, 4, 3};
    int maxElement = 0;
    int lengthOfArray = sizeof (sourceArray) / sizeof (sourceArray[0]);
    for (int i = 0; i < lengthOfArray; ++i) {
        if (sourceArray[i] > maxElement){
            maxElement = sourceArray[i];
        }
    }
    printf("Maximum element : %d.\n", maxElement);
}