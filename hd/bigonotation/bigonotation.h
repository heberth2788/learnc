//
//  bigonotation.h
//  hd
//
//  Created by Heberth Deza on 7/02/25.
//

#ifndef bigonotation_h
#define bigonotation_h
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(void);
void insertionSort(void);
void mergeSort(void);
void sortSubArray(int array[], size_t low, size_t high);
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t righ);

void generateRandomElements(int * array, size_t length);
void printArrayElements(int * array, size_t length);

#endif /* bigonotation_h */
