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

void pointerToVoidThenCasting(void) {
    
    int intA = 1988;
    char charA = 'A';
    double doubleA = 3.14159265;
    
    void* ptrVoid;
    
    ptrVoid = &intA;
    int valIntA = *(int*)ptrVoid; // Casting void pointer to int pointer and dereference it.
    printf("Pointer from void to int: %d \n", valIntA);
    
    ptrVoid = &charA;
    char valCharA = *(char*)ptrVoid; // Casting void pointer to char pointer and dereference it.
    printf("Pointer from void to char: %c \n", valCharA);
    
    ptrVoid = &doubleA;
    double valDoubleA = *(double*)ptrVoid; // Casting void pointer to double pointer and dereference it.
    printf("Pointer from void to double: %f \n", valDoubleA);
    
    puts("");
}

void pointersArithmetic(void) {
    
    char str[] = "Hello world!";
    puts(str);
    
    char* msg = str;
    msg[4] = 'x';
    
    char* msg2 = msg + 7;
    *msg2 = 'x';
    
    puts(msg);
    puts("");
    
    char str2[] = { 'a', 'b', 'c', 'd', '\0', 'e' };
    puts(str2);
    
    char str3[] = { 'a', 'b', 'c', 'd' }; // Dangerous, character '\0' is missing.
    puts(str3);
    puts("");
    
    //char *str4 = "Heberth"; // Store it in static memory. (String literal)
    char str4[] = "Heberth"; // Store it in dynamic memory (Array are stored in Stack memory).
    char* str5 = str4 + 3;
    *str5 = 'x';
    puts(str4);
    puts(str5);
}

void sumUsingPointers(const int* term1, const int* term2, int* sum) {
    
    printf("Int a : %d \n", *term1);
    printf("Int b : %d \n", *term2);
    
    int c = 0;
    printf("Int c : ");
    scanf("%d", &c);
    
    *sum = *term1 + *term2 + c;
}

void printInfo(void) {
    
    int currYear = 2024;
    printf("currYear : %d \n", currYear);
    printf("&currYear : %p \n\n", &currYear);
    
    int currYear2;
    currYear2 = 2024;
    printf("currYear2 : %d \n", currYear2);
    printf("&currYear2 : %p \n\n", &currYear2);
    
    int* pCurrYear2;
    pCurrYear2 = &currYear;
    printf("pCurrYear2 : %p \n", pCurrYear2);
    printf("&pCurrYear2 : %p \n", &pCurrYear2);
    printf("*pCurrYear2 : %d \n\n", *pCurrYear2);
    
    int* pCurrYear3 = &currYear;
    printf("pCurrYear3 : %p \n", pCurrYear3);
    printf("&pCurrYear3 : %p \n", &pCurrYear3);
    printf("*pCurrYear3 : %d \n\n", *pCurrYear3);

    int* pCurrYear;
    pCurrYear = NULL;
    printf("pCurrYear : %p \n", pCurrYear);
    printf("&pCurrYear : %p \n\n", &pCurrYear);
}

void pointerToPointer(void) {
    int a = 369;
    int * aPtr = &a;
    
    int ** aPtrPtr = &aPtr; // pointer to pointer
    printf("a = %d [&a = %p], *aPtr = %d, **aPtrPtr = %d \n", a, &a, *aPtr, **aPtrPtr);
    printf("aPtr = %p, aPtrPtr = %p \n", aPtr, aPtrPtr);
    printf("&aPtr = %p, &aPtrPtr = %p \n\n", &aPtr, &aPtrPtr);
    
    void * aVoidPtrPtr = aPtr; // void pointer
    printf("a = %d [&a = %p], *aPtr = %d, *(int *)aVoidPtrPtr = %d \n", a, &a, *aPtr, *(int *)aVoidPtrPtr);
    printf("aPtr = %p, aVoidPtrPtr = %p \n", aPtr, aVoidPtrPtr);
    printf("&aPtr = %p, &aVoidPtrPtrAux = %p \n\n", &aPtr, &aVoidPtrPtr);
    
    void * bPtr = aPtrPtr; // Parsing "int **" to "void *"
    int ** cPtr = bPtr; // Parsing "void *" to "int **"
    printf("**cPtr = %d \n\n", **cPtr);
}
