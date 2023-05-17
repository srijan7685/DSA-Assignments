#include "stdio.h"

int main(){
    int sourceArray[] = { 2,7,3,5,6, 1,16, 4, 3};
    int minElement = sourceArray[0];
    int lengthOfArray = sizeof (sourceArray) / sizeof (sourceArray[0]);
    for (int i = 0; i < lengthOfArray; ++i) {
        if (sourceArray[i] < minElement){
            minElement = sourceArray[i];
        }
    }
    printf("Minimum element : %d.\n", minElement);
}