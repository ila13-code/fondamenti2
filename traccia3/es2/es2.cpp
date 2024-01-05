#include "Carriera.h"
#include <iostream>
using namespace std;

int main()
{
    Carriera miaC;
    miaC.AggiungiTentativo("Analisi", true);
    miaC.AggiungiTentativo("Fondamenti", false);
    miaC.AggiungiTentativo("Fisica", false);
    cout<<miaC.StudenteDiligente()<<endl;
    Carriera miaC2(miaC);
    cout<<miaC.Num();
    cout<<miaC2.Num();
}