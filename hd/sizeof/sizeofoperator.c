//
//  sizeofoperator.c
//  hd
//
//  Created by Heberth Deza on 21/11/24.
//

#include "sizeofoperator.h"

size_t sizeOfOperator(void) {
    
    int myInt = 1988;
    size_t intSize = sizeof(myInt);
    printf("%zu bytes for int\n", intSize);
    
    int myArray[] = { 1, 2, 3, 4, 5, 6 };
    size_t myArraySize = sizeof(myArray); // 24 bytes
    size_t myArrayElementSize = sizeof(myArray[0]); // 4 bytes
    unsigned long int arrayLong = myArraySize / myArrayElementSize; // 6 elementos en el array
    printf("%lu element for my array\n", arrayLong);
    
    int * pMyArray = myArray;
    printf("%zu bytes for pointer (64 bits system)\n", sizeof(pMyArray));
    
    return sizeof(myInt);
}

void printSizeofPrimitiveDatatypes(void) {
    char c = 'h';
    printf("%zu", sizeof(c));
    short s = 1;
    
    int i = 2;
    long l = 3;
    
    long long ll = 4;
    
    float f = 1.5;
    double d = 1.6;
    
    long double ld = 1.7;
    
    size_t e = 5;
    
}
