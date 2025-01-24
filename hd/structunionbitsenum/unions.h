//
//  unions.h
//  hd
//
//  Created by Heberth Deza on 21/01/25.
//

#ifndef unions_h
#define unions_h

#include <stdio.h>

union member {
    int fatherAge;
    int motherAge;
    double rate;
};

union {
    int fatherAge;
    int motherAge;
    double rate;
} meu;

typedef union {
    int fatherAge;
    int motherAge;
    double rate;
} Memb;

/**
    Bit fields :
    Use in union to specify the number of bits in which to store an unsigned or signed int member.
 */
union myBitCardInUnion {
    unsigned int face : 4;
    unsigned int suit : 2;
    unsigned int color : 1;
};

// Assuming a 4-byte-word computer (4 * 8 = 32 bits word)
union unnamedBitInUnionA {
    unsigned int a : 13;
    unsigned int   : 19; // padding 19 bits
    unsigned int b : 4;
};

// Assuming a 4-byte-word computer (4 * 8 = 32 bits word)
union unnamedBitInUnionB {
    unsigned int a : 13;
    unsigned int   : 0; // skip 19 bits to complete the word(E.g: 32 bits)
    unsigned int b : 4;
};

union myUnion {
    int a;
    int b;
    union { // anonymous union
        int nestedc;
        int nestedd;
    };
    int e;
};

void declareUnionObjects(void);
void usingAnonymousUnion(void);

#endif /* unions_h */
