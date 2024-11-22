//
//  bubblesort.c
//  hd
//
//  Created by Heberth Deza on 21/11/24.
//

#include "bubblesort.h"

void swapValues(int * const a, int * const b) {
    int pivot = *a;
    *a = *b;
    *b = pivot;
}

void printArray(const char * msg, int array[], size_t size) {
    puts(msg);
    for (int i = 0; i < size; i++) {
        printf("%d ,", array[i]);
    }
    puts("\n");
}


//void bubbleSort(int const myArray[], size_t size) {
void bubbleSort(int * const myArray, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        
//      Option 1:
        for (int j = i; j < size - 1; j++) {
            if (myArray[i] > myArray[j + 1]) {
                swapValues(&myArray[i], &myArray[j + 1]);
            }
        }
        
//        Option 2:
//        for (int j = 0; j < size - 1; j++) {
//            if (myArray[j] > myArray[j + 1]) {
//                swapValues(&myArray[j], &myArray[j + 1]);
//            }
//        }
    }
}

void runBubbleSort(void) {
    int myArray[] = { 5, 9, 7, 2, 4, 5, 6, 3, 2, 1, 0, 8 };
    size_t arraySize = 12;
    
    printArray("Array desordenado: ", myArray, arraySize);
    bubbleSort(myArray, arraySize);
    printArray("Array ordenado: ", myArray, arraySize);
}
