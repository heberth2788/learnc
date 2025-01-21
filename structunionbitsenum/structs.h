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

#endif /* structs_h */
