//
//  main.c
//  hd
//
//  Created by Heberth Deza on 6/11/24.
//

#include <stdio.h>
#include "iohd.h"
#include "iohd.h"

void myPrint(void);

int main(int argc, const char *argv[]) {
    
//    myPrint();
    
    pointersArithmetic();
    
//    int term1 = 100, term2 = 200;
//    int sum = 0;
//    sumThreeIntsUsingPointers(&term1, &term2, &sum);
//    printf("The sum is = %d \n\n", sum);
    
//    printInformation();
    
    return 0;
}

void pointersArithmetic(void) {
    
    char str[] = "Hello world!";
    puts(str);
    
    char *msg = str;
    msg[4] = 'x';
    
    char *msg2 = msg + 7;
    *msg2 = 'x';
    
    puts(msg);
    puts("");
    
    char str2[] = { 'a', 'b', 'c', 'd', '\0', 'e' };
    puts(str2);
    
    char str3[] = { 'a', 'b', 'c', 'd' }; // Dangerous because of there isn't the end of string character '\0'
    puts(str3);
    puts("");
    
    //char *str4 = "Heberth"; // Store it in static memory. (String literal)
    char str4[] = "Heberth"; // Store it in dynamic memory (Array are stored in Stack memory).
    char *str5 = str4 + 3;
    *str5 = 'x';
    puts(str4);
    puts(str5);
}

void sumUsingPointers(const int *term1, const int *term2, int *sum) {
    
    printf("Int a : %d \n", *term1);
    printf("Int b : %d \n", *term2);
    
    int c = 0;
    printf("Int c : ");
    scanf("%d", &c);
    
    *sum = *term1 + *term2 + c;
}

void printInformation(void) {
    
    int currYear = 2024;
    printf("currYear : %d \n", currYear);
    printf("&currYear : %p \n\n", &currYear);
    
    int currYear2;
    currYear2 = 2024;
    printf("currYear2 : %d \n", currYear2);
    printf("&currYear2 : %p \n\n", &currYear2);
    
    int *pCurrYear2;
    pCurrYear2 = &currYear;
    printf("pCurrYear2 : %p \n", pCurrYear2);
    printf("&pCurrYear2 : %p \n", &pCurrYear2);
    printf("*pCurrYear2 : %d \n\n", *pCurrYear2);
    
    int *pCurrYear3 = &currYear;
    printf("pCurrYear3 : %p \n", pCurrYear3);
    printf("&pCurrYear3 : %p \n", &pCurrYear3);
    printf("*pCurrYear3 : %d \n\n", *pCurrYear3);

    int *pCurrYear;
    pCurrYear = NULL;
    printf("pCurrYear : %p \n", pCurrYear);
    printf("&pCurrYear : %p \n\n", &pCurrYear);
}

void myPrint(void) {
    puts("myPrint");
}
