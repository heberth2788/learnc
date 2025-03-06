//
//  signalhandling.c
//  hd
//
//  Created by Heberth Deza on 6/03/25.
//

#include "signalhandling.h"

/**
 An external asynchronous "event" or "signal" can cause a program to terminate prematurely.
 
 E.g:
     * Ctrl + c (Linux or Windows) , Command + c (MacOS)
     * Termintion order from the OS.
 
 The signal-handling library is <signal.h> and is used to trap unexpected signals with the function "signal"
 
 To generate a signal we can call the function "raise"
 
 Standar signals list:
 
    SIGABRT : abort
    SIGFPE : arithmetic operation error
    SIGILL : illegal instruction
    SIGINT : interactive (Ctrl + c,  Command + c)
    SIGSEGV : try to access memory that is not allocated
    SIGTERM : termintion request sent
 */

int main(void) {
    signal(SIGINT, signalHandler); // register the signal handler of SIGINT
    srand(time(NULL));
    
    int x = 0;
    for (int i = 1; i <= 100; i++) {
        x = 1 + rand() % 50;
        if (x == 25) {
            printf("\n[SIGINT = %d]\n", SIGINT);
            raise(SIGINT); // send the SIGINT signal
        }
        printf("%4d", i);
        
        // new line when multiplo of 10
        if (i % 10 == 0) {
            printf("%s", "\n");
        }
    }
}

void signalHandler(int signalValue) {
    printf("\nSignal caught [%d], Continue(1=yes, 0=no)? ", signalValue);
    int resp = 0;
    scanf("%d", &resp);
    
    while (resp != 1 && resp != 0) {
        printf("%s", "\nContinue(1=yes, 0=no)? ");
        scanf("%d", &resp);
    }
    
    if (resp == 1) {
        signal(SIGINT, signalHandler); // register the signal handler of SIGINT
    } else {
        exit(EXIT_SUCCESS);
    }
}
