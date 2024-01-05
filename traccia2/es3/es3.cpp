#include <iostream>
#include "AlberoB.h"
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

void visitaLivelli(AlberoB<int> A, int x, vector<int> &nodi)
{
    if(A.nullo()) 
        return;
    else
    {
        queue<AlberoB<int>> miaCoda;
        miaCoda.push(A);
        int liv=1;
        nodi.push_back(liv);
        while(!miaCoda.empty())
        {
            AlberoB<int> temp=miaCoda.front();
            liv++;
            if((temp.figlio(DES).nullo() && (!temp.figlio(SIN).nullo()) || (!temp.figlio(DES).nullo()) && temp.figlio(SIN).nullo()))
                nodi.push_back(liv);
            if(!(temp.figlio(DES).nullo() && temp.figlio(SIN).nullo()))
            {
                nodi.push_back(liv);
                nodi.push_back(liv);
            }
            miaCoda.pop();          
            if(!temp.figlio(SIN).nullo())
                miaCoda.push(temp.figlio(SIN));
            if(!temp.figlio(DES).nullo())
                miaCoda.push(temp.figlio(DES));
        }
    }
}

int main()
{
    AlberoB<int> mioAB(5);
    AlberoB<int> ABSIN(6);
    ABSIN.insNodo(SIN, 10);
    mioAB.insFiglio(SIN, ABSIN);
    AlberoB<int> ABDES(12);
    ABDES.insNodo(SIN, 42);
    ABDES.insNodo(DES, 32);
    mioAB.insFiglio(DES, ABDES);
    cout<<mioAB.Nodofiglio(SIN)<<endl;
    cout<<mioAB.Nodofiglio(DES)<<endl;
    AlberoB<int> Bdes(mioAB.figlio(DES));
    cout<<Bdes.Nodofiglio(SIN)<<endl;
    cout<<Bdes.Nodofiglio(DES)<<endl;

    int x=0;
    cout<<"INSERISCI X: ";
    cin>>x;
    bool trv=false;
    vector<int> nodi;
    visitaLivelli(mioAB, x, nodi);


    for(int k=0; k<=nodi.size()-1; k++)
        cout<<nodi[k]<<endl;

}