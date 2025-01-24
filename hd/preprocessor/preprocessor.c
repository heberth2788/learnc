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
    //return (PI * x * x); // This line issue an error because of PI was #undef previously
    return (3.1416 * x * x);
}
