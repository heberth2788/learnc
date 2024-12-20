//
//  arrays.c
//  hd
//
//  Created by Heberth Deza on 19/11/24.
//

#include "arrays.h"

#define SIZE 100

void createArrays(void) {
    //int myArray[SIZE] = {0};
    int myArray2[SIZE] = {1, 2, 3, 4, 5, 6, 30, 60, 90, 103};
    
    printf("%s%8s \n", "Element", "Value");
    for(size_t i = 0; i < SIZE; i++) {
        printf("%7zu%5d \n", i, myArray2[i]);
    }
}

void createStaticArray(void) {
    
    static int myArray[5];
    
    puts("Printing static array - Before");
    for(size_t i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
        myArray[i] += 3;
    }
    
    puts("\nPrinting static array - After");
    for(size_t i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }
    
    puts("");
    puts("");
}

void createAutomaticArray(void) {
    
    int myArray[5] = {0};
    
    puts("Printing automatic array - Before");
    for(size_t i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
        myArray[i] += 2;
    }
    
    puts("\nPrinting automatic array - After");
    for(size_t i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }
    
    puts("");
    puts("");
}

void scanString(void) {
    char str[10] = {'\0'};
    
    scanf("%9s", str); // For array, it does not need the '&' operator
    printf("%s \n", str);
}

void passingArrayToFunction(void) {
    int ages[] = {36, 37, 15, 8, 1};
    
    printf("Before: %d, %d, %d, %d, %d \n", ages[0], ages[1], ages[2], ages[3], ages[4]);
    multiplyArrayByTwo(ages, 5);
    //multiplyArrayByTwo(&ages[0], 5);
    //multiplyArrayByTwo(&ages, 5);
    printf("After: %d, %d, %d, %d, %d \n", ages[0], ages[1], ages[2], ages[3], ages[4]);
}

void multiplyArrayByTwo(int ages[], size_t size) {
//void multiplyArrayByTwo(int * ages, size_t size) {
    for (size_t i = 0; i < size; i++) {
        ages[i] *= 2;
    }
}

void printingArrayAddress(void) {
    int myArray[] = {1, 2, 3, 4, 5, 6};
    printf("myArray     = %p \n", myArray);
    printf("&myArray[0] = %p \n", &myArray[0]);
    printf("&myArray    = %p \n", &myArray);
}


