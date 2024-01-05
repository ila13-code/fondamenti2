#ifndef Persona_h
#define Persona_h
#include <iostream>
#include <string>
using namespace std;

class Persona
{
    private:
        string nome, cognome;
    public:
        Persona() {nome=""; cognome="";}
        Persona(string n, string c) {nome=n; cognome=c;}
        void setNome(string n) {nome=n;}
        void setCognome(string c) {cognome=c;}
        string getNome() const {return nome;}
        string getCognome() const {return cognome;}
        virtual int getStipendio() const=0; //metodo costante virtuale puro -> Persona è una classe astratta, non è possibile define oggetti di tipo persona
};
#endif