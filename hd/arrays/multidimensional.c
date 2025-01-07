//
//  multidimensional.c
//  hd
//
//  Created by Heberth Deza on 2/12/24.
//

#include "multidimensional.h"

void createMultimensionalArray(void) {
    
    int matriz[3][COLUMNS_NO] = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
    int auxMatriz[6][COLUMNS_NO] = {{ 1 }, { 2, 3 }, {4, 5, 6}};
    int emptyMatriz[3][COLUMNS_NO] = { 0 };
    
    printMatriz(matriz, 3);
    puts("");
    printMatriz(auxMatriz, 12);
    puts("");
    printMatriz(emptyMatriz, 3);
    puts("");
}

void printMatriz(int matriz[][COLUMNS_NO], size_t rowsNo) {
    for (size_t i = 0; i < rowsNo; i++) {
        for (size_t j = 0; j < COLUMNS_NO; j++) {
            printf("%d\t", matriz[i][j]);
        }
        puts("");
    }
}
