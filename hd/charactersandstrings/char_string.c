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

// Strings literals or String constans (Null character at the end '\0' is added automatically)
char myNameB[] = "Heberth Deza B.";
char myNameD[16] = "Heberth Deza D.";
const char * myNameA = "Heberth Deza A.";

void testCharFunctionsAroundDigits(void) {
    puts("");
    
    printf("%s %s %s\n", "According to isdigit :", isdigit('8') ? "8 is a" : "8 is not a", "digit");
    printf("%s %s %s\n", "According to isdigit :", isdigit('#') ? "# is a" : "# is not a", "digit");
    
    puts("");
    
    printf("%s %s %s\n", "According to isalpha :", isalpha('A') ? "A is a" : "A is not a", "letter");
    printf("%s %s %s\n", "According to isalpha :", isalpha('b') ? "b is a" : "b is not a", "letter");
    printf("%s %s %s\n", "According to isalpha :", isalpha('#') ? "# is a" : "# is not a", "letter");
    printf("%s %s %s\n", "According to isalpha :", isalpha('3') ? "3 is a" : "3 is not a", "letter");
    
    puts("");
    
    printf("%s %s %s\n", "According to isalnum :", isalnum('A') ? "A is a" : "A is not a", "digit or letter");
    printf("%s %s %s\n", "According to isalnum :", isalnum('6') ? "6 is a" : "6 is not a", "digit or letter");
    printf("%s %s %s\n", "According to isalnum :", isalnum('%') ? "% is a" : "% is not a", "digit or letter");
    
    puts("");
    
    printf("%s %s %s\n", "According to isxdigit :", isxdigit('F') ? "F is a" : "F is not a", "hexadecimal digit");
    printf("%s %s %s\n", "According to isxdigit :", isxdigit('J') ? "J is a" : "J is not a", "hexadecimal digit");
    printf("%s %s %s\n", "According to isxdigit :", isxdigit('7') ? "7 is a" : "7 is not a", "hexadecimal digit");
    printf("%s %s %s\n", "According to isxdigit :", isxdigit('$') ? "$ is a" : "$ is not a", "hexadecimal digit");
    printf("%s %s %s\n", "According to isxdigit :", isxdigit('f') ? "f is a" : "f is not a", "hexadecimal digit");
}

void testCharFunctionsAroundLowerUpper(void) {
    puts("");
    
    printf("%s %s %s\n", "According to islower :", islower('h') ? "h is a" : "h is not a", "lowercase letter");
    printf("%s %s %s\n", "According to islower :", islower('H') ? "H is a" : "H is not a", "lowercase letter");
    printf("%s %s %s\n", "According to islower :", islower('9') ? "9 is a" : "9 is not a", "lowercase letter");
    printf("%s %s %s\n", "According to islower :", islower('!') ? "! is a" : "! is not a", "lowercase letter");
    
    puts("");
    
    printf("%s %s %s\n", "According to isupper :", isupper('j') ? "j is a" : "j is not a", "uppercase letter");
    printf("%s %s %s\n", "According to isupper :", isupper('J') ? "J is a" : "J is not a", "uppercase letter");
    printf("%s %s %s\n", "According to isupper :", isupper('3') ? "3 is a" : "3 is not a", "uppercase letter");
    printf("%s %s %s\n", "According to isupper :", isupper('#') ? "# is a" : "# is not a", "uppercase letter");
    
    puts("");
    
    printf("%s %c\n", "d converted to uppercase is :", toupper('d'));
    printf("%s %c\n", "3 converted to uppercase is :", toupper('3'));
    
    printf("%s %c\n", "D converted to lowercase is :", tolower('D'));
    printf("%s %c\n", "3 converted to lowercase is :", tolower('3'));
}

void testCharFunctionsAroundPrinting(void) {
    puts("");
    
    printf("%s %s %s\n", "According to isspace :", isspace('\n') ? "\\n is a" : "\\n is not a", "whitespace character");
    printf("%s %s %s\n", "According to isspace :", isspace('\t') ? "\\t is a" : "\\t is not a", "whitespace character");
    printf("%s %s %s\n", "According to isspace :", isspace('%') ? "% is a" : "% is not a", "whitespace character");
    
    puts("");
    
    printf("%s %s %s\n", "According to iscntrl :", iscntrl('\n') ? "\\n is a" : "\\n is not a", "control character");
    printf("%s %s %s\n", "According to iscntrl :", iscntrl('$') ? "$ is a" : "$ is not a", "control character");
    
    puts("");
    
    printf("%s %s %s\n", "According to ispunct :", ispunct(';') ? "; is a" : "; is not a", "punctuation character");
    printf("%s %s %s\n", "According to ispunct :", ispunct('y') ? "y is a" : "y is not a", "punctuation character");
    printf("%s %s %s\n", "According to ispunct :", ispunct('#') ? "# is a" : "# is not a", "punctuation character");
    
    puts("");
    
    printf("%s %s %s\n", "According to isprint :", isprint('$') ? "$ is a" : "$ is not a", "printing character");
    printf("%s %s %s\n", "According to isprint :", isprint('\a') ? "\\a is a" : "\\a is not a", "printing character");
    
    puts("");
    
    printf("%s %s %s\n", "According to isgraph :", isgraph('H') ? "H is a" : "H is not a","printing character other than space");
    printf("%s %s %s\n", "According to isgraph :", isgraph(' ') ? "\' \' is a" : "\' \' is not a","printing character other than space");
    printf("%s %s %s\n", "According to isgraph :", isgraph('\n') ? "\\n is a" : "\\n is not a","printing character other than space");
    printf("%s %s %s\n", "According to isgraph :", isgraph('\t') ? "\\t is a" : "\\t is not a","printing character other than space");
}

void testStringFunctions(void) {
    const char * ptrMyStr = " 36.5 is a good number"; // Ok, it starts with a digit or space
//    const char * ptrMyStr = "    36  "; // Ok, it starts with a digit or space
//    const char * ptrMyStr = "The value 36.555 is a good number"; // Wrong, it does not start with a number or space
    char * ptrStr = NULL;
    
    double doubleVal = strtod(ptrMyStr, &ptrStr); // strtod means String to Double
    
    printf("Original string: %s \n", ptrMyStr);
    printf("Double value: %.2f \n", doubleVal);
    printf("The remainder of the string: %s \n", ptrStr);
}
