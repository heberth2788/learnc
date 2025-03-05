//
//  programtermination.c
//  hd
//
//  Created by Heberth Deza on 5/03/25.
//

#include "programtermination.h"

/**
 The library <stdlib.h> provides methods of terminating program execution in "main"
 
    "exit" function: to terminates the program inmediately, often used when error is detected.
        It takes one argument : EXIT_SUCCESS or EXIT_FAILURE
 
    "atexit" function: to registers a function to call when the program terminates by reaching the end
        of "main" or when "exit" is invoked.
        It takes as argument another function's name.
 */

int main(void) {
    atexit(gotTheEnd); // register the funtion to invoke at the end of the program
    puts("Enter 1 to terminate the program by exit function or 2 to terminate the program normally:");
    int answer = 0;
    scanf("%d", &answer);
    
    if (answer == 1) {
        puts("End by exit");
        exit(EXIT_SUCCESS); // finish by exit-success
    }
    puts("End normally"); // finish by reaching the end of "main"
}

void gotTheEnd(void) {
    puts("The end of the program execution has been reached");
}
