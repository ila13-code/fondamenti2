#include "GestoreValori.h"
#include "GestoreValoriA.h"
#include "GestoreValoriB.h"
#include <iostream>
using namespace std;

int main()
{
    GestoreValori mioGest;
    GestoreValoriA gA;
    GestoreValoriB gB;
    mioGest.inserisciCoppia(1, 'a');
    mioGest.inserisciCoppia(4, 'a');
    mioGest.inserisciCoppia(5, 'b');
    mioGest.inserisciCoppia(1, 'g');
    gA.inserisciCoppia(1, 'a');
    gA.inserisciCoppia(1, 'v');
    gB.inserisciCoppia(3, 'b');
    cout<<"NUMERO DI COPPIE ATTUALMENTE PRESENTI IN ARCHIVIO: "<<mioGest.numCoppie()<<endl;
    cout<<"RISULTATO TOTALE: "<<mioGest.getRisultato()<<endl;
    cout<<"RISULTATO A: "<<gA.getRisultato()<<endl;
    cout<<"RISULTATO B: "<<gB.getRisultato()<<endl;
    return 0;

}