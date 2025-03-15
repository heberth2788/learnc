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
#include <stdlib.h> // to use 'malloc', 'quick_exit' and 'at_quick_exit' functions
#include <tgmath.h> // to use type-generic math: E.g: sin(x)

typedef struct {
    int x;
    int y;
} TwoInt;

bool myFooBar2(int myArray[]);
void testMyFooBar2(void);
void testComplexNum(void);
void testMacroWithVariableLengthArg(void);
void testRestrictKeyword(void);
void testFlexibleArrayMembers(void);
void testTypeGenericMath(void);
void testInlineFunction(void);
inline int myInlineFun(int, int);
void testPreProcessorMacros(void);
void c11c18Headers(void);
_Noreturn void myExit(int myStatus);
_Noreturn void myInfiniteLoop(void);

#endif /* c99c11c18_h */
