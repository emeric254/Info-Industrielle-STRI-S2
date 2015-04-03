#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
char msg[32];
const int longueur = 32;

void setup()
{
    Serial.begin(9600);
    if (!driver.init())
        if(Serial.available())
            Serial.println("RF433 >> imposible a initialiser");
}

void loop()
{
    driver.recv((uint8_t *)msg, (uint8_t *)&longueur);
    Serial.println(msg);
    delay(200);
}
