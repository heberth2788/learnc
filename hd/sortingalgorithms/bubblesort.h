//
//  bubblesort.h
//  hd
//
//  Created by Heberth Deza on 21/11/24.
//

#ifndef bubblesort_h
#define bubblesort_h

#include <stdio.h>

void swapValues(int * const a, int * const b);
void printArray(const char * msg, int array[], size_t size);
void runBubbleSort(void);
void bubbleSort(int * const myArray, size_t size);
//void bubbleSort(int const myArray[], size_t size);

#endif /* bubblesort_h */
