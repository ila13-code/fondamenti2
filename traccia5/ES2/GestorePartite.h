#ifndef GestorePartite_h
#define GestorePartite_h
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include "Partita.h"
using namespace std;

class GestorePartite
{
    private:
        list<Partita*> partite;
    public:
        GestorePartite() {}
        void aggiungiPartita(string squadraCasa, string squadraOspite, int golCasa, int golOspite)
        {
            Partita miaP(squadraCasa, squadraOspite, golCasa, golOspite);
            partite.push_back(&miaP);
        }
        string getSquadraPiuForte()
        {
            int golMax=0;
            string SquadraForte="";
            vector<string> Squadre;
            list<Partita*>::const_iterator it;
            for(it=partite.begin(); it!=partite.end(); it++)
            {
                if(!(find(Squadre.begin(), Squadre.end(), (*it)->getNomeCasa())!=Squadre.end()))
                    Squadre.push_back((*it)->getNomeCasa());
                else if(!(find(Squadre.begin(), Squadre.end(), (*it)->getNomeOspite())!=Squadre.end()))
                    Squadre.push_back((*it)->getNomeOspite());
            }

            int max=0, corr=0;
            string SquadraForte="";
            for(int k=0; k<=Squadre.size()-1; k++)
            {
                list<Partita*>::const_iterator it;
                for(it=partite.begin(); it!=partite.end(); it++)
                {
                    if(Squadre[k]==(*it)->getNomeCasa())
                        corr+=(*it)->getGolCasa();
                    else if(Squadre[k]==(*it)->getNomeOspite())
                        corr+=(*it)->getGolOspite();
                }

                if(corr>max)
                {
                    max=corr;
                    SquadraForte=Squadre[k];
                }
            }
            return SquadraForte;
        }

        double MediaGol() const
        {
            int somma=0;
            list<Partita*>::const_iterator it;
            for(it=partite.begin(); it!=partite.end(); it++)
            {
                somma+=(*it)->getGolCasa();
                somma+=(*it)->getGolOspite();
            }
            return somma/partite.size();
        }
};
#endif
