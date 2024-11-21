//
//  family.c
//  hd
//
//  Created by Heberth Deza on 13/11/24.
//

#include "family.h"

int myAgeGlobal = 36;

// Basic declaration then typedef
enum DaugtherA {
    HEILYA,     // 0
    JOICYA,     // 1
    BERTHLYA    // 2
};
typedef enum DaugtherA DautherA2;

// Recomended declaration
typedef enum {
    HEILYB,         // 0
    JOICYB = 6,     // 6
    BERTHLYB        // 7
} DaughterB;

// Redundant declaration(Not recomended)
typedef enum DaugtherC {
    HEILYC = 1,     // 1
    JOICYC,         // 2
    BERTHLYC        // 3
} DaugtherC2;

void usingNewTypes(void) {
    
    enum DaugtherA myHeilyA = HEILYA;
    DautherA2 myHeilyA2 = HEILYA;
    
    DaughterB myJoicy = JOICYB;
    
    enum DaugtherC myBerthlyC = BERTHLYC;
    DaugtherC2 myBerthlyCNew = BERTHLYC;
}
