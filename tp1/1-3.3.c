#include<c167.h>
#include<gnutrap.h>

// interupts:
TRAP(0x2B,readSer);
TRAP(0x47,writeSer);

// vars :
char buffer = 0;


// fct :
void readSer()
{
    buffer = S0RBUF;

    if( buffer<0 || buffer>15 ) // verif brocche analog choisie
        ADCON = 0x0;
    else
        ADCON = 0x0 + buffer;
}

void writeSer()
{
    S0TBUF = buffer;
}

// emission sans interuption
void writeTestSer()
{
    S0TBUF = buffer;
    CLR_SFRBIT(P3.10); // emission start
    WAIT_UNTIL_BIT_SET(S0TIR);
    SET_SFRBIT(P3.10); // emission etat repos
}


// main :
void main()
{
// init registres
    // activation interupts sur uC
    SET_SFRBIT(IEN);

    ADCON = 0; // mesure

    //serial :
    S0CON = 0xA011;
    S0RIC = 0x4C;
    S0TBIC = 0x44;
    S0BG = 21;
    SET_SFRBIT(DP3.10); // emission, broche en sortie
    CLR_SFRBIT(DP3.11); // reception, broche en entree

// loop
    while(1)
    {
        CLR_SFRBIT(ADCIR);
        SET_SFRBIT(ADST);
        WAIT_UNTIL_BIT_SET(ADCIR);
        writeTestSer();
        buffer = (ADDAT & 0x3FF) / 21;
    }
}
