//
//  function_pointer.c
//  hd
//
//  Created by Heberth Deza on 17/12/24.
//

#include "function_pointer.h"

void pointerToFunction(void) {
    
    void (* pMyFunc) (int, int) = NULL; // Declaring a pointer to function as NULL
    pMyFunc = &sumTwoNoV1;
    pMyFunc(10, 20); // Not recommended for readability purposes
    pMyFunc = &sumTwoNoV2;
    (*pMyFunc)(30, 40); // Recommended for readability purposes
    
    puts("");
    
    void (* pMyFunc2) (int, int) = &sumTwoNoV1; // Declaring a pointer to function with default function's address
    pMyFunc2(50, 60); // Not recommended for readability purposes
    pMyFunc2 = &sumTwoNoV2;
    (*pMyFunc2)(70, 80);  // Recommended for readability purposes
}

void sumTwoNoV1(int a, int b) {
    printf("sumTwoNoV1 = %d \n", a + b);
}

void sumTwoNoV2(int c, int d) {
    int e = c + d;
    printf("sumTwoNoV2 = %d \n", e);
}

void arrayOfPointersToFunctions(void) {
    // Declaring an array of pointers to funtions
    void (* func[3])(int) = {function0, function1, function2};
    
    int no = 0;
    puts("Enter a number between 0 and 2:");
    scanf("%d", &no);
    while(no >= 0 && no <= 2) {
        (*func[no])(no); // Calling the function
        puts("Enter a number between 0 and 2:");
        scanf("%d", &no);
    }
    puts("Finished!");
}

void function0(int a) {
    printf("function0 %d \n", a);
}

void function1(int b) {
    printf("function1 %d \n", b);
}

void function2(int c) {
    printf("function2 %d \n", c);
}
