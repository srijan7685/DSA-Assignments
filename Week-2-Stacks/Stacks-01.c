#include "stdio.h"

int top = -1;
int myStack[5];

void pushItem(int inElement){
    int sizeOfStack = sizeof (myStack)/sizeof (myStack[0]);
    if (top >= sizeOfStack - 1){
        printf("Stack is Full.\n");
    } else{
        top++;
        myStack[top] = inElement;
        printf("%d is inserted into the stack.\n", inElement);
    }

}
void peekElement(){
    int sizeOfStack = sizeof (myStack) / sizeof (myStack[0]);
    int dataElement = myStack[sizeOfStack - 1];
    printf("%d is at the top of the Stack.\n", dataElement);
}

void popItem(){
    if (top < 0){
        printf("Stack is already empty.\n");
    } else{
        int outElement = myStack[top];
        printf("%d is removed from the stack.\n", outElement);
        top--;
    }
}
int main(){
    pushItem(5);
    pushItem(10);
    pushItem(15);
    pushItem(20);
    pushItem(25);
    pushItem(18);
    pushItem(25);
    peekElement();
    peekElement();
    popItem();
    popItem();
    popItem();
    popItem();
    popItem();
    popItem();
    popItem();



}

