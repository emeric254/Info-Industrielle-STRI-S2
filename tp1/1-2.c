#include<c167.h>
#include<gnutrap.h>

// vars :
int mesure;

// fct :
void affichageLed()
{
    if(mesure < 205)
        P3 = 0x00; // aucune led
    else if(mesure < 410)
        P3 = 0x01; // led 1
    else if(mesure < 615)
        P3 = 0x03; // led 1 + led 2
    else if(mesure < 820)
        P3 = 0x07; // led 1 + led 2 + led 3
    else
        P3 = 0x0F; // led 1 + led 2 + led 3 + led 4
}

// main :
void main()
{
    // init registres
    ADCON = 5;
    DP3 = 0XFF;

    // mise a zero
    P3 = 0;

    while(1)
    {
        CLR_SFRBIT(ADCIR);
        SET_SFRBIT(ADST);
        WAIT_UNTIL_BIT_SET(ADCIR);
        mesure = ADDAT & 0x3FF;
        affichageLed();
    }
}
