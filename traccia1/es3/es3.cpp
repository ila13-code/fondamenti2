#include "Grafo.h"
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

bool TrovaCammino(const Grafo &g, int s, int t, vector<bool> visitati) //restituisce un vector in cui c'è il cammino da s a t 
//e un bool che mi dice se ho trovato il cammino dal nodo s al nodo t; USO VISITA DFS 
{
    if(s==t)
    {
        visitati[t]=true;
        return true;
    }
    else
    {
        visitati[s]=true;
        bool trovato=false;
        for(int j=0; j<=g.n()-1; j++)
            if(s!=j && g(s,j) && !visitati[j])
                trovato=TrovaCammino(g, j, t, visitati);
        return trovato;
    }
}

int main()
{
    int n;
    cout<<"Inserisci il numero di nodi: ";
    cin>>n;
    Grafo mioG(n);

    bool v;
    for(int i=0; i<=n-1; i++)
        for(int j=0; j<=n-1; j++)
        {
            cout<<"ARCO DA NODO "<<i+1<<" A NODO "<<j+1<<"; (se esiste inserisci 1, 0 altrimenti): ";
            cin>>v;
            if(v==0 || v==1)
                mioG(i, j, v);
            else
                cout<<"PROBLEMI NELL'INPUT, RIPROVA.";
        }
    
    vector<bool> visitati;
    bool Risultato;
    int sommaNodiRaggiunti=0;
    vector<int> NodiRaggiunti;
    for(int k=0; k<=n-1; k++)
    {
        for(int k1=0; k1<=n-1; k1++)
        {
            Risultato=TrovaCammino(mioG, k, k1, visitati);
            if(Risultato)
                sommaNodiRaggiunti++;
        }
        NodiRaggiunti.push_back(n-sommaNodiRaggiunti);
        sommaNodiRaggiunti=0;
    }
    
    int max=NodiRaggiunti[0];
    int pos=0;
    for(int k=1; k<=NodiRaggiunti.size()-1; k++)
    {
        if(max<NodiRaggiunti[k])
        {
            max=NodiRaggiunti[k];
            pos=k;
        }
    }
    
    cout<<"NODO RAGGIUNTO DA MENO NODI: "<<pos;

    return 0;
}