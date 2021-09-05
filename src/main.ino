#include <Arduino.h>
#include <parser.h>
#include <SD.h>
#include <SPI.h>
// #include "avr8-stub.h"
// #include "app_api.h" // only needed with flash breakpoints

const uint8_t chipSelect = 10;

parser Parser;
char* buffer = "Aviation";

void setup()
{
    // debug_init();
    pinMode(SS, OUTPUT);
    Serial.begin(9600);
    while (!Serial)
        continue;
    if (!SD.begin(chipSelect))
    {
        Serial.println("Card failed, or not present");
        return;
    }
    // Parser.ParserFile("RECIPES.TXT");
    Parser.setFile("RECIPES.TXT"); 
    Parser.parse(buffer);
}

void loop()
{
}