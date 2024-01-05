#ifndef Partita_h
#define Partita_h
#include <iostream>
#include <string>
using namespace std;

class Partita
{
    private:
        string squadraOspite, squadraCasa;
        int golOspite, golCasa;
    public:
        Partita() 
        {
            squadraOspite="";
            squadraCasa="";
            golOspite=0;
            golCasa=0;
        }
        Partita(string C, string O, int gc, int go) 
        {
            squadraOspite=O;
            squadraCasa=C;
            golOspite=go;
            golCasa=gc;
        }
        Partita(const Partita &p) //copia profonda 
        {
            squadraOspite=p.squadraOspite;
            squadraCasa=p.squadraCasa;
            golCasa=p.golCasa;
            golOspite=p.golOspite;

        }
        Partita &operator = (const Partita &p) //copia superficiale
        {
            squadraOspite=p.squadraOspite;
            squadraCasa=p.squadraCasa;
            golCasa=p.golCasa;
            golOspite=p.golOspite;
            return *this;
        }
        string getNomeCasa() {return squadraCasa;}
        string getNomeOspite() {return squadraOspite;}
        int getGolCasa() {return golCasa;}
        int getGolOspite() {return golOspite;}
        void setNomeCasa(string C) {squadraCasa=C;}
        void setNomeOspite(string O) {squadraOspite=O;}
        void setGolCasa(int C) {golCasa=C;}
        void setGolOspite(int O) {golOspite=O;}
};
#endif