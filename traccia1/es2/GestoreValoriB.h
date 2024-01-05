#ifndef GestoreValoriB_h
#define GestoreValoriB_h
#include "GestoreValori.h"
#include <iostream>
#include <vector>
using namespace std;

class GestoreValoriB:public GestoreValori
{
    public: 
        int getRisultato()
        {
            int somma=0;
            for(int k=0; k<=miaSeq.size()-1; k++)
            {
                if(miaSeq[k].second=='b')
                    somma+=miaSeq[k].first;
            }
            return somma;
        }
};
#endif