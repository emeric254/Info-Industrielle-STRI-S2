#include<c167.h>
#include<gnutrap.h>

// vars :
int mesure;

// main :
void main()
{
    ADCON = 0x5;
    while(1)
    {
        CLR_SFRBIT(ADCIR);
        SET_SFRBIT(ADST);
        WAIT_UNTIL_BIT_SET(ADCIR);
        mesure = ADDAT & 0x3FF;
    }
}
