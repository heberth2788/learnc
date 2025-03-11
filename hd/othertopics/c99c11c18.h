//
//  c99c11c18.h
//  hd
//
//  Created by Heberth Deza on 8/03/25.
//

#ifndef c99c11c18_h
#define c99c11c18_h

// defining a macro with variable-length argument lists
#define DEBUGAUX(...) printf(__FILE__": "__VA_ARGS__)

#include <stdio.h>
#include <string.h>
#include <stdbool.h> // to use 'bool' data type and 'true', 'false'
#include <complex.h> // to use 'complex' numbers

typedef struct {
    int x;
    int y;
} TwoInt;

bool myFooBar2(int myArray[]);
void testMyFooBar2(void);
void testComplexNum(void);
void testMacroWithVariableLengthArg(void);
void testRestrictKeyword(void);

#endif /* c99c11c18_h */
