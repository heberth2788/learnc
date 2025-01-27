//
//  preprocessor.c
//  hd
//
//  Created by Heberth Deza on 23/01/25.
//

#include "preprocessor.h"

/**
    The preprocessor executes before the compilation.
    Preprocessor directives begin with the character #.
 */

/**
 #include
 
 This preprocessor directive replace the directive with the copy of the specified file.
 
 Format:
  
    // For standard libraries, implementation-dependent
    #include <filename.h>
    
    // For libraries that we define, folders to search: same folder, implementation-depend and system folders.
    #include "path/filename.h"
*/

/**
 #define
 
 When the preprocessor encounters a #define directive, it replace the identifier
 with the replacement-text.
 By convention it should only contain uppercase letters(A, B,...) and undercores(_)
 
 Format:
    
    #define identifier replacement-text
 
 To define:
 
    1. Symbolic constants. Util to define named constants.   E.g:     #define PI 3.14159
                                                 #define START_HD
        * Another alternative is use 'const':                       E.g.     const double PI = 3.14159
 
    2. Macros.
 
       a) With arguments:                         E.g:      #define CIRCLE_AREA(x) ((PI) * (X) * (X))
                                     #define RECT_AREA(x, y) ((x) * (y))
 
            * Another recomended alternative is use inline functions instead:
 
                                E.g:    inline double calcCircleArea(double x) {
                                        return (3.14169 * x * x);
                                     }
 
       b) Whitout arguments:                    E.g:    #define LOG_PI 6.144
 
    IMPORTANT: Use macro #undef to undefines previous defined macros.
 
                                E.g: #undef PI
 */

inline double calcCircleArea(double x) {
    return (PI * x * x);
}

inline double calcRectArea(double x, double y) {
    return (x * y);
}

#undef PI // Undefine the constant, so it cannot be used below

inline double calcCircleAreaAux(double x) {
    //return (PI * x * x); // This line issue an error because of PI was #undef above
    return (3.1416 * x * x);
}

/**
    #if ... #endif
    #ifdef  // #if defined(...)
    #ifndef // #if !defined(...)
    #elif
    #else
    
    For Conditional Compilation: which preprocesor directives execute and whether parts of your C code compile
    It evaluates a constant integer expresion.
 
    Conditional preprocessor directives are frequently used to prevent header files from being included multiples
    times in the same file.
 
    E.g:    #if !defined(MY_CONSTANT)
            #define MY_CONSTANT 0
         #endif

*/

void printDebugInfo(void) {
    #ifdef DEBUG // Compiler just if DEBUG is defined
        printf("%d", 1988);
    #endif
}

/**
    #error
    
    Prints and implementation-dependent message, the tokens are displayed as an error message,
    and the program does not compile(fatal error).
 
    Format:
            #error tokens
 
    E.g:    #error 1 - Out of range error // prints 6 tokens as message
        #error 2 - Error information // prints 5 tokens
    
 */

/**
    #pragma
 
    Causes and implementation-defined action (Beyond  what is conveyed in the language itself)
 
    Format:
            #pragma tokens
    E.g:
        #pragma GCC dependency "parse.y"
        #pragma GCC dependency "/usr/include/time.h" rerun fixincludes
 */

/**
    # and ##
 
    # convert the replacement-text token to a string surrounded by quotes("").
    
        E.g:    #define HELLO(x) puts("Hello, " #x);
 
            So execute:     HELLO("Heberth");
            Result:         puts("Hello, ""Heberth");  // Same as: puts("Hello, Heberth");
 
    ## concat two tokens, it must have two operands.
    
        E.g:    #define TOKENCONCAT(x, y) x ## y
 
            So execute: TOKENCONCAT(O, K)
            Result:     OK
 */

void hashAndDoubleHash(void) {
    puts("AB");
    puts("A" "B");// Same as above
    
    #define OK
    TOKENCONCAT(O, K) // Result: OK , the above symbolic constant
}

/**
    #line
 
    Inform to the C compiler of the location in your code where each token came from, this is the
    file name and the line number.
 
    Format:
            #line 100
            #line 100 "file1.c"
            
 */

/**
    Standard C Predefined symbolic constants, these begin and end with two underscores (__)
    and often are useful for including additional information in error messages.
 
    These indetifiers cannot be used in #define and #undef diretives.
 
        __LINE__
        __FILE__;
        __DATE__;
        __TIME__;
        __STDC__;
 */

void showPredefinedSymbolicConstants(void) {
    __LINE__;
    __FILE__;
    __DATE__;
    __TIME__;
    __STDC__; // it means: Standard C support(1) or not(0)
    
    int length = 100;
    fprintf(stderr, "Internal error: "
                    "negative string length "
                    "%d at %s, line %d.",
                    length, __FILE__, __LINE__);
}

void assertTest(void) {
    int notGreaterThanTen = 1988;
    // Show error message if false, showing line number a filename
    assert(notGreaterThanTen <= 10); // if false, call the abort function from <stdlib.h>
    
    // if the symbolic constant "#define NDEBUG" is defined, asserts are ignored.
}

