#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
    char data[50];
    struct Node *nextNode;
} Node;

Node *firstNode;

void insertNodeAtStart(char data[]){
    if (firstNode == NULL){
        firstNode = (struct Node *) malloc(sizeof (Node));
        strcpy(firstNode->data, data);
        printf("%s\n", data);
        firstNode->nextNode = NULL;
    } else{
        Node *newNode = (struct Node *) malloc(sizeof (Node));
        strcpy(newNode->data, data);
        printf("%s\n", data);
        newNode->nextNode = firstNode;
        firstNode = newNode;
    }
}

void traverseNodes(){
    Node *currentNode = firstNode;
    while (currentNode->nextNode != NULL){
        printf("%s=>", currentNode->data);
        currentNode = currentNode->nextNode;
    }
    printf("%s", currentNode->data);
}

void deleteNodeAtEnd(){

}

int main(){
    printf("Sam’s to-do list for today\nInsertion operation.....\n");
    insertNodeAtStart("Read DSA");
    insertNodeAtStart("Code");
    insertNodeAtStart("Use chat gpt");
    insertNodeAtStart("Dance");
    printf("Traversing operation..............\n");
    traverseNodes();
}