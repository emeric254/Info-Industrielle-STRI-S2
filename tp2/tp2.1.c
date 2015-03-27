#include<c167.h>
#include<gnutrap.h>

// interupts:
TRAP(0x23,compteur);


void compteur()
{

    if(SFR_BIT(P3.0))
        CLR_SFRBIT(P3.0);
    else
        SET_SFRBIT(P3.0);
}

// main :
void main()
{
    // init registres

    SET_SFRBIT(IEN);//autorisation des interruptions

    T2 = 28086;
    T3CON = 0x44;
    T2CON = 0x27;
    T3IC = 0x4C;

    DP3 = 0xFF;
    P3 = 0;


    while(1);
}




