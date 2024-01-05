#ifndef Studente_h
#define Studente_h
#include <iostream>
#include "Persona.h"
using namespace std;

class Studente:public Persona
{
    public:
        Studente(string n, string c):Persona(n, c) {}
        int getStipendio() const {return 10;}
};
#endif 