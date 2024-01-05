#include <iostream>
using namespace std;

int main()
{
    int *matricola=new int[6] {2, 3, 0, 5, 6, 9}; //mi creo un vettore di puntatori a int grande 6
    cout << *(&matricola[4])<<endl; //stampa 6
    cout<<*(matricola+3)<<endl; //stampa 5
    int &second = matricola[1]; //second è un riferimento (ALIAS) per matricola[1] = 3
    matricola[1]++; //aggiorno matricola[1] e diventa = 4
    second++; //aggiorno second e diventa = 5
    cout<<second<<endl; //second=5
}