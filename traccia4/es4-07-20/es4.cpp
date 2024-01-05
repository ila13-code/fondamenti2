#include <iostream>
#include <string>
#include <vector>
using namespace std;

int val(string s)
{
    //restituisce un int per ogni stringa che riceve
}

struct btSoluzione
{
    vector<string> S;
    vector<string> sol1;
    vector<string> sol2;
};

void add(string miaX, vector<string> &s)
{
    s.push_back(miaX);
}

bool isComplete(const btSoluzione &bt)
{
    int valSol1=0;
    int valSol2=0;
    for(int k=0; k<=bt.sol1.size()-1; k++)
        valSol1+=val(bt.sol1[k]);
    for(int k=0; k<=bt.sol2.size()-1; k++)
        valSol2+=val(bt.sol2[k]);
    return((bt.sol1.size()+bt.sol2.size())==bt.S.size() && valSol1==valSol2); //la soluzione è completa quando tutte le stringhe in s sono state separate in s1 ed s2
}

void remove(vector<string> &v)
{
    v.pop_back();
}

int canAdd(string miaX, const btSoluzione &bt) //posso aggiungere in sol1 se val(tutte le stringhe in sol1)+val(miaX) non sforano val(sol2); 
//viceversa aggiungo in sol2 se ho in val(sol1) un valore minore;
{
    int valSol1=0;
    int valSol2=0;
    for(int k=0; k<=bt.sol1.size()-1; k++)
        valSol1+=val(bt.sol1[k]);
    for(int k=0; k<=bt.sol2.size()-1; k++)
        valSol2+=val(bt.sol2[k]);
    if(valSol1>=valSol2)
        return 2;
    else if(valSol2>=valSol1)
        return 1;
    else return 0;
}

bool solve(btSoluzione &bt)
{
    int x=0; //dominio delle soluzioni: tutte le stringhe contenute nel vettore S, x tiene conto della posizione nel vettore..
    while(x<=bt.S.size()-1)
    {
        int Ris=canAdd(bt.S[x], bt);
        if(Ris!=0) //canAdd restituisce 0 se non posso aggiungere, 1 se posso farlo in sol1, 2 se posso farlo in sol2..
        {
            if(Ris==1)
                add(bt.S[x], bt.sol1);
            else if(Ris==2)
                add(bt.S[x], bt.sol2);
            if(isComplete(bt))
                return true;
            else if(solve(bt))
                return true;
            if(Ris==1)
                remove(bt.sol1);
            else if(Ris==2)
                remove(bt.sol2);
            x++;
        }
        x++;
    }
    return false;
}