#include <iostream>
using namespace std;

int main()
{
	float m1, m2;
	cout<<"Inserisci il coeficente angolare della retta y = m1x+q1"<<endl;
	cin>>m1;
	cout<<"Inserisci il coeficente angolare della retta y = m2x+q2"<<endl;
	cin>>m2;
	if(m1==m2)
		cout<<"Le rette di eq. y = m1x+q1 e y = m2x+q2 sono parallele "<<endl;
	else {
		if(m1==-1/m2)
			cout<<"le rette sono perpendicolari"<<endl;
		else
		cout<<"le rette sono coincidenti"<<endl;
	}
	system("PAUSE");
}
