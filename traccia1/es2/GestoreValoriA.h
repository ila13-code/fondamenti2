#ifndef GestoreValoriA_h
#define GestoreValoriA_h
#include "GestoreValori.h"
#include <iostream>
#include <vector>
using namespace std;

class GestoreValoriA:public GestoreValori
{
    public: 
        int getRisultato()
        {
            int somma=0;
            for(int k=0; k<=miaSeq.size()-1; k++)
            {
                if(miaSeq[k].second=='a')
                    somma+=miaSeq[k].first;
            }
            return somma;
        }
};
#endif