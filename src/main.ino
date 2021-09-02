#include <Arduino.h>
#include <parser.h>
#include <SD.h>
#include <SPI.h>
// #include "avr8-stub.h"
// #include "app_api.h" // only needed with flash breakpoints

const uint8_t chipSelect = 10;

reader read;

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
    // read.readFile("RECIPES.TXT");
    read.setFile("RECIPES.TXT"); 
    read.getRecipe("Bellini");
    // read.getString(118, '{');
}

void loop()
{
}