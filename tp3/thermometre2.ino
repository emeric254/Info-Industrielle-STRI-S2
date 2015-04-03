#define FREQ 100000 // pour que ce soit pas trop rapide pour un humain
#define RESOLUTION 12

const float conversion = 10 * 33.0 / ( (1<<RESOLUTION) - 1);
const int thermometre = A0;
int mesure = 0;
float temperature = 0;
int i = 0;
float moyenne = 0;

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
    temperature = mesure * conversion; // apres conversion
    ++i %= FREQ; // incrementation modulo FREQ
    if(!i)
    {
        moyenne /= FREQ; // calcul moyenne
        Serial.print("moyenne (");
        Serial.print(FREQ);
        Serial.print(" mesures) = ");
        Serial.println( moyenne);
        moyenne = mesure * conversion; // moyenne reset
    }
    else
        moyenne += temperature; // somme

    /*
    Serial.print("mesure = ");
    Serial.println(mesure);
    Serial.print("temperature = ");
    Serial.println( mesure * conversion);
    */
    // delay(100);
    }
