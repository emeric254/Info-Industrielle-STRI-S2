#include<c167.h>
#include<gnutrap.h>

// interupts:
TRAP(0x23,compteur);

char chenillard[] = {0,1,3,5,7,1,3,0,8,4};
int comptage = 0; // position dans tableau

void compteur()
{
    comptage = ++comptage % 10;
    P3 = chenillard[comptage];
}

// main :
void main()
{
    // init registres

    T2 = 28086;
    SET_SFRBIT(IEN);//autorisation des interruptions

    T3CON = 0x44;
    T2CON = 0x27;
    T3IC = 0x4C;

    DP3 = 0xFFFF;
    P3 = chenillard[comptage];

    while(1);
}




