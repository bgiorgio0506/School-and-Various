#include <iostream>
#include <cmath>
#define pigreco 3,14
using namespace std;
 


int input;

 void input_system()
 {
 	int input;
 	cout<<"Questo programma ti permette di calcolare l'area del cerchio o del quadrato a tua scelta"<<endl;
 	cout<<"Insersci un numero non negativo"<<endl;
 	cin>>input;
 	if(input<0)
	cout<<"Hai inserito un numero negativo il programma adesso uscira'"<<endl;		 
 }
 int scelta()
 { 
 	int scelta;
 	cout<<"inserisci 0 per calcolare l'area del quadrato 1 per calcolare l'area del cerchio"<<endl;
 	cin>>scelta;
 	
 	return scelta;
 }
 
 float area_quadrato()
 {
 	int qc;
 	qc= pow(input,2);
 	
 	return qc;
}
float area_cerchio()
{
	int qc;
	qc=(pigreco*pow(input,2));
	
	return qc;
}
void output_system(float z,float qc)
{
	if(z==0)
		cout<<"L'area del"<<qc<<endl;
	else if(z==1)
		cout<<"L' area del"<<qc<<endl;
	else
		cout<<"Non ha inserito un opzione valida!!"<<endl;
}


int main() {
float qc;
int z;
	void input_system();
	int scelta_system(int s);
	if (z==0)
	{
	 float area_quadrato(float qc);
	 void output_system();
	}
	else if(z==1){
		float area_cerchio(float qc);
		void output_system();
	}
	else
	void output_system();
	
	system("PAUSE");
	
}
 /*void input_system()
 {
 	int input;
 	cout<<"Questo programma ti permette di calcolare l'area del cerchio o del quadrato a tua scelta"<<endl;
 	cout<<"Insersci un numero non negativo"<<endl;
 	cin>>input;
 	if(input<0)
	cout<<"Hai inserito un numero negativo il programma adesso uscira'"<<endl;		 
 }
 int scelta()
 { 
 	int scelta;
 	cout<<"inserisci 0 per calcolare l'area del quadrato 1 per calcolare l'area del cerchio"<<endl;
 	cin>>scelta;
 	
 	return scelta;
 }
 
 float area_quadrato()
 {
 	int qc;
 	qc= pow(input,2);
 	
 	return qc;
}
float area_cerchio()
{
	int qc;
	qc=(pigreco*pow(input,2));
	
	return qc;
}
void output_system(float z,float qc)
{
	if(z==0)
		cout<<"L'area del"<<qc<<endl;
	else if(z==1)
		cout<<"L' area del"<<qc<<endl;
	else
		cout<<"Non ha inserito un opzione valida!!"<<endl;
}*/ //debug commet 
