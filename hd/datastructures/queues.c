//
//  queues.c
//  hd
//
//  Created by Heberth Deza on 3/02/25.
//

#include "queues.h"

/**
    Queues
           Linear data structure, you con add(enqueue) on the tail and remove(dequeue) from the head
           FIFO (first-in first-out) data structure.
           Operations: enqueue and dequeue
 
    * Se agrega por la cola(tail) y se retira por la cabeza(head)
 */

void myQueue(void) {
    QueueNode * tailNodePtr = NULL;
    QueueNode * headNodePtr = NULL;
    
    int data = 0;
    int choice = 0;
    
    puts("\tQUEUE data structure\n");
    
    showInstructionsQueue();
    printf("%s", "? ");
    scanf("\n%d", &choice);
    
    while (choice != 3) {
        switch (choice) {
            case 1:
                printf("%s", "Enter the integer to enqueue: ");
                scanf("\n%d", &data);
                enqueue(&tailNodePtr, &headNodePtr, data);
                printQueue(headNodePtr);
                break;
            case 2:
                printf("%s", "Dequeue");
                dequeue(&headNodePtr, &tailNodePtr);
                printQueue(headNodePtr);
                break;
            default:
                printf("[%d] %s\n\n", choice, "is an invalid option, try again");
                break;
        }
        
        showInstructionsQueue();
        printf("%s", "? ");
        scanf("%d", &choice);
    }
    
    puts("\n[End of run]");
}

void enqueue(QueueNode ** tailNodePtr, QueueNode ** headNodePtr, int data) {
    QueueNode * newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("[%d] could not be enqueue onto the queue, no memory available\n", data);
        return;
    }
    
    newNode->data = data;
    newNode->nextNodePtr = NULL;
    
    // if head/tail node points to null, then it is the first element in the queue
    if (*tailNodePtr == NULL || *headNodePtr == NULL) {
        *tailNodePtr = newNode;
        *headNodePtr = newNode;
        printf("\t[%d queued]\n", data);
        return;
    }
    
    // Incorrect, these two lines below does not modify the original object(struct)
    //QueueNode queueNodeAux = **tailNodePtr;
    //queueNodeAux.nextNodePtr = newNode;
    
    QueueNode * pivotNode = *tailNodePtr;
    pivotNode->nextNodePtr = newNode;
//    (*tailNodePtr)->nextNodePtr = newNode; // same as the above line
    *tailNodePtr = newNode;
    
    printf("\t[%d queued]\n", data);
}

int dequeue(QueueNode ** headNodePtr, QueueNode ** tailNodePtr) {
    // if head/tail node points to null, then it is the first element in the queue
    if (*tailNodePtr == NULL || *headNodePtr == NULL) {
        printf("%s", "\t[Empty queue]\n");
        return 0;
    }
    
    int data = 0;
    
    QueueNode * currentHead = *headNodePtr;
    *headNodePtr = currentHead->nextNodePtr;
    data = currentHead->data;
    currentHead->nextNodePtr = NULL;
    free(currentHead);
    currentHead = NULL;
    
    printf("\t[%d dequeued]\n", data);
    return data;
}

void printQueue(QueueNode * headNodePtr) {
    if (headNodePtr == NULL) {
        puts("Empty queue");
        return;
    }
    
    QueueNode * currentNodePtr = headNodePtr;
    printf("%s", "Printing queue: ");
    while (currentNodePtr != NULL) {
        printf("[%d] ", currentNodePtr->data);
        currentNodePtr = currentNodePtr->nextNodePtr;
    }
    puts("");
}

void showInstructionsQueue(void) {
    puts("Enter your choice:\n"
         "\t1 to enqueue an element.\n"
         "\t2 to dequeue an element.\n"
         "\t3 to exit.");
}
