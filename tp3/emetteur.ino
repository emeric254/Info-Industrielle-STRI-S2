#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
char msg[] = {'t','e','s','t'};

void setup()
{
    Serial.begin(9600);
    if (!driver.init())
        if(Serial.available())
            Serial.println("RF433 >> imposible a initialiser");
}

void loop()
{
    driver.send((uint8_t*)msg, strlen((char *)msg));
    driver.waitPacketSent();

    delay(200);
}
