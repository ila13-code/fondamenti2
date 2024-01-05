#include <iostream>
using namespace std;

void func(char& a, char b)
{    
    char c = a;    a = b;     b = c;
} 

int main()
{     
    char *nome = new char[3]{'i', 'l', 'a'}; //{..i primi tre caratteri diversi del tuo nome..};   
    //1. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(nome[1]) << endl;  //NO 
    //2. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(nome + 2) << endl;       //SI STAMPA a
    //3. La seguente istruzione è corretta? Se sì, cosa stampa? 
    char *a = &nome[2];
    cout << *(a - 1) << endl;   //SI STAMPA l
    //4. Cosa viene stampato dalla seguente porzione di codice?      
    char* nome_prof = new char[3]{'m','a','t'};
    func (nome_prof[0], nome_prof[1]);
    cout << nome_prof[0] << " " << nome_prof[1] << endl; //SI STAMPA a a
} 