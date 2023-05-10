#include "stdio.h"

int top = -1;
char *myStack[4];

void pushItem(char inElement[]){
    int sizeOfStack = sizeof (myStack)/sizeof (myStack[0]);
    if (top >= sizeOfStack - 1){
        printf("Stack is Full.\n");
    } else{
        top++;
        myStack[top] = inElement;
        printf("%s is inserted into the stack.\n", inElement);
    }
}

void popItem(){
    if (top < 0){
        printf("Stack is already empty.\n");
    } else{
        printf("%s\n", myStack[top]);
        top--;
    }
}

int main(){
    pushItem("Hawa Le Sushant KC");
    pushItem("English chill music");
    pushItem("It's possible Les Brown");
    pushItem("New chat - chat gpt");
    pushItem("Test push");
    popItem();
    popItem();
    popItem();
    popItem();
    popItem();
    popItem();

}
