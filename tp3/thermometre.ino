#define RESOLUTION 12

const float conversion = 10 * 33.0 / ( (1<<RESOLUTION) - 1);
const int thermometre = A0;
int mesure = 0;

void setup()
{
    Serial.begin(9600);
    if(Serial.available())
    Serial.println("bonjour je suis un thermometre");
    analogReadResolution(RESOLUTION); // passage a une resolution de 12bit
    Serial.println("");
    Serial.print("resolution can = ");
    Serial.println(RESOLUTION);
}

void loop()
{
    mesure = analogRead(thermometre); // valeur retourne par le can
    Serial.print("mesure = ");
    Serial.println(mesure);
    Serial.print("temperature = ");
    Serial.println( mesure * conversion );
    delay(1000); // == 1sec
}
