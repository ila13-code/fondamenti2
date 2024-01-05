#ifndef GestoreValori_h
#define GestoreValori_h
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class GestoreValori
{
    protected:
        vector<pair<int, char>> miaSeq;
    public:
        void inserisciCoppia(int a, char b)
        {
            miaSeq.push_back(pair(a, b));
        }
        int numCoppie()
        {
            return miaSeq.size();
        }
        virtual int getRisultato()
        {
            return -1;
        }
};
#endif
