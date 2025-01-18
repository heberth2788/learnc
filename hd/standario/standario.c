//
//  standario.c
//  hd
//
//  Created by Heberth Deza on 13/01/25.
//

#include "standario.h"

#define MAX_SIZE 90
#define FIVE 5

void functionsFgetsAndPutchar(void) {
    char sequence[MAX_SIZE] = "";
    
    puts("Enter a linea of text:");
    fgets(sequence, MAX_SIZE, stdin);
    
    printf("%s %s \n", "The line printed is:", sequence);
    printf("%s ", "The line printed backward is:");
    reverse(sequence);
    puts("");
}

void reverse(const char * const ptrStr) {
    if('\0' == ptrStr[0]) { // Base case
        return;
    } else {
        reverse(&ptrStr[1]); // Call it's self
        putchar(ptrStr[0]);
    }
}

void functionGetchar(void) {
    int c = 0;
    char str[MAX_SIZE] = {'\0'};
    int i = 0;
    
    puts("Write a message a then enter:");
    while((i < MAX_SIZE - 1) && ((c = getchar()) != '\n')) {
        str[i++] = c;
    }
    str[i] = '\0';
    
    puts("The line entered was:");
    puts(str);
}

void functionSprintf(void) {
    int myInt = 0;
    double myDouble = 0.0;
    puts("Enter and int and a double: ");
    scanf("%d %lf", &myInt, &myDouble);
    
    char myCharArray[MAX_SIZE] = {'\0'};
    sprintf(myCharArray, "\n\tint=%d \n\tdouble=%.2lf", myInt, myDouble);
    
    printf("The values are: %s \n", myCharArray);
}

void functionSscanf(void) {
    char str[] = "1988 26.5";
    int myInt = 0;
    double myDouble = 0.0;
    
    sscanf(str, "%d %lf", &myInt, &myDouble);
    puts("The values stores in character array 'str' is:");
    printf("int=%d , double=%.2lf \n", myInt, myDouble);
}


