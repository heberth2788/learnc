//
//  queues.h
//  hd
//
//  Created by Heberth Deza on 3/02/25.
//

#ifndef queues_h
#define queues_h

#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
    int data;
    struct queueNode * nextNodePtr;
} QueueNode;

// function prototypes
void myQueue(void);
void enqueue(QueueNode ** tailNodePtr, QueueNode ** headNodePtr, int data);
int dequeue(QueueNode ** headNodePtr, QueueNode ** tailNodePtr);
void printQueue(QueueNode * headNodePtr);
void showInstructionsQueue(void);

#endif /* queues_h */
