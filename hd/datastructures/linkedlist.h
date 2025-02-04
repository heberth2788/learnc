//
//  linkedlist.h
//  hd
//
//  Created by Heberth Deza on 3/02/25.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definning the self-referential structure for the linked-list node
typedef struct listNode {
    char letter; // character
    struct listNode * nextNodePtr; // pointer to the next node
} ListNode;

typedef ListNode * ListNodePtr; // ListNodePtr = ListNode *

void myLinkedList(void);
void showInstructionsLinkedList(void);
void insertNode(ListNode ** listPtr, char letter);
void deleteNode(ListNode ** listPtr, char letter);
void printLinkedList(ListNode * listPtr);

void callFooBar(void);
void fooBar(int * myIntP);
void barFoo(int myInt);

#endif /* linkedlist_h */
