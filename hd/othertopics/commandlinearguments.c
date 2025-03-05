//
//  commandlinearguments.c
//  hd
//
//  Created by Heberth Deza on 25/02/25.
//

#include "commandlinearguments.h"

/**
 Used to pass filenames and options to the program as a parameters.
 
 The "main" function does not need prototype, and have 3 basic definitions:
 
     a) Option 1:    int main(void)

     b) Option 2:    int main(int argc, const char* argv[])
                     int main(int argc, char** argv)

         - Notes: "argc" means "argument count"
                  "argv" means "argument vector"

      c) Option 3:   int main(int argc, char* argv[], char* envp[])
                     int main(int argc, char** argv, char** envp)
         
         - Notes: "envp" means "environment variables"
 */

/**
    Copy a file into another file
 
    Use:
        hd myFile.txt yourFile.txt
 
    3 Agruments:
        [0] : binary name. E.g: hd
        [1]: input file name. E.g: myFile.txt
        [2]: output file name. E.g: yourFile.txt
 
    
 */
int main2(int argc, const char * argv[]) {

    if (argc != 3) {
        puts("Usage: hd infile outfile.");
        return 0;
    }
    
    printf("Trying to copy the file %s to the file %s\n", argv[1], argv[2]);
    
    FILE * inFile = NULL; // input file pointer
    FILE * outFile = NULL; // output file pointer
    
    // try to open the input file
    if ((inFile = fopen(argv[1], "r")) == NULL) {
        printf("The input file %s could not be opened.\n", argv[1]);
        return 0;
    }
    
    // try yo open the output file
    if ((outFile = fopen(argv[2], "w")) == NULL) { // "a" for append, "w" for writting
        printf("The output file %s could not be opened.\n", argv[2]);
        return 0;
    }
    
    // copy the input file to the output file until reach the EOF(end of file)
    int c = 0;
    while ((c = fgetc(inFile)) != EOF) {
        fputc(c, outFile);
    }
    
    // close input and output files
    fclose(inFile);
    fclose(outFile);
    
    printf("Success coping the file %s to the file %s\n", argv[1], argv[2]);
    exit(EXIT_SUCCESS);
}
