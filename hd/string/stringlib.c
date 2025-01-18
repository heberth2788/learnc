//
//  stringlib.c
//  hd
//
//  Created by Heberth Deza on 17/01/25.
//

#include "stringlib.h"

#define MAX_X 20
#define MAX_Y 30
#define MAX_Z 8

void functionStrcpyAndStrncpy(void) {
    char x[] = "Heberth Deza";
    char y[MAX_Y] = "";
    char z[MAX_Z] = "";
    
    strcpy(y, x);
    strncpy(z, x, MAX_Z - 1);
    z[MAX_Z - 1] = '\0';
    
    printf("The original string 'x' is: %s\n", x);
    printf("The string 'y' is: %s\n", y);
    printf("The string 'z' is: %s\n", z);
}

void functionStrcatAndStrncat(void) {
    char x[MAX_X] = "Heberth ";
    char y[] = "Deza ";
    char z[40] = "";
    
    printf("x = %s \ny = %s \nz = %s \n", x, y, z);
    
    printf("strcat(x, y) = %s \n", strcat(x, y));
    printf("strncat(z, x, 8) = %s \n", strncat(z, x, 8));
    printf("strcat(z, x) = %s \n", strcat(z, x));
}
