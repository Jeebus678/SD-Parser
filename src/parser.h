#ifndef PARSER_H_
#define PARSER_H_

#include <SD.h>

// FILE FORMAT:
// $name{x1, y1; x2, y2}

class reader
{
public:
    // Delimiters below 
    char newArray = '{'; 
    char newElement = ';';
    char divider = ','; 
    char endLine = '}';
    char newLine = '$';

    File file;
    unsigned int fileSize;
    unsigned int pos = 0; 
    char buffer[100];
    char readByte; 
    
    void clearBuffer(); 
    void setFile(const char *filename); 
    // void readFile();
    void getRecipe(const char *name); 
    char* bufferString(unsigned int position, char delimiter); 

    void lex(unsigned int *position); 
};

#endif