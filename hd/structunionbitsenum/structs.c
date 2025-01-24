//
//  structs.c
//  hd
//
//  Created by Heberth Deza on 20/01/25.
//

#include "structs.h"

/**
    Aggregated type: Are data types that group multiple elements together
    E.g: Arrays, structs, unions.
 
    A struct is a blueprint (similar to a class) and its definition does not
    reserve memory.
    
    However, a declaration of a variable of that type (struct) do reserve
    memory.
 */
void declareObjects(void) {
    struct card myCard = { .face = "face", .suit = "suit" }; // Declaration of a new variable/object, it reserve memory
    struct card myCardW = { .suit = "suit", .face = "face" };
    struct card myCardX = { .face = "face" };
    struct card myCardY = { .suit = "suit" };
    struct card myCardZ = { };
    struct card myCards[3]; // Declaring an array of object
    struct card * myCardPtr = &myCard; // Declaring a pointer to an object of type 'card'
    
    struct employee myEmp1;
    struct employee * myEmp1Ptr = &myEmp1;
    Emp myEmp2;
    Emp myEmps[6];
    Emp * myEmp2Ptr = NULL;
    
    char * myNamePtr = me.name;
    char * nextPersonNamePtr = nextPerson->name;
}

void structOperations(void) {

    // IMPORTANT: structures may not be compared using == and !=
    // because of structure members may not be stored in consecutive
    // bytes of memory
    
    // Assigning values
    struct card cardA = { }; // zero initializing
    cardA.face = "faceA";
    struct card cardB = { }; // zero initializing
    cardB.face = "faceB";
    
    cardA = cardB;
    
    // Dereferencing
    struct card * ptrCardA = &cardA;
    struct card * ptrCardB = &cardB;
    
    ptrCardA = ptrCardB;
    
    // Accessing to members of the struct
    const char * faceA = ptrCardA->face;
    const char * suitA = ptrCardA->suit;
    
    // sizeof operator
    size_t sizeOfStruct = sizeof(cardA);
}

void accessStructMembers(void) {
    const char * face = NULL;
    
    // Member operator: . (Dot operator)
    struct card myCard = {};
    myCard.face = "Ace";
    myCard.suit = "Spades";
    face = myCard.face;
    
    // Pointer operator: -> (Arrow operator)
    struct card * myCardPtr = &myCard;
    myCardPtr->face = "Ace2";
    (*myCardPtr).face = "Ace2"; // equivalent
    myCardPtr->suit = "Spades2";
    (*myCardPtr).suit = "Spades2"; // equivalent
    
    face = myCardPtr->face;
    face = (*myCardPtr).face; // equivalent
}

// Pass a pointer to the object (efficient)
void passStructByReference(struct person * ptrP) {
    char * name = ptrP->name;
}

// Pass a copy of the entire object (less efficient)
void passStructByValue(struct person p) {
    char * name = p.name;
}

void usingBitFields(void) {
    
}

void usingAnonymousStruct(void) {
    struct myStruct ms = { };
    ms.a = 1;
    ms.b = 2;
    ms.nestedc = 3;
    ms.nestedd = 4;
    ms.e = 5;
}
