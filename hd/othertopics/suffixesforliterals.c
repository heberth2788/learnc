//
//  suffixesforliterals.c
//  hd
//
//  Created by Heberth Deza on 5/03/25.
//

#include "suffixesforliterals.h"

void suffixesForIntegerAndFloatingPoint(void) {
    // suffixes for integers
    unsigned int ui = 369U; // or 369u
    long int li = 369L; // or 369l
    unsigned long int uli = 369UL; // or 369ul
    unsigned long long int ulli = 369LLU; // or 369llu
    
    // suffixes for floating-point
    float f = 369.12F; // or 369.12f
    long double ld = 369.12L; // or 369.12l
}
