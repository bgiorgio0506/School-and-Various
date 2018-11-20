
#include "iostream"
#include "cmath"
#include"stdlib.h"
#define a_max 450
#define pigreco 3.14
using namespace std;

int main()
{
float T,m,val,f,A,w,v;
int i;
cout<<"Ciao questo programma risolve il compito di fisica del giorgno 22 novembre 2017"<<endl;
cout<<"Il testo del problema e'il seguente"<<endl;
cout<<"Attraverso un apparato di fotocellule riesci a rilevare che l'oggetto passa per la posizione di equilibrio ad intervalli regolari di 15ms.Quanto valela frequenza del moto?"<<endl;
cout<<"Da quali caratteristiche del sistema dipende tale valore? Come devi scegliere tali caratteristeche per ottenere il valore di frequenza del moto osservato?(fornisci almeno 3 esempi numerici)."<<endl;
cout<<"Sapendo che durante il moto in questione l'accelerazione massima è pari a 450ms^2,calcola l'ampiezza del moto e il modulo della velocita' massima dell'oggetto; inoltre, scrivi le tre leggi orarie del moto(posizione,velocità e accelerazione)";
cout<<"e rappresentale graficamente"<<endl;
cout<<"Inserisci il periodo T in ms: "<<endl;
cin>>T;
if(T<=0)
	cout<<"Periodo non valido";
else{
		T=2*T;
		T=T/1000;
		f=1/T;
		cout<<"La Frequenza e'"<<f<<"Hrz"<<endl;
}
cout<<"le cratteristiche del sistema sono"<<endl;
cout<<"1"<<" la massa del CARRELLO"<<endl;
cout<<"2"<<" la costante elastica della molla"<<endl;

		for(i=0;i<=3;i++)
		{
		cout<<"inserisci la massa per trovare i valori richiesti nella domanda Come devi scegliere tali caratteristeche per ottenere il valore di frequenza del moto osservato?(fornisci almeno 3 esempi numerici): ";
		cin>>m;
		if(m==0)
		cout<<"Inserisci una massa valida"<<endl;
		else
		{val=m/T;
		cout<<"Per m che e'uguale: "<<m<<" la costante elastica e': "<<val<<endl;		//ciclo for per la domanda 3 
		i++;
		}
		}
	
	cout<<"il programma da ora fara' quasi tutto da solo"<<endl;
	w=2*pigreco*f;
	A=sqrt(a_max/w);
	cout<<"L'ampiezza e'uguale a: "<<A<<endl;
	v=w*A;
	cout<<"la velocita' e'uguale a: "<<v<<endl;
	cout<<"Le leggi orarie sono"<<endl;
	cout<<"s(t)=A*sin(wt) "<<"v(t)=wA*cos(wt) "<<"a(t)=w^2A*sin(wt)"<<endl;
	cout<<"Hai finito il compito bravoooo!!!!!!!!!"<<endl;
	system("PAUSE");
	return 0;
}

