#include "stdio.h"
#include "string.h"

int top = -1;
char myStack[3];

void pushItem(char inElement){
    int sizeOfStack = sizeof (myStack)/sizeof (myStack[0]);
    if (top >= sizeOfStack - 1){
        printf("Stack is Full.\n");
    } else{
        top++;
        myStack[top] = inElement;
        printf("%c is inserted into the stack.\n", inElement);
    }
}

char popItem(){
    if (top < 0){
        printf("Stack is already empty.\n");
    } else{
        char outElement = myStack[top];
        top--;
        return outElement;

    }
}

int main(){
    pushItem('L');
    pushItem('O');
    pushItem('L');
    pushItem('S');
    printf("Reversed Output:\n");
    char popFirstOutput = popItem();
    char popSecondOutput = popItem();
    char popThirdOutput = popItem();
    printf("%c%c%c\n", popFirstOutput, popSecondOutput, popThirdOutput);
    char popFourthOutput = popItem();

}
