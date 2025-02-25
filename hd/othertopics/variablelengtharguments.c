//
//  variablelengtharguments.c
//  hd
//
//  Created by Heberth Deza on 24/02/25.
//

#include "variablelengtharguments.h"

/**
    For variable-length argument list, we can use ellipsis.
    Ellipsis (...) means that a function can recive variable number of arguments of any type, ellipsis
    must be the last parameter.
 
    E.g:
        printf(const char * format, ...)
 
    Variable arguments header: <stdarg.h>
        va_list, va_start, va_arg, va_end
 */

double average(int i, ...) {
    double total = 0.0;
    
    // store information needed by va_start and va_end
    va_list ap = NULL; // ap means "argument pointer"
    va_start(ap, i); // initialize the va_list object
    
    // process variable-length argument list
    for (int j = 0; j < i; j++) {
        total += va_arg(ap, double);
    }
    
    va_end(ap); // clean up variable-length argument list
    return total / i;
}

void varLengthArg(void) {
    double a = 37.5;
    double b = 22.5;
    double c = 1.7;
    double d = 10.2;
    
    printf("average of a, b : %.3f\n", average(2, a, b));
    printf("average of a, b, c : %.3f\n", average(3, a, b, c));
    printf("average of a, b, c, d : %.3f\n", average(4, a, b, c, d));
}
