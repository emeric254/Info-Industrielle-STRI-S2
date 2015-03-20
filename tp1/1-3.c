#include<c167.h>
#include<gnutrap.h>

// interupts:
TRAP(0x2B,readTestSer);

// vars :
int mesure;
char buffer = 'a';

// fct :
void readTestSer()
{
    buffer = S0RBUF;
}

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
    // activation interupts sur uC
    SET_SFRBIT(IEN);

    // init registres
    ADCON = 5;
    S0CON = 0xA011;
    S0RIC = 0x4C;
    S0BG = 21;

    SET_SFRBIT(DP3.10); // emission
    SET_SFRBIT(P3.10); // emission etat repos

    CLR_SFRBIT(DP3.11); // reception
    CLR_SFRBIT(P3.11); // reception etat repos

    while(1)
    {
        writeTestSer();
    }
}
