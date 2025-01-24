//
//  enums.c
//  hd
//
//  Created by Heberth Deza on 23/01/25.
//

#include "enums.h"

void testEnums(void) {
    enum monthsA month1 = JAN;
    Months month2 = FEB_;
    
    for(Months m = JAN_; m <= DEC_; m++) {
        printf("Month id = %d\n", m);
    }
    putchar('\n');
}
