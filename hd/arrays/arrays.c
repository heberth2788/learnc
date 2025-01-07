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

void printRelationArrayVsPointer(void) {
    
    int myArray[3] = { 1, 2, 3 };
    printf("Op1: %d, %d, %d\n", myArray[0], myArray[1], myArray[2]);
    printf("Op2: %d, %d, %d\n\n", *myArray, *(myArray + 1), *(myArray + 2));
    
    int * pMyArray = NULL;
    
    pMyArray = myArray;
    printf("Op3: %d, %d, %d\n", *pMyArray, *(pMyArray + 1), *(pMyArray + 2));
    printf("Op4: %d, %d, %d\n\n", pMyArray[0], pMyArray[1], pMyArray[2]);
    
    pMyArray = &myArray[0];
    printf("Op5: %d, %d, %d\n", *pMyArray, *(pMyArray + 1), *(pMyArray + 2));
    printf("Op6: %d, %d, %d\n\n", pMyArray[0], pMyArray[1], pMyArray[2]);
    
    //int intAux = 0;
    //myArray = &intAux; // Error, it cannot be reasigned
}

void copyStrings(void) {
    
    char msgA[] = "Heberth Deza";
    
    char msgB[33];
    for (size_t i = 0; (msgB[i] = msgA[i]) != 0; i++) {
        ;
    }
    printf("Op1: %s\n", msgB);
    
    char * pMsgA = msgA;
    char msgC[33];
    char * pMsgC = msgC;
    for (; (*pMsgC = *pMsgA) != 0; pMsgC++, pMsgA++) {
        ;
    }
    printf("Op2: %s\n", msgC);
    printf("Op3: %s\n", (pMsgC - 12));
}

void arrayOfPointers(void) {
    
    const char * pNames[5] = { "Heberth", "Lilian", "Heily", "Joicy", "Berthly" };
    pNames[0] = "HEBERTH DEZA";
    
    printf("%s \n", pNames[0]);
    printf("%s \n", pNames[1]);
    printf("%s \n", pNames[2]);
    printf("%s \n", pNames[3]);
    printf("%s \n\n", pNames[4]);
    
    char * pNames2[5] = { "Heberth", "Lilian", "Heily", "Joicy", "Berthly" };
    pNames2[0] = "HEBERTH DEZA";
    
    char * myNameA = NULL;
    char * myNameB = 0;
    myNameA = pNames2[2];
    myNameB = pNames2[3];
    
    printf("%s \n", pNames2[0]);
    printf("%s \n", myNameA);
    printf("%s \n", myNameB);
    
    char nameA[] = "HD";
    char nameB[] = "LC";
    char nameC[] = "JD";
    const char * pName3[3] = {nameA, nameB, nameC};
    
    char * nameA2 = "HD";
    char * nameB2 = "LC";
    char * nameC2 = "JD";
    const char * pName4[3] = {nameA2, nameB2, nameC2};
}

