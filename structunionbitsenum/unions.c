//
//  unions.c
//  hd
//
//  Created by Heberth Deza on 21/01/25.
//

#include "unions.h"

/**
    Union is another derived data type like struct, but its members share the
    same memory. At different times during execution, some variables may not be
    relevant when others are.
 */
void declareUnionObjects(void) {
    union member he = { };
    union member she = { 36 }; // By default use it the first member of the unions
    union member it = { 0.3 }; // Compiler will issue a warning because of the first member is not a double
    
    union member my = { .fatherAge = 36 };
    
    me.motherAge = 37;
    me.rate = 0.5;
    double rate = me.rate;
    
    Memb memberA = { .rate = 0.9 };
    
    union member you = { .rate = 0.5 };
    union member * youPtr = &you;
    double yourRate = youPtr->rate;
    
}
