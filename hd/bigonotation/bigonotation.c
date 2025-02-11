//
//  bigonotation.c
//  hd
//
//  Created by Heberth Deza on 7/02/25.
//

#include "bigonotation.h"

/**
    Big O notation: it's one way to describe an algorithm's effort or complexity
        Good:
            O(1):          constant runtime E.g: check if stack is empty
            O(log n):      logarithmic runtime E.g: Find item in a balanced search tree
 
        Average:
            O(n):          linear runtime E.g: linear iteration of the list
            O(n log n):    logarithmic linear runtime E.g: merge sort
 
        Bad:
            O(n^2):         quadratic runtime E.g: check possible pairs in an array
            O(n^3):         cubic runtime E.g: matrix multiplication of n x n matrices
            O(2^n):         exponential runtime E.g: Generate all sub sets of a given set
            O(n!):          factorial runtime E.g: Generate all permutations of a given list
 
    Sorting algorithms:
        Selection sort
        Insertion sort
        Merge sort (recursive)
        Quick sort
        Bucket sort
 */

#define MAX_LENG 10

void selectionSort(void) {
    
    puts("\tSELECTION sort algorithm\n");
    
    srand(time(NULL));
    int  myList[MAX_LENG] = { 0 };
    
    puts("Random elements to sort:");
    for (int i = 0; i < MAX_LENG; i++) {
        myList[i] = rand() % MAX_LENG;
        printf("[%d] = %d\n", i, myList[i]);
    }
    puts("");

    puts("Running...\n");
    
    int pivot = 0;
    size_t minorIndex = 0;
    for (size_t i = 0; i < MAX_LENG; i++) {
        minorIndex = i;
        for (size_t j = i + 1; j < MAX_LENG; j++) {
            if (myList[minorIndex] > myList[j]) {
                minorIndex = j;
            }
        }
        pivot = myList[i];
        myList[i] = myList[minorIndex];
        myList[minorIndex] = pivot;
    }
    
    puts("Printing sorted list:");
    for (int i = 0; i < MAX_LENG; i++) {
        printf("[%d] = %d\n", i, myList[i]);
    }
}
