#include <iostream>
using namespace std;

string esercizio3(const GrafoPesato &g, int k1, int k2)
{
    bool PrimaCond=true;
    for(int i=0; i<=g.n()-1; i++)
    {
        for(int j=0; j<=g.n()-1 && PrimaCond; j++)
            if(g(i,j) && (g.transfer(i,j)<k1 || g.transfer(i,j)>k2)) //se l'arco (i,j) esiste e il valore del transfer è minore di k1 o maggiore di k2
                PrimaCond=false;
    }

    bool SecondaCond=true;
    int numArchiEntranti=0, nodoInAnalisi, sommaTransferEntrata=0, sommaTransferUscita=0;
    for(int i=0; i<=g.n()-1 && SecondaCond; i++)
    {
        nodoInAnalisi=i;
        numArchiEntranti=0;
        sommaTransferEntrata=0;
        sommaTransferUscita=0;
        for(int j=0; j<=g.n()-1; j++)
        {
            if(g(j, nodoInAnalisi)) //se esiste l'arco da j al nodo che sto analizzando (quindi entra in nodoInAnalisi)
            {
                numArchiEntranti++; //aumento il contatore degli archi entranti nel nodo in analisi di uno
                sommaTransferEntrata+=g.transfer(j, nodoInAnalisi); //aggiungo il transfer di entrata
            }
            if(g(nodoInAnalisi, j)) //se esiste l'arco in uscita dal nodoInAnalisi
                sommaTransferUscita+=g.transfer(nodoInAnalisi, j);
        }
        //alla fine del for interno avrò il numero di archi entranti nel nodo in analisi (i), e le somme dei transfer in uscita
        //e in entrata dal nodoInAnalisi
        if(numArchiEntranti%2==0) //se il numero di archi entranti è pari
            //la somma dei transfer entranti non può essere maggiore di quella dei transfer uscenti
            if(sommaTransferEntrata>sommaTransferUscita)
                SecondaCond=false;
        else 
            //la somma dei transfer entranti non può essere minore di quella dei transfer uscenti
            if(sommaTransferEntrata<sommaTransferUscita)
                SecondaCond=false;
    }

    if(PrimaCond&&SecondaCond)
        return "SI";
    else
        return "NO";
}