#include <iostream>
#include <math.h>

using namespace std;

int main (){

int N, bit, base;
int numero = 0;
int potenza = 2;
   

 cout << "inserisci il numero di bit " << endl;
    cin >> N;
 	 base=10;   
    while (potenza < N){
    cout << "inserisci numero binario partendo dalla cifra meno significativa " << endl;
    cin >> bit;
	numero = numero + ((base^potenza)*bit);
    potenza++;
    }
    cout << " il numero convertito e' : " << numero << endl;
    
system("pause");
}

