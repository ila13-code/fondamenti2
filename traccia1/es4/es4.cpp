#include <iostream>
#include "Grafo.h"
#include <vector>
#include <functional>
using namespace std;

struct btSoluzione
{
    int k1, k2;
    Grafo mioG;
    vector<int> sol;
};

void add(int x, btSoluzione &bt)
{
    bt.sol.push_back(x);
}

bool isComplete(const btSoluzione &bt)
{
    return(bt.sol.size()>=bt.k1 && bt.sol.size()<=bt.k2);
}

void remove(btSoluzione &bt)
{
    bt.sol.pop_back();
}

bool canAdd(int x, const btSoluzione &bt)
{
    //in U entrano i nodi per cui ogni arco (i,j), ha il nodo i in U, e il nodo j non in U e viceversa
    for(int j=0; j<=bt.mioG.n()-1; j++)
        if(bt.mioG(x,j) && !(find(bt.sol.begin(), bt.sol.end(), j)!=bt.sol.end()))
            return true;
    return false;
}

bool solve(btSoluzione &bt)
{
    int x=0; //DOMINIO: tutti i nodi del grafo
    while(x<=bt.mioG.n()-1)
    {
        if(canAdd(x, bt))
        {
            add(x, bt);
            if(isComplete(bt))
                return true;
            else if(solve(bt))
                return true;
            remove(bt);
            x++;
        }
        else
            x++;
    }
    return false;
}