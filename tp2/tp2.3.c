#include<c167.h>
#include<gnutrap.h>

// interupts:
TRAP(0x2B,readTestSer);

// interupts:
TRAP(0x23,compteur);


// vars:
char buffer = 0;
char chenillard[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
char taille = 20;
int comptage = 0; // position dans tableau
int reception = 0;


void readTestSer() // pas trop opti ...
{
    buffer = S0RBUF;
    if(!reception)
    {
        CLR_SFRBIT(T3R); // arret
        P3 = 0; // extinction
        comptage = 0; // reset comptage
        taille = buffer%20;
        reception ++;
    }
    else
    {
        chenillard[reception-1]= buffer%16;
        reception = ++reception % (taille+1);
    }
    if(!reception)
        SET_SFRBIT(T3R);
}

void compteur()
{
    comptage = ++comptage % taille;
    P3 = chenillard[comptage];
}

// main :
void main()
{
    // init registres

    SET_SFRBIT(IEN);//autorisation des interruptions

    // timer
    T2 = 28086;
    T3CON = 0x44;
    T2CON = 0x27;
    T3IC = 0x4C;

    // serie
    ADCON = 0x5;
    S0CON = 0xA011;
    S0RIC = 0x4C;
    S0BG = 21;

    // leds
    DP3 = 0xFF;
    P3 = 0;

    while(1);
}









