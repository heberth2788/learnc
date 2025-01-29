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
    
    // "rewind" means "rebobinar", and put the file position pointer(offset) to the beginning(byte 0)
    // rewind(filePtr);
    
    fclose(filePtr); // close the file
}


void createRandomAccessFile(void) {
    // A random access file uses fixed-length records that may be
    // accessed directly and quickly using a record key.
    
    // fwrite, fread : write and read raw bytes. Also can write and read arrays.
    // fprintf, fscanf : write and read human-readable text format.
    
    FILE * fPtr = NULL;
    
    puts("Openning the file");
    
    // Open the file for writing in binary mode "wb"
    if ((fPtr = fopen("accounts.dat", "wb")) == NULL) {
        puts("File could not be opened");
        return;
    }
    
    // Creating an empty object of type ClientData
    ClientData blankData = {
        .account = 0,
        .lastName = "",
        .firstName = "",
        .balance = 0.0,
    };
    
    puts("Writing the file");
    for (int i = 0; i < 100; i++) {
        fwrite(&blankData, sizeof(ClientData), 1, fPtr); // writing the file
    }
    
    puts("Closing the file");
    fclose(fPtr);
}

/**
    Clean the struct object
 */
void cleanClientData(ClientData * pClientData) {
    pClientData->account = 0;
    memset(pClientData->firstName, '\0', sizeof(pClientData->firstName));
    memset(pClientData->lastName, '\0', sizeof(pClientData->lastName));
    pClientData->balance = 0.0;
}

void writeRandomAccessFile(void) {
    FILE * fPtr = NULL; // pointer to the file
    puts("Openning the file");
    
    // Open the file for writing in binary mode "wb"
    if ((fPtr = fopen("accounts.dat", "wb")) == NULL) {
        puts("File could not be opened");
        return;
    }
    
    ClientData clientData = {
        .account = 0,
        .lastName = "",
        .firstName = "",
        .balance = 0.0,
    };
    
    printf("%s", "Enter account number(from 1 to 100, 0 to end the input): ");
    // read the account number into the clientData's account field
    scanf("%d", &clientData.account);
    
    // iterate while account is not 0
    while (clientData.account != 0) {
        printf("%s","Enter the lastname, firstname and balance: ");
        // read stdin(keyboard) into the clientData's fields
        fscanf(stdin, "%15s%15s%lf", clientData.lastName, clientData.firstName, &clientData.balance);
        
        // seek position(offset or displacement) in file according the account number
        // SEEK_SET means to move the file pointer from the "beginning" of the file
        // SEEK_CUR means to move the file pointer from the "current location" of the file
        // SEEK_END means to move the file pointer from the "end" of the file
        fseek(fPtr, (clientData.account - 1) * sizeof(ClientData), SEEK_SET);
        
        puts("[writing data into the file...]");
        // write struct into the file
        fwrite(&clientData, sizeof(ClientData), 1, fPtr);
        
        // clean data struct object
        cleanClientData(&clientData);
        /*clientData.account = 0;
        memset(clientData.lastName, '\0', sizeof(clientData.lastName));
        memset(clientData.firstName, '\0', sizeof(clientData.firstName));
        clientData.balance = 0.0;*/
        
        // ask for the next account number
        printf("%s", "Enter account number(from 1 to 100, 0 to end the input): ");
        scanf("%d", &clientData.account);
    }
    
    puts("Closing the file");
    fclose(fPtr); // close the file
}

void readRandomAccessFile(void) {
    FILE * pFile = NULL; // pointer to the file
    
    // open the file for reading in binary mode "rb"
    if ((pFile = fopen("accounts.dat", "rb")) == NULL) {
        puts("File could not be openned");
        return;
    }
    
    ClientData clientData = {
        .account = 0,
        .lastName = "",
        .firstName = "",
        .balance = 0.0,
    };
    size_t result = 0;
    
    printf("%-12s%-16s%-11s%10s\n", "Account", "Last name", "First name", "Balance");
    
    // read all the file (pFile moves forward automatically)
    while (!feof(pFile)) {
        
        // read the file, pFile moves forward automatically
        result = fread(&clientData, sizeof(clientData), 1, pFile);
        
        // display read information
        if (result != 0 && clientData.account != 0) {
            printf("%-12d%-16s%-11s%10.2f\n",
                   clientData.account,
                   clientData.lastName,
                   clientData.firstName,
                   clientData.balance
           );
           cleanClientData(&clientData);
        }
    }
    
    fclose(pFile); // close the file
}


