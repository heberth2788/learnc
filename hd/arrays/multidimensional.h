//
//  multidimensional.h
//  hd
//
//  Created by Heberth Deza on 2/12/24.
//

#ifndef multidimensional_h
#define multidimensional_h

#include <stdio.h>

#define COLUMNS_NO 3

void createMultimensionalArray(void);
void printMatriz(int matriz[][COLUMNS_NO], size_t rowsNo);
void printRelationArrayVsPointer(void);
void copyStrings(void);

#endif /* multidimensional_h */
