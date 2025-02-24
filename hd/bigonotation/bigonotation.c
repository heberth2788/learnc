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

#define MAX_LENGTH 10

void selectionSort(void) {
    
    puts("\tSELECTION sort algorithm\n");
    
    srand(time(NULL));
    int  myList[MAX_LENGTH] = { 0 };
    generateRandomElements(myList, MAX_LENGTH);

    puts("Running...\n");
    int pivot = 0;
    size_t minorIndex = 0;
    for (size_t i = 0; i < MAX_LENGTH; i++) {
        minorIndex = i;
        for (size_t j = i + 1; j < MAX_LENGTH; j++) {
            if (myList[minorIndex] > myList[j]) {
                minorIndex = j;
            }
        }
        pivot = myList[i];
        myList[i] = myList[minorIndex];
        myList[minorIndex] = pivot;
    }
    
    printArrayElements(myList, MAX_LENGTH);
}

void insertionSort(void) {
    puts("\t INSERTION sort algortihm\n");
    
    int myList[MAX_LENGTH] = { 0 };
    generateRandomElements(myList, MAX_LENGTH);
    
    puts("Running...\n");
    int pivot = 0;
    for (size_t i = 1; i < MAX_LENGTH; i++) {
        pivot = myList[i];
        for (size_t j = i - 1; j >= 0; j--) {
            if (pivot < myList[j]) {
                myList[j + 1] = myList[j];
                if (j == 0) {
                    myList[j] = pivot;
                }
                continue;
            }
            myList[j + 1] = pivot;
            break;
        }
    }
    
    printArrayElements(myList, MAX_LENGTH);
}

void mergeSort(void) {
    puts("\t MERGE sort algorithm\n");
    
    int myList[MAX_LENGTH] = { 0 };
    generateRandomElements(myList, MAX_LENGTH);
    
    puts("Running...\n");
    sortSubArray(myList, 0, MAX_LENGTH - 1);
    
    printArrayElements(myList, MAX_LENGTH);
}

void sortSubArray(int array[], size_t low, size_t high) {
    // If base case, return
    if ((high - low) == 0) {
        return;
    }
    // calculate the middle values
    size_t middle1 = (low + high) / 2;
    size_t middle2 = middle1 + 1;
    
    // split array in half and sort each half recursively
    sortSubArray(array, low, middle1); // first half
    sortSubArray(array, middle2, high); // second half
    
    // merge the two sorted arrays
    merge(array, low, middle1, middle2, high);
}

void merge(
    int array[],
    size_t left,
    size_t middle1,
    size_t middle2,
    size_t right
) {
    size_t leftIndex = left; // index into left subarray
    size_t rightIndex = middle2; // index into right subarray
    size_t combinedIndex = left; // index into temporary array
    int tempArray[MAX_LENGTH] = { 0 }; // temporary array
    
    // merge the subarrays until the end of one is reached
    while (leftIndex <= middle1 && rightIndex <= right) {
        if (array[leftIndex] <= array[rightIndex]) {
            tempArray[combinedIndex++] = array[leftIndex++];
        } else {
            tempArray[combinedIndex++] = array[rightIndex++];
        }
    }
    
    if (leftIndex == middle2) { // if at end of left subarray
        while (rightIndex <= right) { // copy the right subarray
            tempArray[combinedIndex++] = array[rightIndex++];
        }
    } else { // if at end of the right subarray
        while (leftIndex <= middle1) { // copy the left subarray
            tempArray[combinedIndex++] = array[leftIndex++];
        }
    }
    
    // copy values back into the original array
    for (size_t i = left; i <= right; i++) {
        array[i] = tempArray[i];
    }
}

void generateRandomElements(int * array, size_t length) {
    puts("Random elements to sort:");
    srand(NULL);
    for (size_t i = 0; i < length; i++) {
        array[i] = rand() % length;
        printf("[%lu] = %d\n", i, array[i]);
    }
    puts("");
}

void printArrayElements(int * array, size_t length) {
    puts("Printing sorted list:");
    for (size_t i = 0; i < length; i++) {
        printf("[%lu] = %d\n", i, array[i]);
    }
}
