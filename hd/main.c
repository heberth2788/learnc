//
//  main.c
//  hd
//
//  Created by Heberth Deza on 6/11/24.
//

/*#include "iohd.h"
#include "newtypes/family.h"
#include "storageclasses/cstorageclass.h"
#include "recursive/recursive.h"
#include "arrays/arrays.h"
#include "sortingalgorithms/bubblesort.h"
#include "sizeof/sizeofoperator.h"
#include "pointers/pointers.h"
#include "arrays/multidimensional.h"
#include "pointers/function_pointer.h"
#include "charactersandstrings/char_string.h"
#include "standario/standario.h"
#include "string/stringlib.h"
#include "structunionbitsenum/bits.h"
#include "structunionbitsenum/enums.h"
#include "preprocessor/preprocessor.h"
#include "fileprocessing/fileprocessing.h"
#include "datastructures/linkedlist.h"
#include "pointers/pointers.h"
#include "datastructures/stack.h"
#include "datastructures/queues.h"
#include "datastructures/datastructure.h
#include "datastructures/tree.h""*/
#include "bigonotation/bigonotation.h"

/*
    The "main" function does not need prototype,
    and have 3 basic definitions:
    
        a) Option 1:    int main(void)
 
        b) Option 2:    int main(int argc, const char* argv[])
                        int main(int argc, char** argv)
 
            - Notes: "argc" means "argument count"
                     "argv" means "argument vector"
 
         c) Option 3:   int main(int argc, char* argv[], char* envp[])
                        int main(int argc, char** argv, char** envp)
            
            - Notes: "envp" means "environment variables"
 */

int main(int argc, const char * argv[]) {
    
//    selectionSort();
//    insertionSort();
    mergeSort();
    
//    myBinaryTree();
    
//    testLinkedListWithMemMgmt();
    
//    myQueue();
    
//    myStack();
    
//    pointerToPointer();
//    myLinkedList();
//    testLinkedList();
//    testLinkedListWithMemMgmt();
//    callFooBar();
    
//    readRandomAccessFile();
//    writeRandomAccessFile();
//    createRandomAccessFile();
//    readSequentialAccessFile();
//    createSequentialAccessFile();
    
//    testEnums();
    
//    showBitwiseOperators();
//    displayBitsPortable(8);
//    displayBits();
    
//    functionStrcatAndStrncat();
//    functionStrcpyAndStrncpy();
    
//    functionSscanf();
//    functionSprintf();
//    functionGetchar();
//    functionsFgetsAndPutchar();
    
//    testStringFunctions();
//    testCharFunctionsAroundPrinting();
//    testCharFunctionsAroundLowerUpper();
//    testCharFunctionsAroundDigits();
    
//    arrayOfPointers();
//    arrayOfPointersToFunctions();
    
//    copyStrings();
//    printRelationArrayVsPointer();
//    createMultimensionalArray();
    
//    printSizeofPrimitiveDatatypes();
    
//    sizeOfOperator();
  
//    runBubbleSort();
    
//    pointerToFunction();
    
//    usingConstWithPointers();
    
//    printingArrayAddress();
    
//    passingArrayToFunction();
    
//    scanString();
    
//    createStaticArray();
//    createAutomaticArray();
//    createStaticArray();
//    createAutomaticArray();
    
//    createArrays();
    
//    printFactorial(20);
//    printFibonacci(40);
    
//    if (argc != 3) {
//        fprintf(stderr, "Incompatible arguments cuantity, needed 3, set %d \n", argc);
//        return -1;
//    }
//    
//    for (int i = 0; i < argc; i++) {
//        printf("%s \n", *(&argv[i]));
//    }
    
//    testAutoStorageClass();
//    testAutoStorageClass();
//    puts("");
//    testRegisterStorageClass();
//    testRegisterStorageClass();
//    puts("");
//    testExternStorageClass();
//    testExternStorageClass();
//    testExternStorageClass();
//    puts("");
//    testStaticStorageClass();
//    testStaticStorageClass();
//    testStaticStorageClass();
    
//    pointerToVoidThenCasting();
    
//    usingNewTypes();
    
//    myPrint();
    
//    pointersArithmetic();
    
//    int term1 = 100, term2 = 200;
//    int sum = 0;
//    sumThreeIntsUsingPointers(&term1, &term2, &sum);
//    printf("The sum is = %d \n\n", sum);
    
//    printInfo();
    
    return 0;
}
