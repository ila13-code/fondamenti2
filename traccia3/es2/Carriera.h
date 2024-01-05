#ifndef Carriera_h
#define Carriera_h
#include <iostream>
#include <string>
using namespace std;

class Carriera
{
    private:
        int numAppelli;
        bool *esiti=new bool[100];
        string *nomiEsami=new string[100];
    public:
        Carriera() //costruttore di default
        {
            numAppelli=0;
        }
        Carriera(const Carriera &c) //costruttore di copia
        {
            this->numAppelli=c.numAppelli;
            for(int k=0; k<=100-1; k++)
            {
                this->esiti[k]=c.esiti[k];
                this->nomiEsami[k]=c.nomiEsami[k];
            }
        }
        int Num() {return numAppelli;}
        ~Carriera() //distruttore
        {
            delete []esiti;
            delete []nomiEsami;
        }
        bool operator == (Carriera &c) //operatore di uguaglianza
        {
            if(this->numAppelli==c.numAppelli)
            {
                for(int k=0; k<=99; k++)
                    if(this->esiti[k]!=c.esiti[k] || this->nomiEsami[k]!=c.nomiEsami[k])
                        return false;               
            }
            return true;
        }
        Carriera operator = (Carriera &c) //operatore di assegnamento
        {
            this->numAppelli=c.numAppelli;
            for(int k=0; k<=100-1; k++)
            {
                this->esiti[k]=c.esiti[k];
                this->nomiEsami[k]=c.nomiEsami[k];
            }
            return *this;
        }
        void AggiungiTentativo(string nome, bool esito)
        {

            esiti[numAppelli]=esito;
            nomiEsami[numAppelli]=nome;
            numAppelli++;
        }
        void RimuoviTentativo() //rimuove l'ultimo tentativo
        {

            numAppelli--;
        }
        bool StudenteDiligente()
        {
            int Pos=0, Neg=0;
            for(int k=0; k<=numAppelli-1; k++)
                if(*(esiti+k)==true)
                    Pos++;
                else
                    Neg++;
            if(Pos>=Neg)
                return true;
            else
                return false;
        }

};
#endif
