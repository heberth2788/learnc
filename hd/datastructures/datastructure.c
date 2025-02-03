//
//  datastructure.c
//  hd
//
//  Created by Heberth Deza on 29/01/25.
//

#include "datastructure.h"

/**
    Data structures could be classified by:
 
    a) Fixed-size data structures:
        arrays: lineal datastructure, stored continuously in memory
        matrice: stored continuously in memory
        structs: stored not necesary continuously in memory
 
    b) Dynamic-size data structures: (Self-referential structures)
        linked-lists
        stacks
        queues
        binary trees
 
    Dynamic memory management:
    
       1.malloc: memory allocation.
       2. calloc: continuous allocation.
       3. realloc: re-allocation.
 
       4. free: freeing memory.
 
       5. sizeof: size of whatever in bytes(returned type: size_t).
 */

// self referential structure example
struct node {
    int data;
    struct node * nextNodePtr; // self referential
};

typedef struct node Node;

/**
    Linked-lists
        
       Linear data structure of self-referential struct objects called "NODES".
       Not guaranteed to be stored in continuously memory.
       It uses the "HEAD" memory.
    
 */


void myLinkedList(void) {
    ListNode * startPtr = NULL; // start pointer to the linked-list
    // ListNodePtr startPtr = NULL; // similar to above
    
    char pivotLetter = '\0';
    int choice = 0;
    
    puts("\tLINKED-LIST data structure\n");
    
    showInstructions();
    printf("%s", "? ");
    scanf("\n%d", &choice);
    
    while (choice != 3) {
        switch (choice) {
            case 1:
                printf("%s", "Enter the character to insert: ");
                scanf("\n%c", &pivotLetter);
                insertNode(&startPtr, pivotLetter);
                printLinkedList(&startPtr);
                break;
                
            case 2:
                printf("%s", "Enter the character to delete: ");
                scanf("\n%c", &pivotLetter);
                deleteNode(&startPtr, pivotLetter);
                printLinkedList(&startPtr);
                break;
                
            default:
                printf("[%d] %s\n\n", choice, "is an invalid option, try again");
                break;
        }
        showInstructions();
        printf("%s", "? ");
        scanf("%d", &choice);
    }
    puts("\n[End of run]");
}

void insertNode(ListNode ** listPtr, char letter) {
    // create the new node to insert
    // this object will be destroyed when the method ends.
    /*ListNode newNode = {
        .letter = letter,
        .nextNodePtr = NULL,
    };*/
    
    // memory allocation for the new node to insert
    // this will survie in memory until call it inside the "free" method
    ListNode * newNodePtr = malloc(sizeof(ListNode));
    if(newNodePtr == NULL) { // check if not memory available
        printf("'%c' could not be inserted because of no memory available", letter);
        return;
    }
    newNodePtr->letter = letter;
    newNodePtr->nextNodePtr = NULL;
    
    // if start pointer points to null, add the new node at the beginning
    if (*listPtr == NULL) {
        *listPtr = newNodePtr;
        printf("\t[Inserted: %c]\n", letter);
        return;
    }
    
    //there is at least one element in the linked-list
    ListNode currentNode = **listPtr;
    ListNode previousNode = { };
    
    // iterate linked-list to find the location for the new node
    while (letter > currentNode.letter) {
        // save previous  node
        previousNode = currentNode;
        // check if last node( it points to NULL)
        if (currentNode.nextNodePtr == NULL) {
            break;
        }
        // compare if greather than, then update current node
        currentNode = *(currentNode.nextNodePtr);
    }
    
    // update new node to points to the current node
    newNodePtr->nextNodePtr = &currentNode;
    
    // update the new node to points to the node pointed by the current node
    previousNode.nextNodePtr = newNodePtr;
    
    printf("\t[Inserted: %c]\n", letter);
}

void deleteNode(ListNode ** listPtr, char letter) {
    printf("\t[Deleted: %c]\n", letter);
}

void showInstructions(void) {
    puts("Enter your choise:\n"
         "\t1 to insert an element in the linked-list.\n"
         "\t2 to delete an element from the linked-list.\n"
         "\t3 to exit.");
}

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
    
    printLinkedList(startNodePtr);
}

void printLinkedList(ListNode * listPtr) {
    printf("Printing linked-list: ");
    
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

void testLinkedListWithMemMgmt(void) {
    // create start pointer
    ListNode * startNodePtr = NULL;
    
    // add nodes and insert new one
    addNodes(&startNodePtr);
    
    // print the linked-list
    printLinkedListMemMgmt(startNodePtr);
    
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
    
    // correct, because of the original address(using malloc) persist after function returns.
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

void printLinkedListMemMgmt(ListNode * listPtr) {
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

void callFooBar(void) {
    int a = 369;
    printf("(1) %d\n", a);
    fooBar(&a); // pass by reference (a copy of the memory adress)
    printf("%d\n\n", a);
    
    a = 369;
    printf("(2) %d\n", a);
    int * aPtr = &a;
    fooBar(aPtr); // pass by value (a copy of the pointer)
    printf("%d\n\n", *aPtr);
    
    int * aPtrAux1 = malloc(sizeof(int));
    *aPtrAux1 = 369;
    printf("(3 malloc) %d\n", *aPtrAux1);
    fooBar(aPtrAux1); // pass by value (a copy of the pointer)
    printf("%d\n\n", *aPtrAux1);
    free(aPtrAux1);
    
    int * aPtrAux2 = malloc(sizeof(int));
    *aPtrAux2 = 369;
    printf("(4 malloc) %d\n", *aPtrAux2);
    barFoo(*aPtrAux2); // pass by value.
    printf("%d\n\n", *aPtrAux2);
    free(aPtrAux2);
    
    a = 369;
    printf("(5) %d\n", a);
    barFoo(a); // pass by value (a copy of the variable)
    printf("%d\n\n", *aPtr); // the original 'a' has not been modified
}

// A pointer(or pointer to pointer) as parameter, could by
// passed by value or by reference
void fooBar(int * myIntP) {
    *myIntP += 3; // dereferencing to modify the original value
    printf("%d\n", *myIntP);
    
    int myIntInside = 963;
    myIntP = &myIntInside; // wrong, this update only the local copy, not the original value
    *myIntP += 3;
}

// A variable only can be pass by value
void barFoo(int myInt) {
    myInt += 3;
    printf("%d\n", myInt);
}
