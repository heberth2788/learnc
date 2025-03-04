//
//  compilemultiplesourcefiles.c
//  hd
//
//  Created by Heberth Deza on 26/02/25.
//

/**
    A "c" programs can contain multiple source files (.c and .h files)
 */

/**
 Use the "function prototype" or the "include" preprocessor directive to include the functions definition
 in the source code inside it will be used. The linker will resolve those references automatically.
 */
#include "compilemultiplesourcefiles.h"

/**
 Use of "extern" reserved world: to indicate the use of a global variable in this source file,
 defined in another file or later in the same file.
 Be careful to define a lot of global variables because of violate the principle of "least privilege"
 */
extern int MY_GLOBAL_VAR; // Defined in variablelengtharguments.c

void myFooBar(void) {
    MY_GLOBAL_VAR = 1988;
    printf("%d", MY_GLOBAL_VAR);
}

/**
 Use of "static const" to define restricting scope, this means it is an "internal linkage",
 it is prevent to use it from outside the file that defines it.
 */
static const double MY_PI_VALUE = 3.14159;
