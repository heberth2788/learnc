//
//  unions.h
//  hd
//
//  Created by Heberth Deza on 21/01/25.
//

#ifndef unions_h
#define unions_h

#include <stdio.h>

void declareUnionObjects(void);

union member {
    int fatherAge;
    int motherAge;
    double rate;
};

union {
    int fatherAge;
    int motherAge;
    double rate;
} me;

typedef union {
    int fatherAge;
    int motherAge;
    double rate;
} Memb;

#endif /* unions_h */
