//
//  cstorageclass.c
//  hd
//
//  Created by Heberth Deza on 13/11/24.
//

#include "cstorageclass.h"
#include "../newtypes/family.h"

/**
    Automatic Storage Duration:     auto, register
    Static Storage Duration:            externs, static
 */

// auto
void testAutoStorageClass(void) {
    
    int myAgeA = 36;
    myAgeA += 1;
    auto int myAgeB = 36;
    myAgeB += 1;
    
    printf("auto storage class: %d %d \n", myAgeA, myAgeB);
}

// register
void testRegisterStorageClass(void) {
    
    register int myAge = 36;
    myAge += 1;
    
    printf("register storage class: %d \n", myAge);
}

// extern
void testExternStorageClass(void) {
    
    extern int myAgeGlobal; // Declared in family.c file as global variable
    myAgeGlobal += 1;
    
    printf("extern storage class: %d \n", myAgeGlobal);
}

// static
void testStaticStorageClass(void) {
    
    static int myAge = 36;
    myAge += 1;
    
    printf("static storage class: %d \n", myAge);
}
