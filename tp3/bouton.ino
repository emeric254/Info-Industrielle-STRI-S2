
void bouton() // fct appele sur interupt
{
}

void setup()
{
    pinMode(13,OUTPUT);
    pinMode(4,INPUT_PULLUP); // GND || port 4 donc front descendant sur appui

    attachInterrupt(4, bouton, RISING);

    Serial.begin(9600);

    if(Serial.available())
        Serial.println("bonjour !!");
}

void loop()
{
    /**
    if(digitalRead(4)==LOW) // car front descendant sur appui si bouton entre gnd et broche 4
        digitalWrite(13,HIGH);
    else
        digitalWrite(13,LOW);
    **/

    delay(20); // on evite le rebond avec ce delay suffisant mais surement pas minimum
}
