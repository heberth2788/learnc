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

#include <stdio.h>

#define PI 3.14159
#define LOG_PI 6.144

#define CIRCLE_AREA(x) ((PI) * (x) * (x))
#define RECT_AREA(x, y) ((x) * (y))

// Use the continuation character '\' to continue in the next line if needed
#define MY_CALC(x) ((x) * (x) * (x) \
* (x))

#undef LOG_PI // Undefine the constant, so it cannot be used below

#define getchar() getc(stdin) // Standar library defined as macro
 
inline double calcCircleArea(double x);
inline double calcRectArea(double x, double y);

inline double calcCircleAreaAux(double x);

#endif /* preprocessor_h */
