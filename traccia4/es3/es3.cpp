#include <iostream>
#include "GrafoNonOrientato.h"
using namespace std;


int main()
{ 
    /*nella classe GrafoNonOrientato assumo che ci sia una funzione che mi permette di inserire un arco e di eliminarlo
    (se b=true inserisco, se b=false elimino)
    DEL TIPO:
                void operator() (int i, int j, bool b)
                {
                    assert(i>=0 && i<=this->n()-1 && j>=0 && j<=this->n);
                    bool esisteArco=this->archi[i][j]; ...controllo se l'arco esiste già
                    if(!esisteArco && b) //se l'arco non esiste e l'utente mi chiede di aggiungerlo lo aggiungo
                    {
                        this->archi[i][j]=true;
                        this->archi[j][i]=true; ...da entrambi i lati perchè il grafo non è orientato
                        numArchi++; //variabile private che tiene traccia del numero di archi nel grafo
                    }
                    else if(esistearco && !b) //se l'arco esiste e l'utente mi chiede di eliminarlo lo elimino
                    {
                        this->archi[i][j]=false;
                        this->archi[j][i]=false;
                        numArchi--;
                    }
                }
    */

    //INPUT DEL GRAFO
    int numNodi;
    cout<<"INSERISCI IL NUMERO DI NODI DEL TUO GRAFO: ";
    cin>>numNodi;
    bool b;
    GrafoNonOrientato g(numNodi);
    for(int k=0; k<=g.n()-1; k++)
        for(int k1=0; k1<=g.n()-1; k1++)
        {

            cout<<"VUOI AGGIUNGERE UN ARCO DAL NODO "<<k+1<<" AL NODO "<<k1+1<<"? (inserisci 1 per aggiungerlo, 0 altrimenti): ";
            cin>>b;
            g(k, k1, b);
        }

    //OPPURE
    /*
    int numNodi, numArchi, i, j;
    cout<<"INSERISCI IL NUMERO DI NODI DEL TUO GRAFO: ";
    cin>>numNodi;
    cout<<"\nQUANTI ARCHI VUOI AGGIUNGERE? ";
    cin>>numArchi;
    cout<<"\nINSERISCI GLI ARCHI:\n";
    for(int k=0; k<=numArchi-1; k++)
    {
        cout<<"NODO I: ";
        cin>>i;
        cout<<"\nNODO J: ";
        cin>>j;
        g(i, j, true);
        cout<<"\nHAI INSERITO CORRETTAMENTE L'ARCO ("<<i<<", "<<j<<").\n";
    }
    */

    vector<int> NodiAdiacenti;
    int somma, media;
    vector<int> Stati;
    //Cerco i nodi adiacenti
    for(int k=0; k<=numNodi-1; k++)
    {
        int NodoInAnalisi=k;
        somma=0;
        media=0;
        for(int k1=0; k1<=numNodi-1; k1++)
        {
            if(g(NodoInAnalisi, k1))
                NodiAdiacenti.push_back(k1);
        }
        //alla fine del for interno avrò i nodi adiacenti al nodo in analisi all'interno del vettore NodiAdiacenti..
        for(int i=0; i<=NodiAdiacenti.size()-1; i++)
            somma+=g.pot(NodiAdiacenti[i]);
        //alla fine di questo for avrò la somma di tutti i potenziali dei nodi adiacenti al nodo in analisi
        media=somma/NodiAdiacenti.size(); //media dei nodi adiacenti
        if(g.pot(NodoInAnalisi)>media)
            Stati.push_back(1);
        else
            Stati.push_back(0);
    }
    //alla fine del for in Stati avrò tutti gli stati dei nodi

    int max=0;
    for(int k=0; k<=Stati.size()-1; k++)
    {
        if(Stati[k]==1 && max<g.pot(k))
            max=k;
    }

    cout<<max;
}