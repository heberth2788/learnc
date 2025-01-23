//
//  bits.c
//  hd
//
//  Created by Heberth Deza on 22/01/25.
//

#include "bits.h"

void displayBits(void) {
    
    unsigned int num = 8; // Assuming a unsigned int = 4 bytes (32 bits)
    unsigned int dispMask = 1 << 31; // result: 10000000 00000000 00000000 00000000
    
    printf("%u = ", num);
    
    for (unsigned int i = 1; i <= 32; i++) {
        putchar(num & dispMask ? '1' : '0');
        num <<= 1;
        
        if (i % 8 == 0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

void displayBitsPortable(unsigned int num) {
    
    // Generally 32 bits(8 * 4), or 64 bits(8 * 8) in other architectures
    int intSizeInBits = CHAR_BIT * sizeof(unsigned int); // CHAR_BIT = 8(no of bits in a byte)
    
//    unsigned int num = 8;
    unsigned int dispMask = 1 << (intSizeInBits - 1);
    
    printf("%12u = ", num);
    
    for (unsigned int i = 1; i <= intSizeInBits; i++) {
        putchar(num & dispMask ? '1' : '0');
        num <<= 1;
        
        if (i % 8 == 0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

void showBitwiseOperators(void) {
    unsigned int noA = 8;
    unsigned int noB = 65535;
    unsigned int pivot = 0;
    
    printf("Numbers : %u , %u \n", noA, noB);
    displayBitsPortable(noA);
    displayBitsPortable(noB);
    
    puts("");
    puts("Bitwise AND & operator :");
    pivot = noA & noB;
    displayBitsPortable(pivot);
    
    puts("");
    puts("Bitwise OR | operator :");
    pivot = noA | noB;
    displayBitsPortable(pivot);
    
    puts("");
    puts("Bitwise XOR ^ operator :");
    pivot = noA ^ noB;
    displayBitsPortable(pivot);
    
    puts("");
    puts("Bitwise NOT ~ operator (~noB) :");
    pivot = ~noB;
    displayBitsPortable(pivot);
    
    puts("\n----------------------");
    
    puts("");
    puts("Bitwise left << operator (noB << 8) :");
    pivot = noB << 8;
    displayBitsPortable(pivot);
    
    puts("");
    puts("Bitwise right >> operator (noB >> 8) :");
    pivot = noB >> 8;
    displayBitsPortable(pivot);
}
