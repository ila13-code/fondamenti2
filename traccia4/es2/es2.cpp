#include "GestorePersone.h"
#include "Impiegato.h"
#include "Studente.h"
#include <iostream>
using namespace std;

int main()
{
    Impiegato P1("ciao", "ciao");
    Impiegato P2("d", "d");
    Studente S1("s", "S");
    GestorePersone Miog;
    Miog.AggiungiPersona(&P1);
    Miog.AggiungiPersona(&P2);
    Miog.AggiungiPersona(&S1);
    cout<<Miog.getStipendioMedio();
}