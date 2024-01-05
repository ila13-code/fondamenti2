#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <functional>

using namespace std;

struct btSoluzione
{
    vector<string> S;
    vector<vector<string>> L;
    int q;
    vector<string> solP;
    vector<int> Uguali; //va inizializzato a 0 nel main; la grandezza è L.size();
    
};

void add(string miaX, btSoluzione &bt)
{
    bt.solP.push_back(miaX);
}

bool isComplete(const btSoluzione &bt)
{
    return (bt.solP.size()>=bt.q);
}

void remove(btSoluzione &bt)
{
    bt.solP.pop_back(); //devo semplicemente rimuovere l'ultimo inserito
}

bool Presente(string x, vector<string> v)
{
    return(find(v.begin(), v.end(), x)!=v.end());
}

bool canAdd(string miaX, btSoluzione &bt)
{
    if(Presente(miaX, bt.solP))
        return false;
    else
    {
        int ug=0;
        for(int k=0; k<=bt.L.size()-1; k++)
        {
            for(int k1=0; k1<=bt.L[k].size()-1; k1++)
            {
                if(bt.L[k][k1]==miaX)
                    ug++;
            }
            bt.Uguali[k]+=ug;
            ug=0;
        }
        for(int k=0; k<=bt.Uguali.size()-1; k++)
            if(bt.Uguali[k]==bt.L[k].size())
                return false;
        return true;
    }
}

bool esercizio4(btSoluzione &bt)
{
    //dominio di applicazione: tutte le string contenute in S, x va da 0 a bt.S.size()-1;
    int x=0;
    while(x<=bt.S.size()-1)
    {
        if(canAdd(bt.S[x], bt)) //canAdd riceve una stringa (quella da aggiungere) e l'oggetto bt; posso aggiungere se in L non c'è una lista che contiene tutte le string di sol
        {
            add(bt.S[x], bt);
            if(isComplete(bt)) //la soluzione è completa se contiene almeno q stringhe
                return true;
            else if(esercizio4(bt))
                return true;
            remove(bt); //se non completo la soluzione con questa x e questa non mi va bene la rimuovo
            x++; //aggiungo uno a x (pos in bt.S)
        }
        else
            x++;
    }
    return false; //se esco dal while e ancora non ho una soluzione, quest'ultima non esiste
}

int main()
{
    btSoluzione mioBt;
    mioBt.S.push_back("a");
    mioBt.S.push_back("b");
    mioBt.S.push_back("c");
    mioBt.S.push_back("d");
    mioBt.S.push_back("e");
    mioBt.S.push_back("f");
    vector<string> A{"a", "b", "c"};
    vector<string> B{"a", "d"};
    vector<string> C{"d", "e"};
    vector<string> D{"b", "f"};
    mioBt.L.push_back(A);
    mioBt.L.push_back(B);
    mioBt.L.push_back(C);
    mioBt.L.push_back(D);
    mioBt.q=3;
    mioBt.Uguali.push_back(0);
    mioBt.Uguali.push_back(0);
    mioBt.Uguali.push_back(0);
    mioBt.Uguali.push_back(0);
    cout<<esercizio4(mioBt)<<endl;
}