#include <parser.h>
#include <SD.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void parser::clearBuffer()
{
    for (unsigned int erase = 0; erase < sizeof(buffer); erase++)
    {
        buffer[erase] = '\0';
    }
}

void parser::setFile(const char *filename)
{
    file = SD.open(filename, FILE_READ);
}

// void parser::readFile()
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

void parser::getRecipe(const char *name) // Retrieve a cocktail's recipe string
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
                if (strcmp(buffer, name) == 0)
                {                                   // Does the name parameter match the buffer string?
                    bufferString(pos + 1, endLine); // If it does, save the drink to the buffer
                    break;
                }
            }
        }
    }
    else
        Serial.println("Error: Failed to open file.");
}

char *parser::bufferString(unsigned int position, char delimiter) // Get any string from a starting position until a specified delimiter
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

void parser::lex()
{
    // typedef struct
    // {
    //     char liquor[30];
    //     uint8_t portion;
    // } Ingridient;

    // typedef struct
    // {
    //     char name[30];
    //     Ingridient ingridients[7];
    // } Cocktail;
    // uint8_t recipeLayer = 0;
    // boolean name = true;
    // boolean ingr = false;
    // boolean portn = false;
    getRecipe("Aviation");
    Serial.println(buffer);
    for (unsigned int i = 0; i < sizeof(buffer); i++)
    {
        switch(buffer[i]){
            case ('{'):{
                ;
            }
        }
    }

    Serial.println(cocktail.name);
    for (unsigned int i = 0; i < sizeof(cocktail.ingridients); i++)
    {
        if (cocktail.ingridients[i].portion != NULL)
        {
            Serial.println(cocktail.ingridients[i].liquor);
            Serial.println(cocktail.ingridients[i].portion);
        }
    }
}