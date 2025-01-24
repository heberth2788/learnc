//
//  enums.h
//  hd
//
//  Created by Heberth Deza on 23/01/25.
//

#ifndef enums_h
#define enums_h

#include <stdio.h>

void testEnums(void);

/**
    A enum is a set of integer enumeration constants that by default start with 0
    and increment by 1
 */
enum monthsA {
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};

enum vowels {
    A = 2, E, I = 5, O, U
    //2, 3, 5, 6, 7
};

typedef enum monthsB {
    JAN_ = 1, FEB_, MAR_, APR_, MAY_, JUN_, JUL_, AUG_, SEP_, OCT_, NOV_, DEC_
    //1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
} Months;

#endif /* enums_h */
