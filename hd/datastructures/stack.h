//
//  stack.h
//  hd
//
//  Created by Heberth Deza on 3/02/25.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode * nextPtr;
} StackNode;

// function prototypes
void myStack(void);
void push(StackNode ** topPtr, int data);
int pop(StackNode ** topPtr);
void printStack(StackNode * topPtr);
void showInstructionsStack(void);

#endif /* stack_h */
