//
//  stack.c
//  hd
//
//  Created by Heberth Deza on 3/02/25.
//

#include "stack.h"

/**
    Stack
 
       Linear data structure, you con only add(push) and remove(pop) nodes from the top.
       LIFO (last-in first-out) data structure.
       Operations: push and pop
 */

void myStack(void) {
    StackNode * topPtr = NULL;
    int data = 0;
    int choice = 0;
    
    puts("\tSTACK data structure\n");
    showInstructionsStack();
    printf("%s", "? ");
    scanf("\n%d", &choice);
    
    while (choice != 3) {
        switch (choice) {
            case 1:
                printf("%s", "Enter the integer to push: ");
                scanf("\n%d", &data);
                push(&topPtr, data);
                printStack(topPtr);
                break;
            case 2:
                printf("%s", "Popping");
                pop(&topPtr);
                printStack(topPtr);
                break;
            default:
                printf("[%d] %s\n\n", choice, "is an invalid option, try again");
                break;
        }
        
        showInstructionsStack();
        printf("%s", "? ");
        scanf("%d", &choice);
    }
    puts("\n[End of run]");
}

// add a new node on the top
void push(StackNode ** topPtr, int data) {
    StackNode * newNode = malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("[%d] could not be pushed onto the stack, no memory available\n", data);
        return;
    }
    
    newNode->data = data;
    newNode->nextPtr = *topPtr;
    *topPtr = newNode;
    printf("\t[%d pushed]\n", data);
}

// remove a node from the top
int pop(StackNode ** topPtr) {
    int poppedData = 0;
    
    if (*topPtr == NULL) {
        printf("%s", "Empty stack\n");
        return 0;
    }
    
    StackNode * topNodePtr = *topPtr;
    poppedData = topNodePtr->data;
    *topPtr = topNodePtr->nextPtr;
    free(topNodePtr);
    
    printf("\t[%d popped]\n", poppedData);
    return poppedData;
}

void printStack(StackNode * topPtr) {
    if (topPtr == NULL) {
        puts("Empty stack");
        return;
    }
    
    StackNode * currentNodePtr = topPtr;
    printf("%s", "Printing stack: ");
    while (currentNodePtr != NULL) {
        printf("[%d] ", currentNodePtr->data);
        currentNodePtr = currentNodePtr->nextPtr;
    }
    puts("");
}

void showInstructionsStack(void) {
    puts("Enter your choise:\n"
         "\t1 to push an element in the stack.\n"
         "\t2 to pop an element from the stack.\n"
         "\t3 to exit.");
}


