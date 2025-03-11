//
//  c99c11c18.c
//  hd
//
//  Created by Heberth Deza on 8/03/25.
//

#include "c99c11c18.h"

/**
 Resources limits:
    At least 1023 members in a struct, union or enum.
    At least 127 parameters to a function.
    Limits to 63 characters for identifiers with internal linkage. (static)
    Limits to 31 characters for identifiers with external linkage. (extern)
    etc.
 */

// use of 'bool'(0 or 1) data type and 'true'(1 or other nonzero value), 'false'(0)
bool myFooBar2(int myArray[]) {
    bool myBool = true;
    if (myBool) {
        myBool = false;
    }
    return myBool;
}

// use of compound literals
void testMyFooBar2(void) {
    
    myFooBar2((int [6]) { [0] = 1, [5] = 2 }); // compound literal
    
    TwoInt myTwoInt = { .x = 36, .y = 39 }; // compound literal
    
    TwoInt twoIntArray[6] = {
        [0] = { .x = 3, .y = 6 }, // compound literal
        [5] = { .y = 3, .x = 9 } // compound literal
    };
}

// use 'complex' and 'I' for complex number operations
void testComplexNum(void) {
    double complex a = 3.0 + 2.0 * I;
    double complex b = 2.7 + 4.9 * I;
    
    double complex res = 0.0;
    
    double realA = creal(a); // get the real prt
    double complex imagA = cimag(a); // get the imaginary part
    
    res = a + b;
    res = a - b;
    res = a * b;
    res = a / b;
    res = cpow(a, 2.0);
}

// use a macro with variable length argument lists
void testMacroWithVariableLengthArg(void) {
    int hd = 1988;
    int lm = 1987;
    
    // it will execute: printf("c99c11c18.c"": ""%d & %d", hd, lm);
    DEBUGAUX("%d & %d", hd, lm);
}

// use of 'restrict' keyword tod eclares a restrictec pointer to have
// exclusive access to a region of memory
void testRestrictKeyword(void) {
    int * restrict ptrInt; // restricted pointer to an 'int'
}


