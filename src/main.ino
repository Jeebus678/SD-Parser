#include <Arduino.h>
#include <parser.h>
#include <SD.h>
#include <SPI.h>
// #include "avr8-stub.h" // Uncomment us to debug! 
// #include "app_api.h" // Only needed with flash breakpoints

const uint8_t chipSelect = 10; // CS pin for SD

parser Parser;
char* buffer = "Americano"; // First name in SD card

void setup()
{
    // debug_init(); // Debugger innit 
    pinMode(SS, OUTPUT);
    Serial.begin(9600);
    while (!Serial)
        continue;
    if (!SD.begin(chipSelect))
    {
        Serial.println("Card failed, or not present");
        return;
    }
    Parser.setFile("RECIPES.TXT"); 
    Parser.parse(buffer);
}

void loop()
{
}