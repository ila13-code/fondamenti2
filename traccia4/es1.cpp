#include<iostream>
#include <string>
using namespace std;

int main()
{
    string* nc = new string[2]{"Ilaria", "Frandina"}; //nc è una lista di puntatori a stringhe
    //1: La seguente istruzione è corretta? Se sì, cosa stampa? 
    cout << nc[0][2]<<endl; //SI, stampa "a"
    //2: La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(nc + 1)<<endl; //stampa "Frandina"
    //3: La seguente porzione di codice è corretta? Se sì, cosa fa?
    for (int i = 0; i < nc[0].length();i++) //i va da 0 a 6 (length è 7)
        cout << nc[0][nc[0].length() -1 -i]; //stampa airalI
    //4: Come andrebbe deallocata la memoria dinamica allocata in questo main?
    //A: delete nc[2]; B: delete nc; C: delete [] nc; D: nel main non serve il distruttore. //C
}