//
//  fileprocessing.c
//  hd
//
//  Created by Heberth Deza on 27/01/25.
//

#include "fileprocessing.h"

/**
    A file in C is a secuence stream of bytes.
    Each file ends with a EOF(End Of File) marker.
    
    When open a file, C automatically open 3 streams or file pointers:
        0. stdin : Standard input
        1. stdout : Standard output
        2. stderr : Standard error
        3, 4, ... : another file pointers
    
    File descriptor: integer index of the file into OS (User has access)
    Open File Table: OS arrays of file descriptors (User has access)
    FCB: File Control Block (Only OS has access)
 */

void testFileProcessing(void) {
    FILE * pFile = NULL; // a pointer to the FILE structure
    
    // File descriptor: integer index into the OS array called "Open File Table"
    // fgetc(Similar to getchar): reads char from the stdin
    fgetc(stdin);
    
    // fputc(Similar to putchar): writes char to the stdout
    fputc('a', stdout);
    
    // fgets, fputs : read and write a line of text from/to the file.
    // fscanf, fprintf
    // fread, fwrite
}

void createSequentialAccessFile(void) {
    FILE * filePtr = NULL; // file's pointer
    
    FILE f;
    
    // open the file in write mode, exit if unable to create the file
    if ((filePtr = fopen("clients.txt", "w")) == NULL) {
        puts("File could not be openned");
        return;
    }
    
    int account = 0; // account number
    char name[30] = ""; // account name
    double balance = 0.0; // account balance
    
    puts("Enter the account, name , and balance.");
    puts("Enter EOF to end the input.");
    
    printf("%s", "? ");
    scanf("%d%29s%lf", &account, name, &balance); // read the info
    
    // write info into file until EOF reached(EOF is "ctrl + d" in macos)
    while (!feof(stdin)) {
        fprintf(filePtr, "%d %s %.2f\n", account, name, balance); // write on the file
        
        printf("%s", "? ");
        scanf("%d%29s%lf", &account, name, &balance); // read the info
    }
    
    fclose(filePtr); // close the file
}

void showFileOpenModes(void) {
    // r, w, a (read, write, append)
    
    // r+, w+, a+ (update read + write, create read + write, read + append at the end)
    
    // rb, wb, ab (read binary, write binary, append binary)
    
    // rb+, wb+, ab+ (update read + write binary, create read + write binary, read + append at the end binary)
}

void readSequentialAccessFile(void) {
    FILE * filePtr = NULL; // Pointer to the file
    
    // open the file in read mode, if error exit
    if ((filePtr = fopen("clients.txt", "r")) == NULL) {
        puts("File could not be opened");
        return;
    }
    
    int account = 0;
    char name[30] = "";
    double balance = 0.0;
    
    printf("%-10s%-13s%s\n", "Acount", "Name", "Balance");
    fscanf(filePtr, "%d%29s%lf", &account, name, &balance); // read data from the file
    
    // read info from file until EOF reached
    while (!feof(filePtr)) {
        printf("%-10d%-13s%7.2f\n", account, name, balance);
        fscanf(filePtr, "%d%29s%lf", &account, name, &balance); // read data from the file
    }
    
    // means: rebobinar, and put the file position pointer(offset) to the beginning(byte 0)
    // rewind(filePtr);
    
    fclose(filePtr); // close the file
}
