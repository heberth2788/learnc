//
//  structs.h
//  hd
//
//  Created by Heberth Deza on 20/01/25.
//

#ifndef structs_h
#define structs_h

#include <stdio.h>

// definition a structure type
struct card { // structure tag: card
    const char * face; // member
    const char * suit; // member
};

struct person {
    char * name;
} me, myFam[4], * nextPerson; // declaring variables/objects after the struct definition

// defining a struct without name, but declaring variables/object at the bottom
struct {
    char * name;
} you, yourFamily[6], * nextOne; // declaring variables/objects

struct employee {
    char firstName[30];
    char lastName[30];
    unsigned int age;
    double hourlySalary;
    struct employee * managerPtr; // self reference
    struct other { // defining a new struct inside a struct
        char desc[30];
        int rate;
    } other_info; // variable of the struct
};
typedef struct employee Emp; // defining a type definition for the struct employee

// defining struct using typedef keyword (tag is not required)
typedef struct {
    char name[60];
    char directorName[30];
    unsigned int year;
} Movie; // definition type names

void declareObjects(void);
void structOperations(void);
void accessStructMembers(void);
void passStructByReference(struct person * ptrP);
void passStructByValue(struct person p);

/**
    Bit fields :
    Use in struct to specify the number of bits in which to store an unsigned or signed int member.
 */
struct bitCard { // A bitCard object will be store in 7 bits
    unsigned int face : 4; // store it in 4 bits, values from 0 to 15
    unsigned int suit : 2; // store it in 2 bits, values from 0 to 3
    unsigned int color : 1; // store it in 1 bit, values from 0 to 1
};

// Assuming a 4-byte-word computer (4 * 8 = 32 bits word)
struct unnamedBitA {
    unsigned int a : 13; // 32 - 13 = 19 bits
    // Unnamed bit field, used as a padding in the struct
    unsigned int   : 19; // 13 + 19 = 32 bits (A completed word)
    unsigned int b : 4; // b member is alligned to the next word
};

// Assuming a 4-byte-word computer (4 * 8 = 32 bits)
struct unnamedBitB {
    unsigned int a : 13; // 32 - 13 = 19 bits
    unsigned int   : 0; // skip the last 19 bits to get a 32 bits word
    unsigned int b : 4; // b member is alligned to the next word
};

#endif /* structs_h */
