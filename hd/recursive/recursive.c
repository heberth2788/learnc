//
//  recursive.c
//  hd
//
//  Created by Heberth Deza on 18/11/24.
//

#include "recursive.h"

void printFibonacci(int quantity) {
    unsigned long long int res = 0;
    for(int i = 0; i < quantity; i++) {
        res = calcFibonacci(i);
        printf("%d = %llu \n", i, res);
    }
}

unsigned long long int calcFibonacci(unsigned long long int n) {
    if(n == 0 || n == 1) {
        return n;
    } else {
        return calcFibonacci(n - 1) + calcFibonacci(n - 2);
    }
}

void printFactorial(int quantity) {
    unsigned long long int res = 0;
    for(int i = 0; i < quantity; i++) {
        res = calcFactorial(i);
        printf("%d! = %llu \n", i, res);
    }
}

unsigned long long int calcFactorial(unsigned long long int n) {
    if(n <= 1) {
        return 1;
    } else {
        return n * calcFactorial(n - 1);
    }
}

