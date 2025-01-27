//
//  preprocessor.h
//  hd
//
//  Created by Heberth Deza on 23/01/25.
//

/**
    Header files should include:
        1. structs , unions.
        2. typedef.
        3. enums.
        4. function prototypes.
 */

#ifndef preprocessor_h
    #define preprocessor_h

    //------ #include
    #include <stdio.h>
    #include <assert.h>

    //------ #define
    #define PI 3.14159
    #define LOG_PI 6.144
    #define AGE 36

    #define CIRCLE_AREA(x) ((PI) * (x) * (x))
    #define RECT_AREA(x, y) ((x) * (y))

    // Use the continuation character '\' to continue in the next line if needed
    #define MY_CALC(x) ((x) * (x) * (x) \
    * (x))

    #define getchar() getc(stdin) // Standar library defined as macro

    //------ #undef
    #undef LOG_PI // Undefine the constant, so it cannot be used below
    // LOG_PI // this will issue an error

    inline double calcCircleArea(double x);
    inline double calcRectArea(double x, double y);
    inline double calcCircleAreaAux(double x);

    //------ #if ... #endif
    #define MY_CONSTANT 1

    #if !defined(MY_CONSTANT) // if not defined
        #define MY_CONSTANT 1
    #endif

    #if defined(MY_CONSTANT) // if defined
        #define MY_CONSTANT_AUX 2
    #endif

    //------ #ifndef
    #ifndef MY_CONSTANT // same to: #if !defined(MY_CONSTANT)
        #define MY_CONSTANT 1
    #endif

    //------ #ifdef
    #ifdef MY_CONSTANT // same to: #if defined(MY_CONSTANT)
        #define MY_CONSTANT_AUX 2
    #endif

    //------ #elif ... #else
    #ifndef MY_CONSTANT // if not defined
        #define MY_CONSTANT 1
    #elif MY_CONSTANT == 2 // else if
        #define MY_CONSTANT_PIVOT 1
    #elif defined(MY_CONSTANT_PIVOT) // else if
        #define MY_CONSTANT_PIVOT_AUX 2
    #else // else
        #define MY_CONSTANT_PIVOT 3
    #endif

    // Prevent code from being compiled
    #if 0 // if false
        // This block won't be compiled
    #endif

    // Enabled code to be compiled
    #if 1 // if true
        // This block will be compiled
    #endif
    
    void printDebugInfo(void);

    //------ #error
    #if defined(FOO) && !defined(BAR)
        // stops the compilation process and show the fatal error
        #error 1 - Requires FOO and BAR
        #error "Required FOO and BAR"
    #endif
    
    //------ #pragma
    #pragma GCC dependency "/usr/lib/dtrace/dt_cpp.h" rerun fixincludes
    #define strrchr rindex
    #pragma GCC poison rindex

    //------ #
    #define HELLO(x) puts("Hello, " #x);
    
    //------ ##
    #define TOKENCONCAT(x, y) x ## y

    void hashAndDoubleHash(void);

    //------ #line
    #line 100 "fileA.c"

    void showPredefinedSymbolicConstants(void);

    void assertTest(void);

#endif /* preprocessor_h */
