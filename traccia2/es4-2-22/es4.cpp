#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <utility>
#include "Triple.h"
using namespace std;

struct btSoluzione
{
    vector<string> A;
    vector<Triple> C;
    int n=A.size();
    vector<int> sol;
};

int TrovaPosInA(string t, vector<string> a)
{
    for(int k=0; k<=a.size()-1; k++)
        if(a[k]==t)
            return k;
    return -1;
}

bool canAdd(int miaX, btSoluzione b)
{
    vector<int> solFittizia=b.sol;
    for(int k=0; k<=b.sol.size()-1; k++)
        solFittizia.push_back(0);
    int sz=b.sol.size(); //numeri assegnati fino ad ora
    for(int k=0; k<=sz-1; k++)
        if(b.sol[k]==miaX)
            return false;
        else
        {
            for(int k1=0; k1<=b.C.size()-1; k1++)
            {
                int PosX=TrovaPosInA(b.C[k1].x, b.A);
                int PosY=TrovaPosInA(b.C[k1].y, b.A);
                int PosZ=TrovaPosInA(b.C[k1].z, b.A);
                if(PosX!=-1 || PosY!=-1 || PosZ!=-1)
                {
                    if(b.sol.size()==PosX)
                        if(miaX<solFittizia[PosY]<solFittizia[PosZ] || solFittizia[PosZ]<solFittizia[PosY]<miaX)
                            return true;
                    else if(b.sol.size()==PosY)
                        if(solFittizia[PosX]<miaX<solFittizia[PosZ] || solFittizia[PosZ]<miaX<solFittizia[PosX])
                            return true;
                    else if(b.sol.size()==PosZ)
                        if(solFittizia[PosX]<solFittizia[PosY]<miaX || miaX<solFittizia[PosY]<solFittizia[PosX])
                            return true;
                }
                else
                    return false;
            }
        }
}

void add(int miaX, btSoluzione &bt)
{
    bt.sol.push_back(miaX);
}

bool isComplete(const btSoluzione &bt)
{
    return (bt.sol.size()==bt.A.size());
}

void remove(int miaX, btSoluzione &bt)
{
    bt.sol.pop_back();
}

bool esercizio4(btSoluzione bt)
{
    int x=1; //dominio della soluzione (primo valore)
    while(x<=bt.n)
    {
        if(canAdd(x, bt)) //se f(a)!=f(b) e (f(x)<f(y)<f(z) oppure f(z)<f(y)<f(x))
        {
            add(x, bt);
            if(isComplete(bt))
                return true;
            else if(esercizio4(bt))
                return true;
            remove(x, bt); 
            x++;
        }
        else
            x++;
    }
    return false;
}

int main()
{

}