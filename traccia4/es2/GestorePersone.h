#ifndef GestorePersone_h
#define GestorePersone_h
#include "Persona.h"
#include "Studente.h"
#include "Impiegato.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class GestorePersone
{
    private:
        vector<Persona*> persone;
    public:
        GestorePersone() {}
        void AggiungiPersona(Persona *p)
        {
            persone.push_back(p);
        }
        double getStipendioMedio() const
        {
            int somma=0;
            for(int k=0; k<=persone.size()-1; k++)
                somma+=persone[k]->getStipendio();
            return somma/persone.size();
        }
};
#endif