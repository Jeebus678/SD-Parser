#include <parser.h>
#include <SD.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void reader::clearBuffer()
{
    for (unsigned int erase = 0;erase<sizeof(buffer); erase++)
    {
       buffer[erase] = '\0';
    }
}

void reader::setFile(const char *filename)
{
    file = SD.open(filename, FILE_READ);
}

// void reader::readFile()
// {
//     if (file)
//     {
//         fileSize = file.size();
//         while (file.available())
//         {
//             file.seek(pos);
//             readByte = file.peek();
//             if (readByte == newLine)
//             {
//                 for (unsigned int i = pos; i < fileSize; i++)
//                 {
//                     file.seek(i);
//                     readByte = file.peek();
//                     Serial.println(readByte);
//                     if (readByte == endLine)
//                     {
//                         Serial.println();
//                         pos = file.position() + 1;
//                     }
//                 }
//             }
//         }
//     }
//     else
//         Serial.println("Error: Failed to open file.");
// }

void reader::getRecipe(const char *name) // Retrieve a cocktail's recipe string
{
    if (file) 
    {
        fileSize = file.size();
        pos = 0;
        for (unsigned int i = pos; i <= fileSize; i++) // Loop through entire file
        {
            file.seek(i);
            readByte = file.peek();
            if (readByte == newLine) // Stop at every new line
            {
                pos = file.position();
                bufferString(pos + 1, newArray);
                if(strcmp(buffer, name)==0){ // Does the name parameter match the buffer string?
                    bufferString(pos + 1, endLine); // If it does, save the drink to the buffer
                    Serial.println(buffer);
                }
            }
        }
    }
    else
        Serial.println("Error: Failed to open file.");
}

char* reader::bufferString(unsigned int position, char delimiter) // Get any string from a starting position until a specified delimiter
{
    clearBuffer(); 
    file.seek(position + 1);
    for (unsigned int n = file.position();; n++) // Iterate forward infinitely
    {
        file.seek(n);
        readByte = file.peek();
        if (readByte == delimiter) // If delimiter detected
        {
            file.seek(position);
            file.read(buffer, n - position);
            return buffer;
        }
    }
}

void reader::lex(unsigned int *position){
    bufferString(*position, '}'); 
}