//
//  fileprocessing.h
//  hd
//
//  Created by Heberth Deza on 27/01/25.
//

#ifndef fileprocessing_h
#define fileprocessing_h

#include <stdio.h>
#include <string.h>

// Client data struct definition
typedef struct {
    int account;
    char lastName[16];
    char firstName[16];
    double balance;
} ClientData;


void testFileProcessing(void);

void createSequentialAccessFile(void);
void showFileOpenModes(void);
void readSequentialAccessFile(void);

void cleanClientData(ClientData * pClientData);
void createRandomAccessFile(void);
void writeRandomAccessFile(void);
void readRandomAccessFile(void);

#endif /* fileprocessing_h */
