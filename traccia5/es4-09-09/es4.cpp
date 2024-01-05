#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

struct btSoluzione 
{
    vector<string> V;
    vector<vector<string>> T;
    int k;
    vector<string> solW;
};

void add(string x, btSoluzione &bt)
{
    bt.solW.push_back(x);
}

bool isComplete(const btSoluzione &bt)
{
    return(bt.k>=bt.solW.size());
}

bool remove(btSoluzione &bt)
{
    bt.solW.pop_back();
}

bool canAdd(string miaX, const btSoluzione &bt)
{
    if(bt.solW.size()>=1)
        for(int i=0; i<=bt.solW.size()-1; i++)
        { 
            for(int k=0; k<=bt.T.size()-1; k++)
                if(find(bt.T[k].begin(), bt.T[k].end(), bt.solW[i])!=bt.T[k].end() && find(bt.T[k].begin(), bt.T[k].end(), miaX)!=bt.T[k].end())
                        return false;
            return true;
        }
    else
        return true;
}

bool solve(btSoluzione &bt)
{
    int x=0; //DOMINIO: tutti gli elementi di V, x salva la posizione va da 0 a V.size()-1..
    while(x<=bt.V.size()-1)
    {
        if(canAdd(bt.V[x], bt))
        {
            add(bt.V[x], bt);
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