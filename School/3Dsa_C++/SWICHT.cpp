#include <iostream>// libraries for input and out put 
#define MAX 100 //decleretion of a constat vai define 
// -------END OF PREPROCESSORS OPERETION ----------
using namespace std; //(*)optional to avoid std::cout/cin


//prototype
int chiedi_dimensione();
void carica(int v[], int n);
int ricerca_sequenziale1(int v[], int e, int n,int &pos);
int ricerca_sequenziale2(int v[], int e, int n,int &pos);
void stampa(int v[], int n);
void ordina(int v[], int n);
void contrario(int v[], int n);
void sostituisci(int v[], int n, int x, int y);
void elimina_duplicati(int v[], int &n);
void shift_sinistro(int v[], int &n, int pos);

//             ----END PROTYPES----
/*CODE SWICH HERE
*/















//starting functions 
int chiedi_dimensione()
{	
/*	---FUNCTION VARIABLES---
NOTE(this variable are only visible to the only fuction chiedi_dimensione())
*/
	int n;
	int tentativi=0;
do
{
		cout<<"\nInserisci la dimensione del vettore : ";
		cin>>n;
		if(n<1 || n>MAX)
				{
					cout<<"\nATTENZIONE! La dimensione del vettore non puo' essere inferiore a 1 o a "<<MAX<<endl;
					tentativi++;
					system("PAUSE");
					system("cls");
				}
			if(tentativi==10)
				{
					system("cls");
					cout<<"\n\nE' stato raggiunto il numero massimo di tentativi il programma assegnera' una dimensione valida!!!\n";
					n=7;
					system("pause");
					break;
				}			
	}while(n<1 || n>MAX);
	return n;	
}

void carica(int v[], int n)
{	
	//NOT(The counter used to charge the array is only visible in carica() otherwise you pass this  counter vai adress parameter)
	int i; 
	system("cls");
	cout<<"\n***CARICA VETTORE***\n";
	for(i=0;i<n; i++)
		{
			cout<<"\nInserisci il "<<i+1<<" elemento: ";
			cin>>v[i];
		}
}

int ricerca_sequenziale1(int v[], int ele, int n, int &pos)
	{
		/*NOTE(Be sure in the order that you pass the parameters otherwise will not find the element)
		NOTE(The bool variable is used to understand if the array is check)*/
		bool s=false;
		pos=1;
		cout<<"\n\t\t\t\t***RICERCA DELL'ELEMETO IN MODALITA' SEQUENZIALE DO...WHILE\n";
			do
				{
					if(v[pos]==ele)
						s=true;
					else
						pos++; 
				}while(pos<n&& s==false);
				return s;
	}

	int ricerca_sequenziale2(int v[], int ele, int n, int &pos)
	{
		/*NOTE(Be sure in the order that you pass the parameters otherwise will not finde the element)
		NOTE(The bool variable is used to understand if the array is check)*/
		bool s=false;
		pos=1;
		cout<<"\n\t\t\t\t***RICERCA DELL'ELEMETO MODALITA' CON CICLO FOR***\n";
		for(int i=0; i<n; i++)
				if(v[i]==ele)
					{
						s= true;
						pos=i;
						break;
					}
	return s;
	}
	
//Stampa Vettore
void stampa(int v[], int n)
	{
		for(int i=0;i<n; i++)
			{
				cout<<v[i];
				cout<<" ";
			}
		cout<<endl;
	}

void ordina(int v[], int n)
	{
		int box;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
			if(v[k]>v[j]){
				box=v[j];
				v[j]=v[k];
				v[k]=box;
				
			}
		}
	}
}
void contrario(int v[], int n)
{
		int box;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
			if(v[k]<v[j]){
				box=v[j];
				v[j]=v[k];
				v[k]=box;
				
			}
		}
	}
}
	
void sostituisci(int v[], int n, int x,int y)
	{
		bool replace=false;
		int nr=0; //NOTE(Counter for the number of sostitution only visible in fuction sostituisci())
		for(int i=0; i<n; i++)
		{
			if(v[i]==x)
			{
				v[i]=y;
				replace=true;
				nr++;
			}
		}
		if(replace)
		cout<<"\nSostituzione effettuata con successo! Sono state effettuate "<<nr<<"sostituzioni"<<endl;
		else
		cout<<"\nERRORE numero non trovato"<<endl;
	}
	
void shift_sinistro(int v[], int &n, int pos)
{
	for(int i=pos; i<n; i++)
		{	
		v[i]=v[i+1];
		}
		n--;
}
void elimina_duplicati(int v[], int &n)
	{
		cout<<"\n\n ***ELIMINA DUPLICATI\n";
		ordina(v,n);
		int i=1;
		do{
			if(v[i]== v[i-1]){
				shift_sinistro(v,n,i);
			}
			else i++;
		}while(i<n);
	}

