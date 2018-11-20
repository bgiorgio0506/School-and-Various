#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
 float a, b, c, delta, x1, x2;
 // Programma per soluzione di equazione di secondo grado 

void equazione()
{
	delta=pow(2,b)-4*a*c;
	if(delta<0)
		printf("il delta e' negativo l'equazione e' impossibile ");
	else if(delta==0)
	{
		 	x1=-b+sqrt(delta)/2*a;
			x2=-b-sqrt(delta)/2*a;
			printf("L'equazione ha un solo risultato\n");
	}
	else
	{
					x1=-b+sqrt(delta)/2*a;
					x2=-b-sqrt(delta)/2*a;
	}
}

void primo_grado()
{
	x1=b/c;
}


void condition_output(){
	if((a==0)&&(b==0)){
        printf("Non e' un equazione!");
    }
 else{
 	if(a==0)
	 {
	 	primo_grado();
 		printf("E'un equazione di primo grado\n");
 		printf("Il risulato e' %f\n",x1);
	 }
	 else if(b==0)
	 {
	  equazione();
	  printf("i risulati sono %f  %f",x1,x2);
	  
	 }
	 else
	 {
	 	equazione();
	 	if(x1==x2)
	 		printf("il risultato e'%f\n",x1);
		 else
		 printf("i risultati sono %f  %f\n",x1,x2);
	 }
 }
}

void input()
{
	printf("Questo programma risolve l'equazione di secondo grado di tipo ax^2+bx+c=0\n");
	printf("Inserisci il primo coeficente a: ");
    scanf ("%f",&a);
    printf("inserisci il coeficente b: ");
    scanf("%f",&b);
    printf("Inserisci il coeficiente c: ");
    scanf("%f",&c);
	
}

int main()
{
	input();
    condition_output();
    
  system("PAUSE");	
  return 0;
}
