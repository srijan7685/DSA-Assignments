#include "stdio.h"

int front = -1;
int rear = -1;
char *myQueue[3];
int lengthOfQueue = sizeof (myQueue) / sizeof (myQueue[0]);

void enQueue(char inElement[]){
    if (rear >= lengthOfQueue - 1){
        printf("Queue is already full.\n");
    } else{
        rear++;
        myQueue[rear] = inElement;
        printf("%s is in the queue.\n", inElement);
    }
}

void deQueue(){
    if (front >= lengthOfQueue - 1 ){
        printf("Queue is empty.\n");
    } else{
        front++;
        printf("%s checked out.\n", myQueue[front]);
    }
}

int main(){
    enQueue("Fuchee");
    enQueue("Fuchey");
    enQueue("RichKid");
    enQueue("CoolKid");
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
}