#include <iostream>
using namespace std;

int main()
{
    int *matricola=new int[6]{2, 3, 0, 5, 10, 9};
    cout << *(matricola + 3) << *(matricola + 2) << endl; //50
    //cout << *(matricola[0])  << endl; //no
    int &a=matricola[4];
    int b=matricola[5];
    --a;
    b+=1;
    cout<<matricola[4]<<" "<<matricola[5]<<endl; //5 9
    //delete[] matricola;
    return 0;
}