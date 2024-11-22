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
<<<<<<< HEAD
    
    char c = 'h';
    printf("sizeof(char) = %zu bytes\n", sizeof(c));
    short s = 1;
    printf("sizeof(short) = %zu bytes\n\n", sizeof(s));
    
    int i = 2;
    printf("sizeof(int) = %zu bytes\n", sizeof(i));
    long l = 3;
    printf("sizeof(long) = %zu bytes\n\n", sizeof(l));
    
    long long ll = 4;
    printf("sizeof(long long) = %zu bytes\n\n", sizeof(ll));
    
    float f = 1.5;
    printf("sizeof(float) = %zu bytes\n", sizeof(f));
    double d = 1.6;
    printf("sizeof(double) = %zu bytes\n\n", sizeof(d));
    
    long double ld = 1.7;
    printf("sizeof(long double) = %zu bytes\n\n", sizeof(ld));
    
    size_t e = 5;
    printf("sizeof(size_t) = %zu bytes\n\n", sizeof(e));
    
    int * pInt = &i;
    printf("sizeof(pointer *) = %zu bytes\n", sizeof(pInt));
    int array[6] = {0};
    printf("sizeof(int array[6]) = %zu bytes\n", sizeof(array));
    int * pArray = array;
    printf("sizeof(pointer * to array) = %zu bytes\n", sizeof(pArray));
=======
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
    
>>>>>>> aee4607c8cda4adc81a68d3f03ec24107f91035a
}
