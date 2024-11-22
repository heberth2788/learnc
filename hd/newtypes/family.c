//
//  family.c
//  hd
//
//  Created by Heberth Deza on 13/11/24.
//

#include "family.h"

int myAgeGlobal = 36;

// Basic declaration then typedef
enum daugther_a {
    HEILYA,     // 0
    JOICYA,     // 1
    BERTHLYA    // 2
};
typedef enum daugther_a dauther_a2;

// Recomended declaration
typedef enum {
    HEILYB,         // 0
    JOICYB = 6,     // 6
    BERTHLYB        // 7
} daughter_b;

// Redundant declaration(Not recomended)
typedef enum daugther_c {
    HEILYC = 1,     // 1
    JOICYC,         // 2
    BERTHLYC        // 3
} daugther_c2;

void usingNewTypes(void) {
    
    enum daugther_a myHeilyA = HEILYA;
    dauther_a2 myHeilyA2 = HEILYA;
    
    daughter_b myJoicy = JOICYB;
    
    enum daugther_c myBerthlyC = BERTHLYC;
    daugther_c2 myBerthlyCNew = BERTHLYC;
}
