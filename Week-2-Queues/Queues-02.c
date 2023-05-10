#include "stdio.h"

int front = -1;
int rear = -1;
int ticketCounter[5];
int capacityOfCounter = sizeof (ticketCounter) / sizeof (ticketCounter[0]);

void printTicket(){
    if (rear >= capacityOfCounter - 1){
        printf("No more print available.\n");
    } else{
        rear++;
        int ticketNumber = rear + 1;
        ticketCounter[rear] = ticketNumber;
        printf("Ticket no %d is printed.\n", ticketNumber);
    }
}

void displayTicket(){
    if ( front >= capacityOfCounter - 1){
        printf("No more tickets to display.\n");
    } else{
        front++;
        int displayTicket = ticketCounter[front];
        printf("%d is displayed on the screen.\n", displayTicket);
    }
}

int main(){
    printTicket();
    printTicket();
    printTicket();
    printTicket();
    printTicket();
    printTicket();
    printTicket();
    printTicket();
    displayTicket();
    displayTicket();
    displayTicket();
    displayTicket();
    displayTicket();
    displayTicket();
    displayTicket();
    displayTicket();
}

