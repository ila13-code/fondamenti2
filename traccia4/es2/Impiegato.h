#ifndef Impiegato_h
#define Impiegato_h
#include <iostream>
#include "Persona.h"
using namespace std;

class Impiegato:public Persona
{
    public:
        Impiegato(string n, string c):Persona(n, c) {}
        int getStipendio() const {return 100;}
};
#endif