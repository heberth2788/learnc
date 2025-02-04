//
//  datastructure.h
//  hd
//
//  Created by Heberth Deza on 4/02/25.
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

void printLinkedListA(ListNode * listPtr);
void printLinkedListB(ListNode * listPtr);
void testLinkedList(void);
void testLinkedListWithMemMgmt(void);
void addNodes(ListNode ** startNodePtr);
void freeNodes(ListNode ** startNodePtr);

#endif /* datastructure_h */
