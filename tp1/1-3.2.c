#include<c167.h>
#include<gnutrap.h>

// interupts:
TRAP(0x2B,readSer);
TRAP(0x2A,writeSer);

// vars :
char buffer = 0;

// fct :
void readSer()
{
    buffer = S0RBUF;
}

void writeSer()
{
    S0TBUF = buffer;
}

// main :
void main()
{
    // activation interupts sur uC
    SET_SFRBIT(IEN);

    //serial :
    S0CON = 0xA011;
    S0RIC = 0x4C;
    S0BG = 21;
    SET_SFRBIT(DP3.10); // emission, broche en sortie
    CLR_SFRBIT(DP3.11); // reception, broche en entree

// loop
    while(1) {}
}
