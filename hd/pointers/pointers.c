//
//  pointers.c
//  hd
//
//  Created by Heberth Deza on 28/11/24.
//

#include "pointers.h"

void usingConstWithPointers(void) {
    int a = 1988;
    int b = 2024;
    
    int * aPtr = &a;
    *aPtr = 1987; // Ok
    aPtr = &b; // Ok
    
    int * const aPtr1 = &a;
    *aPtr1 = 1986; // Ok
    // aPtr1 = &b; // Error: constant variable(aPtr1)
    
    const int * aPtr2 = &a;
    // *aPtr2 = 1985; // Error: constant pointer(int *)
    aPtr2 = &b; // Ok
    
    const int * const aPtr3 = &a;
    // *aPtr3 = 1984; // Error: constant pointer(int *)
    // aPtr3 = &b; // Error: constant variable(aPtr3)
    
    printf("%p\n", aPtr3);
}

void pointerToFunction(void) {
    
    void (* pMyFunc) (int, int) = NULL; // Declaring a pointer to function as NULL
    pMyFunc = &sumTwoNoV1;
    pMyFunc(10, 20);
    pMyFunc = &sumTwoNoV2;
    (*pMyFunc)(30, 40);
    
    puts("");
    
    void (* pMyFunc2) (int, int) = &sumTwoNoV1; // Declaring a pointer to function with default function's address
    pMyFunc2(50, 60);
    pMyFunc2 = &sumTwoNoV2;
    (*pMyFunc2)(70, 80);
}

void sumTwoNoV1(int a, int b) {
    printf("sumTwoNoV1 = %d \n", a + b);
}

void sumTwoNoV2(int c, int d) {
    int e = c + d;
    printf("sumTwoNoV2 = %d \n", e);
}
