#ifndef Grafo_h
#define Grafo_h
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Grafo
{
    private:
        vector<vector<bool>>  A; //matrice di adiacenza del grafo.. (1 se esiste l'arco da i a j, 0 altrimenti)
        int miaN;
        int miaM;
    public:
        Grafo(int n)
        {
            for(int i=0; i<=n-1; i++)
            {
                vector<bool> v;
                for(int j=0; j<=n-1; j++)
                    v.push_back(false);
                A.push_back(v);
            }
                    
            miaN=n;
            miaM=0;
        }
        bool operator() (int i, int j) const
        {
            assert(i>=0 && i<=this->miaN-1 && j>=0 && j<=this->miaN-1);
            return this->A[i][j];
        }
        void operator() (int i, int j, bool b) //per inserire o eliminare un arco
        {
            bool EsisteArco=A[i][j];
            if((!EsisteArco && b) || (EsisteArco && !b))
            {
                A[i][j]=b;
                if(b)
                    miaM++;
                else
                    miaM--;
            }
        }
        int n() const
        {return miaN;}
        int m() const
        {return miaM;}
        void setN(int N) {miaN=N;}
        void setM(int M) {miaM=M;}
};
#endif