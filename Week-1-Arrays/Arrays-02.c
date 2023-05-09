#include "stdio.h"

int main(){
    int sourceArray[] = {2,7,3,5,6,16};
    int lengthOfArray = sizeof (sourceArray)/ sizeof (sourceArray[0]);
    for (int i = 0; i < lengthOfArray; ++i) {
        if (i % 2 == 0){
            if (sourceArray[i] % 2 != 0){
                sourceArray[i] += 1;
            }
        }
        else if (i % 2 != 0){
            if (sourceArray[i] % 2 == 0){
                sourceArray[i] += 1;
            }
        }
    }
    for (int i = 0; i < lengthOfArray; ++i) {
        printf("%d\n", sourceArray[i]);
    }
    return 0;
}