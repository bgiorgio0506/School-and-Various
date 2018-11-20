#include <iostream>
using namespace std;

void CONTA_PARI(int m,int& p,int& c,int& contp){
	int i,n;
	c=0;
	p=0;
	n=1;
	contp=0;
	for(i=1;i<=m;i++){
	cout<<"inserisci un numero"<<endl;
	cin>>n;
		if(n%2==0){
			p=n*n;
			c++;
		}
		else 
		contp++;
		i++;
	}
}
		
		
	

int main(){
	int m,pro,cont,contp;
	cout<<"Questo programma ti permette di calcolare il prodotto dei numeri pari"<<endl;
	do{
		cout<<"Inserisci quanti numeri vuoi inserire"<<endl;
		cin>>m;
		if (m<=0){
			cout<<"hai inserito un numero negativo"<<endl;
			continue;
			}
			else{
					break;
			} 
		
			}while(m>0);
			CONTA_PARI(m,pro,cont,contp);
			cout<<"il prodotto e'"<<pro<<"4 i numeri pari inseriti sono "<<cont<<" " <<contp<<endl;
			system("PAUSE");
}
