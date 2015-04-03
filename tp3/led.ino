#define RESOLUTION 12
const float conversion = 10 * 33.0 / ( (1<<RESOLUTION) - 1);
const int thermometre = A0;
float temp = 0;

void setup()
{
    pinMode(2,OUTPUT); // out port 2 qui est PWM
    analogReadResolution(RESOLUTION); // passage a une resolution de 12bit
}

void loop()
{
    temp = analogRead(thermometre);
    temp *= conversion;
    temp -= 20;

    if(temp >= 0)
        analogWrite(2, (temp>5)?(255):((temp/5)*255) );
    else
        analogWrite(2,0);

    delay(70);
}
