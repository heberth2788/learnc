//
//  datastructure.c
//  hd
//
//  Created by Heberth Deza on 4/02/25.
//

#include "datastructure.h"

void testLinkedList(void) {
    // create start pointer and nodes
    ListNode * startNodePtr = NULL;
    ListNode nodeA = { .letter = 'a', .nextNodePtr = NULL };
    ListNode nodeB = { .letter = 'b', .nextNodePtr = NULL };
    ListNode nodeD = { .letter = 'd', .nextNodePtr = NULL };
    
    // create the linked-list
    startNodePtr = &nodeA;
    nodeA.nextNodePtr = &nodeB;
    nodeB.nextNodePtr = &nodeD;
    
    // insert new node to the linked-list
    ListNode newNodeC = { .letter = 'c', .nextNodePtr = NULL };
    nodeB.nextNodePtr = &newNodeC;
    newNodeC.nextNodePtr = &nodeD;
    
    printLinkedListA(startNodePtr);
    //printLinkedListB(startNodePtr);
}

void testLinkedListWithMemMgmt(void) {
    // create start pointer
    ListNode * startNodePtr = NULL;
    
    // add nodes and insert new one
    addNodes(&startNodePtr);
    
    // print the linked-list
    printLinkedListA(startNodePtr);
    //printLinkedListB(startNodePtr);
    
    // freeing nodes
    freeNodes(&startNodePtr);
}

void addNodes(ListNode ** startNodePtr) {
    // create and and nodes
    ListNode * nodeAptr = malloc(sizeof(ListNode));
    nodeAptr->letter = 'a';
    nodeAptr->nextNodePtr = NULL;
    ListNode * nodeBptr = malloc(sizeof(ListNode));
    nodeBptr->letter = 'b';
    nodeBptr->nextNodePtr = NULL;
    ListNode * nodeDptr = malloc(sizeof(ListNode));
    nodeDptr->letter = 'd';
    nodeDptr->nextNodePtr = NULL;
    
    //create the linked-list
    
    // incorrect, because of the pointer "nodeAptr" will be destroyed when function returns
    //startNodePtr = &nodeAptr;
    
    // correct, because of the original address(using malloc it is stored on
    // the 'head' memory) persist after function returns
    *startNodePtr = nodeAptr;
    
    nodeAptr->nextNodePtr = nodeBptr;
    nodeBptr->nextNodePtr = nodeDptr;
    
    // insert new node to the linked-list
    ListNode * nodeCptr = malloc(sizeof(ListNode));
    nodeCptr->letter = 'c';
    nodeCptr->nextNodePtr = NULL;
    nodeBptr->nextNodePtr = nodeCptr;
    nodeCptr->nextNodePtr = nodeDptr;
}

void freeNodes(ListNode ** startNodePtr) {
    if (startNodePtr == NULL) {
        puts("Empty linked-list");
        return;
    }
    
    ListNode * pivotNodePtr = NULL;
    ListNode * currentNodePtr = *startNodePtr;
    
    if (currentNodePtr == NULL) {
        puts("NULL");
        return;
    }
    printf("%s", "Freeing nodes: ");
    // iterate the linked-list
    while (currentNodePtr->nextNodePtr != NULL) {
        // save surrent node to free
        pivotNodePtr = currentNodePtr;
        // update the current node
        currentNodePtr = currentNodePtr->nextNodePtr;
        // freeing pivot node
        printf("[%c] ", pivotNodePtr->letter);
        free(pivotNodePtr);
    }
    // freeing the last one node
    printf("[%c] \n", currentNodePtr->letter);
    free(currentNodePtr);
}

void printLinkedListA(ListNode * listPtr) {
    printf("Printing linked-list(mem mgmt): ");
    
    if (listPtr == NULL) {
        puts("Empty linked-list");
        return;
    }
    
    //ListNode currentNode = **listPtr;
    ListNode * currentNode = listPtr;
    
    // iterate the linked-list
    while (currentNode->nextNodePtr != NULL) {
        // print data of the current node
        printf("[%c] ", currentNode->letter);
        // update the current node
        currentNode = currentNode->nextNodePtr;
    }
    printf("[%c] \n", currentNode->letter);
}

void printLinkedListB(ListNode * listPtr) {
    printf("Printing linked-list(mem mgmt): ");
    
    if (listPtr == NULL) {
        puts("Empty linked-list");
        return;
    }
    
    ListNode currentNode = *listPtr;
    
    // iterate the linked-list
    while (currentNode.nextNodePtr != NULL) {
        // print data of the current node
        printf("[%c] ", currentNode.letter);
        // update the current node
        currentNode = *currentNode.nextNodePtr;
    }
    printf("[%c] \n", currentNode.letter);
}
