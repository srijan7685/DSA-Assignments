#include "stdio.h"

int main(){
    int sourceArray[] = {5, 4, 3, 2, 1};
    int sumOfElements = 0;
    int lengthOfArray = sizeof (sourceArray) / sizeof (sourceArray[0]);
    for (int i = 0; i < lengthOfArray; ++i) {
        sumOfElements += sourceArray[i];
    }
    printf("Sum of the elements : %d\n", sumOfElements);
}
