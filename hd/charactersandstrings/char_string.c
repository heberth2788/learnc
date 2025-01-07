//
//  char_string.c
//  hd
//
//  Created by Heberth Deza on 6/01/25.
//

#include "char_string.h"

// Character (A character is one-byte integer and EOF is -1)
char a = 'a';

// Character array (Use null character at the end '\0')
char myNameC[] = { 'H','e','b','e','r','t','h',' ','D','e','z','a',' ','C','.','\0' };

// Strings literals or String constans (Null character at the end '\0')
char myNameB[] = "Heberth Deza B.";
char myNameD[16] = "Heberth Deza D.";
const char * myNameA = "Heberth Deza A.";

void testCharFunctions(void) {
    printf("%s %s %s\n", "According to isdigit :", isdigit('8') ? "8 is a" : "8 is not a", "digit");
    printf("%s %s %s\n", "According to isdigit :", isdigit('#') ? "# is a" : "# is not a", "digit");
    
    
}
