#include <iostream>
using namespace std;

int main()
{
    int voti[6]={2, 3, 0, 5, 6, 9};
    //cout<<*voti[0]<<endl; //NON CORRETTA; voti è un vettore di int, non ho bisogno del puntatore
    cout<<voti[0]+*(voti+2)<<endl; //2
    double s=0;
    for(int i=0; i<6; i++)
        s+=*(voti+i);
    if(s/6>20)
        cout<<"OK\n"; //no perchè s alla fine del for sarà uguale a 25; 25/6=4
    else
        cout<<"NO\n";
    int a = voti[1];
    --a;
    cout<<voti[1]; //3
}