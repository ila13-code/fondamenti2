#include "Grafo.h"
#include <vector>
#include <iostream>
using namespace std;

/*
Aggiungo nella classe grafo la ridefinizione dell'operatore () in modo da poter inserire o eliminare archi da quest'ultimo

void operator() (int i, int j, bool b) //se b=true sto inserendo, se b=false sto eliminando
{
    assert(i>=0 && i<=this->n()-1; && j>=0 && j<=this->n()-1); //controllo se i e j sono dei nodi ammissibili
    bool ArcoPresente=this->(i, j); //controllo se l'arco è già presente
    if(!ArcoPresente && b)
    {
        this->archi[i][j]=true;
        numArchi++;
    }
    else if(ArcoPresente && !b)
    {
        this->archi[i][j]=false;
        numArchi--;
    }
}

//Aggiungo la ridefinizione dell'operatore () che mi dice se esiste o meno l'arco (i,j)

bool operator() (int i, int j)
{
    assert(i>=0 && i<=this->n()-1 && j>=0 && j<=this->n()-1);
    if(this->archi[i][j])
        return true;
    else
        return false;
}
*/

bool esercizio3()
{
    //input del grafo
    int numNodi, numArchi, p1, p2;
    cout<<"INSERISCI IL NUMERO DI NODI: ";
    cin>>numNodi;
    Grafo mioG(numNodi);
    cout<<"\nINSERISCI IL NUMERO DI ARCHI: ";
    cin>>numArchi;
    cout<<"\nINSERISCI GLI ARCHI:";
    for(int k=0; k<=numArchi-1; k++)
    {
        cout<<"\nNODO DI PARTENZA: ";
        cin>>p1;
        cout<<"\nNODO DI ARRIVO: ";
        cin>>p2;
        mioG(p1, p2, true);
    }


    int NodoInAnalisi=0, somma=0;
    bool PrimaCond=true;
    for(int k=0; k<=numNodi-1 && PrimaCond; k++)
    {
        NodoInAnalisi=k;
        somma=0;
        for(int k1=0; k1<=numNodi-1; k1++)
            somma+=(int)mioG(k1, NodoInAnalisi); //mioG(i, j) restituisce il peso dell'arco tra i e j (se esiste)            
        if(somma>mioG.dep(NodoInAnalisi))
            PrimaCond=false;
    }

    bool SecondaCond=true;
    for(int k=0; k<=numNodi-1; k++)
    {
        NodoInAnalisi=k;
        for(int k1=0; k1<=numNodi-1 && SecondaCond; k1++)
            if(mioG(k1, NodoInAnalisi)!=0) //se esiste l'arco k1, k
                if(mioG.dep(k1)<mioG.dep(NodoInAnalisi))
                    SecondaCond=false;
    }

    if(SecondaCond && PrimaCond)
        return true;
    else
        return false;
}