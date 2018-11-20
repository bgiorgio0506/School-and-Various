#include <iostream>
#include <stdlib.h> 
using namespace std;

int a, b, c;

void Ordina()
{
	if(a>b)
	{
	c=a;
	a=b;
	b=c;
	}
}
 

int main()
{
	cout<<"Inserisci il primo numero"<<endl;
	cin>>a;
	cout<<"Inserisci il secondo numero"<<endl;
	cin>>b;
	Ordina();
	cout<<"I numeri ordinati sono"<<a<<"e"<<b<<endl;
	
	system("PAUSE");
}
