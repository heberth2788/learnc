//
//  multidimensional.c
//  hd
//
//  Created by Heberth Deza on 2/12/24.
//

#include "multidimensional.h"

void createMultimensionalArray(void) {
    
    int matriz[3][COLUMNS_NO] = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
    int auxMatriz[6][COLUMNS_NO] = {{ 1 }, { 2, 3 }, {4, 5, 6}};
    int emptyMatriz[3][COLUMNS_NO] = { 0 };
    
    printMatriz(matriz, 3);
    puts("");
    printMatriz(auxMatriz, 12);
    puts("");
    printMatriz(emptyMatriz, 3);
    puts("");
}

void printMatriz(int matriz[][COLUMNS_NO], size_t rowsNo) {
    for (size_t i = 0; i < rowsNo; i++) {
        for (size_t j = 0; j < COLUMNS_NO; j++) {
            printf("%d\t", matriz[i][j]);
        }
        puts("");
    }
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
