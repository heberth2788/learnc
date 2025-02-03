//
//  datastructure.h
//  hd
//
//  Created by Heberth Deza on 29/01/25.
//

#ifndef datastructure_h
#define datastructure_h

#include <stdio.h>
#include <stdlib.h>

// definning the self-referential structure for the linked-list node
typedef struct listNode {
    char letter; // character
    struct listNode * nextNodePtr; // pointer to the next node
} ListNode;

typedef ListNode * ListNodePtr; // ListNodePtr = ListNode *

void myLinkedList(void);
void showInstructions(void);
void insertNode(ListNode ** listPtr, char letter);
void deleteNode(ListNode ** listPtr, char letter);
void printLinkedListMemMgmt(ListNode * listPtr);
void printLinkedList(ListNode * listPtr);

void testLinkedList(void);
void testLinkedListWithMemMgmt(void);
void addNodes(ListNode ** startNodePtr);
void freeNodes(ListNode ** startNodePtr);


void callFooBar(void);
void fooBar(int * myIntP);
void barFoo(int myInt);

#endif /* datastructure_h */
